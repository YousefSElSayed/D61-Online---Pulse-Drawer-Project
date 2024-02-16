/*
 * PWM_interface.h
 *
 *  Created on: Feb 4, 2024
 *      Author: lenovo
 */

#ifndef MCAL_PWM_PWM_INTERFACE_H_
#define MCAL_PWM_PWM_INTERFACE_H_

ES_t PWM_enuInitialize(PWM_t* Copy_PAstrPWMConfig);
ES_t PWM_enuSetFrequency(uint16 Copy_u16Frequency, PWM_t* Copy_PAstrPWMConfig);
ES_t PWM_enuSetDutyCycle(uint8 Copy_u8DutyCycle, PWM_t* Copy_PAstrPWMConfig);


#endif /* MCAL_PWM_PWM_INTERFACE_H_ */
