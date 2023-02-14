/********************************************************************************/
/********************************************************************************/
/*****************       Aathur:Shehab & Rezk                ********************/
/*****************       Layer:MCAL                          ********************/
/*****************       SWC:UART                            ********************/
/*****************       version:1.00                        ********************/
/********************************************************************************/
/********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "UART_interface.h"
#include "UART_register.h"
#include "UART_private.h"
#include "UART_config.h"

/*--------UART0 Functions------------------------------*/
/*UART0 variables and pointers*/

u8 UART0_Global_u8SendCharSynchState=IDLE;
u8 UART0_Global_u8RecieveCharSynchState=IDLE;
u8 UART0_Global_u8SendCharASynchState=IDLE;
u8 UART0_Global_u8RecieveCharASynchState=IDLE;

u8 UART0_Global_u8SendStringSynchState=IDLE;
u8 UART0_Global_u8RecieveStringSynchState=IDLE;
u8 UART0_Global_u8SendStringASynchState=IDLE;
u8 UART0_Global_u8RecieveStringASynchState=IDLE;

u8 UART0_Global_u8DataSend;
u8 UART0_Global_u8SendType;
u8 UART0_Global_u8RecieveType;
u8 UART0_Global_u8DataSize;
u8*UART0_Global_u8DataRecieve=NULL;

u8*UART0_Global_u8DataStringSend=NULL;
u8*UART0_Global_u8DataStringRecieve=NULL;

void (*UART0_Global_vSendCharNotification)(void)=NULL;
void (*UART0_Global_vRecieveCharNotification)(void)=NULL;
void (*UART0_Global_vSendStringNotification)(void)=NULL;
void (*UART0_Global_vRecieveStringNotification)(void)=NULL;

void UART0_voidInit(void)
{

#if UART0_STOP_BITS==BIT_1
	CLEAR_BIT(UCSR0C,UCSR0C_USBS0);

#elif UART0_STOP_BITS==BIT_2
	SET_BIT(UCSR0C,UCSR0C_USBS0);

#endif

#if UART0_DATA_SIZE==BIT_5
	CLEAR_BIT(UCSR0C,UCSR0C_UCSZ00);
	CLEAR_BIT(UCSR0C,UCSR0C_UCSZ01);
	CLEAR_BIT(CSR0B,UCSR0B_UCSZN02);
#elif UART0_DATA_SIZE==BIT_6
	SET_BIT(UCSR0C,UCSR0C_UCSZ00);
	CLEAR_BIT(UCSR0C,UCSR0C_UCSZ01);
	CLEAR_BIT(UCSR0B,UCSR0B_UCSZN02);
#elif UART0_DATA_SIZE==BIT_7
	CLEAR_BIT(UCSR0C,UCSR0C_UCSZ00);
	SET_BIT(UCSR0C,UCSR0C_UCSZ01);
	CLEAR_BIT(UCSR0B,UCSR0B_UCSZN02);
#elif UART0_DATA_SIZE==BIT_8
	SET_BIT(UCSR0C,UCSR0C_UCSZ00);
	SET_BIT(UCSR0C,UCSR0C_UCSZ01);
	CLEAR_BIT(UCSR0B,UCSR0B_UCSZN02);
#endif
	/*Set synch*/
	CLEAR_BIT(UCSR0C,UCSR0C_UMSEL0);
	/*Parity Disable*/
	CLEAR_BIT(UCSR0C,UCSR0C_UPM00);
	CLEAR_BIT(UCSR0C,UCSR0C_UPM01);
	/*Baud Rate=9600*/
	UBRR0H=0;
	UBRR0L=51;

#if UART0_RX==ENABLE
	SET_BIT(UCSR0B,UCSR0B_RXEN0);

#elif UART0_RX==DISABLE
	CLEAR_BIT(UCSR0B,UCSR0B_RXEN0);

#endif

#if UART0_TX==ENABLE
	SET_BIT(UCSR0B,UCSR0B_TXEN0);

#elif UART0_TX==DISABLE
	CLEAR_BIT(UCSR0B,UCSR0B_TXEN0);

#endif





}

