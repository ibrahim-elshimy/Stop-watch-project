/*******************************************************/
/****   Author : Ibrahim Elshimy      ******************/
/****   SWC:          KPAD            ******************/
/****   Date :        8/8/2023        ******************/
/****   Version : 1.00                ******************/
/*******************************************************/

#ifndef KPAD_CONFIG_H_
#define KPAD_CONFIG_H_

#define NUM_OF_ROWS       4
#define NUM_OF_COLS       4

#define KPAD_PORT         DIO_PORTB
#define KPAD_ROW1_PIN     DIO_PIN0
#define KPAD_ROW2_PIN     DIO_PIN1
#define KPAD_ROW3_PIN     DIO_PIN2
#define KPAD_ROW4_PIN     DIO_PIN3
#define KPAD_COL1_PIN     DIO_PIN4
#define KPAD_COL2_PIN     DIO_PIN5
#define KPAD_COL3_PIN     DIO_PIN6
#define KPAD_COL4_PIN     DIO_PIN7

/*   You can Change the array to ASCII Values or Numbers,
     So we put this array in the configuration file,
     where You can change array based on Your Application.
 */
u8 KPAD_Keys [NUM_OF_ROWS][NUM_OF_COLS] =
{
		{'7', '8', '9', 253}, /* ÷ = 253 in CGROM of LCD*/  /*PI = 247 in CGROM*/
		{'4', '5', '6', 'x'},
		{'1', '2', '3', '-'},
		{'c', '0', '=' ,'+'}
};
/*
u8 KPAD_Keys[NUM_OF_ROWS][NUM_OF_COLS]  = { { 1  ,  2  , 3  ,  4 },
                                            { 4  ,  5  , 6  ,  7 },
                                            { 8  ,  9  , 10 , 11 },
                                            { 12 ,  13 , 14 , 15 }
                                          };

        */
#endif
