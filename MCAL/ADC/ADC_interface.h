/********************************************************************************/
/********************************************************************************/
/*****************       Aathur:Team Members                      ***************/
/*****************       Layer:MCAL                               ***************/
/*****************       SWC:ADC                                  ***************/
/*****************       Date: 30/10/2022                         ***************/
/*****************       version:2.00                             ***************/
/*****************                                                ***************/
/*****************                                                ***************/
/********************************************************************************/
/********************************************************************************/
#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_
/*Conversion Channel Options*/
#define ADC_CHANNEL_0  0
#define ADC_CHANNEL_1  1
#define ADC_CHANNEL_2  2
#define ADC_CHANNEL_3  3
#define ADC_CHANNEL_4  4
#define ADC_CHANNEL_5  5
#define ADC_CHANNEL_6  6
#define ADC_CHANNEL_7  7
/*Prototype of Functions*/
void ADC_voidInit(void);
u8 ADC_u8StartConversionSynchronus(u8 Copy_u8channel,u16* copy_u8PuReading);
u8 ADC_u8StartConversionASynchronus(u8 copy_u8channel,void (*copy_PvNotifacation)(void),u16* copy_u8PuReading);
u8 TEMP(u8* Copy_p8TempHistory);
#endif
