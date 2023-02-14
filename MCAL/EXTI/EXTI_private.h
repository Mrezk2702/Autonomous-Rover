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

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

#define OK  0
#define NOK 1


/*Global Pointers to Functions*/
static void (*Global_pvFuncInt0)(void)=NULL;
static void (*Global_pvFuncInt1)(void)=NULL;
static void (*Global_pvFuncInt2)(void)=NULL;
static void (*Global_pvFuncInt3)(void)=NULL;
static void (*Global_pvFuncInt4)(void)=NULL;
static void (*Global_pvFuncInt5)(void)=NULL;
static void (*Global_pvFuncInt6)(void)=NULL;
static void (*Global_pvFuncInt7)(void)=NULL;

/*****************************************************************************************************/

/*Compiler Directive That Deal with Linker Optimizer To keep ISR And Not Remove It*/
void __vector_1 (void) __attribute__((signal));
void __vector_2 (void)__attribute__((signal));
void __vector_3 (void)__attribute__((signal));
void __vector_4 (void)__attribute__((signal));
void __vector_5 (void) __attribute__((signal));
void __vector_6 (void)__attribute__((signal));
void __vector_7 (void) __attribute__((signal));
void __vector_8 (void)__attribute__((signal));

#endif
