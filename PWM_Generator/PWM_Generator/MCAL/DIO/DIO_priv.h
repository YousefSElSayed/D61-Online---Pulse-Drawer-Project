/*
 * DIO_priv.h
 *
 *  Created on: Jan 22, 2024
 *      Author: lenovo
 */

#ifndef MCAL_DIO_DIO_PRIV_H_
#define MCAL_DIO_DIO_PRIV_H_

#define DIO_uint8PORTA					0
#define DIO_uint8PORTB					1
#define DIO_uint8PORTC					2
#define DIO_uint8PORTD					3

enum{
	DIO_uint8PIN0=0,
	DIO_uint8PIN1,
	DIO_uint8PIN2,
	DIO_uint8PIN3,
	DIO_uint8PIN4,
	DIO_uint8PIN5,
	DIO_uint8PIN6,
	DIO_uint8PIN7,
};

/*
#define DIO_uint8PIN0					0
#define DIO_uint8PIN1					1
#define DIO_uint8PIN2					2
#define DIO_uint8PIN3					3
#define DIO_uint8PIN4					4
#define DIO_uint8PIN5					5
#define DIO_uint8PIN6					6
#define DIO_uint8PIN7					7
*/

#define DIO_uint8INPUT				0
#define DIO_uint8OUTPUT				1

#define DIO_uint8LOW				0
#define DIO_uint8HIGH				1

#define DIO_uint8FLOAT				0
#define DIO_uint8PULL_UP			1

/* You can also declare the registers here. The point is to keep the user away from the pins and the location of the pins */



#endif /* MCAL_DIO_DIO_PRIV_H_ */
