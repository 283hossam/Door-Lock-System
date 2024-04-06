 /******************************************************************************
 *
 * [FILE NAME]: <HMI_ECU.h>
 *
 * [AUTHOR]: <Hossam Hafez>
 *
 * [DATE CREATED]: <29/3/2024>
 *
 * [DESCRIPTION]: <Header file for HMI ECU>
 *
 *******************************************************************************/

#ifndef HMI_ECU_H_
#define HMI_ECU_H_


/*******************************************************************************
 *                                INCLUDES                                     *
 *******************************************************************************/
#include "lcd.h"
#include "keypad.h"
#include "uart.h"
#include "timer.h"
#include "util/delay.h"
#include "avr/interrupt.h"




/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define KEYPAD_DELAY        500
#define UART_DELAY          50



/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

void start(void);
void Password_Enter (uint8 password[] );
void Password_Send (uint8 password[] );
void optionsDisplay (void);
void openDoor (void);
void securityAlarm (void);
void timerHandler (void);

#endif /* HMI_ECU_H_ */
