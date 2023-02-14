#ifndef ADC_PRIVATE_H_
#define ADC_PTIVATE_H_
/*Data State Options*/
#define BIT_10                         1
#define BIT_8                          2
/*Determine Function State Available Or Blocked*/
#define BUSY                           0
#define IDEL                           1
/*ADC VREF Options*/
#define VREF_OFF                       1
#define AVCC 	                       2
#define INTERNAL_2_56                  3
/*Free Running state used OR use Single Conversion */
#define SINGLE_CONVERSION              1
#define FREE_RUNNING                   2

/*Prescaler Options*/
#define     ADC_PRESCALAR_BY_2         1
#define     ADC_PRESCALAR_BY_4         2
#define     ADC_PRESCALAR_BY_8         3
#define     ADC_PRESCALAR_BY_16        4
#define     ADC_PRESCALAR_BY_32        5
#define     ADC_PRESCALAR_BY_64        6
#define     ADC_PRESCALAR_BY_128       7
/*Channel Select Bit Mask*/
#define BIT_MASK                   0b11100000
/*Time Out Value*/
#define TIME_OUT                      500
/*Deceleration OF Global variables And Pointers and ISR compiler directive */
u8 Global_u8state=IDEL;
static void (*Global_PvNotifacation)(void);
static u16 *Global_u16PuReading;
void __vector_21 (void)__attribute((signal));


#endif
