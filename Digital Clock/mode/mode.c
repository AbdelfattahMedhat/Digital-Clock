
#include "mode.h"
static mode_t state =RUN;

void mode_update(void) // check mode every period
{
	if(buttons_getter(BUTTON_MODE) == PRESSED)
	{
		DIO_TogglePin(PIND7);
		switch(state)
		{
			case RUN : state = CONFIG_SEC;
						break;
			case CONFIG_SEC : state = CONFIG_MIN;
						break;
			case CONFIG_MIN : state = RUN;
						break;
		}
	}
	
}

mode_t mode_getter(void)
{
	return state;
}