/*
 * Timers_config.h
 *
 *  Created on: Nov 9, 2022
 *      Author: Team Members
 */

#ifndef TIMERS_CONFIG_H_
#define TIMERS_CONFIG_H_
/***********************************************Timer0****************************************************************************/
#define TIMER0_MODE                 NORMAL
#define TIMER0_WAVE_FORM            COCSOT
#define TIMER0_PRE_SCALER           TIMERS_PRESCALER_BY_8
#define TIMER0_OVF_INTERRUPT        ENABLE
#define TIMER0_CTC_INTERRUPT        DISABLE

/***********************************************Timer1****************************************************************************/
#define TIMER1_MODE                        FAST_PWM_ICR
#define TIMER1_CHANNELA                    ENABLE
#define TIMER1_CHANNELB                    ENABLE
#define TIMER1_CHANNELC                    ENABLE
#define TIMER1_WAVE_FORM_CHANNELA          COCSOT
#define TIMER1_WAVE_FORM_CHANNELB          COCSOT
#define TIMER1_WAVE_FORM_CHANNELC          DISCONNECT
#define TIMER1_CTC_CHANNELA_INTERRUPT      DISABLE
#define TIMER1_CTC_CHANNELB_INTERRUPT      DISABLE
#define TIMER1_CTC_CHANNELC_INTERRUPT      DISABLE
#define TIMER1_OVF_INTERRUPT               DISABLE
#define TIMER1_PRESCALER          TIMERS_PRESCALAR_BY_8

/************************************************Timer2**************************************************************************/
#define TIMER2_MODE               NORMAL
#define TIMER2_WAVE_FORM          COCSOT
#define TIMER2_PRESCALER          TIMERS_PRESCALAR_BY_8
#define TIMER2_OVF_INTERRUPT      ENABLE
#define TIMER2_CTC_INTERRUPT      DISABLE
/***********************************************Timer3****************************************************************************/

#define TIMER3_MODE                        FAST_PWM_ICR
#define TIMER3_CHANNELA                    ENABLE
#define TIMER3_CHANNELB                    ENABLE
#define TIMER3_CHANNELC                    ENABLE
#define TIMER3_WAVE_FORM_CHANNELA          COCSOT
#define TIMER3_WAVE_FORM_CHANNELB          COCSOT
#define TIMER3_WAVE_FORM_CHANNELC          DISCONNECT
#define TIMER3_CTC_CHANNELA_INTERRUPT      DISABLE
#define TIMER3_CTC_CHANNELB_INTERRUPT      DISABLE
#define TIMER3_CTC_CHANNELC_INTERRUPT      DISABLE
#define TIMER3_OVF_INTERRUPT               DISABLE
#define TIMER3_PRE_SCALER				   TIMERS_PRESCALER_BY_8

#endif /* TIMERS_CONFIG_H_ */
