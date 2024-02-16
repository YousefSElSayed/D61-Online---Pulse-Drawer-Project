#include "../../LIB/STD_TYPES.h"
#include "../../LIB/ERROR_STATES.h"
#include "../GIE/GIE_priv.h"
#include "../../LIB/BIT_MATH.h"



ES_t GIE_enuInitialize(void){

	ES_t Local_enuErrorState = ES_NOK;

	SREG &=~(1<<7);
	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;

}

ES_t GIE_enuEnable(void){

	ES_t Local_enuErrorState = ES_NOK;

		SREG  |=(1<<7);
		Local_enuErrorState = ES_OK;

		return Local_enuErrorState;

}

ES_t GIE_enuDisable(void){

	ES_t Local_enuErrorState = ES_NOK;

		SREG&=~(1<<7);
		Local_enuErrorState = ES_OK;

		return Local_enuErrorState;

}

