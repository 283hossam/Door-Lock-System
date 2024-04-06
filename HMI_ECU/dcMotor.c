 /******************************************************************************
 *
 * [FILE NAME]: <dcMotor.c>
 * [AUTHOR]: <Hossam Hafez>
 *
 * [DATE CREATED]: <20/3/2024>
 *
 * [DESCRIPTION]: <Source file for DC Motor driver>
 *
 *******************************************************************************/


#include "common_macros.h"
#include "gpio.h"
#include "dcMotor.h"



/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * [NAME]: DcMotor_Init
 *
 *
 * [Returns]: void
 */
void DcMotor_Init(void)
{
	/*Set motor pins as output pins*/
	GPIO_setupPinDirection (DC_MOTOR_PORT_ID,DC_MOTOR_PIN_1,PIN_OUTPUT);
	GPIO_setupPinDirection (DC_MOTOR_PORT_ID,DC_MOTOR_PIN_2,PIN_OUTPUT);



	/*Stop the motor at first*/
	GPIO_writePin (DC_MOTOR_PORT_ID,DC_MOTOR_PIN_1,LOGIC_LOW);
	GPIO_writePin (DC_MOTOR_PORT_ID,DC_MOTOR_PIN_2,LOGIC_LOW);

}





/*
 * [Description] : Function that responsible for rotate the DC Motor CW/ or A-CW or stop the motor based on the state input state value.
 *
 * [Returns]: void
 */
void DcMotor_Rotate(DcMotor_State state)
{
	if (state == STOP)
	{
		/*Stop the motor*/
		GPIO_writePin (DC_MOTOR_PORT_ID,DC_MOTOR_PIN_1,LOGIC_LOW);
		GPIO_writePin (DC_MOTOR_PORT_ID,DC_MOTOR_PIN_2,LOGIC_LOW);
	}

	else if (state == CW)
	{
		/*Rotate Clockwise*/
		GPIO_writePin (DC_MOTOR_PORT_ID,DC_MOTOR_PIN_1,LOGIC_LOW);
		GPIO_writePin (DC_MOTOR_PORT_ID,DC_MOTOR_PIN_2,LOGIC_HIGH);
	}

	else if (state == ACW)
	{
		/*Rotate AntiClockwise*/
		GPIO_writePin (DC_MOTOR_PORT_ID,DC_MOTOR_PIN_1,LOGIC_HIGH);
		GPIO_writePin (DC_MOTOR_PORT_ID,DC_MOTOR_PIN_2,LOGIC_LOW);
	}
}
