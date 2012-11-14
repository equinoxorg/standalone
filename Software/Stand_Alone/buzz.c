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

#include "buzz.h"

#define                 _CONCAT(a,b) a##b
#define PORT(x)         _CONCAT(PORT,x)
#define LAT(x)          _CONCAT(LAT,x)
#define TRIS(x)         _CONCAT(TRIS,x)

#define BUZZ_LAT        LAT(BUZZ_PORT)
#define BUZZ_TRIS       TRIS(BUZZ_PORT)

#define SET_BUZZ()      (BUZZ_LAT|=(1<<BUZZ_POS))
#define CLEAR_BUZZ()    (BUZZ_LAT&=~(1<<BUZZ_POS))

//Get the optimal half period delay to drive the buzzer
//at it's optimal frequency
#define BUZZ_DELAY      ((_XTAL_FREQ / PIEZO_FREQ) / 2)

void init_buzz (void) {

    BUZZ_TRIS &= ~ (1<<BUZZ_POS);

}

void buzz(int cycles){
	int i;

	for (i=0; i < cycles; i++){
                _delay(BUZZ_DELAY);
                SET_BUZZ();
		_delay(BUZZ_DELAY);
		CLEAR_BUZZ();
	}
}