u8 UART0_u8SendCharSynch(u8 Copy_u8Data)
{
	u8 Local_u8ErrorState=0;

	if(UART0_Global_u8SendCharSynchState==BUSY)
	{
		Local_u8ErrorState=1;
	}
	else
	{
		UART0_Global_u8SendCharSynchState=BUSY;
		while (GET_BIT(UCSR0A,UCSR0A_UDRE0)==0);
		UDR0=Copy_u8Data;
		UART0_Global_u8SendCharSynchState=IDEL;


	}
	return Local_u8ErrorState;
}

u8 UART0_u8ReceiveCharSynch(u8 *Copy_p8ReceiveData)
{
	u8 Local_u8ErrorState=0;

	if(UART0_Global_u8RecieveCharSynchState==BUSY)
	{
		Local_u8ErrorState=1;
	}
	else
	{
		UART0_Global_u8RecieveCharSynchState=BUSY;
		while (GET_BIT(UCSR0A,UCSR0A_RXC0)==0);

		*Copy_p8ReceiveData=UDR0;
		UART0_Global_u8RecieveCharSynchState=IDEL;

	}
	return Local_u8ErrorState;
}


u8 UART0_u8SendCharASynch(u8 Copy_u8Data,void (*Copy_vSendCharNotification)(void))
{
	u8 Local_ErrorState=0;

	if(UART0_Global_u8SendCharASynchState==BUSY || Copy_vSendCharNotification==NULL)
	{
		Local_ErrorState=1;
	}
	else
	{
		UART0_Global_u8SendCharASynchState=BUSY;
		UART0_Global_u8SendType=CHAR;
		UART0_Global_u8DataSend=Copy_u8Data;
		UART0_Global_vSendCharNotification=Copy_vSendCharNotification;
		SET_BIT(UCSR0B,UCSR0B_UDRIE0);
	}

	return Local_ErrorState;
}

u8 UART0_u8ReceiveCharASynch(u8 *Copy_p8ReceiveData,void (*Copy_vRecieveCharNotification)(void))
{
	u8 Local_ErrorState=0;


	if(UART0_Global_u8RecieveCharASynchState==BUSY || Copy_vRecieveCharNotification==NULL || Copy_p8ReceiveData==NULL)
	{
		Local_ErrorState=1;
	}
	else
	{
		UART0_Global_u8RecieveCharASynchState=BUSY;
		UART0_Global_u8RecieveType=CHAR;
		UART0_Global_u8DataRecieve=Copy_p8ReceiveData;
		UART0_Global_vRecieveCharNotification=Copy_vRecieveCharNotification;
		SET_BIT(UCSR0B,UCSR0B_RXCIE0);
	}

	return Local_ErrorState;
}
u8 UART0_u8SendStringSynch(u8*Copy_p8Data)
{
	u8 Local_ErrorState=0;
	u8 Local_Counter=0;
	if(UART0_Global_u8SendStringSynchState==BUSY)
	{
		Local_ErrorState=1;
	}
	else
	{
		UART0_Global_u8SendStringSynchState=BUSY;
		while(Copy_p8Data[Local_Counter]!='\0')
		{
			UART0_u8SendCharSynch(Copy_p8Data[Local_Counter]);
			Local_Counter++;
		}

		UART0_Global_u8SendStringSynchState=IDEL;
	}

	return Local_ErrorState;

}


u8 UART0_u8RecieveStringSynch(u8*Copy_p8Data,u8 Copy_u8DataSize)
{
	u8 Local_ErrorState=0;

	if(UART0_Global_u8RecieveStringSynchState==BUSY)
	{
		Local_ErrorState=1;
	}
	else
	{
		UART0_Global_u8RecieveStringSynchState=BUSY;
		for(u8 Local_Counter=0;Local_Counter<Copy_u8DataSize;Local_Counter++)
		{
			UART0_u8ReceiveCharSynch(Copy_p8Data+Local_Counter);
		}
		UART0_Global_u8RecieveStringSynchState=IDEL;
	}

	return Local_ErrorState;

}

