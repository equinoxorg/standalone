/********************************************************************

 Firmware for the e.quinox Stand Alone Payment Control Board
---------------------------------------------------------

 * Author: Ashley Grealish
 * Email: ashley.grealish09@imperial.ac.uk
 * Date: June 2012
 * Compiler: HI-TECH C Compiler for PIC18 MCUs (http://www.htsoft.com/)

  
 |  Copyright (C) 2011  Ashley Grealish - e.quinox.org
 |
 |  This program is free software: you can redistribute it and/or modify
 |  it under the terms of the GNU General Public License as published by
 |  the Free Software Foundation, either version 3 of the License, or
 |  (at your option) any later version.
 |
 |  This program is distributed in the hope that it will be useful,
 |  but WITHOUT ANY WARRANTY; without even the implied warranty of
 |  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 |  GNU General Public License for more details.
 |
 |  You should have received a copy of the GNU General Public License
 |  along with this program.  If not, see <http://www.gnu.org/licenses/>.   
 
 * Functionality:
 * Drives 16x2 LCD Screen
 * Automatic timeput for the LCD backlight to save power
 * Read values from keypad
 * Gives audible feedback for keypad using buzzer
 * Unlocks power outputs for time set by unlock codes
 * RTC moniters the time passed since the last unlock
 * Allows debugging info to be displayed if '1' held on startup
   then 'tick' pressed after the beep
 * Provides countdown to next lock date on LCD screen

 * Todo
 * Clean the keypad read and intToStr conversions
 * Add better switch de-bouncing
 * Change unlock code, to "Next expected unlock code"
 * Add WDT code 
 ********************************************************************/


#ifndef _XTAL_FREQ
#define _XTAL_FREQ  	8000000
#endif

#include <htc.h>
#include <stdint.h>
#include <time.h>

#include "eeprom.h"
#include "LCD.h"
#include "buzz.h"
#include "keypad.h"
#include "unlock_codes.h"
#include "rtc.h"

//IO Ports
#define TEST_LED_RC7	(1<<7)

#define LVCO_PORT   C
#define LVCO_POS    0
#define LVCO_LAT    LATC
#define LVCO_TRIS   TRISC
#define INV_PORT   C
#define INV_POS    1
#define INV_LAT    LATC
#define INV_TRIS   TRISC

#define POWER_OUT_ON()  LVCO_LAT |= (1 << LVCO_POS); INV_LAT |= (1 << INV_POS)
#define POWER_OUT_OFF() LVCO_LAT &= ~(1 << LVCO_POS); INV_LAT &= ~(1 << INV_POS)

#define STATE_NORMAL		0
#define	STATE_AWAIT_PAYMENT	1
#define	STATE_LVCO		2
#define STATE_FULL_UNLOCK       3

#define FULL_BATT_VOLTAGE       (float)14.0
#define CUTOFF_VOLTAGE          (float)10.5
#define VCC_5V_SUPPLY           (float)5.0
#define LOW_BATT_PERCENTAGE     25
#define BATT_TURN_ON_PERCENTAGE 25

#define BACKLIGHT_TIMEOUT       15

#define DAY2SEC     ( (uint32_t)24 * 60 * 60 )
//Debug only
//#define DAY2SEC     ( (uint32_t)10 )

//Function Prototypes
void init_hardware(void);
void Wait(unsigned int);
char check_code(uint32_t);
char *utoa_b(char*, uint32_t, int, uint8_t);
uint8_t get_batt_level(void);
void box_setup(void);
void delay_sec(uint8_t);
void LCDUpdateBattLevel(uint8_t);
void LCDUpdateDaysRem(time_t, time_t);
void debug_display(void);
void update_expiry_date(uint8_t);

//Global variables
char state = STATE_NORMAL;

