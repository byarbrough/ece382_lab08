/*
 * implementMaze.c
 *
 *  Created on: Dec 6, 2014
 *      Author: C16Brian.Yarbrough
 */




<<<<<<< HEAD
	P1DIR &= ~BIT3;
	P1REN |= BIT3;

	P2DIR |= BIT2;							// P2.2 is associated with TA1CCR1
	P2SEL |= BIT2;							// P2.2 is associated with TA1CCTL1

	P2DIR |= BIT4;							// P2.4 is associated with TA1CCR2
	P2SEL |= BIT4;							// P2.4 is associated with TA1CCTL2

	//ports for direction
	P2DIR |= BIT0 | BIT1 | BIT3 | BIT5;

	TA1CTL = ID_3 | TASSEL_2 | MC_1;		// Use 1:8 presclar off MCLK
	TA1CCR0 = 1000;						// set signal period

	TA1CCR1 = 500;
	TA1CCTL1 = OUTMOD_3;					// set TACCTL1 to Reset / Set mode

	TA1CCR2 = 500;
	TA1CCTL2 = OUTMOD_3;					// set TACCTL1 to Reset / Set mode

	GO_STOP;

}


/*
* drive()
* accepts a direction and moves the robot in that direction
*/
void drive(direction movement){
	GO_STOP;
	_delay_cycles(100);

	switch(movement){
	case	BACKWARD:
		TA1CCTL1 = OUTMOD_7;
		TA1CCTL2 = OUTMOD_7;
		GO_BACKWARD;
		break;

	case	FORWARD:
		TA1CCTL1 = OUTMOD_3;
		TA1CCTL2 = OUTMOD_3;
		GO_FORWARD;
		break;

	case	LEFT_T:
		TA1CCTL1 = OUTMOD_7;
		TA1CCTL2 = OUTMOD_3;
		GO_LEFT;
		break;

	case	RIGHT_T:
		TA1CCTL1 = OUTMOD_3;
		TA1CCTL2 = OUTMOD_7;
		GO_RIGHT;
		break;

	case	STOP:
		GO_STOP;
		break;
	}//end switch

	ENABLE_MOTORS;
}
=======
>>>>>>> parent of 23a0d5a... creating shell code
