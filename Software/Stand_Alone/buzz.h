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

#ifndef _XTAL_FREQ
	#define _XTAL_FREQ  	8000000
#endif

#include <htc.h>

#ifndef _BUZZ_H
#define _BUZZ_H

#define BUZZ_PORT   C
#define BUZZ_POS    6

//Optimal Piezo frequency from Datasheet for buzzer
#define PIEZO_FREQ  5000

//Functions
void init_buzz (void);
void buzz(int);

#endif