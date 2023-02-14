#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_interface.h"
#include"TIMERS_interface.h"
#include"ULTRASONIC_interface.h"
#include"ULTRASONIC_private.h"
#include"ULTASONIC_config.h"
#include"EXTI_interface.h"
#include<util/delay.h>



u8 Global_u8SensorState;
u16 Global_u8OverFlowCounter=0;
u8 Overflow_Error;

u16*Global_u8Distance=NULL;

void OverFlow_voidISRFunc(void);
void EXTI_voidISRFunc(void);


void UltraSonic_voidInit(void)
{
	Global_u8SensorState=IDEL;

	Overflow_Error = 0U;

	EXTI_u8Int0CallBackFunc(EXTI_voidISRFunc);
	TIMER2_u8Timer2OVFCallBackFunc(OverFlow_voidISRFunc);

}
u8 UltraSonic_u8TrigerAndDistanceRead(u16 *Copy_u8Distance)
{
	u8 Local_u8Error_state=0;

	if(Global_u8SensorState==BUSY)
	{
		Global_u8SensorState=1;
	}
	else
	{
		Global_u8SensorState=BUSY;

		Global_u8Distance=Copy_u8Distance;


		DIO_u8SetPinValue(ULTRASONIC_PORT,ULTRASONIC_PIN,HIGH);
		_delay_us(15);

		DIO_u8SetPinValue(ULTRASONIC_PORT,ULTRASONIC_PIN,LOW);

		TIMER2_u8SetOverFlowValue(0);
		Global_u8OverFlowCounter=0;

	}

	return Local_u8Error_state;
}


void OverFlow_voidISRFunc(void)
{

	Global_u8OverFlowCounter++;


}


void EXTI_voidISRFunc(void)
{
	static u8 Local_u8Counter=0;

	Local_u8Counter++;

	if(Local_u8Counter==1)
	{
		TIMER2_u8SetOverFlowValue(0);
		EXTI_u8SetIntControlSense(INT0,FALLING_EDGE);
	}
	else if(Local_u8Counter==2)
	{
		EXTI_u8SetIntControlSense(INT0,RISING_EDGE);
		Global_u8SensorState=IDEL;


		*Global_u8Distance=TIMER2_u8TCNT2Read();
		*Global_u8Distance=(*Global_u8Distance)+(Global_u8OverFlowCounter*255U);
		*Global_u8Distance=(*Global_u8Distance)/58U;
		/*Correction Due to lattancy Time for interrupt*/
		if(*Global_u8Distance<180)
		{
			*Global_u8Distance=*Global_u8Distance-4;
		}
		else if(*Global_u8Distance>=180)
		{
			*Global_u8Distance=*Global_u8Distance-3;
		}
		Local_u8Counter=0;
		Global_u8OverFlowCounter++;




	}

}


