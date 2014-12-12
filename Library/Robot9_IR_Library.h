/*
 * Robot9_IR_Library.h
 *
 *  Created on: Dec 4, 2014
 *      Author: C16Brian.Yarbrough
 *
 *    This library allows the MSP430 ADC to read values
 *    from IR sensors on borad ECE 382 ROBOT 09
 */

#include <msp430.h>

#ifndef ROBOT9_IR_LIBRARY_H_
#define ROBOT9_IR_LIBRARY_H_

#define 	FRONT_WALL_5	0xC0  	//~five inches
#define		LEFT_WALL_5		0x181
#define		RIGHT_WALL_5	0x31A
#define		FRONT_WALL_10	0x5A	//~ten inches
#define 	LEFT_WALL_10	0x95
#define 	RIGHT_WALL_10	0x13F

#define 	FRONT_WALL_NR	0x0185
#define		LEFT_WALL_NR	0x0185
#define		RIGHT_WALL_NR	0x0185

unsigned short	getRightVal();
unsigned short	getLeftVal();
int	getFrontVal();
unsigned short	getRightInch();
unsigned short	getLeftInch();
signed	 int	compareSideDist();


#endif /* ROBOT9_IR_LIBRARY_H_ */
