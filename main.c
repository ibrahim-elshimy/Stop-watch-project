#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "GIE_interface.h"
#include "TIMER_interface.h"
#include "CLCD_interface.h"
#include "KPAD_interface.h"

#include <util/delay.h>
void ONE_SECOND(void);

// Global Variables
static s8 minutes = 0;
static s8 seconds = 0;

int main(void)
{
	//CLCD_PORT DIRECTIONS
	DIO_voidSetPortDirection(DIO_PORTD,DIO_OUTPUT);
	DIO_voidSetPortDirection(DIO_PORTC,DIO_OUTPUT);

	GIE_voidEnable();
	TIMER0_voidInit();
	CLCD_voidInit();
	KPAD_voidInit();

	TIMER0_SetCompareMatchValue(250);

	u8 Local_u8Pressed = 0xff;
	u8 number = 0;

	CLCD_voidSendString("_");
	CLCD_voidSendString("_");
	CLCD_voidSendString(":");
	CLCD_voidSendString("_");
	CLCD_voidSendString("_");

	u8 flag = 0;
	u8 flag1 = 0;

	u8 remainder = 0;
	u8 reverse = 0;
	u8 value = 0;
	while(1)
	{
		Local_u8Pressed = KPAD_u8GetKeyPressed();
		if(flag == 0)
		{
			while( (number <= 4) && (Local_u8Pressed != 'c') )
			{
				//CLCD_voidSetPosition(0,number);
				Local_u8Pressed = KPAD_u8GetKeyPressed();

				if( (number < 2) && (Local_u8Pressed != 0xff) )
				{
					value = Local_u8Pressed-48;
					remainder = value % 10;
					reverse = reverse*10 + remainder;
					minutes = reverse;

					CLCD_voidSetPosition(0,number);
					CLCD_voidSendData(Local_u8Pressed);
					number++;
				}
				else if((number == 2) )
				{
					CLCD_voidSetPosition(0,2);
					CLCD_voidSendString(":");
					remainder = 0;
					reverse = 0;
					number++;
				}
				else if((number > 2) && (Local_u8Pressed != 0xff) )
				{
					value = Local_u8Pressed- 48;
					remainder = value % 10;
					reverse = reverse * 10 + remainder;
					seconds = reverse;

					CLCD_voidSetPosition(0,number);
					CLCD_voidSendData(Local_u8Pressed);
					number++;
				}
			}
			number = 0;
			flag = 1;
		}

		/*
		CLCD_voidSetPosition(1,0);
		CLCD_voidSendNumber(minutes);
		CLCD_voidSetPosition(1,6);
		CLCD_voidSendNumber(seconds);
		 */

		if( (Local_u8Pressed == 'c') && (flag1 == 0) )
		{
			flag  = 1;
			flag1 = 1;
			TIMER0_u8SetCallBack(&ONE_SECOND);
		}

		if(KPAD_u8GetKeyPressed() == '+')
		{
			flag = 0;
			flag1 = 0;
		}


		if( (minutes == 0) && (seconds == 0) )
		{
			CLCD_voidSetPosition(0,0);
			CLCD_voidSendString("_");
			CLCD_voidSendString("_");
			CLCD_voidSendString(":");
			CLCD_voidSendString("_");
			CLCD_voidSendString("_");
			while(Local_u8Pressed != '+');
		}
	}
	return 0;
}

void ONE_SECOND(void)
{
	static u16 counter = 0;
	counter++;
	if(counter == 500)
	{
		counter = 0;
		if(seconds > 0)
		{
			if(seconds > 9)
			{
				CLCD_voidSetPosition(0,3);
				CLCD_voidSendNumber(seconds);
			}
			else if(seconds <=9)
			{
				CLCD_voidSetPosition(0,3);
				CLCD_voidSendNumber(0);
				CLCD_voidSetPosition(0,4);
				CLCD_voidSendNumber(seconds);
			}
			seconds--;
		}
		else if( (seconds == 0) && (minutes > 0) )
		{
			CLCD_voidSetPosition(0,3);
			CLCD_voidSendNumber(0);
			CLCD_voidSetPosition(0,4);
			CLCD_voidSendNumber(0);
			_delay_ms(10);
			minutes--;
			seconds = 60;
			if(minutes <= 9)
			{
				CLCD_voidSetPosition(0,1);
				CLCD_voidSendNumber(minutes);
			}
			else if(minutes > 9)
			{
				CLCD_voidSetPosition(0,0);
				CLCD_voidSendNumber(minutes);
			}
		}
	}
}
