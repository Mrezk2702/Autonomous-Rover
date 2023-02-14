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

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"EXTI_config.h"
#include"EXTI_private.h"
#include"EXTI_register.h"
#include"EXTI_interface.h"


void EXTI_voidInt0Init(void)
{
	/*Set Control Sense*/
#if INT0_CONTROL_SENSE==LOW_LEVEL
	/*Set Control Sense to Low Level*/
	CLEAR_BIT(EICRA,EICRA_ISC00);
	CLEAR_BIT(EICRA,EICRA_ISC01);


#elif INT0_CONTROL_SENSE==FALLING_EDGE
	/*Set Control Sense to Falling Edge*/
	CLEAR_BIT(EICRA,EICRA_ISC00);
	SET_BIT(EICRA,EICRA_ISC01);


#elif  INT0_CONTROL_SENSE==RISING_EDGE
	/*Set Control Sense to Rising Edge*/
	SET_BIT(EICRA,EICRA_ISC00);
	SET_BIT(EICRA,EICRA_ISC01);



#endif

	/*Enable OR Disable Peripheral Interrupt*/

#if INT1_PIE==ENABLE
	/*Enable Peripheral Interrupt*/
	SET_BIT(EIMSK,EIMSK_INT0);



#elif INT1_PIE==DISABLE
	/*Disable Peripheral Interrupt*/
	CLEAR_BIT(EIMSK,EIMSK_INT0);



#endif
}

void EXTI_voidInt1Init(void)
{
	/*Set Control Sense*/
#if INT1_CONTROL_SENSE==LOW_LEVEL
	/*Set Control Sense to Low Level*/
	CLEAR_BIT(EICRA,EICRA_ISC10);
	CLEAR_BIT(EICRA,EICRA_ISC11);


#elif INT1_CONTROL_SENSE==FALLING_EDGE
	/*Set Control Sense to Falling Edge*/
	CLEAR_BIT(EICRA,EICRA_ISC10);
	SET_BIT(EICRA,EICRA_ISC11);


#elif  INT1_CONTROL_SENSE==RISING_EDGE
	/*Set Control Sense to Rising Edge*/
	SET_BIT(EICRA,EICRA_ISC10);
	SET_BIT(EICRA,EICRA_ISC11);



#endif

	/*Enable OR Disable Peripheral Interrupt*/

#if INT1_PIE==ENABLE
	/*Enable Peripheral Interrupt*/
	SET_BIT(EIMSK,EIMSK_INT1);



#elif INT1_PIE==DISABLE
	/*Disable Peripheral Interrupt*/
	CLEAR_BIT(EIMSK,EIMSK_INT1);



#endif



}

void EXTI_voidInt2Init(void)
{ /*Set Control Sense*/
#if INT2_CONTROL_SENSE==LOW_LEVEL
	/*Set Control Sense to Low Level*/
	CLEAR_BIT(EICRA,EICRA_ISC20);
	CLEAR_BIT(EICRA,EICRA_ISC21);


#elif INT2_CONTROL_SENSE==FALLING_EDGE
	/*Set Control Sense to Falling Edge*/
	CLEAR_BIT(EICRA,EICRA_ISC20);
	SET_BIT(EICRA,EICRA_ISC21);

#elif INT2_CONTROL_SENSE==RISSING_EDGE
	/*Set Control Sense to Rising Edge*/
	SET_BIT(EICRA,EICRA_ISC20);
	SET_BIT(EICRA,EICRA_ISC21);

#endif

	/*Enable OR Disable Peripheral Interrupt*/
#if  INT2_PIE==ENABLE
	/*Enable Peripheral Interrupt*/
	SET_BIT(EIMSK,EIMSK_INT2);

#elif  INT2_PIE==DISABLE
	/*Disable Peripheral Interrupt*/
	CLERAR(EIMSK,EIMSK_INT2);

#endif

}


