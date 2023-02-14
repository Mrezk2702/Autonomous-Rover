/*
 * servo_program.c
 *
 *  Created on: Dec 15, 2022
 *      Author: mrezk
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMERS_interface.h"
#include "Servo_config.h"
#include "Servo_interface.h"
#include "Servo_private.h"


u8 Servo_u8SetAngle(s8 Copy_s8Angle)
{
	u8 Local_u8ErrorState=0;
	if(Copy_s8Angle>=-90||Copy_s8Angle<=90)
	{
		u16 Local_u16CompareMatch=6*Copy_s8Angle+1500;
		TIMER1_u8SetCompareMatchValue(SERVO_CHANNEL,Local_u16CompareMatch);

	}
	else
	{
		Local_u8ErrorState=1;
	}


	return Local_u8ErrorState;

}









