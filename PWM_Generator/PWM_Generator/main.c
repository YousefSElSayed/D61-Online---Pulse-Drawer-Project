/*
 * PWM_Generator.c
 *
 * Created: 2/15/2024 11:36:58 PM
 * Author : lenovo
 */ 


#include "MCAL/DIO/DIO_config.h"
#include "MCAL/DIO/DIO_priv.h"
#include "MCAL/DIO/DIO_interface.h"


#include "MCAL/ICU/ICU_config.h"
#include "MCAL/ICU/ICU_priv.h"
#include "MCAL/ICU/ICU_interface.h"

#include "MCAL/PWM/PWM_config.h"
#include "MCAL/PWM/PWM_priv.h"
#include "MCAL/PWM/PWM_interface.h"

#include "LIB/STD_TYPES.h"
#include "LIB/ERROR_STATES.h"
#include "LIB/REGISTERS.h"


extern ICU_Config ICU_ConfigSettings[1];
extern PWM_t PWM_AstrPWMConfig[TIMER_NUM];

// This code is primarily made for the microcontroller responsible for producing a PWM signal and sending this signal to the reading microcontroller. Thus it will only initialize and set the frequency and Duty Cycle
// of the PWM signal and nothing more.

int main(void)
{
	
	DIO_enuSetPinDir(DIO_uint8PORTB,DIO_uint8PIN3,DIO_uint8OUTPUT); // PWM output
	
	
	PWM_enuInitialize(PWM_AstrPWMConfig);
	PWM_enuSetDutyCycle(23,&PWM_AstrPWMConfig);
	PWM_enuSetFrequency(55000,&PWM_AstrPWMConfig);
    while (1) 
    {
    }
}

