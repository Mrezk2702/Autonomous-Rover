/***************************************************************************/
/***************************************************************************/
/**********  Author: Mohamed Rezk Bayoumi               ********************/
/**********     File: DIO_prg.c                          *******************/
/**********     Date: 25/10/2022                         *******************/
/**********      Version: V.2                            *******************/
/*****       Desc: Fixed a logical in get pin value      *******************/
/***************************************************************************/
/***************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include"DIO_register.h"
#include "DIO_private.h"
#include "DIO_interface.h"


u8 DIO_u8SetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Val)
{
	u8 	Local_u8ErrorState=0;

	
	if((Copy_u8Port<DIO_PORTA)||(Copy_u8Port>DIO_PORTG))
	{
		Local_u8ErrorState=WRONG_PORT;
		return Local_u8ErrorState;
		
		
	}
	else if ((Copy_u8Pin<DIO_PIN0)||(Copy_u8Pin>DIO_PIN7))
	{
		    Local_u8ErrorState=WRONG_PIN;
		    return Local_u8ErrorState;
	}
	else if(Copy_u8Port==DIO_PORTG&&Copy_u8Pin>DIO_PIN4)
	{
		Local_u8ErrorState=WRONG_PIN;
		return Local_u8ErrorState;
	}
	else
	{
		if (HIGH==Copy_u8Val)
			{
			switch ( Copy_u8Port)
			{
				case DIO_PORTA:
				{
				SET_BIT(PORTA,Copy_u8Pin);
				break;
				}
			case DIO_PORTB:
			{
				SET_BIT(PORTB,Copy_u8Pin);
				break;
			}
			case DIO_PORTC:
			{
				SET_BIT(PORTC,Copy_u8Pin);
				break;
			}
			case DIO_PORTD:
			{	
				SET_BIT(PORTD,Copy_u8Pin);
				break;
			}
			case DIO_PORTE:
			{	
				SET_BIT(PORTE,Copy_u8Pin);
				break;
			}
			case DIO_PORTF:
			{	
				SET_BIT(PORTF,Copy_u8Pin);
				break;
			}
			case DIO_PORTG:
			{	
				SET_BIT(PORTG,Copy_u8Pin);
				break;
			}
			
			default:;
				}	
		}
	else if(Copy_u8Val==LOW)
	{
		switch ( Copy_u8Port)
		{
			case DIO_PORTA:
			{
				CLEAR_BIT(PORTA,Copy_u8Pin);
				break;
			}
			case DIO_PORTB:
			{
				CLEAR_BIT(PORTB,Copy_u8Pin);
				break;
			}
			case DIO_PORTC:
			{
				CLEAR_BIT(PORTC,Copy_u8Pin);
				break;
			}
			case DIO_PORTD:
			{	
				CLEAR_BIT(PORTD,Copy_u8Pin);
				break;
			}
			case DIO_PORTE:
			{	
				CLEAR_BIT(PORTE,Copy_u8Pin);
				break;
			}
			case DIO_PORTF:
			{	
				CLEAR_BIT(PORTF,Copy_u8Pin);
				break;
			}case DIO_PORTG:
			{	
				CLEAR_BIT(PORTG,Copy_u8Pin);
				break;
			}
		
			default:;
		}	
		}
}
	return Local_u8ErrorState;
}















u8 DIO_u8SetPortValue(u8 Copy_U8Port,u8 Copy_U8PortValue)
{
	u8 Local_u8ErrorState=OK;
	
	if(Copy_U8Port<DIO_PORTA||Copy_U8Port>DIO_PORTG)
	{
		Local_u8ErrorState=WRONG_PORT;
		return Local_u8ErrorState;
	}
	else if(Copy_U8PortValue>0xff||Copy_U8PortValue<0x00)
	{
		Local_u8ErrorState=PORT_OV;
		return Local_u8ErrorState;
	}
	else
	{
		switch(Copy_U8Port)
		{
			case DIO_PORTA:
			PORTA=Copy_U8PortValue;
			break;		
			case DIO_PORTB:
			PORTB=Copy_U8PortValue;
			break;
			case DIO_PORTC:
			PORTC=Copy_U8PortValue;
			break;
			case DIO_PORTD:
			PORTD=Copy_U8PortValue;
			break;
			case DIO_PORTE:
			PORTE=Copy_U8PortValue;
			break;
			case DIO_PORTF:
			PORTF=Copy_U8PortValue;
			break;
			case DIO_PORTG:
			PORTG=Copy_U8PortValue;
			break;
			default:
			break; /*do nothing*/
			
			
		}
	}
	return Local_u8ErrorState;
}




u8 DIO_u8GetPinValue(u8 Copy_U8Port,u8 Copy_U8Pin,u8 * Copy_U8Result)
{
	u8 Local_u8ErrorState=OK;
	if(Copy_U8Port>DIO_PORTG||Copy_U8Port<DIO_PORTA)
	{
		Local_u8ErrorState=WRONG_PORT;
		return Local_u8ErrorState;
	}
	else if(Copy_U8Pin>DIO_PIN7||Copy_U8Pin<DIO_PIN0)
	{
		Local_u8ErrorState=WRONG_PIN;
		return Local_u8ErrorState;
	}
	else if(Copy_U8Port==PORTG&&Copy_U8Pin>DIO_PIN4)
	{
		Local_u8ErrorState=WRONG_PIN;
		return Local_u8ErrorState;
	}
	else
	{
		switch(Copy_U8Port)
		{
			case DIO_PORTA:
			*Copy_U8Result=GET_BIT(PINA,Copy_U8Pin);
			break;
			case DIO_PORTB:
			*Copy_U8Result=GET_BIT(PINB,Copy_U8Pin);
			break;
			case DIO_PORTC:
			*Copy_U8Result=GET_BIT(PINC,Copy_U8Pin);
			break;
			case DIO_PORTD:
			*Copy_U8Result=GET_BIT(PIND,Copy_U8Pin);
			break;
			case DIO_PORTE:
			*Copy_U8Result=GET_BIT(PINE,Copy_U8Pin);
			break;
			case DIO_PORTF:
			*Copy_U8Result=GET_BIT(PINF,Copy_U8Pin);
			break;
			case DIO_PORTG:
			*Copy_U8Result=GET_BIT(PING,Copy_U8Pin);
			break;
			default:
			break; /*do nothing*/
		}
	}
	return Local_u8ErrorState;
}
