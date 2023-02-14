/*
 * LightSystem_program.c
 *
 *  Created on: Dec 22, 2022
 *      Author: mrezk
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_interface.h"
#include "TIMERS_interface.h"
#include "LightStstem_private.h"
#include "LightSystem_config.h"
#include "LightSystem_interface.h"

u8 LightSystem_u8LightAdjustment(void)
{
	u8 Local_u8ErrorState=0;
	u8 Local_u8LDRRead=0;
	u16 Local_u16MilliVolts=0;
	u8	Local_u8CompareMatch;
	if(LDR_CHANNEL<=ADC_CHANNEL_7&&LDR_CHANNEL>=ADC_CHANNEL_0&&(&Local_u8LDRRead)!=NULL)
	{
		ADC_u8StartConversionSynchronus(LDR_CHANNEL,&Local_u8LDRRead);
		Local_u16MilliVolts=Local_u8LDRRead*2560/256;
		Local_u8CompareMatch=(s16)(Local_u16MilliVolts/1000)*(-99)+255;
		TIMER0_u8SetCompareMatchValue(Local_u8CompareMatch);

	}
	else
	{
		Local_u8ErrorState=1;
	}
	return Local_u8ErrorState;
}


