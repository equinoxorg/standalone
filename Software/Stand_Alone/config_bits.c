/*
 * Sets up the configuration bits for the chip.
 *
 * This is used instead of the GUI to make the code more portable
 *
 * Chip: PIC18F25K22
 * Compiler: Hi Tech PIC18 C compiler
 

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

// PIC18F25K22 Configuration Bit Settings

//Can ignore error higlighting
__CONFIG(1, FOSC_INTIO67 & PLLCFG_OFF & PRICLKEN_ON & FCMEN_OFF & IESO_OFF );
__CONFIG(2, PWRTEN_OFF & BOREN_SBORDIS & BORV_190 & WDTEN_SWON & WDTPS_2048);
__CONFIG(3, CCP2MX_PORTC1 & PBADEN_OFF & CCP3MX_PORTC6 & HFOFST_ON & T3CMX_PORTC0 & P2BMX_PORTC0 & MCLRE_EXTMCLR);
__CONFIG(4, STVREN_ON & LVP_ON & XINST_OFF & DEBUG_OFF);
__CONFIG(5, CP0_OFF & CP1_OFF & CP2_OFF & CP3_OFF & CPB_OFF & CPD_OFF);
__CONFIG(6, WRT0_OFF & WRT1_OFF & WRT2_OFF & WRT3_OFF & WRTC_OFF & WRTB_OFF & WRTD_OFF);
__CONFIG(7, EBTR0_OFF & EBTR1_OFF & EBTR2_OFF & EBTR3_OFF & EBTRB_OFF);
