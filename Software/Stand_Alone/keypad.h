#ifndef _XTAL_FREQ
	#define _XTAL_FREQ  	8000000
#endif

#include <htc.h>

#ifndef _KEYPAD_H
#define _KEYPAD_H

#define KEYPAD_PORT     A
#define TRIS_KEYPAD     TRISA
#define PORT_KEYPAD     PORTA


//Functions
unsigned char read_keypad(void);

#endif