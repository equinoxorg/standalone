/*
 * eeprom.h
 *
 *  Created on: 16 Apr 2012
 *      Author: Ashley Grealish

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

