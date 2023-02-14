/********************************************************************************/
/********************************************************************************/
/*****************       Aathur:Shehab Ahmed Ragaai          ********************/
/*****************       Layer:MCAL                          ********************/
/*****************       SWC:PORT                            ********************/
/*****************       version:1.00                        ********************/
/********************************************************************************/
/********************************************************************************/
#include"STD_TYPES.h"
#include"PORT_register.h"
#include"PORT_config.h"
#include"PORT_private.h"
#include"PORT_interface.h"

void PORT_voidInit(void)
{
	DDRA=PORTA_DIR;
	DDRB=PORTB_DIR;
	DDRC=PORTC_DIR;
	DDRD=PORTD_DIR;
	DDRE=PORTE_DIR;
	DDRF=PORTF_DIR;
	DDRG=PORTG_DIR;
	
	PORTA=PORTA_INTL;
	PORTB=PORTB_INTL;
	PORTC=PORTC_INTL;
	PORTD=PORTD_INTL;
	PORTE=PORTE_INTL;
	PORTF=PORTF_INTL;
	PORTG=PORTG_INTL;
}
