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