//------------------------------------------------------------------------------
void main() {
    unsigned char keypad_result, keypad_result_prev;
    char keypad_result_str [10];
    unsigned int i;
    uint8_t digit_count = 0;
    uint32_t entry_code = 0;
    uint8_t batt_level;
    struct tm rtc_time;
    uint16_t backlight_count = 0;

    init_hardware();

    POWER_OUT_OFF();

    //Let the Module start up
    Wait(100);

    //Initialize the LCD Module
    LCDInit(LS_BLINK);

    //Turn on the LCD Backlight
    LCDBacklight_on();

    //Clear the Module
    LCDClear();

    box_setup();
    
    if (!init_rtc()) {
       LCDWriteStringXY(0, 0, "    RTC Error   ");
       delay_sec(1);
    }

    //Check for keypad combination held
    if (read_keypad() == 0x01) {
        buzz(100);
        for (i = 0; i < 200; i++) {
            if (read_keypad() == 0xa1) {
                setup_rtc();
                debug_display();
                break;
            }
            __delay_ms(20);
        }
    }

    // If no WDT timeout (error) occured
    if (RCONbits.TO) {
        //Splash Screen (2s)
        LCDWriteStringXY(0, 0, "    e.quinox    ");
        LCDWriteStringXY(0, 1, "   solar.box    ");
        delay_sec(2);
    }

    //Write Status Info on second line
    LCDWriteStringXY(0, 1, "Batt:___ Days:__");


    //Loop Forever
    while (1) {

        //Case statement implements a state machine.
        //The state is one of four options defined above
        //and stores the overal state of the box
        switch (state) {
            case STATE_NORMAL:
                //Check for Full unlock
                if (ee_read_full_unlock() == EE_FULL_UNLOCK_CODE) {
                    state = STATE_FULL_UNLOCK;
                    LCDWriteStringXY(0, 0, "    e.quinox    ");
                    LCDWriteStringXY(0, 1, "Batt:___        ");
                    backlight_count = 0;
                    break;
                }

                if (read_keypad() != 0xFF) {
                    backlight_count = 0;
                    LCDBacklight_on();
                    buzz(100);
                } else if (backlight_count == BACKLIGHT_TIMEOUT ){
                    LCDBacklight_off();
                } else {
                    backlight_count++;
                }

                //Check Payment
                rtc_get_time_date(&rtc_time);

                LCDUpdateDaysRem(mktime(&rtc_time), ee_read_lock_date());

                if (mktime(&rtc_time) >= ee_read_lock_date()) {
                    state = STATE_AWAIT_PAYMENT;
                    LCDWriteStringXY(0, 0, "Enter:__________");
                    LCDWriteStringXY(0, 1, "Batt:___  Locked");
                    LCDGotoXY(6, 0);
                    backlight_count = 0;
                    break;
                }

                // Battery Level Monitering
                batt_level = get_batt_level();

                if (batt_level == 0)
                    state = STATE_LVCO;
                else
                    LCDUpdateBattLevel(batt_level);

                POWER_OUT_ON();

                //Pauses the box to prevent filckering on screen
                //Update to sleep mode to save power.
                delay_sec(1);

                break;

            case STATE_AWAIT_PAYMENT:

                POWER_OUT_OFF();

                //Read in unlock Code
                keypad_result = read_keypad();

                if ((keypad_result != 0xFF) && (keypad_result != keypad_result_prev)) {
                    backlight_count = 0;
                    LCDBacklight_on();
                    buzz(100);

                    if (keypad_result == 0xa0) {
                        //'X' Pressed
                        //LCDWriteString("x");
                        digit_count = 0;
                        entry_code = 0;
                        LCDWriteStringXY(0, 0, "Enter:__________");
                        LCDWriteStringXY(0, 1, "Batt:___  Locked");
                        LCDGotoXY(6, 0);
                    } else if (keypad_result == 0xa1) {
                        //Tick Pressed
                        //LCDWriteString("./");
                    } else {
                        entry_code = (entry_code * 10) + keypad_result;
                        keypad_result_str[0] = '\0';
                        utoa_b(keypad_result_str, entry_code, 10, digit_count);
                        LCDWriteStringXY(6, 0, keypad_result_str);
                        LCDGotoXY((7 + digit_count), 0);

                        if (digit_count++ == 9) {

                            Wait(1000);

                            digit_count = 0;
                            //Check the unlock code
                            if (check_code(entry_code)) {

                                //Checks if the full unlock code was given
                                if (GET_UNLOCK_DAYS(entry_code) == FULL_UNLOCK) {
                                    ee_write_full_unlock(EE_FULL_UNLOCK_CODE);
                                    state = STATE_FULL_UNLOCK;
                                    LCDWriteStringXY(0, 0, "    e.quinox    ");
                                    LCDWriteStringXY(0, 1, "Batt:___        ");
                                    backlight_count = 0;
                                    break;
                                }

                                //Updates the next unlock code expiry date
                                update_expiry_date(GET_UNLOCK_DAYS(entry_code));

                                //Updates state
                                state = STATE_NORMAL;
                                //Reset the entry code for next code entry
                                entry_code = 0;
                                LCDWriteStringXY(0, 0, "    e.quinox    ");
                                LCDWriteStringXY(0, 1, "Batt:___ Days:__");
                                break;

                            } else {
                                LCDWriteStringXY(0, 0, "    Incorrect   ");
                                LCDWriteStringXY(0, 1, "Enter valid code");
                                delay_sec(5);
                                LCDWriteStringXY(0, 0, "Enter:__________");
                                LCDWriteStringXY(0, 1, "Batt:___ Days:__");
                                LCDGotoXY(6, 0);
                            }
                            entry_code = 0;
                        }
                    }

                } else if (backlight_count == (BACKLIGHT_TIMEOUT*100) ){
                    LCDBacklight_off();
                } else {
                    backlight_count++;
                }

                keypad_result_prev = keypad_result;

                //Debouncing time
                Wait(50);


                // Battery Level Monitering
                batt_level = get_batt_level();

                if (batt_level == 0)
                    state = STATE_LVCO;
                else
                    LCDUpdateBattLevel(batt_level);

                break;

            case STATE_LVCO:
                POWER_OUT_OFF();
                LCDWriteStringXY(0, 0, "  Turn off and  ");
                LCDWriteStringXY(0, 1, "    Recharge!   ");

                // Battery Level Monitering
                if (get_batt_level() >= BATT_TURN_ON_PERCENTAGE) {
                    if (ee_read_full_unlock() == EE_FULL_UNLOCK_CODE) {
                        state = STATE_FULL_UNLOCK;
                        LCDWriteStringXY(0, 0, "    e.quinox    ");
                        LCDWriteStringXY(0, 1, "Batt:___        ");
                        break;
                    } else {
                        state = STATE_NORMAL;
                        LCDWriteStringXY(0, 0, "    e.quinox    ");
                        LCDWriteStringXY(0, 1, "Batt:___ Days:__");
                        break;
                    }
                }

                buzz(100);
                delay_sec(1);

                break;
            case STATE_FULL_UNLOCK:

                POWER_OUT_ON();

                // Battery Level Monitering
                batt_level = get_batt_level();

                if (batt_level == 0) {
                    state = STATE_LVCO;
                    break;
                } else {
                    LCDUpdateBattLevel(batt_level);
                }

                if (read_keypad() != 0xFF) {
                    backlight_count = 0;
                    LCDBacklight_on();
                    buzz(100);
                } else if (backlight_count == BACKLIGHT_TIMEOUT ){
                    LCDBacklight_off();
                } else {
                    backlight_count++;
                }

                delay_sec(1);

                break;
        }
    }

}

