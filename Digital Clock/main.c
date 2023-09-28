#include "buttons.h"
#include "display.h"
#include "shaduler.h"


int main(void)
{
	DIO_Init();
	buttons_init();
	schaduler_init();
    /* Replace with your application code */
    while (1) 
    {
		OS_run();
    }
}