void EXTI_voidInt3Init(void)
{
	/*Set Control Sense*/
#if INT3_CONTROL_SENSE==LOW_LEVEL
	/*Set Control Sense to Low Level*/
	CLEAR_BIT(EICRA,EICRA_ISC30);
	CLEAR_BIT(EICRA,EICRA_ISC31);


#elif INT3_CONTROL_SENSE==FALLING_EDGE
	/*Set Control Sense to Falling Edge*/
	CLEAR_BIT(EICRA,EICRA_ISC30);
	SET_BIT(EICRA,EICRA_ISC31);


#elif  INT3_CONTROL_SENSE==RISING_EDGE
	/*Set Control Sense to Rising Edge*/
	SET_BIT(EICRA,EICRA_ISC30);
	SET_BIT(EICRA,EICRA_ISC31);



#endif

	/*Enable OR Disable Peripheral Interrupt*/

#if INT3_PIE==ENABLE
	/*Enable Peripheral Interrupt*/
	SET_BIT(EIMSK,EIMSK_INT3);



#elif INT3_PIE==DISABLE
	/*Disable Peripheral Interrupt*/
	CLEAR_BIT(EIMSK,EIMSK_INT3);



#endif

}

void EXTI_voidInt4Init(void)
{
	/*Interrupt Sense control*/
#if INT4_CONTROL_SENSE==LOW_LEVEL
	/*Set control sense to low level*/
	CLEAR_BIT(EICRB,EICRB_ISC40);
	CLEAR_BIT(EICRB,EICRB_ISC41);
#elif INT4_CONTROL_SENSE==ON_CHANGE
	/*Set control sense to on change*/
	SET_BIT(EICRB,EICRB_ISC40);
	CLEAR_BIT(EICRB,EICRB_ISC41);
#elif INT4_CONTROL_SENSE==FALLING_EDGE
	/*Set control sense to falling Edge*/
	CLEAR_BIT(EICRB,EICRB_ISC40);
	SET_BIT(EICRB,EICRB_ISC41);
#elif INT4_CONTROL_SENSE==RISING_EDGE
	/*Set control sense to Rising Edge*/
	SET_BIT(EICRB,EICRB_ISC40);
	SET_BIT(EICRB,EICRB_ISC41);

#endif

	/*Enable OR Disable of Peripheral*/
#if INT4_PIE==ENABLE
	/*Enable peripheral Interrupt*/
	SET_BIT(EIMSK,EIMSK_INT4);
#elif INT4_PIE==DISABLE
	/*Disable peripheral Interrupt*/
	CLEAR_BIT(EIMSK,EIMSK_INT4);

#endif

}


void EXTI_voidInt5Init(void)
{
	/*Set Control Sense*/
#if INT5_CONTROL_SENSE==LOW_LEVEL
	/*Set Control Sense to Low Level*/
	CLEAR_BIT(EICRB,EICRB_ISC50);
	CLEAR_BIT(EICRB,EICRB_ISC51);


#elif INT5_CONTROL_SENSE==ON_CHANGE
	/*Set Control Sense to ON Change*/
	SET_BIT(EICRB,EICRB_ISC50);
	CLEAR_BIT(EICRB,EICRB_ISC51);

#elif INT5_CONTROL_SENSE==FALLING_EDGE
	/*Set Control Sense to Falling Edge*/
	CLEAR_BIT(EICRB,EICRB_ISC50);
	SET_BIT(EICRB,EICRB_ISC51);


#elif  INT5_CONTROL_SENSE==RISING_EDGE
	/*Set Control Sense to Rising Edge*/
	SET_BIT(EICRB,EICRB_ISC50);
	SET_BIT(EICRB,EICRB_ISC51);



#endif

	/*Enable OR Disable Peripheral Interrupt*/

#if INT5_PIE==ENABLE
	/*Enable Peripheral Interrupt*/
	SET_BIT(EIMSK,EIMSK_INT5);



#elif INT5_PIE==DISABLE
	/*Disable Peripheral Interrupt*/
	CLEAR_BIT(EIMSK,EIMSK_INT3);



#endif

}

