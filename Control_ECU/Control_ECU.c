 /******************************************************************************
 *
 * [FILE NAME]: <Control_ECU.c>
 *
 * [AUTHOR]: <Hossam Hafez>
 *
 * [DATE CREATED]: <28/3/2023>
 *
 * [DESCRIPTION]: <Source file for CONTROL ECU>
 *
 *******************************************************************************/

#include "Control_ECU.h"



int counter,falsePasswords;

Timer1_Configtype timerConfig = {COMPARE,0,7813,P_1024};

UART_ConfigType uartConfig = {Disabled,one,_9600};

void start(void)
{
	SREG |= (1<<7);


	DcMotor_Init();
	Timer1_setCallBack(timerHandler);
    Buzzer_init();

	UART_init(&uartConfig);


	uint8 password[5] , confirmPassword[5] , passwordVerified , command;

	while(passwordVerified == 0)
	{
		Password_Rec(password);

		Password_Rec(confirmPassword);

		passwordVerified = Password_Ver(password, confirmPassword);
		UART_sendByte(passwordVerified);

		_delay_ms(50);
	}


	Password_Store_EEPROM(password);


	while(1)
	{
		uint8 passwordEEPROM[4];
		Password_Read_EEPROM(passwordEEPROM);
		command = UART_recieveByte();
		_delay_ms(1000);

		if(command == '+')
		{
			Password_Rec(password);

			if(Password_Ver(password, passwordEEPROM))
			{
				falsePasswords = 0;
				UART_sendByte(1);
				_delay_ms(50);
				openDoor();
			}

			else
			{
				UART_sendByte(0);
				_delay_ms(50);
				falsePasswords++;
				UART_sendByte(falsePasswords);
				_delay_ms(50);
				Password_False();

			}
		}

		else if(command == '-')
		{
			Password_Rec(password);


			passwordVerified = Password_Ver(password, passwordEEPROM);
			_delay_ms(50);
			UART_sendByte(passwordVerified);

			if(passwordVerified)
			{
				falsePasswords = 0;
				Password_Rec(password);


				Password_Rec(confirmPassword);

				passwordVerified = Password_Ver(password, confirmPassword);
				_delay_ms(50);
				UART_sendByte(passwordVerified);

				if(passwordVerified)
				{
					Password_Store_EEPROM(password);
				}

				else
				{
					// do nothing
				}

			}

			else
			{
				falsePasswords++;
				UART_sendByte(falsePasswords);
				_delay_ms(50);
				Password_False();
			}
		}
	}
}


void Password_Rec (uint8 password[])
{
	uint8 i;

	for (i=0 ; i<5 ; ++i)
	{
		password [i] = UART_recieveByte();
	}
	_delay_ms(1000);
}



uint8 Password_Ver (uint8 password[] , uint8 confirmPassword[])
{
	uint8 i;

	for (i=0 ; i<5 ; ++i)
	{
		if (password[i] != confirmPassword[i])
		{
			return 0;
		}
	}
	return 1;
}




void openDoor (void)
{
	Timer1_init(&timerConfig);

	DcMotor_Rotate(CW);
	while (counter < 15);
	counter = 0;
	DcMotor_Rotate(STOP);


	while (counter < 3);
	counter = 0;
	DcMotor_Rotate(ACW);


	while (counter < 15);
	counter = 0;
	DcMotor_Rotate(STOP);
	Timer1_deInit();
}




void timerHandler(void)
{
	counter++;
}




void Password_False (void)
{
	if (falsePasswords >= 3)
	{
		falsePasswords = 0;
		Timer1_init (&timerConfig);
		Buzzer_on();
		while (counter < 60);
		Buzzer_off();
		counter = 0;
		Timer1_deInit();
	}
}



void Password_Store_EEPROM (uint8 password[])
{
	uint8 i;
	for (i=0 ; i<5 ; ++i)
	{
	EEPROM_writeByte ((0X0090 + i) , (password[i]));
	_delay_ms(50);
	}
}



void Password_Read_EEPROM (uint8 password [])
{
	uint8 i;
	for (i=0 ; i<5 ; ++i)
	{
		EEPROM_readByte((0x0090 + i) , (password + i));
		_delay_ms(50);
	}
}
