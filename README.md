#Lab 4 - An LCD Device Driver
=========================

Library for writing to the LCD and scrolling messages in C

##Functions

###void writeCommandNibble(char commandNibble);

###void writeCommandByte(char commandByte);

###void writeDataByte(char dataByte);

###void LCD_init();

###void LCD_CLR();

###void LCD_WRT_8(char byteToSend);

###void SPI_SEND(char byteToSend);

###unsigned int getStringLength(char * string);

###void cursorToLineOne();

###void cursorToLineTwo();

###void Set_SS_HI();

###void Set_SS_LO();

###void LCD_WRT_4(char byteToSend);

###void init_SPI();

###void delayMilliSeconds();

###void delayMicroSeconds();

###void scrollDelay();

###void writeChar(char asciiChar);

###void writeString(char * string);

###void scrollString(char * string, unsigned int stringLength);
