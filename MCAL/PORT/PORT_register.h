/********************************************************************************/
/********************************************************************************/
/*****************       Aathur:Shehab Ahmed Ragaai          ********************/
/*****************       Layer:MCAL                          ********************/
/*****************       SWC:PORT                            ********************/
/*****************       version:1.00                        ********************/
/********************************************************************************/
/********************************************************************************/

#ifndef PORT_REGISTER_H_
#define PORT_REGISTER_H_

#define DDRA     *((volatile u8*)0x3A)
#define DDRB     *((volatile u8*)0x37)
#define DDRC     *((volatile u8*)0x34)
#define DDRD     *((volatile u8*)0x31)
#define DDRE     *((volatile u8*)0x22)
#define DDRF     *((volatile u8*)0x61)
#define DDRG     *((volatile u8*)0x64)


#define PORTA     *((volatile u8*)0x3B)
#define PORTB     *((volatile u8*)0x38)
#define PORTC     *((volatile u8*)0x35)
#define PORTD     *((volatile u8*)0x32)
#define PORTE     *((volatile u8*)0x23)
#define PORTF     *((volatile u8*)0x62)
#define PORTG     *((volatile u8*)0x65)



#endif



