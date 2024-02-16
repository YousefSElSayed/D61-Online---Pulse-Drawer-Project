/*
 * EXTI_interface.h
 *
 *  Created on: Feb 3, 2024
 *      Author: lenovo
 */

#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_





ES_t EXTI_enuInit();
ES_t EXTI_enuSetSenseLevel(uint8 Copy_u8IntNum, uint8 Copy_u8IntLevel);
ES_t EXTI_enuEnableInterrupt(uint8 Copy_u8IntNum);
ES_t EXTI_enuDisableInterrupt(uint8 Copy_u8IntNum);
ES_t EXTI_enuCallBack(volatile void (* Copy_pfunAppFun)(void), uint8 Copy_u8IntNum);



#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */


