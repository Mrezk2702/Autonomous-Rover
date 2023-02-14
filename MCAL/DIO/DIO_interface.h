/***************************************************************************/
/***************************************************************************/
/**********  Author: Mohamed Rezk Bayoumi               ********************/
/**********     File: DIO_prg.c                          *******************/
/**********     Date: 25/10/2022                         *******************/
/**********      Version: V.2                            *******************/
/***************************************************************************/
/***************************************************************************/
/***************************************************************************/



#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_


u8 DIO_u8SetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Val);
u8 DIO_u8SetPortValue(u8 Copy_u8Port,u8 Copy_u8PortValue);
u8 DIO_u8GetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 * Copy_u8Result);

/*****************************************************************************************************/
#define HIGH 1
#define LOW 0
/******************************************************************************************************/

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3
#define DIO_PORTE 4
#define DIO_PORTF 5
#define DIO_PORTG 6

/******************************************************************************************************/
#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7



#endif
