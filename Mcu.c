
/******************************************************************************************************************************

*	FILE DESCRIPTION:
*	-------------------------------------------------------------------------------------------------------------------------
*	\*File 	  : Dio.c

*	\*brief	  :
*
*	\*details :
*****************************************************************************************************************************/


/****************************************************************************************************************************

*	INCLUDES

****************************************************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "Mcu.h"
#include "Mcu_Cfg.h"
#include "Mcu_Private.h"



/****************************************************************************************************************************

*	LOCAL MACROS CONSTANT\FUNCTIONS

****************************************************************************************************************************/



/****************************************************************************************************************************

*	LOCAL DATA

****************************************************************************************************************************/



/****************************************************************************************************************************

*	GLOBAL DATA

****************************************************************************************************************************/



/****************************************************************************************************************************

*	LOCAL FUNCTION PROTOTYPE

****************************************************************************************************************************/



/****************************************************************************************************************************

*	LOCAL FUNCTION

****************************************************************************************************************************/



/****************************************************************************************************************************

*	GLOBAL FUNCTIONS

****************************************************************************************************************************/


/*************************************************************************************************************************
*	\syntax:
*	\Description     :
*	\sync\Async      :
*	\Reentrancy      :
*	\Parameters (in) :
*	\Parameters (out):
*	\Return value	 :		:Std_ReturnType E_Ok

											E_NOT_OK
*************************************************************************************************************************/

Mcu_RawResetType Mcu_GetResetRawValue(void){

	Mcu_RawResetType mcu_RawResetType = SCR_RESC;
	
	SCR_RESC=0;
	
	return mcu_RawResetType;

}

void Mcu_PerformReset(void){

	SCB_APINT= (SCB_APINT&0x0000FFFF)|((0x05FA)<<16);  /*setting VectKey*/
	
	CLEAR_BIT(SCB_APINT ,VECTRESET );                  /*system reset*/

}

