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

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"ADC_register.h"
#include"ADC_private.h"
#include"ADC_config.h"
#include"ADC_interface.h"


void ADC_voidInit(void)
{

	/*Voltage reference selection*/
#if ADC_VREF == VREF_OFF
	/*AREF, internal VRef turned off*/

	/*Clear  REFS0*/
	CLEAR_BIT(ADMUX,ADMUX_REFS0);
	/*Clear  REFS1*/
	CLEAR_BIT(ADMUX,ADMUX_REFS1);

#elif ADC_VREF == AVCC
	/*AVCC with external capacitor at AREF pin*/

	/*Set  REFS0*/
	SET_BIT(ADMUX,ADMUX_REFS0);
	/*Clear  REFS1*/
	CLEAR_BIT(ADMUX,ADMUX_REFS1);


#elif ADC_VREF == INTERNAL_2_56

	/* Internal 2.56V Voltage Reference
	 *  with external capacitor at AREF pin*/
	/*Set  REFS0*/
	SET_BIT(ADMUX,ADMUX_REFS0);
	/*Set  REFS1*/
	SET_BIT(ADMUX,ADMUX_REFS1);
#endif

	/*ADC Left/Right adjust selection*/
#if ADC_DATASTATE == BIT_10
	/*Clear ADLAR*/
	CLEAR_BIT(ADMUX,ADMUX_ADLAR);
#elif ADC_DATASTATE == BIT_8

	/*Set ADLAR*/
	SET_BIT(ADMUX,ADMUX_ADLAR);

#endif
	/*Set division factor between the XTAL frequency and the input clock to the
ADC*/
#if ADC_PRESCALER==ADC_PRESCALAR_BY_2
	/*Division by 2*/
	SET_BIT(ADCSRA,ADCSRA_ADPS0);
	CLEAR_BIT(ADCSRA,ADCSRA_ADPS1);
	CLEAR_BIT(ADCSRA,ADCSRA_ADPS2);

#elif 	ADC_PRESCALER==ADC_PRESCALAR_BY_4
	/*Division by 4*/
	CLEAR_BIT(ADCSRA,ADCSRA_ADPS0);
	SET_BIT(ADCSRA,ADCSRA_ADPS1);
	CLEAR_BIT(ADCSRA,ADCSRA_ADPS2);
#elif 	ADC_PRESCALER==ADC_PRESCALAR_BY_8
	/*Division by 8*/
	SET_BIT(ADCSRA,ADCSRA_ADPS0);
	SET_BIT(ADCSRA,ADCSRA_ADPS1);
	CLEAR_BIT(ADCSRA,ADCSRA_ADPS2);
#elif 	ADC_PRESCALER==ADC_PRESCALAR_BY_16
	/*Division by 16*/
	CLEAR_BIT(ADCSRA,ADCSRA_ADPS0);
	CLEAR_BIT(ADCSRA,ADCSRA_ADPS1);
	SET_BIT(ADCSRA,ADCSRA_ADPS2);
	/*Division by 32*/
#elif 	ADC_PRESCALER==ADC_PRESCALAR_BY_32
	SET_BIT(ADCSRA,ADCSRA_ADPS0);
	CLEAR_BIT(ADCSRA,ADCSRA_ADPS1);
	SET_BIT(ADCSRA,ADCSRA_ADPS2);
	/*Division by 64*/
#elif 	ADC_PRESCALER==ADC_PRESCALAR_BY_64
	CLEAR_BIT(ADCSRA,ADCSRA_ADPS0);
	SET_BIT(ADCSRA,ADCSRA_ADPS1);
	SET_BIT(ADCSRA,ADCSRA_ADPS2);
	/*Division by 128*/
#elif 	ADC_PRESCALER==ADC_PRESCALAR_BY_128
	SET_BIT(ADCSRA,ADCSRA_ADPS0);
	SET_BIT(ADCSRA,ADCSRA_ADPS1);
	SET_BIT(ADCSRA,ADCSRA_ADPS2);
#endif

	/*Single conversion mode*/
#if START_CONVERSION_STATE==SINGLE_CONVERSION
	/*Clear ADFT bit*/
	CLEAR_BIT(ADCSRA,ADCSRA_ADFR);
	/*Free running mode*/
#elif START_CONVERSION_STATE==FREE_RUNNING
	/*Set ADFT Bit*/
	SET_BIT(ADCSRA,ADCSRA_ADFR);

#endif

	/*ADC Peripheral enable*/
	SET_BIT(ADCSRA,ADCSRA_ADEN);
}

