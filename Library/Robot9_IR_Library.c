/*
 * Robot9_IR_Library.c
 *
 *  Created on: Dec 4, 2014
 *      Author: C16Brian.Yarbrough
 *      Works with header file to control IR sensors on robot
 */

#include <msp430.h>
#include "Robot9_IR_Library.h"


/**
 * converts the analong input from the right sensors -1.5
 * Returns: digital value from ADC
 */
unsigned short	getRightVal(){
	// Configure P1.5 to be the ADC input
	ADC10CTL0 = 0;										// Turn off ADC subsystem
	ADC10CTL1 = INCH_5 | ADC10DIV_3 ;					// Channel 4, ADC10CLK/4
	ADC10AE0 = BIT5;		 							// Make P1.5 analog input
	ADC10CTL0 = SREF_0 | ADC10SHT_3 | ADC10ON | ENC;	// Vcc & Vss as reference

	ADC10CTL0 |= ADC10SC;								// Start a conversion
	while(ADC10CTL1 & ADC10BUSY);						// Wait for conversion to complete

	return ADC10MEM;
}

/**
 * converts the analong input from the left sensors - 1.3
 * Returns: digital value from ADC
 */
unsigned short	getLeftVal(){
	// Configure P1.3 to be the ADC input
	ADC10CTL0 = 0;										// Turn off ADC subsystem
	ADC10AE0 = BIT3;		 							// Make P1.3 analog input
	ADC10CTL1 = INCH_3 | ADC10DIV_3 ;					// Channel 4, ADC10CLK/4
	ADC10CTL0 = SREF_0 | ADC10SHT_3 | ADC10ON | ENC;	// Vcc & Vss as reference

	ADC10CTL0 |= ADC10SC;								// Start a conversion
	while(ADC10CTL1 & ADC10BUSY);						// Wait for conversion to complete

	return ADC10MEM;
}

/**
 * converts the analong input from the front sensors - 1.4
 * Returns: digital value from ADC
 */
int	getFrontVal(){
	BCSCTL1 = CALBC1_8MHZ;									// 8MHz clock
	DCOCTL = CALDCO_8MHZ;
	ADC10CTL0 = 0;

	ADC10CTL1 = INCH_3;									// Channel 3
	ADC10AE0 = BIT2;

	ADC10CTL1 |= ADC10DIV_3 ;								// ADC10CLK/4
	ADC10CTL0 = SREF_0 | ADC10SHT_3 | ADC10ON | ENC;		// Vcc & Vss as reference

	ADC10CTL0 |= ADC10SC;									// Start a conversion
	while(ADC10CTL1 & ADC10BUSY);							// Wait for conversion to complete
	return ADC10MEM;
}

unsigned short getRightInch(){
	unsigned short raw = getRightVal();
	return (12*raw*raw) - (277*raw) + 1859;
}


unsigned short getLeftInch(){
	unsigned short raw = getLeftVal();
	return (13*raw*raw) - (268*raw) + 1447;
}
/**
 * compares the  distances of the left and right sensors
 * Returns: positive if right closer to wall
 * 	negative if left closer to wall
 */
signed int compareSideDist(){
	_delay_cycles(16);

	unsigned short righty = getRightInch();
	_delay_cycles(58);
	unsigned short lefty = getLeftInch();

	return righty - lefty;
}