void Mcu_Init(const Mcu_ConfigType*ConfigPtr){

	switch( ConfigPtr->clockType ){

		case MOSC :
			SET_BIT( SCR_RCC	, 0);	

		   SET_BIT( SCR_RCC, 11);

		   SCR_RCC=(SCR_RCC&(0xFFFFFFCF))|(0b00<<4);

		   SET_BIT( SCR_RCC, 13);

		   break;

			   /*default is 6MHZ.*/
			   

		case PIOSC : CLR_BIT( SCR_RCC	, 0);	

       	     SET_BIT( SCR_RCC, 11);

		     SCR_RCC=(SCR_RCC&(0xFFFFFFCF))|(0b01<<4);

		     SET_BIT( SCR_RCC, 13);

		     break;


		case PIOSC_DIV_FOUR: CLR_BIT( SCR_RCC	, 0);	

			 SET_BIT( SCR_RCC, 11);

			 SCR_RCC=(SCR_RCC &(0xFFFFFFCF))|(0b10<<4);

       SET_BIT( SCR_RCC, 13) ;

	         break;

		case LFIOSC: CLR_BIT( SCR_RCC	, 0);	

			 SET_BIT( SCR_RCC, 11);

			 SCR_RCC=SCR_RCC&(0xFFFFFFCF)|(0b11<<4);

       SET_BIT( SCR_RCC, 13);

	         break;


		case HIBERNATION:  
		
     		break;

		case PIOSC_PLL :
		
			 CLR_BIT( SCR_RCC , 0);	

     	 SET_BIT( SCR_RCC , 11);

		   SCR_RCC=(SCR_RCC&(0xFFFFFFCF))|(0b01<<4);

			 SCR_RCC=SCR_RCC&(0xF0FFFFFF)|(0xB<<23);  /*16MHz clock source  */
				
		   CLR_BIT( SCR_RCC, 13);
			
			 while( SCR_PLLSTAT == 0 );
			 
			
			 CLR_BIT( SCR_RCC , 11);
		     
			 break;


		case MOSC_PLL:

			 CLR_BIT( SCR_RCC , 0);	

    	 SET_BIT( SCR_RCC , 11);

		   SCR_RCC=(SCR_RCC&(0xFFFFFFCF))|(0b00<<4);

			 SCR_RCC=SCR_RCC&(0xF0FFFFFF)|(0xB<<23);  /*16MHz clock source*/
				
	     CLR_BIT( SCR_RCC, 13);
			
			 while(SCR_PLLSTAT==UNLOCKED);
			
			 CLR_BIT( SCR_RCC , 11);
			 
			 break;

		default:
		
			break;

	}
	
	switch( ConfigPtr->periphralClock ){
				
		case WDT0 :   SET_BIT(SCR_RCGCWD ,0); break;

		case WDT1 :   SET_BIT(SCR_RCGCWD ,1); break;

		case TIMER0:  SET_BIT(SCR_RCGCTIMER ,0); break; 

		case TIMER1:  SET_BIT(SCR_RCGCTIMER ,1); break;

		case TIMER2:  SET_BIT(SCR_RCGCTIMER ,2); break;

		case TIMER3 : SET_BIT(SCR_RCGCTIMER ,3); break;

		case TIMER4 : SET_BIT(SCR_RCGCTIMER ,4); break;

		case TIMER5:  SET_BIT(SCR_RCGCTIMER ,5); break;

	  case PORTA :  SET_BIT(SCR_RCGCGPIO , 0);  break;
	
		case PORTB:    SET_BIT(SCR_RCGCGPIO , 1);  break;

		case PORTC :   SET_BIT(SCR_RCGCGPIO , 2);  break;

		case PORTD :   SET_BIT(SCR_RCGCGPIO , 3);  break;

		case PORTE:    SET_BIT(SCR_RCGCGPIO , 4);  break;

		case PORTF :   SET_BIT(SCR_RCGCGPIO , 5);  break;

		case uDMA :    SET_BIT(SCR_RCGCDMA , 0);break;	
	 
		case UART0:	   SET_BIT(SCR_RCGCUART , 0);break;

		case UART1:	   SET_BIT(SCR_RCGCUART , 1);break;

		case UART2:    SET_BIT(SCR_RCGCUART , 2);break;

		case UART3 :   SET_BIT(SCR_RCGCUART , 3);break;

		case UART4 :   SET_BIT(SCR_RCGCUART , 4);break;

		case UART5:    SET_BIT(SCR_RCGCUART , 5);break;

		case UART6 :   SET_BIT(SCR_RCGCUART , 6);break;

		case UART7:    SET_BIT(SCR_RCGCUART , 7);break;

		case SSI3 :    SET_BIT(SCR_RCGCSSI , 3) ; break;	

		case SSI2:     SET_BIT(SCR_RCGCSSI , 2) ; break;

		case SSI1 :    SET_BIT(SCR_RCGCSSI , 1) ; break;

		case SSI0:      SET_BIT(SCR_RCGCSSI , 0) ; break;

		case I2C3:     SET_BIT(SCR_RCGCI2C , 3);break;	

		case I2C2:		 SET_BIT(SCR_RCGCI2C , 2);break;

		case I2C1:		 SET_BIT(SCR_RCGCI2C , 1);break;

		case I2C0:  	 SET_BIT(SCR_RCGCI2C , 0);break;

		case USB: 	     SET_BIT(SCR_RCGCUSB , 0);break;

		case CAN0:  	 SET_BIT(SCR_RCGCCAN , 0);break;

		case CAN1:  	 SET_BIT(SCR_RCGCCAN , 1);break;

		case ADC0 :  	 SET_BIT(SCR_RCGCADC , 0);break;

		case ADC1 :	     SET_BIT(SCR_RCGCADC, 0);break;


		case ANALOG_COMPARATOR : 

			break;
	

		case PWM0 :	 SET_BIT(SCR_RCGCPWM, 0);break;

		case PWM1:   SET_BIT(SCR_RCGCPWM, 1);break;
		

		case TIMER0_32_64:  SET_BIT(SCR_RCGCWTIMER, 0); break;

		case TIMER1_32_64:  SET_BIT(SCR_RCGCWTIMER, 1); break;

		case TIMER2_32_64:  SET_BIT(SCR_RCGCWTIMER, 2); break;

		case TIMER3_32_64:  SET_BIT(SCR_RCGCWTIMER, 3); break;

		case TIMER4_32_64 : SET_BIT(SCR_RCGCWTIMER, 4); break;

		case TIMER5_32_64:  SET_BIT(SCR_RCGCWTIMER, 5); break;
	
	}

}

