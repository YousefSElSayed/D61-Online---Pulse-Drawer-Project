/*
 * PWM_config.h
 *
 *  Created on: Feb 4, 2024
 *      Author: lenovo
 */

#ifndef MCAL_PWM_PWM_CONFIG_H_
#define MCAL_PWM_PWM_CONFIG_H_


/* Here we will define number of timers used to generate PWM signal */
/* I just need one Timer to generate a PWM signal */

#define TIMER_NUM		1

#define TIMER0_RES		255
#define TIMER1_RES		65535
#define TIMER2_RES		255


/*Linking Time Config*/
typedef struct {

	uint8	Timer_Num;
	uint8	PWM_Type;
	uint8	PWM_Inv_Mode;
}PWM_t;


#endif /* MCAL_PWM_PWM_CONFIG_H_ */
