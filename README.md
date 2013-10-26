#Lab 4 - An LCD Device Driver
Library for writing to the LCD and scrolling messages in C

##Functions

###void writeCommandNibble(char commandNibble)
Writes command to LCD (only nibble size)

###void writeCommandByte(char commandByte)
Writes command to LCD (byte size)

###void writeDataByte(char dataByte)
Writes data to LCD (byte size); prints byte on LCD

###void LCD_init()
Initializes the LCD

###void LCD_CLR();
Clears the LCD and sets the cursor on the upper line of the LCD

###unsigned int getStringLength(char * string)
Returns the number of elements in an array of characters

###void cursorToLineOne()
Sets the cursor to the upper line on the LCD display

###void cursorToLineTwo
Sets the cursor on the lower line of the LCD display

###void init_SPI();
Initializes SPI

###void delayMilliSeconds()
Delays CPU for ~1.65 ms

###void delayMicroSeconds()
Delays CPU for ~40.5 us

###void scrollDelay
Delays CPU 100000 clock cycles to permit string to shift slow enough for the human eye to detect

###void writeChar(char asciiChar)
Prints character to LCD (where the cursor is pointing)

###void writeString(char * string)
Prints a string of characters on LCD starting at the cursor

###void scrollString(char * string, unsigned int stringLength)
Scrolls string of characters and wraps the text around the LCD