void EXTI_voidInt6Init(void)
{
	/*Interrupt Sense control*/
#if INT6_CONTROL_SENSE==LOW_LEVEL
	/*Set sense control low level*/
	CLEAR_BIT(EICRB,EICRB_ISC60);
	CLEAR_BIT(EICRB,EICRB_ISC61);
#elif INT6_CONTROL_SENSE==ON_CHANGE
	/*Set sense control on change*/
	SET_BIT(EICRB,EICRB_ISC60);
	CLEAR_BIT(EICRB,EICRB_ISC61);
#elif INT6_CONTROL_SENSE==FALLING_EDGE
	/*set sense control falling Edge*/
	CLEAR_BIT(EICRB,EICRB_ISC60);
	SET_BIT(EICRB,EICRB_ISC61);
#elif INT6_CONTROL_SENSE==RISING_EDGE
	/*set sense control rising Edge*/
	SET_BIT(EICRB,EICRB_ISC60);
	SET_BIT(EICRB,EICRB_ISC61);

#endif

	/*Enable OR Disable of Peripheral*/
#if INT6_PIE==ENABLE
	/*Enable Peripheral Interrupt*/
	SET_BIT(EIMSK,EIMSK_INT6);
#elif INT6_PIE==DISABLE
	/*Disable Peripheral Interrupt*/
	CLEAR_BIT(EIMSK,EIMSK_INT6);


#endif

}


void EXTI_voidInt7Init(void)
{
	/*Set Control Sense*/
#if INT7_CONTROL_SENSE==LOW_LEVEL
	/*Set Control Sense to Low Level*/
	CLEAR_BIT(EICRB,EICRB_ISC70);
	CLEAR_BIT(EICRB,EICRB_ISC71);


#elif INT7_CONTROL_SENSE==ON_CHANGE
	/*Set Control Sense to ON Change*/
	SET_BIT(EICRB,EICRB_ISC70);
	CLEAR_BIT(EICRB,EICRB_ISC71);

#elif INT7_CONTROL_SENSE==FALLING_EDGE
	/*Set Control Sense to Falling Edge*/
	CLEAR_BIT(EICRB,EICRB_ISC70);
	SET_BIT(EICRB,EICRB_ISC71);


#elif  INT7_CONTROL_SENSE==RISING_EDGE
	/*Set Control Sense to Rising Edge*/
	SET_BIT(EICRB,EICRB_ISC70);
	SET_BIT(EICRB,EICRB_ISC71);



#endif

	/*Enable and Disable Peripheral Interrupt*/

#if INT7_PIE==ENABLE
	/*Enable Peripheral Interrupt*/
	SET_BIT(EIMSK,EIMSK_INT7);



#elif INT7_PIE==DISABLE
	/*Disable Peripheral Interrupt*/
	CLEAR_BIT(EIMSK,EIMSK_INT7);



#endif
}

/**************************************************************************************************/

/*Call Back Functions oF INT0:That Take an Interrupt Handler Function From user And Assign it to Global Pointer to Function
 ,To be Call in ISR ,To be executed when interrupt is Fired*/
u8 EXTI_u8Int0CallBackFunc(void (*Copy_pvFunc)(void))
{
	u8 Local_u8ErrorState=OK;
	if(Copy_pvFunc!=NULL)
	{
		Global_pvFuncInt0=Copy_pvFunc;

	}
	else
	{
		Local_u8ErrorState=NOK;

	}
	return Local_u8ErrorState;

}


/*Call Back Functions oF INT1:That Take an Interrupt Handler Function  From user And Assign it to Global Pointer to Function
 ,To be Call in ISR ,To be executed when interrupt is Fired*/

u8 EXTI_u8Int1CallBackFunc(void(*Copy_pvFunc)(void))
{
	u8 Local_ErrorState=OK;
	if(Copy_pvFunc!=NULL)
	{
		Global_pvFuncInt1=Copy_pvFunc;
	}
	else
	{
		Local_ErrorState=NOK;
	}
	return Local_ErrorState;
}


/*Call Back Functions oF INT2:That Take an Interrupt Handler Function  From user And Assign it to Global Pointer to Function
 ,To be Call in ISR ,To be executed when interrupt is Fired*/

u8 EXTI_u8Int2CallBackFunc(void(*Copy_pvFunc)(void))
{
	u8 Local_ErrorState=OK;
	if(Copy_pvFunc!=NULL)
	{
		Global_pvFuncInt2=Copy_pvFunc;
	}
	else
	{
		Local_ErrorState=NOK;
	}
	return Local_ErrorState;
}


