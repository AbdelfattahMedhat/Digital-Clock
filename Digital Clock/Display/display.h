
#ifndef DISPLAY_H_
#define DISPLAY_H_
#include "Utils.h"
#include "seven_segment.h"

#define DISPLAYS_NUM 4


#define SEC_TENS PINA7
#define SEC_UNITS PINA4
#define MIN_TENS PINA5
#define MIN_UNITS PINA6

void display_time(void);
void time_setter(u8 second,u8 minute);

#endif /* DISPLAY_H_ */