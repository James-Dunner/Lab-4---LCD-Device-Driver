/**************************************************************
 * main.c
 * Author: James Dunn
 * Created on: 21 October 2013
 * Author: main that implements LCD functions
 *************************************************************/
#include <msp430.h>
#include "lcd.h"

void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

    char topLineMessage[] = "ECE382 is my favorite class!";	//Don't need to predefine final character because string is terminated by null character \0
    char bottomLineMessage[] = "Capt. Branchflower is great!";

	unsigned int volatile topMessageLength, bottomMessageLength;

	topMessageLength = 0;
	bottomMessageLength = 0;

    // Sets SS as GPIO
    P1DIR |= BIT0;

	// Sets PB1-3 as input
	P1DIR &= ~BIT1;
	P1DIR &= ~BIT2;
	P1DIR &= ~BIT3;

    init_SPI();
	LCD_init();
	LCD_CLR();

	topMessageLength = getStringLength(topLineMessage);
	bottomMessageLength = getStringLength(bottomLineMessage);

	while(1)
	{
		cursorToLineOne();
		writeString(topLineMessage);
		cursorToLineTwo();
		writeString(bottomLineMessage);

		scrollString(topLineMessage, topMessageLength);
		scrollString(bottomLineMessage, bottomMessageLength);
	}

}
