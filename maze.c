#include <msp430.h> 
#include "maze.h"
#include "Library/Robot9_IR_Library.h"

/*
 * main.c
 */
void main(void) {
	WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

	initMotors();				//initialize the system

	_delay_cycles(LONG_T);		//let use move out of way
	
	signed int sensDif = 0;

	while(1){			//infinite loop
		while (getFrontVal() < FRONT_WALL_NR){ //not headed into a wall
			//navigage maze
			drive(FORWARD);		// go forward

			sensDif = compareSideDist();	//compare sides

			if (sensDif < 0) { //left closer to wall
				TA1CCR1++;		//increase left power
				TA1CCR2--;		//decrease right power
			}
			else if (sensDif > 0) {//right closer to wall
				TA1CCR1--;		//decrease left power
				TA1CCR2++;		//increase right power
			}

			_delay_cycles(1000);		//delay

		}//there is a wall

		GO_STOP;
		_delay_cycles(500);

		if (compareSideDist < 0) {//wall on left
			drive(RIGHT_T);			//turn right
		}
		else {
			drive(LEFT_T);			//turn left
		}
		GO_STOP;
		_delay_cycles(500);

	}//end infinite loop
}//end main
