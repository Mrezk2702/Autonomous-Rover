/********************************************************************************/
/********************************************************************************/
/*****************       Aathur:Shehab & Rezk                ********************/
/*****************       Layer:MCAL                          ********************/
/*****************       SWC:UART                            ********************/
/*****************       version:1.00                        ********************/
/********************************************************************************/
/********************************************************************************/

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

/*--------UART0------------------------------*/
void UART0_voidInit(void);
u8 UART0_u8SendCharSynch(u8 Copy_u8Data);
u8 UART0_u8ReceiveCharSynch(u8 *Copy_p8ReceiveData);
u8 UART0_u8SendCharASynch(u8 Copy_u8Data,void (*Copy_vSendCharNotification)(void));
u8 UART0_u8ReceiveCharASynch(u8 *Copy_p8ReceiveData,void (*Copy_vRecieveCharNotification)(void));
u8 UART0_u8SendStringSynch(u8*Copy_p8Data);
u8 UART0_u8RecieveStringSynch(u8*Copy_p8Data,u8 Copy_u8DataSize);
u8 UART0_u8SendStringASynch(u8*Copy_p8Data,void (*Copy_vSendStringNotification)(void));
u8 UART0_u8RecieveStringASynch(u8*Copy_p8Data,u8 Copy_u8DataSize,void (*Copy_vRecieveStringNotification)(void));




/*--------UART1------------------------------*/
void UART1_voidInit(void);
u8 UART1_u8SendCharSynch(u8 Copy_u8Data);
u8 UART1_u8ReceiveCharSynch(u8 * Copy_p8ReceiveData);
u8 UART1_u8SendCharAsynch(u8 Copy_u8Data,void (*Copy_vSendCharNotification)(void));
u8 UART1_u8SendStringAsynch(u8 * Copy_p8Data,void (*Copy_vSendStringNotification)(void));
u8 UART1_u8ReceiveCharAsynch(u8 * Copy_p8ReceiveData,void (* Copy_vReceiveCharNotification)(void));
u8 UART1_u8ReceiveStringAsynch(u8 * Copy_p8Data,u8 Copy_u8Size,void (*Copy_vReceiveStringNotification)(void));
u8 UART1_u8SendStringSynch(u8 * Copy_p8Data);
u8 UART1_u8ReceiveStringSynch(u8 * Copy_u8Data,u8 Copy_u8DataSize);
#endif /* UART_INTERFACE_H_ */