u8 UART0_u8SendStringASynch(u8*Copy_p8Data,void (*Copy_vSendStringNotification)(void))
{
	u8 Local_ErrorState=0;
	UART0_Global_u8SendType=STRING;
	if(UART0_Global_u8SendStringASynchState==BUSY || Copy_vSendStringNotification==NULL)
	{
		Local_ErrorState=1;
	}
	else
	{
		UART0_Global_u8SendCharASynchState=BUSY;
		UART0_Global_u8DataStringSend=Copy_p8Data;
		UART0_Global_vSendStringNotification=Copy_vSendStringNotification;
		SET_BIT(UCSR0B,UCSR0B_UDRIE0);
	}
	return Local_ErrorState;

}

u8 UART0_u8RecieveStringASynch(u8*Copy_p8Data,u8 Copy_u8DataSize,void (*Copy_vRecieveStringNotification)(void))
{
	u8 Local_ErrorState=0;
	UART0_Global_u8RecieveType=STRING;
	if(UART0_Global_u8RecieveStringASynchState==BUSY || Copy_vRecieveStringNotification==NULL || Copy_p8Data==NULL)
	{
		Local_ErrorState=1;
	}
	else
	{
		UART0_Global_u8RecieveStringASynchState=BUSY;
		UART0_Global_u8DataStringRecieve=Copy_p8Data;
		UART0_Global_u8DataSize=Copy_u8DataSize;
		UART0_Global_vRecieveStringNotification=Copy_vRecieveStringNotification;
		SET_BIT(UCSR0B,UCSR0B_RXCIE0);
	}
	return Local_ErrorState;

}




void __vector_19 (void)
{
	static u8 Local_Counter=0;
	if(UART0_Global_u8SendType==CHAR)
	{
		UDR0=UART0_Global_u8DataSend;
		CLEAR_BIT(UCSR0B,UCSR0B_UDRIE0);
		UART0_Global_u8SendCharASynchState=IDEL;
		UART0_Global_vSendCharNotification();
	}
	else if(UART0_Global_u8SendType==STRING)
	{

		if(UART0_Global_u8DataStringSend[Local_Counter]=='\0')
		{
			CLEAR_BIT(UCSR0B,UCSR0B_UDRIE0);
			UART0_Global_u8SendCharASynchState=IDEL;
			UART0_Global_vSendStringNotification();
			Local_Counter=0;

		}
		else
		{
			UDR0=UART0_Global_u8DataStringSend[Local_Counter];
			Local_Counter++;
		}

	}

}

void __vector_18 (void)
{
	static u8 Local_Counter=0;
	if(UART0_Global_u8RecieveType==CHAR)
	{
		*UART0_Global_u8DataRecieve=UDR0;
		CLEAR_BIT(UCSR0B,UCSR0B_RXCIE0);
		UART0_Global_u8RecieveCharASynchState=IDEL;
		UART0_Global_vRecieveCharNotification();
	}
	else if(UART0_Global_u8RecieveType==STRING)
	{
		if(Local_Counter==UART0_Global_u8DataSize-1)
		{
			UART0_Global_u8DataStringRecieve[Local_Counter]=UDR0;
			CLEAR_BIT(UCSR0B,UCSR0B_RXCIE0);
			UART0_Global_u8RecieveStringASynchState=IDEL;
			UART0_Global_vRecieveStringNotification();
			Local_Counter=0;
		}
		else
		{
			UART0_Global_u8DataStringRecieve[Local_Counter]=UDR0;
			Local_Counter++;
		}

	}

}














/*--------UART1 Functions------------------------------*/
/*UART 1 variables and pointers*/
u8 UART1_Global_u8SendCharStateSynch=IDLE;
u8 UART1_Global_u8SendStringStateSynch=IDLE;
u8 UART1_Global_u8ReceiveCharStateSynch=IDLE;
u8 UART1_Global_u8ReceiveStringStateSynch=IDLE;

