/*******************************************************/
/****   Author : Ibrahim Elshimy      ******************/
/****   SWC:          KPAD            ******************/
/****   Date :        8/8/2023        ******************/
/****   Version : 1.00                ******************/
/*******************************************************/

#ifndef KPAD_INTERFACE_H_
#define KPAD_INTERFACE_H_


#define KEYPAD_NOT_PRESSED     0xff

void KPAD_voidInit(void);
u8 KPAD_u8GetKeyPressed(void);


#endif
