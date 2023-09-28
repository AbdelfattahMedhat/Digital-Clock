


#ifndef MODE_H_
#define MODE_H_
#include "buttons.h"
#include "display.h"
#define DEFAULT_STATE RUN

typedef enum
{
	RUN,
	CONFIG_SEC,
	CONFIG_MIN
	}mode_t;

void mode_update(void); // check mode every period
mode_t mode_getter(void); // get mode 


#endif /* MODE_H_ */