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
	
	while(1){			//infinite loop
		while (the front sensor is less than threshold0{
					//go straight
					get the left/ right difference
						this will be done my subtracting getRight() from getLeft()
						also may need to be normailzed with reference to the characterization
							from A funct, lab07


					if (left < right) {
						increase left, decrease right
					}
					else if (left > right) {
						decrea right, increase left
					}

					delay, so not jerky?

				}//there is a wall

				stop the robot
				wait
				compare sensors
				if (left < right) {
					turn right
				}
				else {
					turn left
				}
				stop, delay - will loop and go forward again
	}//end infinite loop
}//end main
