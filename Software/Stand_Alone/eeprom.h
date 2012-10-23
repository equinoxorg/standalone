/*
 * eeprom.h
 *
 *  Created on: 16 Apr 2012
 *      Author: Ashley Grealish
 */

#ifndef SA_EEPROM_H_
#define SA_EEPROM_H_

    #include <htc.h>
    #include <stdint.h>
    #include <time.h>

    #define EE_FULL_UNLOCK_CODE 0x55
    

    //Functions
    void ee_write_unlock_count(uint8_t);
    uint8_t ee_read_unlock_count(void);
    void ee_write_full_unlock(uint8_t);
    uint8_t ee_read_full_unlock(void);
    void ee_write_lock_date(time_t);
    time_t ee_read_lock_date(void);
    void ee_write_box_id(uint16_t);
    uint16_t ee_read_box_id(void);
    
#endif

