#include "../../LIB/STD_TYPES.h"
#include "../../LIB/ERROR_STATES.h"

#include "EXTI_priv.h"
#include "EXTI_config.h"


EXTI_t EXTI_AstrEXTIConfig[INT_NUM] =
{
		{ENABLED, RISING}, //INT0
		{DISABLED, DISABLED}, //INT1
		{DISABLED, DISABLED} //INT2
};
