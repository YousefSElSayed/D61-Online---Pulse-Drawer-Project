/*
 * ICU_prog.c
 *
 * Created: 2/10/2024 10:47:51 PM
 *  Author: lenovo
 */ 
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/ERROR_STATES.h"
#include "../../LIB/REGISTERS.h"
#include "ICU_config.h"
#include "ICU_priv.h"
#include "ICU_interface.h"

// Initialize the Input Capture Unit that is using Timer1 
void ICU_enuInit(ICU_Config* Copy_ICUSetting){
	TCCR1A = 0x00;
	TCCR1B = 0x00;
	switch(Copy_ICUSetting->ICU_EDGE_TRIGGER){
		case(RISING_EDGE): TCCR1B |=  (1<<6);
		case(FALLING_EDGE): TCCR1B &=~(1<<6);
		
	}
	switch(Copy_ICUSetting->ICU_FLAG_STATUS){
		case(FLAG_ON): TIMSK |=  (1<<5);
		case(FLAG_OFF):TIMSK &=~(1<<5);
	}	
}

//Get the Frequency of the PWM signal being received 
uint16 ICU_enuGetFrequency(ICU_Config* Copy_ICUSetting){
	// Clear Flag and Timer1 values
	TCNT1=0;
	TIFR &= ~(1<<5);
	
	uint32 time1;
	uint32 time2;
	uint32 Period;
	uint32 Freq;
	uint32 F_cpu = 16000000;
 // Set ICU to trigger on rising edge 
	Copy_ICUSetting->ICU_EDGE_TRIGGER=RISING_EDGE;
	TCCR1B |=  (1<<6);
// When the flag isnt 0 anymore, take the value of the timer at that point and store it in t1
	while((TIFR &(1<<5))==0);
	time1 = ICR1;
	
//Clear the flag and loop again to find the second time it triggers on a rising edge. Take both times and subtract the second from the first to find the period of the signal 
	TIFR &= (1<<5);
	while((TIFR &(1<<5))==0);
	time2 = ICR1;
// Get p for period and find the frequency by inverting the value of the period (1/period)
	Period = time2 - time1;
	Freq = F_cpu/Period;
	
	return Freq;
	
}
// Get the frequency and invert it to get the period
uint16 ICU_enuGetPeriod(ICU_Config* Copy_ICUSetting){
	uint16 Freq = ICU_enuGetFrequency(Copy_ICUSetting);
	uint16 Per = 1/Freq;
	
	return Per;	
}


// Measure the duty cycle of the received PWM signal 
uint16 ICU_enGetCycle(ICU_Config* Copy_ICUSetting){
	uint16 cycle;
	uint16 t_on;
	uint16 per;
	uint16 t_off;
	// Clear TCNT AND Flag
	TCNT1 = 0;
	TIFR &= ~(1<<5);
	
	// Set to trigger on rising edge 
	Copy_ICUSetting->ICU_EDGE_TRIGGER=RISING_EDGE;
	TCCR1B |=  (1<<6);
	//Get the time it triggered on the rising edge 
	while((TIFR &(1<<5))==0);
	t_on = ICR1;
	// Set to trigger on Falling edge and get the time it triggered on falling edge
	Copy_ICUSetting->ICU_EDGE_TRIGGER=FALLING_EDGE;
	TCCR1B &= ~(1<<6);
	TIFR &= ~(1<<5);
	while((TIFR &(1<<5))==0);
	 t_off = ICR1;
	 // Measure Period by calling function and divide the difference between the time the ICU triggered on falling edge from time triggered on rising by the period and multiply by 100
	 per = ICU_enuGetPeriod(Copy_ICUSetting);
	 cycle = (t_off - t_on)/per * 100;
	
	
	return cycle;
	
}