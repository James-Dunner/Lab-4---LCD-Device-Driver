/**************************************************************
 * lcd.c
 * Author: James Dunn
 * Created on: 21 October 2013
 * Author: Definitions of declared functions in lcd.h
 *************************************************************/
#include <msp430.h>
#include "lcd.h"

#define RS_MASK 0x40

// Global Variables
char LCD_CON = 0;

// Ported to C by me
void init_SPI()
{
	UCB0CTL1 |= UCSWRST;

	UCB0CTL0 |= UCMSB|UCCKPH|UCMST|UCSYNC;
	UCB0CTL1 |= UCSSEL1;

	P1SEL |= BIT5;
	P1SEL2 |= BIT5;

	P1SEL |= BIT6;
	P1SEL2 |= BIT6;

	P1SEL |= BIT7;
	P1SEL2 |= BIT7;

	UCB0CTL1 &= ~UCSWRST;
}

// Function provided by Capt. Branchflower
void writeCommandNibble(char commandNibble)
{
	LCD_CON &= ~RS_MASK;
	LCD_WRT_4(commandNibble);

	delayMilliSeconds();
}

// Function provided by Capt. Branchflower
void writeCommandByte(char commandByte)
{
	LCD_CON &= ~RS_MASK;
	LCD_WRT_8(commandByte);

	delayMilliSeconds();
}

// Function provided by Capt. Branchflower
void writeDataByte(char dataByte)
{
    LCD_CON |= RS_MASK;
    LCD_WRT_8(dataByte);
    delayMilliSeconds();
}

// Function provided by Capt. Branchflower
void LCD_CLR()
{
    writeCommandByte(1);
}

// Ported to C by me
void LCD_init()
{
    writeCommandNibble(0x03);

    writeCommandNibble(0x03);

    writeCommandNibble(0x03);

    writeCommandNibble(0x02);

    writeCommandByte(0x28);

    writeCommandByte(0x0C);

    writeCommandByte(0x01);

    writeCommandByte(0x06);

    writeCommandByte(0x01);

    writeCommandByte(0x02);

    SPI_SEND(0);
    delayMicroSeconds();
}

// Function provided by Capt. Branchflower
void LCD_WRT_8(char byteToSend)
{
	unsigned char sendByte = byteToSend;

	sendByte &= 0xF0;
	sendByte = sendByte >> 4;
	LCD_WRT_4(sendByte);
	sendByte = byteToSend;
	sendByte &= 0x0F;
	LCD_WRT_4(sendByte);
}

// Ported to C by me
void LCD_WRT_4(char byteToSend)
{
	 byteToSend &= 0x0F;
	 byteToSend |= LCD_CON;
	 byteToSend &= 0x7F;
	 SPI_SEND(byteToSend);
	 delayMicroSeconds();

	 byteToSend |= 0x80;
	 SPI_SEND(byteToSend);
	 delayMicroSeconds();

	 byteToSend &= 0x7F;
	 SPI_SEND(byteToSend);
	 delayMicroSeconds();
}

// Ported to C by me
void Set_SS_HI()
{
	P1OUT |= BIT0;
}

// Ported to C by me
void Set_SS_LO()
{
	P1OUT &= ~BIT0;
}

// Created by me
void delayMilliSeconds()
{
	__delay_cycles(1745);
}

// Created by me
void delayMicroSeconds()
{
	__delay_cycles(45);
}

// Function provided by Capt. Branchflower
void SPI_SEND(char byteToSend)
{
	volatile char readByte;

	Set_SS_LO();

    UCB0TXBUF = byteToSend;

    while(!(UCB0RXIFG & IFG2))
    {

    }

    readByte = UCB0RXBUF;

    Set_SS_HI();
}

// Created by me
void cursorToLineTwo()
{
	writeCommandByte(0xc0);
}

/*Defined writeChar and writeString*/

void writeChar(char asciiChar)
{
	writeDataByte(asciiChar);
}

void writeString(char * string)
{
	while(*string != 0)	// Using null character to know when to terminate string
	{
		writeChar(*string);
		string++;
	}
}

void scrollString(char * string1, char * string2)
{

}
