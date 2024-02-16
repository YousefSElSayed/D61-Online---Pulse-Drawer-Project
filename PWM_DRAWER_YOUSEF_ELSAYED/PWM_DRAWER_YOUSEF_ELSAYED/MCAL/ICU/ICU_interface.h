/*
 * ICU_interface.h
 *
 * Created: 2/10/2024 10:47:37 PM
 *  Author: lenovo
 */ 
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/ERROR_STATES.h"
#include "../../LIB/REGISTERS.h"


void ICU_enuInit(ICU_Config* Copy_ICUSetting);
uint16 ICU_enuGetFrequency(ICU_Config* Copy_ICUSetting);
uint16 ICU_enuGetPeriod(ICU_Config* Copy_ICUSetting);