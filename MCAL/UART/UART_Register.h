/********************************************************************************/
/********************************************************************************/
/*****************       Aathur:Shehab Ahmed Ragaai          ********************/
/*****************       Layer:MCAL                          ********************/
/*****************       SWC:PORT                            ********************/
/*****************       version:1.00                        ********************/
/********************************************************************************/
/********************************************************************************/


#ifndef UART_REGISTER_H_
#define UART_REGISTER_H_
/*--------UART0------------------------------*/
#define UCSR0A    *((volatile u8*)0X2B)
#define UCSR0A_UDRE0       5
#define UCSR0A_TXC0        6
#define UCSR0A_RXC0        7

#define UCSR0B    *((volatile u8*)0X2A)
#define UCSR0B_UCSZN02     2
#define UCSR0B_TXEN0       3
#define UCSR0B_RXEN0       4
#define UCSR0B_UDRIE0      5
#define UCSR0B_TXCIE0      6
#define UCSR0B_RXCIE0      7

#define UCSR0C    *((volatile u8*)0X95)
#define UCSR0C_UCPOL0   0
#define UCSR0C_UCSZ00   1
#define UCSR0C_UCSZ01   2
#define UCSR0C_USBS0	3
#define UCSR0C_UPM00	4
#define UCSR0C_UPM01	5
#define UCSR0C_UMSEL0   6

#define UBRR0L    *((volatile u8*)0X29)
#define UBRR0H    *((volatile u8*)0X90)

#define UDR0      *((volatile u8*)0X2C)


/*--------UART1------------------------------*/
#define UCSR1A *((volatile u8 *)0x9B)
#define UCSR1A_UDRE1	5
#define UCSR1A_TXC1		6
#define UCSR1A_RXC1		7


#define UCSR1B *((volatile u8 *)0x9A)
#define UCSR1B_UCSZ12	2
#define UCSR1B_TXEN1	3
#define UCSR1B_RXEN1	4
#define UCSR1B_UDRIE1	5
#define UCSR1B_TXCIE1	6
#define UCSR1B_RXCIE1	7

#define UCSR1C *((volatile u8 *)0x9D)
#define UCSR1C_UCPOL1	0
#define UCSR1C_UCSZ10	1
#define UCSR1C_UCSZ11	2
#define UCSR1C_USBS1	3
#define UCSR1C_UPM10	4
#define UCSR1C_UPM11	5
#define UCSR1C_UMSEL1	6


#define UBRR1L *((volatile u8 *)0x99)
#define UBRR1H *((volatile u8 *)0x98)
#define UDR1 *((volatile u8 *)0x9C)

#endif /* UART_REGISTER_H_ */