u8 UART1_Global_u8SendCharStateAsynch=IDLE;
u8 UART1_Global_u8ReceiveCharStateAsynch=IDLE;
u8 UART1_Global_u8SendStringStateAsynch=IDLE;
u8 UART1_Global_u8ReceiveStringStateAsynch=IDLE;

u8 UART1_Global_u8SendData;
u8 UART1_Global_u8ReceiveSize;
u8 * UART1_Global_p8ReceiveData=NULL;
u8 * UART1_Global_p8DataStringSend=NULL;
u8 * UART1_Global_p8DataStringReceive=NULL;

u8 UART1_Global_u8SendType;
u8 UART1_Global_u8ReceiveType;
void (*UART1_Global_vSendCharNotification)(void)=NULL;
void (*UART1_Global_vReceiveCharNotification)(void)=NULL;
void (*UART1_Global_vSendStringNotification)(void)=NULL;
void (*UART1_Global_vReceiveStringNotification)(void)=NULL;


void UART1_voidInit(void)
{

	/*Stop bits selection*/
	/*1-bit stop*/
#if UART1_STOP_BITS == BIT_1
	CLEAR_BIT(UCSR1C,UCSR1C_USBS1);
	/*2-bit stop*/
#elif UART1_STOP_BITS == BIT_2
	SET_BIT(UCSR1C,UCSR1C_USBS1);
#endif

	/*Data Size selection*/

#if UART1_DATA_SIZE == BIT_5
	/*5_bit*/
	CLEAR_BIT(UCSR1C,UCSR1C_UCSZ10);
	CLEAR_BIT(UCSR1C,UCSR1C_UCSZ11);
	CLEAR_BIT(UCSR1B,UCSR1B_UCSZ12);
#elif UART1_DATA_SIZE == BIT_6
	/*6_bit*/
	SET_BIT(UCSR1C,UCSR1C_UCSZ10);
	CLEAR_BIT(UCSR1C,UCSR1C_UCSZ11);
	CLEAR_BIT(UCSR1B,UCSR1B_UCSZ12);
#elif UART1_DATA_SIZE == BIT_7
	/*7_bit*/
	CLEAR_BIT(UCSR1C,UCSR1C_UCSZ10);
	SET_BIT(UCSR1C,UCSR1C_UCSZ11);
	CLEAR_BIT(UCSR1B,UCSR1B_UCSZ12);
#elif UART1_DATA_SIZE == BIT_8
	/*8_bit*/
	SET_BIT(UCSR1C,UCSR1C_UCSZ10);
	SET_BIT(UCSR1C,UCSR1C_UCSZ11);
	CLEAR_BIT(UCSR1B,UCSR1B_UCSZ12);
#endif
	/*Asynchronous Mode*/
	CLEAR_BIT(UCSR1C,UCSR1C_UMSEL1);
	/*Parity Disable*/
	CLEAR_BIT(UCSR1C,UCSR1C_UPM10);
	CLEAR_BIT(UCSR1C,UCSR1C_UPM11);
	/*Baud Rate =9600*/
	UBRR1H=0;
	UBRR1L=51;
#if UART1_TX == DISABLE
	/*TX enable*/
	CLEAR_BIT(UCSR1B,UCSR1B_TXEN1);
#elif UART1_TX == ENABLE
	/*TX disable*/
	SET_BIT(UCSR1B,UCSR1B_TXEN1);
#endif


#if UART1_RX == DISABLE
	/*RX enable*/
	CLEAR_BIT(UCSR1B,UCSR1B_RXEN1);
#elif UART1_RX == ENABLE
	/*RX disable*/
	SET_BIT(UCSR1B,UCSR1B_RXEN1);
#endif

}






