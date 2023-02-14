/********************************************************************************/
/********************************************************************************/
/*****************       Aathur:Team Members                      ***************/
/*****************       Layer:MCAL                               ***************/
/*****************       SWC:EXTI                                 ***************/
/*****************       Date: 25/10/2022                         ***************/
/*****************       version:2.00                             ***************/
/*****************       Desc:Fixed logical error in ISR          ***************/
/*****************       naming method                            ***************/
/********************************************************************************/
/********************************************************************************/

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_
/*Control Sense Options*/
#define LOW_LEVEL		1
#define ON_CHANGE		2
#define FALLING_EDGE    3
#define RISING_EDGE		4
/*************************************************************************************************/
#define ENABLE          1
#define DISABLE         2
/*************************************************************************************************/
/*External Interrupt Pins*/
#define INT0            0
#define INT1            1
#define INT2            2
#define INT3            3
#define INT4            4
#define INT5            5
#define INT6            6
#define INT7            7
/**************************************************************************************************/
/*Prototype Of Preconfig Functions*/
void EXTI_voidInt0Init(void);
void EXTI_voidInt1Init(void);
void EXTI_voidInt2Init(void); 
void EXTI_voidInt3Init(void);
void EXTI_voidInt4Init(void);
void EXTI_voidInt5Init(void);
void EXTI_voidInt6Init(void);
void EXTI_voidInt7Init(void);
/***************************************************************************************************/
/*Prototype Of Postconfig Functions*/
u8 EXTI_u8Int0CallBackFunc(void(*Copy_pvFunc)(void));
u8 EXTI_u8Int1CallBackFunc(void(*Copy_pvFunc)(void));
u8 EXTI_u8Int2CallBackFunc(void(*Copy_pvFunc)(void));
u8 EXTI_u8Int3CallBackFunc(void(*Copy_pvFunc)(void));
u8 EXTI_u8Int4CallBackFunc(void(*Copy_pvFunc)(void));
u8 EXTI_u8Int5CallBackFunc(void(*Copy_pvFunc)(void));
u8 EXTI_u8Int6CallBackFunc(void(*Copy_pvFunc)(void));
u8 EXTI_u8Int7CallBackFunc(void(*Copy_pvFunc)(void));
u8 EXTI_u8SetIntControlSense(u8 Copy_u8Int,u8 Copy_u8IntControlSense);
u8 EXTI_u8Enable(u8 Copy_U8Int);
u8 EXTI_u8Disable(u8 Copy_U8Int);

#endif
