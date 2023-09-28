#include "shaduler.h"

static s8 minute = 0;
static s8 second = 0;
volatile u8 ticks = 0;
volatile u8 sch_flag = FLAG_LOW;
static task_t tasks[TASK_MAX]={0};
static const void (*task_array[TASK_MAX])(void)  = {time_update,time_setting,button_periodic_check,mode_update,display_time};
static const u8 task_period [TASK_MAX] = {PERIOD_TIME,PERIOD_SETTING,PERIOD_BUTTON,PERIOD_MODE,PERIOD_DISPLAY};
	
void schaduler_init(void)
{
	for(int i=0 ; i<TASK_MAX ; i++)
	{
		tasks[i].task = task_array[i];
		tasks[i].period = task_period[i];
		tasks[i].ticks = 0;
		tasks[i].ready_flag = FLAG_LOW;
	}
	TIMER0_Init(TIMER0_NORMAL_MODE,TIMER0_SCALER_64);
	TIMER0_OV_SetCallBack(update_tick);
	sei();
	TIMER0_OV_InterruptEnable();
}
void schaduler_update(void)
{
		for (u8 i = 0; i<TASK_MAX ; i++)
		{
			// for converting the mode
			if (mode_getter() && i== 0)
			{
				i = 1;
			}
			else if (i == 1)
			{
				i = 2;
			}
			/**************************/
			tasks[i].ticks++;
			if(tasks[i].ticks == tasks[i].period)
			{
				tasks[i].ready_flag = FLAG_HIGH;
				tasks[i].ticks = 0;
			}
		}		
}

void despatcher (void)
{
	for (int i = 0 ; i<TASK_MAX ; i++)
	{
		if(FLAG_HIGH == tasks[i].ready_flag)
		{
			tasks[i].ready_flag = FLAG_LOW;
			tasks[i].task();
		}
	}
}

void OS_run(void)
{
	if(sch_flag == FLAG_HIGH)
	{
		schaduler_update();
		sch_flag = FLAG_LOW;
	}
	
	despatcher();
	
	if(ticks == 20)
	{
		ticks = 0;
	}
}

void update_tick(void)
{
	sch_flag++;
	ticks++;
	TIMER0 = TICK_TIME; // to get 1000us -> 1ms
}

void time_update(void)
{
	
	static u16 tick_counter = 0;
	tick_counter++;
	if (tick_counter == SEC_TICKS)
	{	
		time_setter(++second,minute);
		if (second == MIN_SECS)
		{
			second =0;
			time_setter(second,++minute);
		}
		tick_counter = 0;
	}
}

void time_setting(void)
{
	if(mode_getter() == CONFIG_SEC)
	{
		second+=!buttons_getter(BUTTON_PLUSE);
		second-=!buttons_getter(BUTTON_MINUS);
	}
	else if(mode_getter() == CONFIG_MIN)
	{
		minute+=!buttons_getter(BUTTON_PLUSE);
		minute-=!buttons_getter(BUTTON_MINUS);
	}
	if (second >= MIN_SECS)
	{
		second = 0;
		
	}
	else if (second < 0)
	{
		second = TIME_OVF;
	}
	
	if (minute >= HOUR_MINS )
	{
		minute = 0;
		
	}
	else if (minute < 0)
	{
		minute = TIME_OVF;
	}
	time_setter(second,minute);
}