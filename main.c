/**************************************************************
 * main.c
 * Author: James Dunn
 * Created on: 21 October 2013
 * Author: main that implements LCD functions
 *************************************************************/
#include <msp430.h>
#include "lcd.h"
#include "buttons/button.h"

void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

    char screen1_topLine[] = "Message?";
    char screen1_bottomLine[] = "Press123";
    char screen2_topLine[] = "ECE382 is my favorite class!";

    char chosenMessage_1[] = "You have chosen message 1!";
    char chosenMessage_2[] = "You have chosen message 2!";
    char chosenMessage_3[] = "You have chosen message 3!";

    P1DIR |= BIT0;	// Sets SS as GPIO

    P1DIR |= BIT0|BIT6; // Set Launchpad LEDs to output

    configureP1PinAsButton(BIT1|BIT2|BIT3);

	unsigned int volatile screen2_topLineLength, chosenMessageLength;

	screen2_topLineLength = 0;
	chosenMessageLength = 0;

    init_SPI();
	LCD_init();
	LCD_CLR();

	writeString(screen1_topLine);
	cursorToLineTwo();
	writeString(screen1_bottomLine);

	while (1)
	{
		char buttons[] = {BIT1, BIT2, BIT3};
	    char pressedButton = pollP1Buttons(buttons, 3);

	    switch (pressedButton)
	    {
	    	case BIT1:

	    		P1OUT ^= BIT0|BIT6;
	    		waitForP1ButtonRelease(BIT2);

	    		screen2_topLineLength = getStringLength(screen2_topLine);
	    		chosenMessageLength = getStringLength(chosenMessage_1);

	    		while(1)
	    		{
		    		cursorToLineOne();
		    		writeString(screen2_topLine);
		    		cursorToLineTwo();
		    		writeString(chosenMessage_1);
		    		scrollString(screen2_topLine, screen2_topLineLength);
		    		scrollString(chosenMessage_1, chosenMessageLength);
	    		}

	    	break;

	    	case BIT2:

	    		P1OUT ^= BIT0|BIT6;
	    		waitForP1ButtonRelease(BIT2);

	    		screen2_topLineLength = getStringLength(screen2_topLine);
	    		chosenMessageLength = getStringLength(chosenMessage_2);

	    		while(1)
	    		{
		    		cursorToLineOne();
		    		writeString(screen2_topLine);
		    		cursorToLineTwo();
		    		writeString(chosenMessage_2);
		    		scrollString(screen2_topLine, screen2_topLineLength);
		    		scrollString(chosenMessage_2, chosenMessageLength);
	    		}

	    	break;

	    	case BIT3:

                P1OUT ^= BIT0|BIT6;
                waitForP1ButtonRelease(BIT3);

	    		screen2_topLineLength = getStringLength(screen2_topLine);
	    		chosenMessageLength = getStringLength(chosenMessage_3);

	    		while(1)
	    		{
		    		cursorToLineOne();
		    		writeString(screen2_topLine);
		    		cursorToLineTwo();
		    		writeString(chosenMessage_3);
		    		scrollString(screen2_topLine, screen2_topLineLength);
		    		scrollString(chosenMessage_3, chosenMessageLength);
	    		}

	    	break;
	    }
	}
}
