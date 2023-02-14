/*
 * Timers_private.h
 *
 *  Created on: Nov 9, 2022
 *      Author: mrezk
 */

#ifndef TIMERS_PRIVATE_H_
#define TIMERS_REGISTER_H_
/*Timer 0 ISR pointers*/
static void (*Global_pvFuncTimer0OVF) (void);
static void (*Global_pvFuncTimer0CTC) (void);
/*Timer 1 ISR pointers*/
static void (*Global_pvFuncTimer1OVF)(void)=NULL;
static void (*Global_pvFuncTimer1CTCChannelA)(void)=NULL;
static void (*Global_pvFuncTimer1CTCChannelB)(void)=NULL;
static void (*Global_pvFuncTimer1CTCChannelC)(void)=NULL;
/*Timer 2 ISR pointers*/
static void (*Global_pvFuncTimer2OVF)(void)=NULL;
static void (*Global_pvFuncTimer2CTC)(void)=NULL;
/*Timer 3 ISR pointers*/
static void (*Global_pvFuncTimer3OVF)(void)=NULL;
static void (*Global_pvFuncTimer3CTCChannelA)(void)=NULL;
static void (*Global_pvFuncTimer3CTCChannelB)(void)=NULL;
static void (*Global_pvFuncTimer3CTCChannelC)(void)=NULL;


void __vector_9(void) __attribute__((signal));
void __vector_10(void) __attribute__((signal));
void __vector_12(void) __attribute__((signal));
void __vector_13(void) __attribute__((signal));
void __vector_14(void) __attribute__((signal));
void __vector_15(void) __attribute__((signal));
void __vector_16(void) __attribute__((signal));
void __vector_24(void) __attribute__((signal));
void __vector_26 (void) __attribute__((signal));
void __vector_27 (void) __attribute__((signal));
void __vector_28 (void) __attribute__((signal));
void __vector_29 (void) __attribute__((signal));


#define OK 0
#define NOK 1

#define CHANNELA                            0
#define CHANNELB                            1
#define CHANNELC                            2

#define NORMAL 1
#define PHASE_CORRECT_PWM 2
#define CTC 3
#define FAST_PWM 4
#define FAST_PWM_8BIT 5
#define FAST_PWM_ICR 6
#define PHASE_CORRECT_PWM_8BIT 7
#define PHASE_CORRECT_PWM_ICR 8

#define DISCONNECT 1
#define TOGGLE 2
#define CLEAR 3
#define SET 4
#define COCSOT 5
#define SOCCOT 6
#define COCWUSOCWD 7
#define SOCWUCOCWD 8


#define TIMERS_NO_PRESCALAR            1
#define TIMERS_PRESCALER_BY_8          2
#define TIMERS_PRESCALER_BY_32         3
#define TIMERS_PRESCALER_BY_64         4
#define TIMERS_PRESCALER_BY_128        5
#define TIMERS_PRESCALER_BY_256        6
#define TIMERS_PRESCALER_BY_1024       7
#define TIMERS_EXTERNAL_CLOCK          8
#define TIMERS_EXTERNAL_CLOCK_FALLING  9
#define TIMERS_EXTERNAL_CLOCK_RISING   10

#define ENABLE 1
#define DISABLE 2

#endif