/*Call Back Functions oF INT3:That Take an Interrupt Handler Function  From user And Assign it to Global Pointer to Function
 ,To be Call in ISR ,To be executed when interrupt is Fired*/

u8 EXTI_u8Int3CallBackFunc(void(*Copy_pvFunc)(void))
{
	u8 Local_ErrorState=OK;
	if(Copy_pvFunc!=NULL)
	{
		Global_pvFuncInt3=Copy_pvFunc;
	}
	else
	{
		Local_ErrorState=NOK;
	}
	return Local_ErrorState;
}


/*Call Back Functions oF INT4:That Take an Interrupt Handler Function  From user And Assign it to Global Pointer to Function
 ,To be Call in ISR ,To be executed when interrupt is Fired*/
u8 EXTI_u8Int4CallBackFunc(void(*Copy_pvFunc)(void))
{
	u8 Local_u8ErrorState=OK;
	if(Copy_pvFunc!=NULL)
	{
		 Global_pvFuncInt4=Copy_pvFunc;

	}
	else
	{
		Local_u8ErrorState=NOK;;
	}
	return Local_u8ErrorState;
}


/*Call Back Functions oF INT5:That Take an Interrupt Handler Function  From user And Assign it to Global Pointer to Function
 ,To be Call in ISR ,To be executed when interrupt is Fired*/

u8 EXTI_u8Int5CallBackFunc(void(*Copy_pvFunc)(void))
{
	u8 Local_ErrorState=OK;
	if(Copy_pvFunc!=NULL)
	{
		Global_pvFuncInt5=Copy_pvFunc;
	}
	else
	{
		Local_ErrorState=NOK;
	}
	return Local_ErrorState;
}

/*Call Back Functions oF INT6:That Take an Interrupt Handler Function  From user And Assign it to Global Pointer to Function
 ,To be Call in ISR ,To be executed when interrupt is Fired*/
u8 EXTI_u8Int6CallBackFunc(void(*Copy_pvFunc)(void))
{
	u8 Local_u8ErrorState=OK;
	if(Copy_pvFunc==NULL)
	{
		Local_u8ErrorState=NOK;

	}
	else
	{
		Global_pvFuncInt6=Copy_pvFunc;
	}
	return Local_u8ErrorState;
}


/*Call Back Functions oF INT7:That Take an Interrupt Handler Function  From user And Assign it to Global Pointer to Function
 ,To be Call in ISR ,To be executed when interrupt is Fired*/

u8 EXTI_u8Int7CallBackFunc(void(*Copy_pvFunc)(void))
{
	u8 Local_ErrorState=OK;
	if(Copy_pvFunc!=NULL)
	{
		Global_pvFuncInt7=Copy_pvFunc;
	}
	else
	{
		Local_ErrorState=NOK;
	}
	return Local_ErrorState;
}

/*****************************************************************************************************************************************************/
/*Set the INT Pin control Sense that take : INT Pin Number AND Control Sense: 1-Low Level
                                                                              2-ON Change
                                                                              3-Falling Edge
                                                                              4-Rising Edge */
