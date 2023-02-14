/********************************************************************************/
/********************************************************************************/
/*****************       Aathur:Team Members                      ***************/
/*****************       Layer:MCAL                               ***************/
/*****************       SWC:UART                                 ***************/
/*****************       Date: 30/10/2022                         ***************/
/*****************       version:2.00                             ***************/
/*****************                                                ***************/
/*****************                                                ***************/
/********************************************************************************/
/********************************************************************************/
#include "STD_TYPES.h"
#include  "BIT_MATH.h"
#include "UART_interface.h"
#include "GPS_private.h"
#include "GPS_config.h"
#include "GPS_interface.h"







u8 GPS_u8Read(GPS_Data * Copy_PsGPSReceive)
{
	u8 Local_u8ErrorState=0;


	if(Copy_PsGPSReceive!=NULL)
	{
		do
		{
			UART0_u8ReceiveCharSynch(&Copy_PsGPSReceive->dollar);
		}
		while(Copy_PsGPSReceive->dollar !='$');

		do
		{
			UART0_u8RecieveStringSynch(Copy_PsGPSReceive->MSG_ID,6);

		}while((Copy_PsGPSReceive->MSG_ID[2]!='G')||(Copy_PsGPSReceive->MSG_ID[3]!='G')||(Copy_PsGPSReceive->MSG_ID[4]!='A'));

			UART0_u8RecieveStringSynch(Copy_PsGPSReceive->Time,11);
            UART0_u8RecieveStringSynch(Copy_PsGPSReceive->Lat,10);
			UART0_u8RecieveStringSynch(Copy_PsGPSReceive->N_S,2);
			UART0_u8RecieveStringSynch(Copy_PsGPSReceive->Long,11);
			UART0_u8RecieveStringSynch(Copy_PsGPSReceive->E_W,2);
			UART0_u8ReceiveCharSynch(&(Copy_PsGPSReceive->PFI));
	}
	else
	{
		Local_u8ErrorState=1;
	}
	return Local_u8ErrorState;

}


