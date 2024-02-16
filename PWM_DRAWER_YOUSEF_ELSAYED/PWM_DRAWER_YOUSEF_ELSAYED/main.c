/*
 * ATmega 16 frequency and duty cycle measurment using input capture
 * www.electronicwings.com
 */


#define F_CPU 16000000

#include "MCAL/DIO/DIO_config.h"
#include "MCAL/DIO/DIO_priv.h"
#include "MCAL/DIO/DIO_interface.h"


#include "MCAL/ICU/ICU_config.h"
#include "MCAL/ICU/ICU_priv.h"
#include "MCAL/ICU/ICU_interface.h"

#include "MCAL/PWM/PWM_config.h"
#include "MCAL/PWM/PWM_priv.h"
#include "MCAL/PWM/PWM_interface.h"

#include "LIB/STD_TYPES.h"
#include "LIB/ERROR_STATES.h"
#include "LIB/REGISTERS.h"

#include "HAL/LCD/LCD.h"

int main ( )
{
	
		uint16 time0,time1,time2,t_on,period;
		uint8 display_freq[14],display_duty[7];
		
		LCD_Init();
		PORTD = 0xFF;		//Makes all of PORTD an Pull Up
		
		
		while(1)
		{
			// Clear the TCCR1 and TCNT1 registers, including the TIFR flag
			TCCR1A = 0; 
			TCNT1=0;
			TIFR = (1<<5);				 

			TCCR1B = 0x01;
			TCCR1B |= (1<<6) ;				
			while ((TIFR&(1<<5)) == 0);
			time0 = ICR1;						// Capture the time the ICU first detects a rising edge 
			TIFR = (1<<5);				 // Clears TIMER1 immediately after to prepare for the next capture
			
			TCCR1B &= ~(1<<6);				   //Change the Input Capture Edge Select to falling edge
			while ((TIFR&(1<<5)) == 0);
			time1 = ICR1;						// Time 1 will be for a detection of a falling edge, thus time1-time0 could get us the time the signal is 1 
			TIFR = (1<<5);				 
			
			TCCR1B |= (1<<6) ;					//Recalibrate to triggering on rising edge 
			while ((TIFR&(1<<5)) == 0);
			time2 = ICR1;						// Once the flag is raised, capture time2, which will help us get the period of the PWM signal
			TIFR = (1<<5);				

			TCCR1B = 0;			
			
				t_on=time1-time0; // Get the time that the signal is on 
				period=time2-time0; //get the period of the signal
				
				uint32 freq= F_CPU/period;	 //get the frequency of the signal	
				f32 duty_cycle = ((f32) t_on/ (f32) period)*100;	 // Get the duty cycle based on the equation of time_on over period 
				
				//Place the frequency and duty cycle values in an array
				ltoa(freq,display_freq,10);
				itoa((uint8)duty_cycle,display_duty,10);
				
				
				//LCD commands to place the cursor in a specific area and display the values of the frequency and period
				
				
				LCD_Command(0x80);
				LCD_String("Freq: ");
				LCD_String(display_freq);
				LCD_String(" Hz  ");
				
				LCD_Command(0xC0);
				LCD_String("Duty: ");
				LCD_String(display_duty);
				LCD_String(" %  ");
				
			

		}
}