u8 EXTI_u8SetIntControlSense(u8 Copy_u8Int,u8 Copy_u8IntControlSense)
{
	u8 Local_ErrorState=OK;


	switch(Copy_u8Int)
	{
	/*Set the INT0 control Sense*/
	case INT0:
		if(Copy_u8IntControlSense==LOW_LEVEL)
		{
			/*Set Control Sense to Low Level*/
			CLEAR_BIT(EICRA,EICRA_ISC00);
			CLEAR_BIT(EICRA,EICRA_ISC01);
		}
		else if(Copy_u8IntControlSense==FALLING_EDGE)
		{
			/*Set Control Sense to Falling Edge*/
			CLEAR_BIT(EICRA,EICRA_ISC00);
			SET_BIT(EICRA,EICRA_ISC01);
		}
		else if(Copy_u8IntControlSense==RISING_EDGE)
		{
			/*Set Control Sense to Rising Level*/
			SET_BIT(EICRA,EICRA_ISC00);
			SET_BIT(EICRA,EICRA_ISC01);
		}
		else
		{
			Local_ErrorState=NOK;
		}
		break;
		/*Set the INT1 control Sense*/
	case INT1:
		if(Copy_u8IntControlSense==LOW_LEVEL)
		{
			/*Set Control Sense to Low Level*/
			CLEAR_BIT(EICRA,EICRA_ISC10);
			CLEAR_BIT(EICRA,EICRA_ISC11);
		}
		else if(Copy_u8IntControlSense==FALLING_EDGE)
		{
			/*Set Control Sense to Falling Edge*/
			CLEAR_BIT(EICRA,EICRA_ISC10);
			SET_BIT(EICRA,EICRA_ISC11);
		}
		else if(Copy_u8IntControlSense==RISING_EDGE)
		{
			/*Set Control Sense to Rising Edge*/
			SET_BIT(EICRA,EICRA_ISC10);
			SET_BIT(EICRA,EICRA_ISC11);
		}
		else
		{
			Local_ErrorState=NOK;
		}
		break;

		/*Set the INT2 control Sense*/
	case INT2:
		if(Copy_u8IntControlSense==LOW_LEVEL)
		{
			/*Set Control Sense to Low Level*/
			CLEAR_BIT(EICRA,EICRA_ISC20);
			CLEAR_BIT(EICRA,EICRA_ISC21);
		}
		else if(Copy_u8IntControlSense==FALLING_EDGE)
		{
			/*Set Control Sense to Falling Edge*/
			CLEAR_BIT(EICRA,EICRA_ISC20);
			SET_BIT(EICRA,EICRA_ISC21);
		}
		else if(Copy_u8IntControlSense==RISING_EDGE)
		{
			/*Set Control Sense to Rising Edge*/
			SET_BIT(EICRA,EICRA_ISC20);
			SET_BIT(EICRA,EICRA_ISC21);
		}
		else
		{
			Local_ErrorState=NOK;
		}

		break;

		/*Set the INT3 control Sense*/
	case INT3:
		if(Copy_u8IntControlSense==LOW_LEVEL)
		{
			/*Set Control Sense to Low Level*/
			CLEAR_BIT(EICRA,EICRA_ISC30);
			CLEAR_BIT(EICRA,EICRA_ISC31);
		}
		else if(Copy_u8IntControlSense==FALLING_EDGE)
		{
			/*Set Control Sense to Falling Edge*/
			CLEAR_BIT(EICRA,EICRA_ISC30);
			SET_BIT(EICRA,EICRA_ISC31);
		}
		else if(Copy_u8IntControlSense==RISING_EDGE)
		{
			/*Set Control Sense to Rising Edge*/
			SET_BIT(EICRA,EICRA_ISC30);
			SET_BIT(EICRA,EICRA_ISC31);
		}
		else
		{
			Local_ErrorState=NOK;
		}

		break;

		/*Set the INT4 control Sense*/
	case INT4:
		if(Copy_u8IntControlSense==LOW_LEVEL)
		{
			/*Set Control Sense to Low Level*/
			CLEAR_BIT(EICRB,EICRB_ISC40);
			CLEAR_BIT(EICRB,EICRB_ISC41);
		}

		else if(Copy_u8IntControlSense==ON_CHANGE)
		{
			/*Set Control Sense to On Change*/
			SET_BIT(EICRB,EICRB_ISC40);
			CLEAR_BIT(EICRB,EICRB_ISC41);

		}


		else if(Copy_u8IntControlSense==FALLING_EDGE)
		{
			/*Set Control Sense to Falling Edge*/
			CLEAR_BIT(EICRB,EICRB_ISC40);
			SET_BIT(EICRB,EICRB_ISC41);
		}


		else if(Copy_u8IntControlSense==RISING_EDGE)
		{
			/*Set Control Sense to Rising Edge*/
			SET_BIT(EICRB,EICRB_ISC40);
			SET_BIT(EICRB,EICRB_ISC41);
		}
		else
		{
			Local_ErrorState=NOK;
		}

		break;
		/*Set the INT5 control Sense*/
	case INT5:
		if(Copy_u8IntControlSense==LOW_LEVEL)
		{
			/*Set Control Sense to Low Level*/
			CLEAR_BIT(EICRB,EICRB_ISC50);
			CLEAR_BIT(EICRB,EICRB_ISC51);
		}

		else if(Copy_u8IntControlSense==ON_CHANGE)
		{
			/*Set Control Sense to On Change*/
			SET_BIT(EICRB,EICRB_ISC50);
			CLEAR_BIT(EICRB,EICRB_ISC51);

		}

		else if(Copy_u8IntControlSense==FALLING_EDGE)
		{
			/*Set Control Sense to  Falling Edge*/
			CLEAR_BIT(EICRB,EICRB_ISC50);
			SET_BIT(EICRB,EICRB_ISC51);
		}


		else if(Copy_u8IntControlSense==RISING_EDGE)
		{
			/*Set Control Sense to Rising Edge*/
			SET_BIT(EICRB,EICRB_ISC50);
			SET_BIT(EICRB,EICRB_ISC51);
		}
		else
		{
			Local_ErrorState=NOK;
		}

		break;
		/*Set the INT6 control Sense*/
	case INT6:
		if(Copy_u8IntControlSense==LOW_LEVEL)
		{
			/*Set Control Sense to Low Level*/
			CLEAR_BIT(EICRB,EICRB_ISC60);
			CLEAR_BIT(EICRB,EICRB_ISC61);
		}
		else if(Copy_u8IntControlSense==ON_CHANGE)
		{
			/*Set Control Sense to  On Change*/
			SET_BIT(EICRB,EICRB_ISC60);
			CLEAR_BIT(EICRB,EICRB_ISC61);
		}


		else if(Copy_u8IntControlSense==FALLING_EDGE)
		{
			/*Set Control Sense to  Falling Edge*/
			CLEAR_BIT(EICRB,EICRB_ISC60);
			SET_BIT(EICRB,EICRB_ISC61);
		}




		else if(Copy_u8IntControlSense==RISING_EDGE)
		{
			/*Set Control Sense to Rising Edge*/
			SET_BIT(EICRB,EICRB_ISC60);
			SET_BIT(EICRB,EICRB_ISC61);
		}
		else
		{
			Local_ErrorState=NOK;
		}

		break;
		/*Set the INT7 control Sense*/
	case INT7:
		if(Copy_u8IntControlSense==LOW_LEVEL)
		{
			/*Set Control Sense to Low Level*/
			CLEAR_BIT(EICRB,EICRB_ISC70);
			CLEAR_BIT(EICRB,EICRB_ISC71);
		}

		else if(Copy_u8IntControlSense==ON_CHANGE)
		{
			/*Set Control Sense to On Change*/
			SET_BIT(EICRB,EICRB_ISC70);
			CLEAR_BIT(EICRB,EICRB_ISC71);

		}


		else if(Copy_u8IntControlSense==FALLING_EDGE)
		{
			/*Set Control Sense to Falling Edge*/
			CLEAR_BIT(EICRB,EICRB_ISC70);
			SET_BIT(EICRB,EICRB_ISC71);
		}


		else if(Copy_u8IntControlSense==RISING_EDGE)
		{
			/*Set Control Sense to Rising Edge*/
			SET_BIT(EICRB,EICRB_ISC70);
			SET_BIT(EICRB,EICRB_ISC71);
		}
		else
		{
			Local_ErrorState=NOK;
		}

		break;

	default:
		Local_ErrorState=NOK;
		break;

	}



	return Local_ErrorState;

}



