/*
 * Timers_interface.h
 *
 *  Created on: Nov 9, 2022
 *      Author: Team Members
 */

#ifndef TIMERS_INTERFACE_H_
#define TIMERS_INTERFACE_H_
/*********************************************************TIMER 0***************************************************************/
void Timer0_voidInit(void);
u8 TIMER0_u8SetPreLoadValue(u8 Copy_u8CompareMatchValue);
u8 Timer0_u8SetCompareMatchValue(u8 Copy_u8CompareMatchValue);
u8 Timer0_u8Timer0OVFCallBackFunc(void (*Copy_pvFunc)(void));
u8 Timer0_u8Timer0CTCCallBackFunc(void (*Copy_pvFunc)(void));
u8 Timer0_u8ReadTimerValue(void);
/*********************************************************TIMER 1**************************************************************/
void TIMER1_voidInit(void);
u8 TIMER1_u8SetCompareMatchValue(u8 Copy_u8Channel,u16 Copy_CTCValue);
u8 TIMER1_u8SetICRValue(u16 Copy_ICR1Value);
u8 TIMER1_u8Timer1OVFCallBackFunc(void (*COPY_pvFuncTimer1OVF)(void));
u8 TIMER1_u8Timer1CTCCallBackFunc(u8 Copy_u8Channel,void(*COPY_pvFuncTimer1CTC)(void));

/*********************************************************TIMER 2***************************************************************/
void TIMER2_voidInit(void);
u8 TIMER2_u8Timer2OVFCallBackFunc(void (*COPY_pvFuncTimer2OVF)(void));
u8 TIMER2_u8Timer2CTCCallBackFunc(void (*COPY_pvFuncTimer2CTC)(void));
u8 TIMER2_u8SetCompareMatchValue(u8 Copy_CTCValue);
u8 TIMER2_u8SetOverFlowValue(u8 Copy_OVFValue);
u8 TIMER2_u8TCNT2Read(void);


/*********************************************************TIMER 3***************************************************************/
void TIMER3_voidInit(void);
u8 TIMER3_u8SetCompareMatchValue(u8 Copy_u8Channel,u16 Copy_CTCValue);
u8 TIMER3_u8SetICRValue(u16 Copy_u16ICR3Value);
u8 TIMER3_u8Timer3OVFCallBackFunc(void (*COPY_pvFuncTimer3OVF)(void));
u8 TIMER3_u8Timer3CTCCallBackFunc(u8 Copy_u8Channel,void(*COPY_pvFuncTimer3CTC)(void));

/*******************************************************************************************************************************/

#define CHANNELA                            0
#define CHANNELB                            1
#define CHANNELC                            2




#endif /* TIMERS_INTERFACE_H_ */
