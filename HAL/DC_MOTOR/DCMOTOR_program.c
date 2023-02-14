/********************************************************************************/
/********************************************************************************/
/*****************       Aathur:Team Member                  ********************/
/*****************       Layer:HAL                           ********************/
/*****************       SWC:DC MOTOR                        ********************/
/*****************       version:1.00                        ********************/
/********************************************************************************/
/********************************************************************************/
#include"STD_TYPES.h"
#include"PORT_interface.h"
#include"DIO_interface.h"
#include"TIMERS_interface.h"
#include"DCMOTOR_interface.h"
#include"DCMOTOR_private.h"
#include"DCMOTOR_config.h"

u8 DCMOTOR_Dirction(u8 Copy_MotorDirecton,u8 Copy_DCMotor)
{
	u8 Local_ErrorState=0;
	if(Copy_DCMotor==RIGHT)
	{
		if(Copy_MotorDirecton==CLOCKWISE)
		{
			DIO_u8SetPinValue(RIGHT_MOTOR_PORT,RIGHT_MOTOR_PIN1,HIGH);
			DIO_u8SetPinValue(RIGHT_MOTOR_PORT,RIGHT_MOTOR_PIN2,LOW);

		}
		else if(Copy_MotorDirecton==COUNTERCLOCKWISE)
		{
			DIO_u8SetPinValue(RIGHT_MOTOR_PORT,RIGHT_MOTOR_PIN1,LOW);
			DIO_u8SetPinValue(RIGHT_MOTOR_PORT,RIGHT_MOTOR_PIN2,HIGH);
		}
		else
		{
			Local_ErrorState=1;
		}
	}

	else if(Copy_DCMotor==LEFT)
	{
		if(Copy_MotorDirecton==CLOCKWISE)
		{
			DIO_u8SetPinValue(LEFT_MOTOR_PORT,LEFT_MOTOR_PIN1,HIGH);
			DIO_u8SetPinValue(LEFT_MOTOR_PORT,LEFT_MOTOR_PIN2,LOW);

		}
		else if(Copy_MotorDirecton==COUNTERCLOCKWISE)
		{
			DIO_u8SetPinValue(LEFT_MOTOR_PORT,LEFT_MOTOR_PIN1,LOW);
			DIO_u8SetPinValue(LEFT_MOTOR_PORT,LEFT_MOTOR_PIN2,HIGH);
		}
		else
		{
			Local_ErrorState=1;
		}
	}

	else
	{
		Local_ErrorState=1;
	}


	return Local_ErrorState;
}






u8 DCMOTOR_ON(u8 Copy_DCMOTOR)
{
	u8 Local_ErrorState=0;

	if(Copy_DCMOTOR==LEFT)
	{

#if LEFT_CHANNEL==MOTOR_CHANNELA
		TIMER1_u8SetCompareMatchValue(CHANNELA,Max_COMPARE_MATCH);
#elif LEFT_CHANNEL=MOTOR_CHANNELB
		TIMER1_u8SetCompareMatchValue(CHANNELB,Max_COMPARE_MATCH);
#endif
	}
	else if(Copy_DCMOTOR==RIGHT)
	{
#if RIGHT_CHANNEL==MOTOR_CHANNELA
		TIMER1_u8SetCompareMatchValue(CHANNELA,Max_COMPARE_MATCH);
#elif RIGHT_CHANNEL==MOTOR_CHANNELB
		TIMER1_u8SetCompareMatchValue(CHANNELB,Max_COMPARE_MATCH);
#endif
	}

	else
	{
		Local_ErrorState=1;
	}

	return Local_ErrorState;


}


u8 DCMOTOR_OFF(u8 Copy_DCMOTOR)
{
	u8 Local_ErrorState=0;
	if(Copy_DCMOTOR==LEFT)
	{
#if LEFT_CHANNEL==MOTOR_CHANNELA
		TIMER1_u8SetCompareMatchValue(CHANNELA,Min_COMPARE_MATCH);
#elif LEFT_CHANNEL=MOTOR_CHANNELB
		TIMER1_u8SetCompareMatchValue(CHANNELB,Min_COMPARE_MATCH);
#endif
	}
	else if(Copy_DCMOTOR==RIGHT)
	{
#if RIGHT_CHANNEL==MOTOR_CHANNELA
		TIMER1_u8SetCompareMatchValue(CHANNELA,Min_COMPARE_MATCH);
#elif RIGHT_CHANNEL==MOTOR_CHANNELB
		TIMER1_u8SetCompareMatchValue(CHANNELB,Min_COMPARE_MATCH);
#endif
	}

	else
	{
		Local_ErrorState=1;
	}

	return Local_ErrorState;
}

u8 DCMOTOR_SpeedControl(u16 Copy_Speed,u8 Copy_DCMOTOR)
{

	u8 Local_ErrorState=0;
	if(Copy_Speed<193)
	{
		u16 Local_CompareMatchValue=100*Copy_Speed+815+2600;




		if(Copy_DCMOTOR==LEFT)
		{

#if LEFT_CHANNEL==MOTOR_CHANNELA
			TIMER1_u8SetCompareMatchValue(CHANNELA,Local_CompareMatchValue);
#elif LEFT_CHANNEL=MOTOR_CHANNELB
			TIMER1_u8SetCompareMatchValue(CHANNELB,Local_CompareMatchValue);

#endif
		}
		else if(Copy_DCMOTOR==RIGHT)
		{
#if RIGHT_CHANNEL==MOTOR_CHANNELA
			TIMER1_u8SetCompareMatchValue(CHANNELA,Local_CompareMatchValue);
#elif RIGHT_CHANNEL==MOTOR_CHANNELB
			TIMER1_u8SetCompareMatchValue(CHANNELB,Local_CompareMatchValue);
#endif
		}

		else
		{
			Local_ErrorState=1;
		}
	}
	else
	{
		Local_ErrorState=1;
	}

	return Local_ErrorState;


}








