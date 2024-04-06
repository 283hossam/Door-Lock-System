 /******************************************************************************
 *
 * [FILE NAME]: <buzzer.c>
 *
 * [AUTHOR]: <Hossam Hafez>
 *
 * [DATE CREATED]: <23/3/2024>
 *
 * [DESCRIPTION]: <Source file for BUZZER Driver>
 *
 *******************************************************************************/

#include "buzzer.h"
#include "gpio.h"


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void Buzzer_init(void)
{
	GPIO_setupPinDirection (PORTB_ID , PIN0_ID , PIN_OUTPUT);


	GPIO_writePin (PORTB_ID , PIN0_ID , LOGIC_LOW);
}


void Buzzer_on(void)
{
	GPIO_writePin (PORTB_ID , PIN0_ID , LOGIC_HIGH);
}


void Buzzer_off(void)
{
	GPIO_writePin (PORTB_ID , PIN0_ID , LOGIC_LOW);
}
