 /******************************************************************************
 *
 * [FILE NAME]: <dc motor.h>
 *
 * [AUTHOR]: <Hossam Hafez >
 *
 * [DATE CREATED]: <20/3/2024>
 * [DESCRIPTION]: <Header file for dc motor Driver>
 *
 *******************************************************************************/
#ifndef DCMOTOR_H_
#define DCMOTOR_H_

#include "std_types.h"


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define DC_MOTOR_PORT_ID           PORTC_ID

#define DC_MOTOR_PIN_1             PIN4_ID
#define DC_MOTOR_PIN_2             PIN5_ID


/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/

/*
 * [NAME]: DcMotor_State
 *
 * [Description] :
 * Select the state of the DC motor
 */
typedef enum
{
	STOP , CW , ACW
}DcMotor_State;




/*******************************************************************************
 *                         Function Prototypes                                 *
 *******************************************************************************/

/*
 * [NAME]: DcMotor_Init
 *
 * [Description] : Function that setup the direction for the two motor pins through the GPIO driver.
 *
 * [Returns]: void
 */
void DcMotor_Init(void);


/*
 * [NAME]: DcMotor_Rotate
 *
 * [Description] : Function that responsible for rotate the DC Motor CW/ or A-CW or stop the motor based on the state input state value.
 *
 * [Returns]: void
 */
void DcMotor_Rotate(DcMotor_State state);

#endif /* DCMOTOR_H_ */
