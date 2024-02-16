#include "../../LIB/STD_TYPES.h"
#include "../../LIB/ERROR_STATES.h"
#include "../../LIB/REGISTERS.h"
#include "PWM_config.h"
#include "PWM_priv.h"
#include "PWM_interface.h"


 
/* Initialize the PWM based on the configuration in Config.c */
ES_t PWM_enuInitialize(PWM_t* Copy_PAstrPWMConfig){

	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_PAstrPWMConfig[0].PWM_Type == FAST_PWM){
		switch(Copy_PAstrPWMConfig[0].PWM_Inv_Mode){
			case(INV): TCCR0 = 0x78;
			case(NOT_INV): TCCR0 = 0x68;
		}
	}
	else if(Copy_PAstrPWMConfig[0].PWM_Type == PHASE_PWM){
		switch(Copy_PAstrPWMConfig[0].PWM_Inv_Mode){
			case(INV): TCCR0 = 0x70;
			case(NOT_INV): TCCR0 = 0x60;
		}
		
	}
	else if(Copy_PAstrPWMConfig[0].PWM_Type == NORMAL_PWM){
		switch(Copy_PAstrPWMConfig[0].PWM_Inv_Mode){
			case(INV): TCCR0 = 0x30;
			case(NOT_INV): TCCR0 = 0x20;
		}
		
	}
	Local_enuErrorState = ES_OK;
	
	
	return Local_enuErrorState;
}

/* Set the Duty cycle of the output PWM signal */
ES_t PWM_enuSetDutyCycle(uint8 Copy_uint8DutyCycle, PWM_t* Copy_PAstrPWMConfig){
 	ES_t Local_enuErrorState = ES_NOK;

	uint8 OCR_Value = 0;
	switch(Copy_PAstrPWMConfig[0].PWM_Inv_Mode){
		case(NOT_INV): OCR_Value = (uint8)((Copy_uint8DutyCycle * 256)/100);
		case(INV): OCR_Value = (uint8)(((100 - Copy_uint8DutyCycle) * 256)/100);
	}
	OCR0 = OCR_Value;
	Local_enuErrorState = ES_OK;
	
	return Local_enuErrorState;  



}



  
ES_t PWM_enuSetFrequency(uint16 Copy_uint16Frequency, PWM_t* Copy_PAstrPWMConfig){
	ES_t Local_enuErrorState=ES_NOK;

	uint16 Local_Au16FreqFast[]= {62400,7812,976,245,61};

	uint16 Local_Au16FreqPhase[]= {31200,3650,467,123,30};
	uint8 flag=0;


	if(Copy_PAstrPWMConfig[0].Timer_Num==0)
	{
		if(Copy_PAstrPWMConfig[0].PWM_Type== FAST_PWM)
		{
			for (uint8 i =0; i<5;i++)
			{
				if(Copy_uint16Frequency== Local_Au16FreqFast[i])
				{
					TCCR0 &= ~(7<<0);
					TCCR0 |= (i+1);
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				for (uint8 i =0; i<5;i++)
				{
					if(Copy_uint16Frequency > Local_Au16FreqFast[i])
					{
						TCCR0 &= ~(7<<0);
						TCCR0 |= (i+1);
						flag=1;
						break;
					}
				}
				if(flag==0)
				{
					TCCR0 &= ~(7<<0);
					TCCR0 |= (5);
				}
			}
		}
	}
	return Local_enuErrorState;
	
} 
 
