/*
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

#ifndef _RTC_H
#define _RTC_H

#include <htc.h>
#include <stdint.h>
#include <time.h>

#include "i2c.h"

//Returns non-zero on error
unsigned char init_rtc(void);

void setup_rtc(void);

void rtc_get_time_date( struct tm* time_ptr );
//---Below not advsided as date/time could roll-over during reading
//---seperate parts. Use above functions where possible

//Functions to read single words from RTC
void rtc_word_write(unsigned char, unsigned char);
unsigned char rtc_word_read(unsigned char);
//Functions for converting data from RTC clock format to ints
uint8_t rtc_get_sec (void);
uint8_t rtc_get_min (void);
uint8_t rtc_get_hour (void);
uint8_t rtc_get_month (void);
uint8_t rtc_get_date (void);
uint16_t rtc_get_year (void);


#endif