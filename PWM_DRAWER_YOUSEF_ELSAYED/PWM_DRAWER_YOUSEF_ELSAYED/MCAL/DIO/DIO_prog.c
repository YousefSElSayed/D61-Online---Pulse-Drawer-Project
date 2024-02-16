/*
 * DIO_prog.c
 *
 *  Created on: Jan 22, 2024
 *      Author: lenovo
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/ERROR_STATES.h"
#include "../../LIB/REGISTERS.h"
#include "../../LIB/BIT_MATH.h"

#include "../DIO/DIO_priv.h"
#include "../DIO/DIO_config.h"
#include "../DIO/DIO_interface.h"

// Set the Direction of a Port 
ES_t DIO_enuSetPortDir(uint8 Copy_uint8PortName,uint8 Copy_uint8PortDirection){
	ES_t Local_enuErrorState = ES_NOK;
if(Copy_uint8PortDirection == DIO_uint8OUTPUT){	
	switch(Copy_uint8PortName){
		
		case DIO_uint8PORTA: DDRA = 0xFF;
		case DIO_uint8PORTB: DDRB = 0xFF;
		case DIO_uint8PORTC: DDRC = 0xFF;
		case DIO_uint8PORTD: DDRD = 0xFF; 
	}
}
if(Copy_uint8PortDirection == DIO_uint8INPUT){
	switch(Copy_uint8PortName){
		case DIO_uint8PORTA: DDRA = 0x00;
		case DIO_uint8PORTB: DDRB = 0x00;
		case DIO_uint8PORTC: DDRC = 0x00;
		case DIO_uint8PORTD: DDRD = 0x00;
	}
}
	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}

// Set Direction of a Pin
ES_t DIO_enuSetPinDir(uint8 Copy_uint8PortName , uint8 Copy_uint8PinName , uint8 Copy_uint8Direction)
{
	ES_t Local_enuErrorState = ES_NOK;

	if (Copy_uint8PortName <= DIO_uint8PORTD
	&& Copy_uint8PinName <= DIO_uint8PIN7
	&& Copy_uint8Direction <= DIO_uint8OUTPUT)
	{
		switch (Copy_uint8PortName)
		{
			case DIO_uint8PORTA:

			DDRA &=~(BIT_MASK<<Copy_uint8PinName);
			DDRA |= (Copy_uint8Direction<<Copy_uint8PinName);

			break;
			case DIO_uint8PORTB:

			DDRB &=~(BIT_MASK<<Copy_uint8PinName);
			DDRB |= (Copy_uint8Direction<<Copy_uint8PinName);

			break;
			case DIO_uint8PORTC:

			DDRC &=~(BIT_MASK<<Copy_uint8PinName);
			DDRC |= (Copy_uint8Direction<<Copy_uint8PinName);

			break;
			case DIO_uint8PORTD:

			DDRD &=~(BIT_MASK<<Copy_uint8PinName);
			DDRD |= (Copy_uint8Direction<<Copy_uint8PinName);

			break;
		}
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}


// Set the value of a Pin 
ES_t DIO_enuSetPinValue(uint8 Copy_uint8PortName , uint8 Copy_uint8PinName , uint8 Copy_uint8PinValue)
{
	ES_t Local_enuErrorState = ES_NOK;

	if (Copy_uint8PortName <= DIO_uint8PORTD
	&& Copy_uint8PinName <= DIO_uint8PIN7
	&& (Copy_uint8PinValue <= DIO_uint8HIGH || Copy_uint8PinValue <= DIO_uint8PULL_UP ))
	{
		switch (Copy_uint8PortName)
		{
			case DIO_uint8PORTA:

			PORTA &=~(BIT_MASK<<Copy_uint8PinName);
			PORTA |= (Copy_uint8PinValue<<Copy_uint8PinName);

			break;
			case DIO_uint8PORTB:

			PORTB &=~(BIT_MASK<<Copy_uint8PinName);
			PORTB |= (Copy_uint8PinValue<<Copy_uint8PinName);

			break;
			case DIO_uint8PORTC:

			PORTC &=~(BIT_MASK<<Copy_uint8PinName);
			PORTC |= (Copy_uint8PinValue<<Copy_uint8PinName);

			break;
			case DIO_uint8PORTD:

			PORTD &=~(BIT_MASK<<Copy_uint8PinName);
			PORTD |= (Copy_uint8PinValue<<Copy_uint8PinName);

			break;
		}
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}

// Toggle a Pin value 
ES_t DIO_enuTogglePinValue(uint8 Copy_uint8PortName , uint8 Copy_uint8PinName)
{
	ES_t Local_enuErrorState = ES_NOK;

	if (Copy_uint8PortName <= DIO_uint8PORTD
	&& Copy_uint8PinName <= DIO_uint8PIN7)
	{
		switch (Copy_uint8PortName)
		{
			case DIO_uint8PORTA:

			PORTA ^= (BIT_MASK<<Copy_uint8PinName);

			break;
			case DIO_uint8PORTB:

			PORTB ^= (BIT_MASK<<Copy_uint8PinName);

			break;
			case DIO_uint8PORTC:

			PORTC ^= (BIT_MASK<<Copy_uint8PinName);

			break;
			case DIO_uint8PORTD:

			PORTD ^= (BIT_MASK<<Copy_uint8PinName);

			break;
		}
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;

}

// Get the value of a PIN 
ES_t DIO_enuGetPinValue(uint8 Copy_uint8PortName , uint8 Copy_uint8PinName , uint8 * Copy_puint8Value)
{
	ES_t Local_enuErrorState = ES_NOK;

	if (Copy_puint8Value != NULL)
	{
		if(Copy_uint8PortName <= DIO_uint8PORTD
		&& Copy_uint8PinName <= DIO_uint8PIN7)
		{
			switch (Copy_uint8PortName)
			{
				case DIO_uint8PORTA:

				*Copy_puint8Value = ( (PINA >> Copy_uint8PinName ) & BIT_MASK);

				break;
				case DIO_uint8PORTB:

				*Copy_puint8Value = ( (PINB >> Copy_uint8PinName ) & BIT_MASK);

				break;
				case DIO_uint8PORTC:

				*Copy_puint8Value = ( (PINC >> Copy_uint8PinName ) & BIT_MASK);

				break;
				case DIO_uint8PORTD:

				*Copy_puint8Value = ( (PIND >> Copy_uint8PinName ) & BIT_MASK);

				break;
			}
			Local_enuErrorState = ES_OK;
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
