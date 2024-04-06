 /******************************************************************************
 *
 * [FILE NAME]: <control.ECU.h>
 *
 * [AUTHOR]: <Hossam Hafez >
 *
 * [DATE CREATED]: <28/3/2024>
 *
 * [DESCRIPTION]: <Source file for control.ECU Driver>
 *
 *******************************************************************************/
#ifndef CONTROL_ECU_H_
#define CONTROL_ECU_H_

/*******************************************************************************
 *                                INCLUDES                                     *
 *******************************************************************************/
#include "uart.h"
#include "twi.h"
#include "timer.h"
#include "buzzer.h"
#include "external_eeprom.h"
#include "dcMotor.h"
#include "avr/interrupt.h"
#include <util/delay.h>

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

void start(void);
void Password_Rec (uint8 password[]);
uint8 Password_Ver (uint8 password[] , uint8 confirmPassword[]);
void openDoor (void);
void timerHandler(void);
void Password_False (void);
void Password_Store_EEPROM (uint8 password[]);
void Password_Read_EEPROM (uint8 password []);



#endif /* CONTROL_ECU_H_ */
