/*
 * maze.h
 *
 *  Created on: Dec 5, 2014
 *      Author: C16Brian.Yarbrough
 */

#ifndef MAZE_H_
#define MAZE_H_

typedef		unsigned char		int8;
typedef		unsigned short		int16;
typedef		unsigned long		int32;

//different motor commands for the robot
typedef enum	{FORWARD, BACKWARD, LEFT_T, RIGHT_T, STOP} direction;
#define		ENABLE_MOTORS	P2OUT |= BIT0 | BIT5
#define		GO_BACKWARD		P2OUT |= BIT1 | BIT3
#define		GO_FORWARD		P2OUT &= ~(BIT1 | BIT3)
#define		GO_LEFT			P2OUT &= ~BIT3
#define		GO_RIGHT		P2OUT &= ~BIT1
#define		GO_STOP			P2OUT &= ~(BIT0 | BIT5)
#define		RLONG_T			0x2000000
#define		LONG_T			0x400000
#define		SHORT_T			0x200000

#define		TRUE				1
#define		FALSE				0


void initMotors();
void drive(direction movement);



#endif /* MAZE_H_ */
