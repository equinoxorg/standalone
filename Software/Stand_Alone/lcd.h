/********************************************************************

16X2 ALPHANEUMERIC LCD INTERFACING LIBRARY FOR PIC 18F MCUS
-----------------------------------------------------------

Easy to use library for interfacing 16x2 lcd in 4 bit mode.

MCU: PIC18FXXXX Series from Microchip.
Compiler: HI-TECH C Compiler for PIC18 MCUs (http://www.htsoft.com/)

Copyrights 2008-2009 Avinash Gupta
eXtreme Electronics, India

For More Info visit
http://www.eXtremeElectronics.co.in

Mail: me@avinashgupta.com

 -----------------------------------------------------------
 Modified:
 * Auther: Ashley Grealish
 * Date: 18/04/2012
 * Changes: Added backlight control functionality
 *          with functions : LCDBacklight_on() and LCDBacklight_off()
 
  
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

********************************************************************/
#ifndef _XTAL_FREQ
	#define _XTAL_FREQ  	8000000
#endif

#include <htc.h>
#include <stdint.h>

#ifndef _LCD_H
#define _LCD_H

/*_________________________________________________________________________________________*/

/************************************************
	LCD CONNECTIONS
*************************************************/

#define LCD_DATA B	//Port PB0-PB3 are connected to D4-D7

#define LCD_E B		//Enable/strobe signal
#define LCD_E_POS	4	//Position of enable in above port

#define LCD_RS B	
#define LCD_RS_POS 5

#define LCD_RW B
#define LCD_RW_POS 6

#define LCD_BCKL B
#define LCD_BCKL_POS 7


//************************************************

#define LS_BLINK 0B00000001
#define LS_ULINE 0B00000010



/***************************************************
			F U N C T I O N S
****************************************************/



void LCDInit(uint8_t style);
void LCDWriteString(const char *msg);
void LCDWriteInt(int val,unsigned int field_length);
void LCDGotoXY(uint8_t x,uint8_t y);
void LCDBacklight_on (void);
void LCDBacklight_off (void);

//Low level
void LCDByte(uint8_t,uint8_t);
#define LCDCmd(c) (LCDByte(c,0))
#define LCDData(d) (LCDByte(d,1))

void LCDBusyLoop();



/***************************************************
			F U N C T I O N S     E N D
****************************************************/


/***************************************************
	M A C R O S
***************************************************/
#define LCDClear() LCDCmd(0b00000001)
#define LCDHome() LCDCmd(0b00000010)

#define LCDWriteStringXY(x,y,msg) {\
 LCDGotoXY(x,y);\
 LCDWriteString(msg);\
}

#define LCDWriteIntXY(x,y,val,fl) {\
 LCDGotoXY(x,y);\
 LCDWriteInt(val,fl);\
}
/***************************************************/




/*_________________________________________________________________________________________*/
#endif




