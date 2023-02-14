/********************************************************************************/
/********************************************************************************/
/*****************       Aathur:Team Members                      ***************/
/*****************       Layer:MCAL                               ***************/
/*****************       SWC:ADC                                 ***************/
/*****************       Date: 30/10/2022                         ***************/
/*****************       version:2.00                             ***************/
/*****************                                                ***************/
/*****************                                                ***************/
/********************************************************************************/
/********************************************************************************/
#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_


/*ADC_VREF Options:1-VREF_OFF
                   2-AVCC
                   3-INTERNAL_2_56 */
#define ADC_VREF       INTERNAL_2_56
/*FREE_RUNNING Options:1-SINGLE_CONVERSION
                       2-FREE_RUNNING  */
#define START_CONVERSION_STATE   SINGLE_CONVERSION
/*ADC_DATASTATE Options:1-BIT_8
                        2-BIT_10 */
#define ADC_DATASTATE    BIT_8
/*/*ADC_VREF Options:1-ADC_PRESCALAR_BY_2
                     2-ADC_PRESCALAR_BY_4
                     3-ADC_PRESCALAR_BY_8
                     4-ADC_PRESCALAR_BY_16
                     5-ADC_PRESCALAR_BY_32
                     6-ADC_PRESCALAR_BY_64
                     7-ADC_PRESCALAR_BY_128*/
#define ADC_PRESCALER    ADC_PRESCALAR_BY_4


#endif
