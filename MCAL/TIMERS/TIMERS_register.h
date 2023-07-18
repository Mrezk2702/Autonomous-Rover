/*
 * Timers_register.h
 *
 *  Created on: Nov 9, 2022
 *      Author: Team Members
 */

#ifndef TIMERS_REGISTER_H_
#define TIMERS_REGISTER_H_

/***********************************************************Timer 0 Registers*******************************************************/
/*TCCR0 Register*/
#define TCCR0 *((volatile u8 *) 0x53)
#define TCCR0_CS00 0
#define TCCR0_CS01 1
#define TCCR0_CS02 2
#define TCCR0_WGM01 3
#define TCCR0_COM00 4
#define TCCR0_COM01 5
#define TCCR0_WGM00 6
#define TCCR0_FOC0 7

#define  ASSR *((volatile u8 *) 0x50)
#define ASSR_AS0 3
/*TCNT0*/
#define TCNT0 *((volatile u8 *) 0x52)
#define OCR0 *((volatile u8 *) 0x51)




/*Timer 0 register end*/

/******************************************Timer 1 Registers***************************************************************************/
#define TCCR1A     *((volatile u8*)0x4F)
#define TCCR1A_WGM10     0
#define TCCR1A_WGM11     1
#define TCCR1A_COM1C0    2
#define TCCR1A_COM1C1    3
#define TCCR1A_COM1B0    4
#define TCCR1A_COM1B1    5
#define TCCR1A_COM1A0    6
#define TCCR1A_COM1A1    7

#define TCCR1B     *((volatile u8*)0x4E)
#define TCCR1B_CS10     0
#define TCCR1B_CS11     1
#define TCCR1B_CS12     2
#define TCCR1B_WGM12    3
#define TCCR1B_WGM13    4
#define TCCR1B_ICES1    6
#define TCCR1B_ICNC1    7


#define TCNT1L     *((volatile u8*)0x4C)
#define TCNT1H     *((volatile u8*)0x4H)
#define OCR1AL     *((volatile u8*)0x4A)
#define OCR1AH     *((volatile u8*)0x4B)
#define OCR1BL     *((volatile u8*)0x48)
#define OCR1BH     *((volatile u8*)0x49)
#define OCR1CL     *((volatile u8*)0x78)
#define OCR1CH     *((volatile u8*)0x79)
#define ICR1L      *((volatile u8*)0x46)
#define ICR1H      *((volatile u8*)0x47)

#define ETIMSK     *((volatile u8*)0x7D)
#define ETIMSK_OCIE1C 0


/***********************************************************Timer 2 Registers*******************************************************/
#define TCCR2   *((volatile u8*)0x45)
#define TCCR2_CS20   0
#define TCCR2_CS21   1
#define TCCR2_CS22   2
#define TCCR2_WGM21  3
#define TCCR2_COM20  4
#define TCCR2_COM21  5
#define TCCR2_WGM20  6
#define TCCR2_FOC2   7

#define TCNT2   *((volatile u8*)0x44)
#define OCR2    *((volatile u8*)0x43)
#define TIMSK   *((volatile u8*)0x57) // Common Register between Timer2 and Timer1
#define TIMSK_TOIE0   0
#define TIMSK_OCIE0   1
#define TIMSK_TOIE1   2
#define TIMSK_OCIE1B  3
#define TIMSK_OCIE1A  4
#define TIMSK_TICIE1  5
#define TIMSK_TOIE2   6
#define TIMSK_OCIE2   7
#define TIFR   *((volatile u8*)0x56)








/***********************************************************Timer 3 Registers*******************************************************/
/*timer 3 control register A*/
#define TCCR3A *((volatile u8 *) 0x8B)
#define TCCR3A_COM3A1 7
#define TCCR3A_COM3A0 6
#define TCCR3A_COM3B1 5
#define TCCR3A_COM3B0 4
#define TCCR3A_COM3C1 3
#define TCCR3A_COM3C0 2
#define TCCR3A_WGM31  1
#define TCCR3A_WGM30  0

/*timer 3 control register B*/
#define TCCR3B *((volatile u8 *) 0x8A)
#define TCCR3B_ICNC3  7
#define TCCR3B_ICES3  6
#define TCCR3B_WGM33  4
#define TCCR3B_WGM32  3
#define TCCR3B_CS32   2
#define TCCR3B_CS31   1
#define TCCR3B_CS30   0



#define ETIMSK_TICIE3 5
#define ETIMSK_OCIE3A 4
#define ETIMSK_OCIE3B 3
#define ETIMSK_TOIE3  2
#define ETIMSK_OCIE3C 1
#define ETIMSK_OCIE1C 0

#define OCR3AH *((volatile u8 *) 0x87)
#define OCR3AL *((volatile u8 *) 0x86)

#define OCR3BH *((volatile u8 *) 0x85)
#define OCR3BL *((volatile u8 *) 0x84)

#define OCR3CH *((volatile u8 *) 0x83)
#define OCR3CL *((volatile u8 *) 0x82)

#define ICR3H *((volatile u8 *)0x81)
#define ICR3L *((volatile u8 *)0x80)




/*Timer 3 register end*/






#endif /* TIMERS_REGISTER_H_ */
