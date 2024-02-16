/*
 * ICU_config.h
 *
 * Created: 2/10/2024 10:47:10 PM
 *  Author: lenovo
 */ 
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/ERROR_STATES.h"
#include "../../LIB/REGISTERS.h"
#define TIMER1_RES		65535


typedef struct {

	uint8	ICU_EDGE_TRIGGER;
	uint8	ICU_FLAG_STATUS;
}ICU_Config;