#include <msp430.h> 
#include "peripherals.h"
/**
 * main.c
 */

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer

	initLeds();
	setLeds(0x01);

	return 0;
}







