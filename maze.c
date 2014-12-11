/***************
 *  Authro: Brian Yarbrough
 *  Date: 6 Dec 14
 *  Device: TI MSP430 with ECE 382, Robot #9
 *  Instructor: Capt Trimble
 *
 *//////////////////////////////////////////////

#include <msp430.h> 
#include "maze.h"
#include "Library/Robot9_IR_Library.h"

unsigned short distance;

/*
 * main.c
 */
void main(void) {
	WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

	initMotors();				//initialize the system

	P1DIR |= BIT6;
	P1OUT |= BIT6;
	_delay_cycles(SHORT_T);		//let use move out of way
	

	while(TRUE){
		drive(BACKWARD);
		P1OUT |= BIT6;
		

		while(distance < 0x200){
			distance = getFrontVal();
			_delay_cycles(1600);
		}

		GO_STOP;
		
		drive(LEFT_T);
		P1OUT &= ~BIT6;
		_delay_cycles(LONG_T);

	}
	/*
	signed int sensDif = 0;

	while(1){			//infinite loop
		unsigned int firstPWM = 500;
		unsigned int secondPWM = 500;

		while (getFrontVal() < FRONT_WALL_5){ //not headed into a wall
			//navigage maze
			TA1CCR1 = firstPWM;
			TA1CCR2 = secondPWM;
			drive(FORWARD);		// go forward
			_delay_cycles(SHORT_T);

			sensDif = compareSideDist();	//compare sides

			if (sensDif < 0) { //left closer to wall
				firstPWM += 0xF;		//increase left power
				secondPWM -= 0xF;		//decrease right power
			}
			else if (sensDif > 0) {//right closer to wall
				firstPWM -= 0xF;		//decrease left power
				secondPWM += 0xF;		//increase right power
			}
			_delay_cycles(100);		//delay

		}//there is a wall

		GO_STOP;
		_delay_cycles(500);

		if (compareSideDist < 0) {//wall on left
			drive(RIGHT_T);			//turn right
		}
		else {
			drive(LEFT_T);			//turn left
		}
		_delay_cycles(SHORT_T);
		GO_STOP;
		_delay_cycles(100);

	}//end infinite loop
	*/
}//end main