/*This function Enables the Peripheral interrupt enable, it takes the INT pin number as input */
u8 EXTI_u8Enable(u8 Copy_U8Int)
{
	u8 Local_u8ErrorState=OK;
	switch(Copy_U8Int)
	{
	case INT0:
		/*INT0 Peripheral Interrupt Enable*/
		SET_BIT(EIMSK,EIMSK_INT0);
		break;
	case INT1:
		/*INT1 Peripheral Interrupt Enable*/
		SET_BIT(EIMSK,EIMSK_INT1);
		break;
	case INT2:
		/*INT2 Peripheral Interrupt Enable*/
		SET_BIT(EIMSK,EIMSK_INT2);
		break;
	case INT3:
		/*INT3 Peripheral Interrupt Enable*/
		SET_BIT(EIMSK,EIMSK_INT3);
		break;
	case INT4:
		/*INT4 Peripheral Interrupt Enable*/
		SET_BIT(EIMSK,EIMSK_INT4);
		break;
	case INT5:
		/*INT5 Peripheral Interrupt Enable*/
		SET_BIT(EIMSK,EIMSK_INT5);
		break;
	case INT6:
		/*INT6 Peripheral Interrupt Enable*/
		SET_BIT(EIMSK,EIMSK_INT6);
		break;
	case INT7:
		/*INT7 Peripheral Interrupt Enable*/
		SET_BIT(EIMSK,EIMSK_INT7);
		break;
	default:
		Local_u8ErrorState=NOK;
		break;
	}

	return Local_u8ErrorState;
}
/*This function Disables the Peripheral interrupt enable it takes the INT pin number as input*/
u8 EXTI_u8Disable(u8 Copy_U8Int)
{
	u8 Loc_U8ErrorState=OK;
	switch(Copy_U8Int)
	{
	case INT0:
		/*INT0 Peripheral Interrupt Disable*/
		CLEAR_BIT(EIMSK,EIMSK_INT0);
		break;
	case INT1:
		/*INT1 Peripheral Interrupt Disable*/
		CLEAR_BIT(EIMSK,EIMSK_INT1);
		break;
	case INT2:
		/*INT2 Peripheral Interrupt Disable*/
		CLEAR_BIT(EIMSK,EIMSK_INT2);
		break;
	case INT3:
		/*INT3 Peripheral Interrupt Disable*/
		CLEAR_BIT(EIMSK,EIMSK_INT3);
		break;
	case INT4:
		/*INT4 Peripheral Interrupt Disable*/
		CLEAR_BIT(EIMSK,EIMSK_INT4);
		break;
	case INT5:
		/*INT5 Peripheral Interrupt Disable*/
		CLEAR_BIT(EIMSK,EIMSK_INT5);
		break;
	case INT6:
		/*INT6 Peripheral Interrupt Disable*/
		CLEAR_BIT(EIMSK,EIMSK_INT6);
		break;
	case INT7:
		/*INT7 Peripheral Interrupt Disable*/
		CLEAR_BIT(EIMSK,EIMSK_INT7);
		break;
	default:
		Loc_U8ErrorState=NOK;
		break;
	}

	return Loc_U8ErrorState;
}

