/********************************************************************************/
/********************************************************************************/
/*****************       Aathur:Team Members                      ***************/
/*****************       Layer:HAL                                ***************/
/*****************       SWC:PRESS                                 ***************/
/*****************       Date: 30/10/2022                         ***************/
/*****************       version:2.00                             ***************/
/*****************                                                ***************/
/*****************                                                ***************/
/********************************************************************************/
/********************************************************************************/

#include"STD_TYPES.h"
#include"ADC_interface.h"
#include"PRESSURE_interface.h"
#include "PRESSURE_config.h"



u8 PRESSURE(u8* Copy_p8PressureHistory)
{
    u16 MilliVolt;
    u8 Local_u8ErrorState = 0;
    u8 Local_u8Press= 0;
    u16 Local_u8Value=0;
    u8 static Local_u8Counter;


if (Copy_p8PressureHistory == NULL)
    {
        Local_u8ErrorState = 1;
    }
else
    {




        Local_u8ErrorState=ADC_u8StartConversionSynchronus(PRESS_CHANNEL,&Local_u8Value);
        MilliVolt = (u16)(((u32)Local_u8Value*2560UL)/256UL);
        Local_u8Press=(u8)((250UL*(u16)MilliVolt/5000UL)-25);



    if(Local_u8Counter == 4)
        {
            Local_u8Counter = 0 ;

        }
    else
        {
            Copy_p8PressureHistory[Local_u8Counter] =Local_u8Press;
            Local_u8Counter ++;

        }


    }
    return Local_u8ErrorState;



}