//------------------------------------------------------------------------------
void delay_sec(uint8_t seconds) {
    unsigned int i;

    for (i = 0; i < (100 * seconds); i++)
        __delay_ms(10);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
void box_setup() {
    uint16_t box_id;
    uint8_t i, keypad_result;
    uint8_t keypad_result_prev = 0xFF;

    box_id = ee_read_box_id();

    


    if ((box_id == 0) || (box_id == 0xFFFF)) {

        POWER_OUT_ON();

        
        LCDWriteStringXY(0, 0, "Box_ID:")

        for (i = 0; i < 5; i++) {
            do {
                //Read in box_id
                keypad_result = read_keypad();
                if (keypad_result == 0xFF)
                    keypad_result_prev = 0xFF;
                //Debouncing time
                Wait(50);
            } while ((keypad_result == 0xFF) || (keypad_result == keypad_result_prev));

            buzz(100);
            if (keypad_result == 0xa0) {
                //tick Pressed
            } else if (keypad_result == 0xa1) {
                //cross pressed
                box_id = 0;
                i = 0;
            } else {
                box_id = (box_id * 10) + keypad_result;
                LCDWriteIntXY(7, 0, box_id, (i + 1));
            }

            keypad_result_prev = keypad_result;

        }

        //delay_sec(1);

        //box_id = 12345;

        //idloc_write(0, (box_id & 0xFF));
        //idloc_write(1, ((box_id >> 8) & 0xFF));
        ee_write_box_id(box_id);

        LCDClear();
        LCDWriteStringXY(0, 0, "Box_ID_Verify:");
        LCDWriteIntXY(0, 1, ee_read_box_id(), 5);
        delay_sec(3);
        LCDClear();

        setup_rtc();

        debug_display();

        POWER_OUT_OFF();

    }

    if (ee_read_unlock_count() == 0xFF)
        ee_write_unlock_count(0x00);

    //Set the box ID
    set_box_id(box_id);

}
//------------------------------------------------------------------------------
char check_code(uint32_t code) {
    char code_valid = 0;
    uint8_t unlock_count = ee_read_unlock_count();

    if (check_checksum(code)) {
        if (((GET_UNLOCK_COUNT(code) - unlock_count) <= 1) || (GET_UNLOCK_DAYS(code) == FULL_UNLOCK)) {
            ee_write_unlock_count(GET_UNLOCK_COUNT(code) + 1);
            code_valid = 1;
        }
    }

    return code_valid;
}

//------------------------------------------------------------------------------
char *utoa_b(char *buf, uint32_t val, int base, uint8_t pad) {
    uint32_t v;
    char c;
    int i = 0;

    v = val;
    do {
        v /= base;
        buf++;
    } while (i++ != pad);
    *buf-- = 0;
    i = 0;
    do {
        c = val % base;
        val /= base;
        if (c >= 10)
            c += 'A' - '0' - 10;
        c += '0';
        *buf-- = c;
    } while (i++ != pad);
    return buf;
}

//------------------------------------------------------------------------------
//Simple Delay Routine
void Wait(unsigned int delay) {
    for (; delay; delay--)
        __delay_us(100);
}

//------------------------------------------------------------------------------
void init_hardware() {

    //8Mhz Clock
    OSCCON &= 0b11101111;
    OSCCON |= 0b01100000;

    //A register is keypad
    //Sets up all pins as digital inputs
    //One-hot switching to outputs in keypad_read() function
    TRISA = 0xFF;
    ANSELA = 0x00;

    //B port used for LCD comms
    //Sets up all pins as digital inputs
    TRISB = 0xFF;
    ANSELB = 0x00;

    //Port C used for I2c bus and misc outputs
    //Buzzer is output
    TRISC = ~TEST_LED_RC7;
    //Set up Analogue in on RC2/AN14
    ANSELC = (1 << 2);
    //Disables PWM output on RC0
    CCP1CON = 0;
    CCP2CON = 0;
    T1CON &= ~0b11000000;
    T3CON &= ~0b11000000;

    //Make LVCO pin an output
    LVCO_TRIS &= ~(1 << LVCO_POS);

    INV_TRIS &= ~(1 << INV_POS);

    init_buzz();
}

//------------------------------------------------------------------------------
void LCDUpdateBattLevel(uint8_t batt_level) {
    if (batt_level == 100) {
        LCDWriteStringXY(0, 1, "Batt:100%");
    } else if (batt_level < LOW_BATT_PERCENTAGE) {
        //low_voltage_indicator = 1;
        LCDWriteStringXY(0, 1, "Low Batt ");
    } else {
        //Go to battery level location
        LCDWriteStringXY(0, 1, "Batt:");
        LCDWriteInt(batt_level, 2);
        LCDWriteString("% ");
        //LCDBacklight_on();
    }
    LCDGotoXY(17, 0);

}

//------------------------------------------------------------------------------
uint8_t get_batt_level(void) {
    int i;
    uint16_t adc_result = 0;
    float adc_result_float, batt_voltage;

    //ADC Channel Select AN14
    ADCON0 = 0b00111000;
    //Turn on ADC
    ADCON0 |= 0b00000001;

    //Right justified, longest aqu time, fasted clock
    //Needs work
    ADCON2 = 0b10111000;

    for (i = 0; i < 8; i++) {
        //Start the conversion
        ADCON0 |= 0b00000010;

        //Wait for conversion to finish
        while (ADCON0 & 0b00000010);

        adc_result += (((uint16_t) ADRESH << 8) | ADRESL);
    }

    //adc_result div 8
    adc_result_float = (float) adc_result / 8.0;

    batt_voltage = ((float) (VCC_5V_SUPPLY * 3) / 1024.0) * adc_result_float;

    if (batt_voltage < CUTOFF_VOLTAGE) {
        return 0;
        //Error
    } else if (batt_voltage > FULL_BATT_VOLTAGE) {
        return 100;
    } else {
        return (uint8_t) (((batt_voltage - CUTOFF_VOLTAGE) / (FULL_BATT_VOLTAGE - CUTOFF_VOLTAGE)) * 100);
    }
}

//------------------------------------------------------------------------------
void LCDUpdateDaysRem(time_t current_time, time_t unlock_time) {
    uint8_t days_rem;

    if (current_time > unlock_time) {
        LCDWriteStringXY(9, 1, "_Locked");
    } else {
        days_rem = (uint8_t) ((float) (unlock_time - current_time) / (float) (DAY2SEC));
        LCDWriteIntXY(14, 1, days_rem, 2);
    }
}

//------------------------------------------------------------------------------
void debug_display(void) {
    struct tm rtc_time;
    unsigned char j;
    uint32_t temp_32;

    //debug mode
    LCDWriteStringXY(0, 0, "Unlock Count:");
    LCDWriteIntXY(0, 1, ee_read_unlock_count(), 3);
    delay_sec(3);
    LCDClear();
    LCDWriteStringXY(0, 0, "Box_ID:");
    LCDWriteInt(ee_read_box_id(), 5);
    delay_sec(3);
    LCDClear();
    if (ee_read_full_unlock() == EE_FULL_UNLOCK_CODE) {
        LCDWriteString("Full Unlock");
    } else {
        LCDWriteString("Not Full Unlock");
    }
    delay_sec(3);

    for (j = 0; j < 100; j++) {

        //RTC Clock Test
        rtc_get_time_date(&rtc_time);
        temp_32 = mktime(&rtc_time);
        LCDClear();
        LCDGotoXY(0, 0);
        LCDWriteInt(rtc_time.tm_mday, 2);
        LCDWriteString("/");
        LCDWriteInt(rtc_time.tm_mon, 2);
        LCDWriteString("/");
        LCDWriteInt((uint16_t) ((uint16_t) rtc_time.tm_year + (uint16_t) 1900), 4);
        LCDGotoXY(0, 1);
        LCDWriteInt(rtc_time.tm_hour, 2);
        LCDWriteString(":");
        LCDWriteInt(rtc_time.tm_min, 2);
        LCDWriteString(":");
        LCDWriteInt(rtc_time.tm_sec, 2);
        __delay_ms(20);
    }
}

//------------------------------------------------------------------------------
void update_expiry_date(uint8_t unlock_time_code) {

    time_t unlock_time_sec = 0;
    time_t unlock_time = 0;
    struct tm rtc_time;

    LCDClear();

    switch (unlock_time_code) {
        case FULL_UNLOCK:
            unlock_time = 0xFFFFFFFF;
            LCDWriteString("   Full Unlock  ");
            break;
        case TWO_DAYS:
            unlock_time = (2 * DAY2SEC);
            LCDWriteString("     2 Days     ");
            break;
        case FIVE_DAYS:
            unlock_time = (5 * DAY2SEC);
            LCDWriteString("     5 Days     ");
            break;
        case SEVEN_DAYS:
            unlock_time = (7 * DAY2SEC);
            LCDWriteString("    7 Days      ");
            break;
        case TWO_WEEKS:
            unlock_time = (14 * DAY2SEC);
            LCDWriteString("    2 Weeks     ");
            break;
        case THREE_WEEKS:
            unlock_time = (21 * DAY2SEC);
            LCDWriteString("     3 Weeks    ");
            break;
        case ONE_MONTH:
            unlock_time = (28 * DAY2SEC);
            LCDWriteString("    4 Weeks     ");
            break;
        case TWO_MONTHS:
            unlock_time = (56 * DAY2SEC);
            LCDWriteString("     8 Weeks    ");
            break;
        default:
            unlock_time = 0;
            LCDWriteString("      Error     ");
    }

    //Write RTC + unlock time to expire date eeprom
    rtc_get_time_date(&rtc_time);
    unlock_time_sec = mktime(&rtc_time) + (time_t) unlock_time;
    ee_write_lock_date(unlock_time_sec);

    delay_sec(3);
}