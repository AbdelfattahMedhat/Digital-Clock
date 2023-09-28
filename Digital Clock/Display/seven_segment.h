


#ifndef SEVEN_SEGMENT_H_
#define SEVEN_SEGMENT_H_
#include "DIO_Interface.h"
#include "seven_seg_private.h"

#define SEVEN_SEGMENT_PORT PB

void seven_segment_init(void);
void seven_segment_write_number(u8 number);



#endif /* SEVEN_SEGMENT_H_ */