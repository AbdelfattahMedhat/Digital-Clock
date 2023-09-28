#include "display.h"

static u8 minutes = 0;
static u8 seconds = 0;
static u8 counter = 0;


void display_time(void)
{
	counter++;
	switch(counter)
	{
		case 1 :
		DIO_WritePin(MIN_TENS,LOW);
		DIO_WritePin(MIN_UNITS,HIGH);
		seven_segment_write_number(minutes%10);
		break;
		case 2 :
		DIO_WritePin(MIN_UNITS,LOW);
		DIO_WritePin(MIN_TENS,HIGH);
		seven_segment_write_number(minutes/10);
		break;
		case 3 :
		DIO_WritePin(SEC_TENS,LOW);
		DIO_WritePin(SEC_UNITS,HIGH);
		seven_segment_write_number(seconds%10);
		break;
		case 4 :
		DIO_WritePin(SEC_UNITS,LOW);
		DIO_WritePin(SEC_TENS,HIGH);
		seven_segment_write_number(seconds/10);
		counter = 0;
		break;
		default: break;
	}
}

void time_setter(u8 second,u8 minute)
{
	seconds = second;
	minutes = minute;
}