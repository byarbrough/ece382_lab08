#include <msp430.h> 
#include "maze.h"
//#include "Library/Robot9_IR_Library.h"
#include "adc10.h"



/*
 * main.c
 */
void main(void) {
	IFG1=0;
	WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	P1DIR |= BIT0;

	BCSCTL1 = CALBC1_8MHZ;
	DCOCTL = CALDCO_8MHZ;
	ADC10CTL0 = 0;

	initMotors();				//initialize the system

	//_delay_cycles(SHORT_T);		//let use move out of way
	int frontRead;
	
	while(1){			//infinite loop
		frontRead  = readADC(3);
		if (frontRead < 0x300){ //leftIn < 0x290){
			P1OUT |= BIT0;
			drive(FORWARD);
			_delay_cycles(3000);
		}
		else {
		drive(BACKWARD);
		_delay_cycles(2500000);
		//initMotors();
		P1OUT &= ~BIT0;
		drive(RIGHT_T);
		_delay_cycles(SHORT_T);
		drive(FORWARD);
		_delay_cycles(1000);
		}

	}//end infinite loop
}//end main
