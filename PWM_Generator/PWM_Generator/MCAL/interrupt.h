/*
 * interrupt.h
 *
 *  Created on: Feb 4, 2024
 *      Author: lenovo
 */

#ifndef MCAL_INTERRUPT_H_
#define MCAL_INTERRUPT_H_

#define ISR(vect_num) 		void vect_num (void)__attribute__((signal));\
void vect_num (void)



// our way of summarizing the ISR function
/*
#define ISR(vector_num)		void vect_num (void)__attribute__((signal));\
							void vect_num(void) */

/* ISR FUNCTION
void vect_num (void)__attribute__((signal));\
void vect_1(void)
{
C code here (Callback function)
}
 */


#define		VECT_INT0 				__vector_1
#define		VECT_INT1				__vector_2
#define		VECT_INT2				__vector_3



#endif /* MCAL_INTERRUPT_H_ */
