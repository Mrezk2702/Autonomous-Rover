/********************************************************************************/
/********************************************************************************/
/*****************       Aathur:Shehab & Rezk                ********************/
/*****************       Layer:MCAL                          ********************/
/*****************       SWC:UART                            ********************/
/*****************       version:1.00                        ********************/
/********************************************************************************/
/********************************************************************************/

#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_


#define BIT_1 1
#define BIT_2 2
#define BIT_5 5
#define BIT_6 6
#define BIT_7 7
#define BIT_8 8

#define ENABLE	1
#define DISABLE 2

#define IDLE 0
#define BUSY 1



#define CHAR 1
#define STRING 2



void __vector_19 (void)__attribute((signal));
void __vector_18 (void)__attribute((signal));
void __vector_30 (void) __attribute__((signal));
void __vector_31 (void) __attribute__((signal));







#endif /* UART_PRIVATE_H_ */