u8 UART1_u8SendCharSynch(u8 Copy_u8Data)
{
	u8 Local_u8ErrorState=0;

	if(UART1_Global_u8SendCharStateSynch==BUSY)
	{
		Local_u8ErrorState=1;
	}
	else
	{
		UART1_Global_u8SendCharStateSynch=BUSY;
		while(GET_BIT(UCSR1A,UCSR1A_UDRE1)==0);
		UDR1=Copy_u8Data;
		UART1_Global_u8SendCharStateSynch=IDLE;
	}

	return Local_u8ErrorState;
}


u8 UART1_u8ReceiveCharSynch(u8 * Copy_p8ReceiveData)
{
	u8 Local_u8ErrorState=0;

	if(UART1_Global_u8ReceiveCharStateSynch==BUSY)
	{
		Local_u8ErrorState=1;
	}
	else
	{
		UART1_Global_u8ReceiveCharStateSynch=BUSY;
		while(GET_BIT(UCSR1A,UCSR1A_RXC1)==0)
		{

		}
		*Copy_p8ReceiveData=UDR1;
		UART1_Global_u8ReceiveCharStateSynch=IDLE;
	}
	return Local_u8ErrorState;
}

u8 UART1_u8SendCharAsynch(u8 Copy_u8Data,void (*Copy_vSendCharNotification)(void))
{
	u8 Local_u8ErrorState=0;

	if(UART1_Global_u8SendCharStateAsynch==BUSY||Copy_vSendCharNotification==NULL)
	{
		Local_u8ErrorState=1;
	}
	else
	{
		UART1_Global_u8SendCharStateAsynch=BUSY;
		UART1_Global_u8SendType=CHAR;
		UART1_Global_u8SendData=Copy_u8Data;
		UART1_Global_vSendCharNotification=Copy_vSendCharNotification;
		SET_BIT(UCSR1B,UCSR1B_UDRIE1);


	}
	return Local_u8ErrorState;
}

u8 UART1_u8SendStringAsynch(u8 * Copy_p8Data,void (*Copy_vSendStringNotification)(void))
{
	u8 Local_u8ErrorState=0;
	if(Copy_vSendStringNotification==NULL||Copy_p8Data==NULL||UART1_Global_u8SendStringStateAsynch==BUSY)
	{
		Local_u8ErrorState=1;
	}
	else
	{
		UART1_Global_u8SendStringStateAsynch=BUSY;
		UART1_Global_u8SendType=STRING;
		UART1_Global_p8DataStringSend=Copy_p8Data;
		UART1_Global_vSendStringNotification=Copy_vSendStringNotification;
		SET_BIT(UCSR1B,UCSR1B_UDRIE1);

	}
	return Local_u8ErrorState;

}





u8 UART1_u8ReceiveCharAsynch(u8 * Copy_p8ReceiveData,void (* Copy_vReceiveCharNotification)(void))
{
	u8 Local_u8ErrorState=0;

	if(UART1_Global_u8ReceiveCharStateAsynch==BUSY||Copy_vReceiveCharNotification==NULL||Copy_p8ReceiveData==NULL)
	{
		Local_u8ErrorState=1;
	}
	else
	{
		UART1_Global_u8ReceiveCharStateAsynch=BUSY;
		UART1_Global_u8ReceiveType=CHAR;
		UART1_Global_p8ReceiveData=Copy_p8ReceiveData;
		UART1_Global_vReceiveCharNotification=Copy_vReceiveCharNotification;
		SET_BIT(UCSR1B,UCSR1B_RXCIE1);


	}
	return Local_u8ErrorState;


}


