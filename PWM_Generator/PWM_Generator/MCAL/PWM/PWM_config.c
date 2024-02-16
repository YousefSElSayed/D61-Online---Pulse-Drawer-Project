#include "../../LIB/STD_TYPES.h"
#include "../../LIB/ERROR_STATES.h"
#include "../../LIB/REGISTERS.h"

#include "PWM_config.h"
#include "PWM_priv.h"

uint8 PWM_uint8TimerNum = TIMER_NUM;


/*PWM Mode:   FAST_PWM    PHASE_PWM */
  


PWM_t PWM_AstrPWMConfig[TIMER_NUM]=
{
		{TIMER0, FAST_PWM, NOT_INV},
};
