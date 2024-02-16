/*
 * DIO_interface.h
 *
 *  Created on: Jan 22, 2024
 *      Author: lenovo
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/ERROR_STATES.h"
#include "../../LIB/REGISTERS.h"

#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_


/* Return_Data_type   ModuleName_ReturnDataTypeDescriptionName   () */
/*
 * PORTA = 0
 * PORTB = 1
 * PORTC = 2
 * PORTD = 3
 * Pin0=0
 * Pin1=1 etc
 * Direction = OUTPUT | INPUT
 **/

ES_t DIO_enuSetPortDir(uint8 Copy_uint8PortName,uint8 Copy_uint8PortDirection);
ES_t DIO_enuSetPinDir(uint8 Copy_uint8PortName, uint8 Copy_uint8PinName , uint8 Copy_uint8PinDirection);
ES_t DIO_enuSetPinValue(uint8 Copy_uint8PortName, uint8 Copy_uint8PinName,uint8 Copy_uint8PinValue);
ES_t DIO_enuTogglePinValue(uint8 Copy_uint8PortName, uint8 Copy_uint8PinName);
ES_t DIO_enuGetPinValue(uint8 Copy_uint8PortName, uint8 Copy_uint8PinName, uint8 * Copy_Puint8Value);


#endif /* MCAL_DIO_DIO_INTERFACE_H_ */
