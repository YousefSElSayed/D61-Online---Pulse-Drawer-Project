#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/ERROR_STATES.h"

#include "EXTI_priv.h"
#include "EXTI_config.h"
#include "../interrupt.h"


/*
 * EXTI_prog.c
 *
 */

static volatile void (* EXTI_pfunISRFun[3]) (void) = {NULL,NULL,NULL};
	
	
// Initialize External Interrupt 
ES_t EXTI_enuInit(EXTI_t * Copy_pAstrEXTIConfig)
{
	ES_t Local_enuErrorState = ES_NOK;
	if (Copy_pAstrEXTIConfig[INT0].Int_State == ENABLED)
	{
		GICR |=(1<<6);
		switch(Copy_pAstrEXTIConfig[INT0].Sense_Level)
		{
		case LOW_LEVEL:
			MCUCR &= ~(3<<0);
			break;
		case ANY_LOGICAL:
			MCUCR |=  (1<<0);
			MCUCR &= ~(1<<1);
			break;
		case FALLING:
			MCUCR &= ~(1<<0);
			MCUCR |=  (1<<1);
			break;
		case RISING:
			MCUCR |=  (3<<0);
			break;
		default:
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}
	}
	else if (Copy_pAstrEXTIConfig[INT0].Int_State == DISABLED)
	{
		GICR &=~(1<<6);
	}

	if (Copy_pAstrEXTIConfig[INT1].Int_State == ENABLED)
	{
		GICR |= (1<<7);
		switch(Copy_pAstrEXTIConfig[INT1].Sense_Level)
		{
		case LOW_LEVEL:
			MCUCR &= ~(3<<2);
			break;
		case ANY_LOGICAL:
			MCUCR |=  (1<<2);
			MCUCR &= ~(1<<3);
			break;
		case FALLING:
			MCUCR &= ~(1<<2);
			MCUCR |=  (1<<3);
			break;
		case RISING:
			MCUCR |=  (3<<2);
			break;
		default:
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}
	}
	else if (Copy_pAstrEXTIConfig[INT1].Int_State == DISABLED)
	{
		GICR &=~(1<<7);
	}

	if (Copy_pAstrEXTIConfig[INT2].Int_State == ENABLED)
	{
		GICR |= (1<<5);
		switch(Copy_pAstrEXTIConfig[INT2].Sense_Level)
		{
		case FALLING:
			MCUCSR &= ~(1<<6);
			break;
		case RISING:
			MCUCSR |=  (1<<6);
			break;
		default:
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}
	}
	else if (Copy_pAstrEXTIConfig[INT2].Int_State == DISABLED)
	{
		GICR &=~(1<<5);
	}
	return Local_enuErrorState;
}

// Set the Sense level of the external interrupt based on the MCUCR register
ES_t EXTI_enuSetSenseLevel(uint8 Copy_u8IntNum, uint8 Copy_u8SenceLevel)
{
	ES_t Local_enuErrorState = ES_NOK;

	if (Copy_u8IntNum == INT0)
	{
		switch(Copy_u8SenceLevel)
		{
		case LOW_LEVEL:
			MCUCR &= ~(3<<0);
			break;
		case ANY_LOGICAL:
			MCUCR |=  (1<<0);
			MCUCR &= ~(1<<1);
			break;
		case FALLING:
			MCUCR &= ~(1<<0);
			MCUCR |=  (1<<1);
			break;
		case RISING:
			MCUCR |=  (3<<0);
			break;
		default:
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}
	}
	else if (Copy_u8IntNum == INT1)
	{
		switch(Copy_u8SenceLevel)
		{
		case LOW_LEVEL:
			MCUCR &= ~(3<<2);
			break;
		case ANY_LOGICAL:
			MCUCR |=  (1<<2);
			MCUCR &= ~(1<<3);
			break;
		case FALLING:
			MCUCR &= ~(1<<2);
			MCUCR |=  (1<<3);
			break;
		case RISING:
			MCUCR |=  (3<<2);
			break;
		default:
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}
	}
	else if (Copy_u8IntNum == INT2)
	{
		switch(Copy_u8SenceLevel)
		{
		case FALLING:
			MCUCSR &= ~(1<<6);
			break;
		case RISING:
			MCUCSR |=  (1<<6);
			break;
		default:
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}
	}


	return Local_enuErrorState;
}

// Enable the external interrupt
ES_t EXTI_enuEnableInterrupt(uint8 Copy_u8IntNum)
{
	ES_t Local_enuErrorState = ES_NOK;

	if (Copy_u8IntNum == INT0)
	{
		GICR |= (1<<6);
	}
	else if (Copy_u8IntNum == INT1)
	{
		GICR |= (1<<7);
	}
	else if (Copy_u8IntNum == INT2)
	{
		GICR |= (1<<5);
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}

// Disable External interrupt
ES_t EXTI_enuDisableInterrupt(uint8 Copy_u8IntNum)
{
	ES_t Local_enuErrorState = ES_NOK;

	if (Copy_u8IntNum == INT0)
	{
		GICR &=~(1<<6);
	}
	else if (Copy_u8IntNum == INT1)
	{
		GICR &=~(1<<7);
	}
	else if (Copy_u8IntNum == INT2)
	{
		GICR &=~(1<<5);
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}

ES_t EXTI_enuCallBack(volatile void (* Copy_pfunAppFun)(void), uint8 Copy_u8IntNum)
{
	ES_t Local_enuErrorState = ES_NOK;

	if (Copy_pfunAppFun != NULL)
	{
		if (Copy_u8IntNum <=2 )
		{
			EXTI_pfunISRFun[Copy_u8IntNum] = Copy_pfunAppFun;
	 

		}
		else
		{
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}

// Interrupt Service Routines
ISR(VECT_INT0)
{
	if (EXTI_pfunISRFun[0] != NULL)
	{
		EXTI_pfunISRFun[0] ();
	}
}

ISR(VECT_INT1)
{
	if (EXTI_pfunISRFun[1] != NULL)
	{
		EXTI_pfunISRFun[1] ();
	}
}

ISR(VECT_INT2)
{
	if (EXTI_pfunISRFun[2] != NULL)
	{
		EXTI_pfunISRFun[2] ();
	}
}
