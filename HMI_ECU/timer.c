 /******************************************************************************
 *
 * [FILE NAME]: <timer.c>
 *
 * [AUTHOR]: <Hossam Hafez>
 *
 * [DATE CREATED]: <25/3/2024>

 * [DESCRIPTION]: <Source file for TIMER1 Driver>
 *
 *******************************************************************************/

#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer.h"
#include "common_macros.h"
#include "stdio.h"


void (*g_Timer1CallBackPtr)(void) = NULL_PTR;



/*******************************************************************************
 *                                ISR                                          *
 *******************************************************************************/
/* Timer1 OV mode */
ISR(TIMER1_OVF_vect)
{
	if (*g_Timer1CallBackPtr != NULL_PTR)
	{
		(*g_Timer1CallBackPtr)();
	}
}

/* Timer1 COMP mode */
ISR(TIMER1_COMPA_vect)
{
	if (*g_Timer1CallBackPtr != NULL_PTR)
	{
		(*g_Timer1CallBackPtr)();
	}
}


/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void Timer1_init(const Timer1_Configtype * Config_Ptr)
{
        TCCR1A =0;

		SET_BIT(TCCR1A,FOC1A);

		SET_BIT(TCCR1A,FOC1B);
		TCCR1B = Config_Ptr->prescale;
		TCNT1 = Config_Ptr->initialvalue;

		if( (Config_Ptr -> mode) == NORMAL )
		{
			/* Enable interrupts for OV mode */
			SET_BIT(TIMSK,TOIE1);
			/* Enable overflow flag */
			SET_BIT(TIFR,TOV1);
		}
		else if ( (Config_Ptr -> mode) == COMPARE )
		{
			SET_BIT(TCCR1B,WGM12);
			OCR1A = Config_Ptr -> comparevalue;
			SET_BIT(TIMSK,OCIE1A); /*  interrupts for CTC mode */
			SET_BIT(TIFR,OCF1A); /* CTC flag */
		}
}



void Timer1_deInit(void)
{
	TCCR1A =0;
	TCCR1B = 0; /* disable clock */
	TCNT1 = 0;
	CLEAR_BIT(TIMSK, TOIE1); /* disable interrupts for overflow mode */
	OCR1A = 0;  /* clear compare value for CTC mode */
	CLEAR_BIT(TIMSK, OCIE1A); /* disable interrupts for CTC mode */
	g_Timer1CallBackPtr = NULL_PTR;
}




void Timer1_setCallBack(void(*a_ptr)(void))
{
	g_Timer1CallBackPtr = a_ptr;/*set the call back function address */
}



void Timer1_setValue (uint8 newValue)
{
	TCNT1 = newValue; /*add new value*/
}


void Timer1_clearValue(void)
{
	TCNT1 = 0; /*clear value*/
}
