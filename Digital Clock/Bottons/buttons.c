#include "buttons.h"


static button_status_t buttons_s[BUTTON_MAX]; // array of buttons to store status of each button
static u8 button_counter[BUTTON_MAX]={0};		 


void buttons_init(void)
{
	for(int i=0;i<BUTTON_MAX;i++)
	{
		DIO_InitPin(FIRST_BUTTON+i,INPULL);
		buttons_s[i] = UNPRESSED;
	}
}
button_status_t buttons_getter(button_t button) // to get state of needed button
{
	button_status_t state = buttons_s[button];
	buttons_s[button] = UNPRESSED;
	return state;
}

void button_periodic_check(void)
{
	for(int i=0;i<BUTTON_MAX;i++)
	{
		if(buttons_s[i] == UNPRESSED)
		{
			if(DIO_ReadPin(FIRST_BUTTON+i) == PRESSED)
			button_counter[i]+=1;
			else
			button_counter[i]=0;
			if(button_counter[i]>=SAMPLES_NUM)
			{
				button_counter[i]=0;
				buttons_s[i]=PRESSED;
			}
		}
		
	}
	
}