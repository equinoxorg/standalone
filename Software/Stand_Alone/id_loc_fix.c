/*
 | Added here to fix the problem with Hi Tech C compiler not finding these
 | functions in it's sources directory

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

#include <htc.h>


extern unsigned char idloc_read(unsigned char reg_no);

void initiate_write(void)
{
	while(EECON1bits.WR)continue;	// don't proceed if write in progress
	STATUSbits.C=0;
	if(INTCONbits.GIE)
		STATUSbits.C=1;
	INTCONbits.GIE=0;
	EECON1bits.WREN=1;				// this is the required sequence
	EECON2=0x55;
	EECON2=0xAA;
	EECON1bits.WR=1;
	asm("\tNOP");
	_CLEAR_EEIF();
	EECON1bits.WREN=0;
	if(STATUSbits.C)
		INTCONbits.GIE=1;
}

void
idloc_write(unsigned char reg_no, unsigned char value){
#if _FLASH_ERASE_SIZE > 255
	static unsigned char saved[_FLASH_ERASE_SIZE];
	unsigned int i;
#else
	unsigned char saved[_FLASH_ERASE_SIZE];
	unsigned char i;
#endif
#ifdef _OMNI_CODE_
	unsigned char	saved_tblptrh;
	unsigned char	saved_tblptru;

	saved_tblptrh = TBLPTRH;
	saved_tblptru = TBLPTRU;
#endif

	i=_FLASH_ERASE_SIZE;
	do{	// save existing data
		i--;
		saved[i]=idloc_read(i);
	}while(i);

#if defined(_OMNI_CODE_)
	TBLPTRU=0x20;	// read will clear this - needs to be set again
	TBLPTRH=0x0;	// read restores TBLPTRH to previous value, so clear again
#elif defined(SMALL_DATA)
	TBLPTRU=0x20;	// if 16-Bit pointers, read will clear this - needs to be set again
#endif
	// at this point TBLPTR should equal 200000h.
	// erase this sector before writing.
	EECON1=0x90;

// WARNING - DO NOT SET ICD2 BREAKPOINTS BELOW THIS LINE!!
	initiate_write();
	asm("tblrd*-");	// adjust TBLPTRs prior to increment ops

	for(i=0;i<_FLASH_ERASE_SIZE;i++){
		TABLAT = saved[i];	// rewrite previous byte
		if(i==reg_no)
			TABLAT = (value | 0xF0);	// write lower nibble only
		asm("\tTBLWT+*");		// copy to flash holding register
		if((TBLPTRL&(_FLASH_WRITE_SIZE-1))==(_FLASH_WRITE_SIZE-1)){
			initiate_write();	// commit holding registers to flash
		}
	}
#ifdef _OMNI_CODE_
	TBLPTRH = saved_tblptrh;
	TBLPTRU = saved_tblptru;
#elif defined(SMALL_DATA)
	TBLPTRU=0;	// if program uses 16-Bit pointers, manually clear TBLTRU now
#endif
}

unsigned char
idloc_read(unsigned char reg_no){

#ifdef _OMNI_CODE_
	unsigned char	saved_tblptrh;
	unsigned char	saved_tblptru;

	saved_tblptrh = TBLPTRH;
	saved_tblptru = TBLPTRU;
#endif
	TBLPTRU=0x20;	// IDLoc stuff starts at address 0x200000
	TBLPTRH=0;
	TBLPTRL=reg_no;	// select the register to read
	EECON1 = 0x80;	// set to select Flash area

// read lower byte of IDLoc register
#if	_ERRATA_TYPES & ERRATA_MINUS40
	coldTableRead();	// special errata for cold days (use -D_MINUS40C compiler option)
#else
	asm("\tTBLRD*");	// another Microchip errata case
#endif

#ifdef _OMNI_CODE_
	TBLPTRH = saved_tblptrh;
	TBLPTRU = saved_tblptru;
#elif defined(SMALL_DATA)
	TBLPTRU=0;	// if program uses 16-Bit pointers, manually clear TBLTRU now
#endif
	return TABLAT;
}

