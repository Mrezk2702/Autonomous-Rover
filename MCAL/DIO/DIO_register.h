/*******************************************************************************/
/*******************************************************************************/  
/*****************       Aathur:Shehab Ahmed Ragaai         ********************/   
/*****************       Layer:MCAL                         ********************/    
/*****************       SWC:DIO                            ********************/
/*****************       version:2.00                       ********************/      
/*******************************************************************************/       
/*******************************************************************************/          


#ifndef DIO_REGISTER_H_
#define DIO_REGISTER_H_

#define PORTA  *((volatile u8*) 0x3B)
#define PORTB  *((volatile u8*) 0x38)
#define PORTC  *((volatile u8*) 0x35)
#define PORTD  *((volatile u8*) 0x32)
#define PORTE  *((volatile u8*) 0x23)
#define PORTF  *((volatile u8*) 0x62)
#define PORTG  *((volatile u8*) 0x65)




#define PINA   *((volatile u8*) 0x39)
#define PINB   *((volatile u8*) 0x36)
#define PINC   *((volatile u8*) 0x33)
#define PIND   *((volatile u8*) 0x30)
#define PINE   *((volatile u8*) 0x21)
#define PINF   *((volatile u8*) 0x20)
#define PING   *((volatile u8*) 0x63)

#endif
