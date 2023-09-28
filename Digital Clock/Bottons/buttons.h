
#ifndef BUTTONS_H_
#define BUTTONS_H_
#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "Utils.h"
#define FIRST_BUTTON PINC0
#define SAMPLES_NUM 150
typedef enum
{
	BUTTON_PLUSE,
	BUTTON_MODE,
	BUTTON_MINUS,
	BUTTON_MAX
	}button_t;

typedef enum
{
	PRESSED,
	UNPRESSED
	}button_status_t;
	

void buttons_init(void);
button_status_t buttons_getter(button_t button);
void button_periodic_check(void);


#endif /* BUTTONS_H_ */