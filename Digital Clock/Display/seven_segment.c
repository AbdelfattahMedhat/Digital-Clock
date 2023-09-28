
#include "seven_segment.h"

void seven_segment_write_number(u8 number)
{
	DIO_WritePort(SEVEN_SEGMENT_PORT,~seven_seg_char[number]);
}