/*Starting ADC Conversion with Poling Technique*/
u8 ADC_u8StartConversionSynchronus(u8 Copy_u8channel,u16* copy_u16PuReading)
{
	u8 Local_u8ErrorState=0;
	u32 Local_u32Counter=0;
	/*Check if Function Available or blocked */
	if(Global_u8state==BUSY)
	{
		Local_u8ErrorState=1;
	}
	else
	{
		Global_u8state=BUSY;
		if(Copy_u8channel<=ADC_CHANNEL_7)
		{
		/*Set the required channel into the MUX bits in ADMUX Register*/
		ADMUX&= BIT_MASK;
		ADMUX|= Copy_u8channel;
		}
		else
		{
			Local_u8ErrorState=1;
		}
		/*ADC Start Conversion*/
		SET_BIT(ADCSRA, ADCSRA_ADSC);


		/*Polling until the conversion is complete OR TIME OUT*/
		while(GET_BIT(ADCSRA, ADCSRA_ADIF) == 0 && Local_u32Counter<TIME_OUT)
		{
			Local_u32Counter++;
		}

		if(Local_u32Counter==TIME_OUT)
		{
			Local_u8ErrorState=1;
		}

		else
		{

			/*Conversion completed*/

#if ADC_DATASTATE==BIT_10
			*copy_u16PuReading=ADCL;

#elif ADC_DATASTATE==BIT_8
			*copy_u16PuReading=ADCH;
#endif

			/*Clear the flag*/
			SET_BIT(ADCSRA, ADCSRA_ADIF);
			/*Make Start Conversion Function Available*/
			Global_u8state=IDEL;

		}
	}


	return Local_u8ErrorState;

}


/*Starting ADC Conversion with Interrupt technique*/
u8 ADC_u8StartConversionASynchronus(u8 Copy_u8channel,void (*copy_PvNotifacation)(void),u16* copy_u16PuReading)
{
	u8 Local_u8ErrorState=0;
	/*Check if Function Available or blocked */
	if(Global_u8state==BUSY)
	{
		Local_u8ErrorState=1;
	}
	else
	{
		/*Make Start Conversion Function Block*/
		Global_u8state=BUSY;

		/*Conversion channel select*/
		if(Copy_u8channel<=ADC_CHANNEL_7)
		{
			ADMUX&=BIT_MASK;
			ADMUX|=Copy_u8channel;
		}
		else
		{
			Local_u8ErrorState=1;

		}

		/*Assign Notification address to Global Address that will execute in ISR*/
		if(copy_PvNotifacation!=NULL)
		{
			Global_PvNotifacation=copy_PvNotifacation;
		}
		else
		{
			Local_u8ErrorState=1;
		}
		/*Assign Address of Receive Variable in Global Pointer to be used in ISR*/
		Global_u16PuReading=copy_u16PuReading;

		/* ADC Conversion Complete Interrupt Enable*/
		SET_BIT(ADCSRA,ADCSRA_ADIE);

		/*ADC Start Conversion*/
		SET_BIT(ADCSRA,ADCSRA_ADSC);
	}

	return Local_u8ErrorState;


}


/* ISR is the Function that will be  Execute when the Interrupt of ADC Complete Conversion is Fired*/
void __vector_21 (void)
{
#if(ADC_DATASTATE==BIT_10)

	*Global_u16PuReading=ADCL;


#elif(ADC_DATASTATE==BIT_8)

	*Global_u16PuReading=ADCH;


#endif

	/*Execute Notification Function*/
	Global_PvNotifacation();
	/*Make Start Conversion Function Available*/
	Global_u8state=IDEL;


}



