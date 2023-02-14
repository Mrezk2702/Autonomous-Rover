/********************************************************************************/
/********************************************************************************/
/*****************       Aathur:Team Members                      ***************/
/*****************       Layer:HAL                                ***************/
/*****************       SWC:HUMIDITY                             ***************/
/*****************       Date: 30/10/2022                         ***************/
/*****************       version:2.00                             ***************/
/*****************                                                ***************/
/*****************                                                ***************/
/********************************************************************************/
/********************************************************************************/
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"ADC_interface.h"
#include "Humidity_interface.h"
#include "Humidity_config.h"

u8 Humidity_u8Read(u8* Copy_p8HumHistory)
{
    u16 MilliVolt;
    u8 Local_u8ErrorState = 0;
    u8 Local_u8Hum = 0;
    u16 Local_u8Value=0;
    u8 static Local_u8Counter;


if (Copy_p8HumHistory == NULL)
    {
        Local_u8ErrorState = 1;
    }
else
    {

        Local_u8ErrorState=ADC_u8StartConversionSynchronus(HUMID_CHANNEL,&Local_u8Value);
        MilliVolt = (u16)(((u32)Local_u8Value*2560UL)/256UL);

        if (MilliVolt>500)
        {
        Local_u8Hum=(u8)((157UL*(u16)MilliVolt/5000UL)-23);
        }

            else
           {

        	  Local_u8Hum=NULL;

           }


    if(Local_u8Counter == 4)
        {
            Local_u8Counter = 0 ;

        }
    else
        {
    	Copy_p8HumHistory[Local_u8Counter] =Local_u8Hum;
            Local_u8Counter ++;

        }


    }
    return Local_u8ErrorState;



}
