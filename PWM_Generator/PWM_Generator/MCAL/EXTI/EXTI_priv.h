/*
 * EXTI_priv.h
 *
 *  Created on: Feb 3, 2024
 *      Author: lenovo
 */

#ifndef MCAL_EXTI_EXTI_PRIV_H_
#define MCAL_EXTI_EXTI_PRIV_H_

#define 		MCUCR				(*(volatile uint8*)(0x55))
#define			MCUCSR				(*(volatile uint8*)(0x54))
#define			GIFR				(*(volatile uint8*)(0x5B))
#define			GICR				(*(volatile uint8*)(0x5A))


#define INT_NUM 		3

/* Sensitivity Level of Interrupt */

/*Instead of #define everything, just use enu function*/
enum
{
	LOW_LEVEL,
	ANY_LOGICAL,
	FALLING,
	RISING,
	DISABLED=0,
	ENABLED,
	INT0=0,
	INT1,
	INT2
};


#endif /* MCAL_EXTI_EXTI_PRIV_H_ */
