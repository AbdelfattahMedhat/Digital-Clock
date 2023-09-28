 


#ifndef SHADULER_H_
#define SHADULER_H_
#include "Timers.h"
#include "display.h"
#include "buttons.h"
#include "mode.h"
#define TIMER0 TCNT0
/*    periods       */
#define TICK_TIME (255-130) // to get 1000us -> 1ms
#define  PERIOD_TIME 1
#define  PERIOD_BUTTON 1
#define  PERIOD_SETTING 50
#define  PERIOD_MODE   10	
#define  PERIOD_DISPLAY 5
/* time_relations  */
#define SEC_TICKS 717
#define MIN_SECS 60
#define HOUR_MINS 60
#define TIME_OVF 59
/*    task's code      */
#if 0
#define  TASK_BUTTON button_periodic_check
#define  TASK_MODE	mode_update
#define  TASK_DISPLAY display_time
#endif
typedef enum
{
	TASK_TIME,
	TASK_SETTING,
	TASK_BUTTON,
	TASK_MODE,
	TASK_DISPLAY,
	TASK_MAX
	}tasks_t;

typedef enum
{
	FLAG_LOW,
	FLAG_HIGH
	}flag_t;

typedef struct
{
	void(*task)(void);
	u8 period;
	u8 ticks;
	u8 ready_flag;
	}task_t;

void schaduler_init(void);
void schaduler_update(void);
void despatcher (void);
void update_tick(void);
void OS_run(void);
void time_update(void);
void time_setting(void);
#endif /* SHADULER_H_ */