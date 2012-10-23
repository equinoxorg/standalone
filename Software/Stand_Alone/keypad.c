#include "keypad.h"

//Global Variables
#define Vert_0      (1 << 6)
#define Vert_1      (1 << 5)
#define Vert_2      (1 << 4)
#define Vert_3      (1 << 3)
#define Horiz_0     (1 << 0)
#define Horiz_1     (1 << 1)
#define Horiz_2     (1 << 2)


unsigned char read_keypad(void){

        //Reset all keypad port to inputs
        TRIS_KEYPAD = 0xFF;
    
	//Set the current vertical pin as output
	TRIS_KEYPAD = ~Vert_0;
	//Pull it to ground
	PORT_KEYPAD = ~Vert_0;
	_delay(10);
	//Input pins have pull up, so high is no-press, low is pressed
	if ( ~PORT_KEYPAD & Horiz_0)
		return 0x01;
	if ( ~PORT_KEYPAD & Horiz_1)
		return 0x02;
	if ( ~PORT_KEYPAD & Horiz_2)
		return 0x03;

	TRIS_KEYPAD = ~Vert_1;
	PORT_KEYPAD = ~Vert_1;
	_delay(10);
	if ( ~PORT_KEYPAD & Horiz_0)
		return 0x04;
	if ( ~PORT_KEYPAD & Horiz_1)
		return 0x05;
	if ( ~PORT_KEYPAD & Horiz_2)
		return 0x06;

	TRIS_KEYPAD = ~Vert_2;
	PORT_KEYPAD = ~Vert_2;
	_delay(10);
	if ( ~PORT_KEYPAD & Horiz_0)
		return 0x07;
	if ( ~PORT_KEYPAD & Horiz_1)
		return 0x08;
	if ( ~PORT_KEYPAD & Horiz_2)
		return 0x09;

	TRIS_KEYPAD = ~Vert_3;
	PORT_KEYPAD = ~Vert_3;
	_delay(10);
	if ( ~PORT_KEYPAD & Horiz_0)
		return 0xA0;
	if ( ~PORT_KEYPAD & Horiz_1)
		return 0x00;
	if ( ~PORT_KEYPAD & Horiz_2)
		return 0xA1;

	return 0xFF;
}