Std_ReturnType Mcu_InitClock(Mcu_ClockType  ClockSetting){
	
	switch( ClockSetting ){

		case MOSC :SET_BIT( SCR_RCC	, 0);	

		   SET_BIT( SCR_RCC, 11);

		   SCR_RCC= (SCR_RCC&(0xFFFFFFCF))| (0b00<<4);

		   SET_BIT( SCR_RCC, 13);

		   break;

			   /*default is 6MHZ.*/
			   

		case PIOSC : CLR_BIT( SCR_RCC	, 0);	

       	     SET_BIT( SCR_RCC, 11);

		     SCR_RCC=(SCR_RCC&(0xFFFFFFCF))|(0b01<<4);

		     SET_BIT( SCR_RCC, 13);

		     break;


		case PIOSC_DIV_FOUR:
			
				CLR_BIT( SCR_RCC	, 0);	

			 SET_BIT(SCR_RCC, 11);

			 SCR_RCC= (SCR_RCC&(0xFFFFFFCF))|(0b10<<4);

       SET_BIT( SCR_RCC, 13);
         break;

		case LFIOSC: CLR_BIT( SCR_RCC	, 0);	

			 SET_BIT( SCR_RCC, 11);

			 SCR_RCC=(SCR_RCC&(0xFFFFFFCF))|(0b11<<4);

       SET_BIT( SCR_RCC, 13);

	         break;


		case HIBERNATION:  
		
     		break;

		case PIOSC_PLL :
		
			 CLR_BIT( SCR_RCC , 0);	

  		 SET_BIT( SCR_RCC , 11);

       SCR_RCC=(SCR_RCC&(0xFFFFFFCF))|(0b01<<4);

			 SCR_RCC=SCR_RCC&(0xF0FFFFFF)|(0xB<<23);  /*16MHz clock source*/
				
	     CLR_BIT( SCR_RCC, 13);
			
			 while(SCR_PLLSTAT==UNLOCKED);
			
			 CLR_BIT( SCR_RCC , 11);
		     
			 break;


		case MOSC_PLL:

			 CLR_BIT( SCR_RCC , 0);	

    	 SET_BIT( SCR_RCC , 11);

	     SCR_RCC=(SCR_RCC&(0xFFFFFFCF))|(0b00<<4);

			 SCR_RCC=SCR_RCC&(0xF0FFFFFF)|(0xB<<23);  /*16MHz clock source*/
				
	     CLR_BIT( SCR_RCC, 13);
			
			 while(SCR_PLLSTAT==UNLOCKED);
			
			 CLR_BIT( SCR_RCC , 11);
			 
			 break;

		default:
		
			break;

	}
	
}

Std_ReturnType Mcu_DistributePllClock(void){
	
		SET_BIT(SCR_RCC , 11);
		
		CLR_BIT( SCR_RCC, 13);
		
		SCR_RCC=SCR_RCC&(0xF0FFFFFF)|(0xB<<23);  /*16MHz clock source*/
	    
		while(SCR_PLLSTAT==UNLOCKED);
		
		CLR_BIT(SCR_RCC , 11);
		
}

Mcu_PllStatusType Mcu_GetPllStatus(void){
	
	switch(SCR_PLLSTAT){
	

		case UNLOCKED:
			return UNLOCKED;

		case LOCKED:
			return LOCKED;
	}
}
/*************************************************************************************************************************

END OF FILE: Dio.c

**************************************************************************************************************************/
