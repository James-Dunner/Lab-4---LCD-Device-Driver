/**************************************************************
 * lcd.h
 * Author: James Dunn
 * Created on: 19 October 2013
 * Author: Library to interact with the Geek Box LCD
 *************************************************************/
#include <msp430.h>

#ifndef LCD_H_
#define LCD_H_

//API Library for Lab 4

void writeCommandNibble(char commandNibble);

void writeCommandByte(char commandByte);

void writeDataByte(char dataByte);

void LCD_init();

void LCD_CLR();

void LCD_WRT_8(char byteToSend);

void SPI_SEND(char byteToSend);

void cursorToLineTwo();

void Set_SS_HI();

void Set_SS_LO();

void LCD_WRT_4(char byteToSend);

void init_SPI();

void delayMilliSeconds();

void delayMicroSeconds();

// Yet to be defined

void printChar(char asciiChar);

void printString(char * string);

void scrollMessage(char * string1, char * string2);

#endif // LCD_H_


