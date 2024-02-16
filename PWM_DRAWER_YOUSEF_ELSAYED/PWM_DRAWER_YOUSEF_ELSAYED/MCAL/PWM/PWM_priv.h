/*
 * PWM_priv.h
 *
 *  Created on: Feb 4, 2024
 *      Author: lenovo
 */

#ifndef MCAL_PWM_PWM_PRIV_H_
#define MCAL_PWM_PWM_PRIV_H_

#define 		TIMER0			0
#define 		TIMER2			2

#define			NORMAL_PWM		8
#define 		FAST_PWM		9
#define			PHASE_PWM		10

#define			NOT_INV			15
#define			INV				16


#endif /* MCAL_PWM_PWM_PRIV_H_ */
/*
#define TIMSK	*((volatile uint8*)0x59)
#define TIFR 	*((volatile uint8*)0x58)

*TIMER 0 REGISTERS*

#define TCCR0	*((volatile uint8*)0x53)
#define TCNT0	*((volatile uint8*)0x52)
#define OCR0	*((volatile uint8*)0x5C)

*TIMER 1 REGISTERS* 

#define TCCR1A	*((volatile uint8*)0x4F)
#define TCCR1B  *((volatile uint8*)0x4E)
#define TCNT1H  *((volatile uint8*)0x4D)
#define TCNT1L  *((volatile uint8*)0x4C)

#define OCR1AH  *((volatile uint8*)0x4B)
#define OCR1AL  *((volatile uint8*)0x4A)

#define OCR1BH  *((volatile uint8*)0x49)
#define OCR1BL  *((volatile uint8*)0x48)

#define ICR1H   *((volatile uint8*)0x47)
#define ICR1L	*((volatile uint8*)0x46)

*TIMER 2 REGISTERS*

#define TCCR2	*((volatile uint8*)0x45)
#define TCNT2	*((volatile uint8*)0x44)
#define OCR2	*((volatile uint8*)0x43)


*/