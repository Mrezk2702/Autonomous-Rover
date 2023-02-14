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

#ifndef EXTI_REGISTER_H_
#define EXTI_REGISTER_H_

#define EICRA       *((volatile u8*)0x6A)
#define EICRA_ISC00  0
#define EICRA_ISC01  1
#define EICRA_ISC10  2
#define EICRA_ISC11  3
#define EICRA_ISC20  4
#define EICRA_ISC21  5
#define EICRA_ISC30  6
#define EICRA_ISC31  7


#define EICRB       *((volatile u8*)0x5A)

#define EICRB_ISC40  0
#define EICRB_ISC41  1
#define EICRB_ISC50  2
#define EICRB_ISC51  3
#define EICRB_ISC60  4
#define EICRB_ISC61  5
#define EICRB_ISC70  6
#define EICRB_ISC71  7


#define EIMSK       *((volatile u8*)0x59)

#define EIMSK_INT0	 0
#define EIMSK_INT1	 1
#define EIMSK_INT2	 2
#define EIMSK_INT3	 3
#define EIMSK_INT4	 4
#define EIMSK_INT5	 5
#define EIMSK_INT6	 6
#define EIMSK_INT7	 7


#define EIFR       *((volatile u8*)0x58)



#endif
