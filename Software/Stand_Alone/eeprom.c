/*
 *  Functions created to interface with the eeporm
 *
 *  Eeprom size : 256 bytes
 *  Or use macrodefinition __EEPROMSIZE
 *
 *  EEPROM access functions
 *  unsigned char eeprom_read(unsigned int addr);
 *  void eeprom_write(unsigned int addr, unsigned char value);
 * 
 
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

 */

#include "eeprom.h"

#define UNLOCK_COUNT_ADDR   0
//Indicates if the bix has been fully unlocked
#define FULL_UNLOCK_ADDR    (UNLOCK_COUNT_ADDR + sizeof(uint8_t))
//Specifies the date untill which the dox has been unlocked.
#define LOCK_DATE_ADDR      (FULL_UNLOCK_ADDR + sizeof(uint8_t))

#define BOX_ID_ADDR         (LOCK_DATE_ADDR + sizeof(time_t))

//Clears the first 32 bytes of eeprom
__EEPROM_DATA(0, 0, 0, 0, 0, 0, 0, 0);
__EEPROM_DATA(0, 0, 0, 0, 0, 0, 0, 0);
__EEPROM_DATA(0, 0, 0, 0, 0, 0, 0, 0);
__EEPROM_DATA(0, 0, 0, 0, 0, 0, 0, 0);


void ee_write_unlock_count(uint8_t value) {
    eeprom_write(UNLOCK_COUNT_ADDR, value);
    while (!EEIF);
    EEIF = 0;
}

uint8_t ee_read_unlock_count(void) {
    return eeprom_read(UNLOCK_COUNT_ADDR);
}

void ee_write_full_unlock(uint8_t value) {
    eeprom_write(FULL_UNLOCK_ADDR, value);
    while (!EEIF);
    EEIF = 0;
}

uint8_t ee_read_full_unlock(void) {
    return eeprom_read(FULL_UNLOCK_ADDR);
}
void ee_write_lock_date(time_t value) {
    uint8_t a1, a2, a3, a4;

    a1 = (value >> 24);
    a2 = (value & 0x00FF0000) >> 16;
    a3 = (value & 0x0000FF00) >> 8;
    a4 = (value & 0x000000FF);
    eeprom_write(LOCK_DATE_ADDR, a1);
    while (!EEIF);
    EEIF = 0;
    eeprom_write(LOCK_DATE_ADDR + 1, a2);
    while (!EEIF);
    EEIF = 0;
    eeprom_write(LOCK_DATE_ADDR + 2, a3);
    while (!EEIF);
    EEIF = 0;
    eeprom_write(LOCK_DATE_ADDR + 3, a4);
    while (!EEIF);
    EEIF = 0;
}

time_t ee_read_lock_date(void) {
    uint8_t b1, b2, b3, b4;
    time_t time_read;

    b1 = eeprom_read(LOCK_DATE_ADDR);
    b2 = eeprom_read(LOCK_DATE_ADDR + 1);
    b3 = eeprom_read(LOCK_DATE_ADDR + 2);
    b4 = eeprom_read(LOCK_DATE_ADDR + 3);
    time_read = ((time_t) b1 << 24) & 0xFF000000;
    time_read |= ((time_t) b2 << 16) & 0x00FF0000;
    time_read |= ((time_t) b3 << 8) & 0x0000FF00;
    time_read |= (time_t) b4 & 0x000000FF;

    return time_read;
}

void ee_write_box_id(uint16_t value) {
    uint8_t a1, a2;

    a1 = (value & 0xFF00) >> 8;
    a2 = (value & 0x00FF);

    eeprom_write(BOX_ID_ADDR, a1);
    while (!EEIF);
    EEIF = 0;

    eeprom_write(BOX_ID_ADDR + 1, a2);
    while (!EEIF);
    EEIF = 0;
}

uint16_t ee_read_box_id(void) {
    uint8_t b1, b2;
    uint16_t temp;

    b1 = eeprom_read(BOX_ID_ADDR);
    b2 = eeprom_read(BOX_ID_ADDR + 1);

    temp = (uint16_t)b1 << 8;
    temp |= (uint16_t) b2;

    return temp;
}