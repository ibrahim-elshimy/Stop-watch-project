#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"


#include "KPAD_interface.h"
#include "KPAD_config.h"
#include "KPAD_private.h"

#include <util/delay.h>
#define F_CPU    8000000UL

void KPAD_voidInit(void)
{
	//1- MAKING ALL ROWS PINS AS INPUT PINS
	DIO_voidSetPinDirection(KPAD_PORT,KPAD_ROW1_PIN,DIO_INPUT);
	DIO_voidSetPinDirection(KPAD_PORT,KPAD_ROW2_PIN,DIO_INPUT);
	DIO_voidSetPinDirection(KPAD_PORT,KPAD_ROW3_PIN,DIO_INPUT);
	DIO_voidSetPinDirection(KPAD_PORT,KPAD_ROW4_PIN,DIO_INPUT);

	//2- MAKING ALL COLUMNS PINS AS OUTPUT PINS
	DIO_voidSetPinDirection(KPAD_PORT,KPAD_COL1_PIN,DIO_OUTPUT);
	DIO_voidSetPinDirection(KPAD_PORT,KPAD_COL2_PIN,DIO_OUTPUT);
	DIO_voidSetPinDirection(KPAD_PORT,KPAD_COL3_PIN,DIO_OUTPUT);
	DIO_voidSetPinDirection(KPAD_PORT,KPAD_COL4_PIN,DIO_OUTPUT);

	//3-INITIATING ALL COLUMNS TO HIGH AND ACTIVATING PULL UP RESISTORS TO ROW PINS
	DIO_voidSetPortValue(KPAD_PORT, 0xFF);

}


u8 KPAD_u8GetKeyPressed(void)
{
	//DELAY TO AVOID BOUNCING if u used hardware
	//_delay_ms(50);

	u8 Local_u8KeyPressed = KEYPAD_NOT_PRESSED;
	static u8 rows_pins[NUM_OF_ROWS] = {KPAD_ROW1_PIN, KPAD_ROW2_PIN, KPAD_ROW3_PIN, KPAD_ROW4_PIN };
	static u8 cols_pins[NUM_OF_COLS] = {KPAD_COL1_PIN, KPAD_COL2_PIN, KPAD_COL3_PIN, KPAD_COL4_PIN };

	for(u8 ColCounter = 0; ColCounter < NUM_OF_COLS; ColCounter++)
	{
		/*Apply LOW on each Column to Know Which Switch will connect Row with col*/
		DIO_voidSetPinValue(KPAD_PORT,cols_pins[ColCounter],DIO_LOW);
		for(u8 RowCounter = 0; RowCounter < NUM_OF_ROWS; RowCounter++)
		{

			if( DIO_u8GetPinValue(KPAD_PORT,rows_pins[RowCounter]) == 0)
			{
				Local_u8KeyPressed = KPAD_Keys[RowCounter][ColCounter];

				//WAIT UNTIL THE KEY IS NOT PRESSED (l7ad lama eluser yshel edo mn 3la elswitch)
				// 3shan elprocesser momken y2rahaa 1000 mara masln fel wa2t eluser das feeh 3la elswitch
				while(DIO_u8GetPinValue(KPAD_PORT, rows_pins[RowCounter]) == 0)
				{
					// hytl3 mn eloop de lama ysheel edo mn 3la elswitch
				}
			//	_delay_ms(50); // active the delay if u connect hardware
			}
			else
			{

			}
		}
		/* Return this old COL pin to HIGH then the new col after it low*/
		DIO_voidSetPinValue(KPAD_PORT,cols_pins[ColCounter],DIO_HIGH);
	}


	return Local_u8KeyPressed;
}
