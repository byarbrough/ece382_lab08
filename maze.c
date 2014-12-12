#include <msp430.h> 
#include "maze.h"
#include "Library/Robot9_IR_Library.h"



/*
 * main.c
 */
void main(void) {
	WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	P1DIR |= BIT0;

	BCSCTL1 = CALBC1_8MHZ;
	DCOCTL = CALDCO_8MHZ;
	ADC10CTL0 = 0;

	initMotors();				//initialize the system

	_delay_cycles(SHORT_T);		//let use move out of way
	
	while(1){			//infinite loop

		if (getLeftVal() > 0x290){ //leftIn < 0x290){
			P1OUT &= ~BIT0;
			drive(FORWARD);
		}
		else {
			GO_STOP;
			_delay_cycles(3000000);
		//initMotors();
		P1OUT |= BIT0;
		drive(RIGHT_T);
		_delay_cycles(LONG_T);
		GO_STOP;
		}
		_delay_cycles(1000);

	}//end infinite loop
}//end main
