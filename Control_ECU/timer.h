 /******************************************************************************
 *
 * [FILE NAME]: <timer.c>
 *
 *   [AUTHOR]: <Hossam Hafez>
 *
 * [DATE CREATED]: <25/3/2024>
 *

 * [DESCRIPTION]: <header file for TIMER1 Driver>
 *
 *******************************************************************************/

#ifndef TIMER_H_
#define TIMER_H_

#include "std_types.h"



/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define TIMER1_MAX_VALUE 65535

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
typedef enum
{
	NORMAL , COMPARE
} Timer1_Mode;

typedef enum
{
	No_clock,No_P,P_8,P_64,P_256,P_1024
}Timer1_Clock;

typedef struct
{
		Timer1_Mode mode;
		uint16 initialvalue;
		uint16 comparevalue;
		Timer1_Clock prescale;
}Timer1_Configtype;


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/


void Timer1_init(const Timer1_Configtype * Config_Ptr);


void Timer1_deInit(void);

void Timer1_setCallBack(void(*a_ptr)(void));


void Timer1_setValue (uint8 newValue);

void Timer1_clearValue(void);

#endif /* TIMER_H_ */
