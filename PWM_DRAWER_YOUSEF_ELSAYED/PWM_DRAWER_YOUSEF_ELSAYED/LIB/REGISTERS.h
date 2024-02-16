/*
 * REGISTERS.h
 *
 *  Created on: Jan 22, 2024
 *      Author: lenovo
 */

#ifndef LIBRARIES_REGISTERS_H_
#define LIBRARIES_REGISTERS_H_

/* GROUP A || PORT A */
/* PORTA 0x3B || DDRA 0x3A || PINA 0x39 */

# define PORTA							(*(volatile uint8*)(0x3B))
# define DDRA							(*(volatile uint8*)(0x3A))
# define PINA 							(*(volatile uint8*)(0x39))


 /* GROUP B || PORT B */
/* PORTB 0x38 || DDRB 0x37 || PINB 0x36 */

# define PORTB  						(*(volatile uint8*)(0x38))
# define DDRB 							(*(volatile uint8*)(0x37))
# define PINB   						(*(volatile uint8*)(0x36))

/* GROUP C || Port C */

# define PORTC						  	(*(volatile uint8*)(0x35))
# define DDRC 						  	(*(volatile uint8*)(0x34))
# define PINC    						(*(volatile uint8*)(0x33))

//#define _MMIO_BYTE(mem_addr) (*(volatile uint8_t *)(mem_addr))
/* GROUP D || PORT D */
/* PORTD 0x32 || DDRD 0x31 || PIND 0x30 */

# define PORTD  						(*(volatile uint8*)(0x32))
# define DDRD 							(*(volatile uint8*)(0x31))
# define PIND   						(*(volatile uint8*)(0x30))



/*Interrupt Registers */
#define 		SREG 				(*(volatile uint8*)(0x5F))
#define 		MCUCR				(*(volatile uint8*)(0x55))
#define			MCUCSR				(*(volatile uint8*)(0x54))
#define			GIFR				(*(volatile uint8*)(0x5B))
#define			GICR				(*(volatile uint8*)(0x5A))

/*TIMER REGISTERS */
#define TIMSK	*((volatile uint8*)0x59)
#define TIFR 	*((volatile uint8*)0x58)

/*TIMER 0 SPECIFIC REGISTERS*/

#define TCCR0	*((volatile uint8*)0x53)
#define TCNT0	*((volatile uint8*)0x52)
#define OCR0	*((volatile uint8*)0x5C)

/*TIMER 1 SPECIFIC REGISTERS*/

#define TCCR1A	*((volatile uint8*)0x4F)
#define TCCR1B  *((volatile uint8*)0x4E)

#define TCNT1	*((volatile uint8*)0x4C)
#define TCNT1H  *((volatile uint8*)0x4D)
#define TCNT1L  *((volatile uint8*)0x4C)

#define OCR1A	*((volatile uint8*)0x4A)
#define OCR1AH  *((volatile uint8*)0x4B)
#define OCR1AL  *((volatile uint8*)0x4A)

#define OCR1B	*((volatile uint8*)0x48)
#define OCR1BH  *((volatile uint8*)0x49)
#define OCR1BL  *((volatile uint8*)0x48)

#define ICR1	*((volatile uint8*)0x46)
#define ICR1H   *((volatile uint8*)0x47)
#define ICR1L	*((volatile uint8*)0x46)

/*TIMER 2 SPECIFIC REGISTERS*/

#define TCCR2	*((volatile uint8*)0x45)
#define TCNT2	*((volatile uint8*)0x44)
#define OCR2	*((volatile uint8*)0x43)

#endif /* LIBRARIES_REGISTERS_H_ */