/*****************************************************************************************************/

/* ISR that Call Global Pointer to Function to be Executed when the Interrupt of Int0 is Fired */
void __vector_1 (void)
{
	Global_pvFuncInt0();
}

/* ISR that Call Global Pointer to Function to be Executed when the Interrupt of Int1 is Fired */


void __vector_2 (void)
{
	Global_pvFuncInt1();
}

/* ISR that Call Global Pointer to Function to be Executed when the Interrupt of Int2 is Fired */


void __vector_3 (void)
{
	Global_pvFuncInt2();
}


/* ISR that Call Global Pointer to Function to be Executed when the Interrupt of Int3 is Fired */

void __vector_4 (void)
{
	Global_pvFuncInt3();
}

/* ISR that Call Global Pointer to Function to be Executed when the Interrupt of Int4 is Fired */
void __vector_5 (void)
{
	Global_pvFuncInt4();
}



/* ISR that Call Global Pointer to Function to be Executed when the Interrupt of Int5 is Fired */

void __vector_6 (void)
{
	Global_pvFuncInt5();
}

/* ISR that Call Global Pointer to Function to be Executed when the Interrupt of Int6 is Fired */
void __vector_7 (void)
{
	Global_pvFuncInt6();
}

/* ISR that Call Global Pointer to Function to be Executed when the Interrupt of Int7 is Fired */

void __vector_8 (void)
{
	Global_pvFuncInt7();
}

