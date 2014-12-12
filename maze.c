#include <msp430.h> 
#include "maze.h"
#include "Library/Robot9_IR_Library.h"



/*
 * main.c
 */
void main(void) {
	WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	P1DIR |= BIT0;

	unsigned short leftIn = 0x3FF;

	initMotors();				//initialize the system

	_delay_cycles(SHORT_T);		//let use move out of way
	
	while(1){			//infinite loop
		drive(FORWARD);
		while (getLeftVal() > 0x290){ //leftIn < 0x290){
			leftIn = 0;
			P1OUT &= ~BIT0;

			_delay_cycles(1600);
			char i;
			for (i = 0; i++; i < 8){
				leftIn += getLeftVal();
			}
			leftIn = leftIn >> 3;

		}
		//initMotors();
		P1OUT |= BIT0;
		drive(LEFT_T);

		_delay_cycles(LONG_T);

	}//end infinite loop
}//end main