u8 UART1_u8ReceiveStringAsynch(u8 * Copy_p8Data,u8 Copy_u8Size,void (*Copy_vReceiveStringNotification)(void))
{
	u8 Local_u8ErrorState=0;
	if(Copy_vReceiveStringNotification==NULL||Copy_p8Data==NULL||UART1_Global_u8ReceiveStringStateAsynch==BUSY)
	{
		Local_u8ErrorState=1;
	}
	else
	{
		UART1_Global_u8ReceiveStringStateAsynch=BUSY;
		UART1_Global_u8ReceiveType=STRING;
		UART1_Global_p8DataStringReceive=Copy_p8Data;
		UART1_Global_u8ReceiveSize=Copy_u8Size;
		UART1_Global_vReceiveStringNotification=Copy_vReceiveStringNotification;
		SET_BIT(UCSR1B,UCSR1B_RXCIE1);

	}
	return Local_u8ErrorState;

}












void __vector_30 (void)
{
	static u8 Local_Counter=0;
	if(UART1_Global_u8ReceiveType==CHAR)
	{
		*UART1_Global_p8ReceiveData=UDR1;
		CLEAR_BIT(UCSR1B,UCSR1B_RXCIE1);
		UART1_Global_u8ReceiveCharStateAsynch=IDLE;
		UART1_Global_vReceiveCharNotification();
	}
	else if(UART1_Global_u8ReceiveType==STRING)
	{
		if(Local_Counter==UART1_Global_u8ReceiveSize-1)
		{
			UART1_Global_p8DataStringReceive[Local_Counter]=UDR1;
			CLEAR_BIT(UCSR1B,UCSR1B_RXCIE1);
			UART1_Global_u8ReceiveStringStateAsynch=IDLE;
			UART1_Global_vReceiveStringNotification();
			Local_Counter=0;
		}
		else
		{
			UART1_Global_p8DataStringReceive[Local_Counter]=UDR1;
			Local_Counter++;
		}
	}
}
void __vector_31 (void)
{
	static u8 Local_Counter=0;
	if(UART1_Global_u8SendType==CHAR)
	{
		UDR1=UART1_Global_u8SendData;
		UART1_Global_u8SendCharStateAsynch=IDLE;
		CLEAR_BIT(UCSR1B,UCSR1B_UDRIE1);
		UART1_Global_vSendCharNotification();
	}
	else if(UART1_Global_u8SendType==STRING)
	{
		if(UART1_Global_p8DataStringSend=='\0')
		{
			CLEAR_BIT(UCSR1B,UCSR1B_UDRIE1);
			UART1_Global_u8SendStringStateAsynch=IDLE;
			UART1_Global_vSendStringNotification();
			Local_Counter=0;
		}
		else
		{
			UDR1=UART1_Global_p8DataStringSend[Local_Counter];
			Local_Counter++;
		}
	}
}


u8 UART1_u8SendStringSynch(u8 * Copy_p8Data)
{
	u8 Local_u8ErrorState=0;
	if(UART1_Global_u8SendStringStateSynch==BUSY)
	{
		Local_u8ErrorState=1;
	}
	else if(UART1_Global_u8SendStringStateSynch==IDLE)
	{
		UART1_Global_u8SendStringStateSynch=BUSY;
		u8 Local_u8Counter=0;
		while(Copy_p8Data[Local_u8Counter]!='\0')
		{
			UART1_u8SendCharSynch(Copy_p8Data[Local_u8Counter]);
			Local_u8Counter++;
		}
		UART1_Global_u8SendStringStateSynch=IDLE;
	}
	return Local_u8ErrorState;
}


u8 UART1_u8ReceiveStringSynch(u8 * Copy_u8Data,u8 Copy_u8DataSize)
{
	u8 Local_u8ErrorState=0;
	if(UART1_Global_u8ReceiveStringStateSynch==BUSY)
	{
		Local_u8ErrorState=1;
	}
	else if(UART1_Global_u8ReceiveStringStateSynch==IDLE)
	{
		UART1_Global_u8ReceiveStringStateSynch=BUSY;
		for(u8 Local_u8Counter=0;Local_u8Counter<Copy_u8DataSize;Local_u8Counter++)
		{
			UART1_u8ReceiveCharSynch(Copy_u8Data+Local_u8Counter);

		}
		UART1_Global_u8ReceiveStringStateSynch=IDLE;
	}
	return Local_u8ErrorState;
}





