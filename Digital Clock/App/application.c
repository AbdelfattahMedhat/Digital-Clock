
#include "application.h"

volatile static u8 ticks = 0;
void application_init(void)
{
	TIMER0_Init(TIMER0_NORMAL_MODE,TIMER0_SCALER_64);
	//TIMER0_OV_SetCallBack()
}

void update_tick(void)
{
	ticks++;
	TIMER0 = 255 - 130; // to get 1000us -> 1ms
}

void application_update(void)
{
	
	
}