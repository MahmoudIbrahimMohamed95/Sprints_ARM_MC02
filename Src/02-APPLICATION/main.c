/*****************************************************************************************************************************
*FILE DESCRIPTION
*-----------------------------------------------------------------------------------------------------------------------------
*   FILE: main.c

*	Module:   APPLICATION_C_

*   DESCRIPTION: source file for APPLICATION Implementation

*
*****************************************************************************************************************************/


/****************************************************************************************************************************

*  INCLUDES-:

*****************************************************************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Mcu.h"
#include "Stk.h"
#include "Gpio_Dio.h"
#include "Gpio_Port.h"
#include "Pwm.h"
#include "main.h"

/**********************************************************************************************************************************************

* GLOBAL VARIABLES AND MACROS

**********************************************************************************************************************************************/

int TURN_0N_TIME =5;

int TURN_OFF_TIME=5;

/*define externs in main for keil simulator use */

extern Mcu_ConfigType  Mcu_Config[2];
extern Stk_ConfigType  Stk_Config;
extern Pwm_ConfigType  Pwm_Config;
extern Port_ConfigType Port_Config[3];


int main(void){
	
	uint16 i=0;

	for(i=0 ;i<2 ; i++){

		Mcu_Init(&Mcu_Config[i]);

	}
	


/****************************************************************************************************************************
*	\syntax:		  : void Port_Init(const Port_ConfigType* ConfigPtr )
*	\Description     :  function to set configuration for all GPIO of Mcu and it's Alternative Functions 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Reentrant
*	\Parameters (in) :	pointer to Struct of Configurations
*	\Parameters (out):	void
*	\Return value	 :	void
*************************************************************************************************************************/

	for(i=0 ;i<3 ; i++){

		Port_Init(&Port_Config[i]);

	}  


/****************************************************************************************************************************
*	\syntax:	
*	\Description     :  function to set Pwm-Timer Configurations 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Non-Reentrant
*	\Parameters (in) :	const Pwm_ConfigType*ConfigPtr "Pointer to struct"
*	\Parameters (out):	void
*************************************************************************************************************************/

		/*	Pwm_Init (&Pwm_Config);  */



/****************************************************************************************************************************
*	\syntax          :	void Stk_IntCtrlInit (const Stk_ConfigType* ConfigPtr  );  
*	\Description     :  function to Intialize systick Configurations 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Non-Reentrant
*	\Parameters (in) :	const Stk_ConfigType*ConfigPtr "Pointer to struct"
*	\Parameters (out):	void
*************************************************************************************************************************/

	Stk_Init(&Stk_Config);	



/****************************************************************************************************************************
*	\syntax			 :	void DIO_WriteChannel(Dio_ChannelType ChannelId , Dio_LevelType Level);	
*	\Description     :  function to write on any Channel"Pin" which takes Pin no. and level 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Reentrant
*	\Parameters (in) :	Channel ID "of type Dio_ChannelType" & DIO Level "of type Dio_Level Type"  
*	\Parameters (out):	void
*	\Return value	 :	void
*************************************************************************************************************************/

	DIO_WriteChannel(PF3, LOW); 

	while(1){


/*******************************************************FIRST IMPLEMENTATION USING PWM*********************************************************/


	/*****************************************************Start PWM***********************************************************/


	/*	
		Pwm_StartTimer(PWM_TIMER1_16_32 , 0xFFF , 0xFFF);
		
	*/  

			
	/*********************************************LIGHT LED by increasing duty cycle******************************************/
		
	/*	for(i=0xFFF ; i > 0 ;i--){
			
			Pwm_SetMatchValue(PWM_TIMER1_16_32 , i);
			Stk_SetBusyWait(0xFFFF);

		}	
	*/
	
	/*************************************************DIM LED  by decreasing duty cyle********************************************/

	/*	
		for(i=0 ; i < 0xFFF ;i++){

			Pwm_SetMatchValue(PWM_TIMER1_16_32 , i);   
			Stk_SetBusyWait(0xFFFF);

		}
	*/

	/*************************************************************Stop PWM***********************************************************/

		/*		
			Pwm_StopTimer(PWM_TIMER1_16_32); 
	    */  

/*******************************ANOTHER IMPLEMENTATION WITHOUT USING PWM FOR SIMULATION PURPOSE AS WE CAN'T SIMULATE PWM IN KIEL***************/	


/******************************************************CHECKING FOR SW1 STATUS*************************************************/
	if(Dio_ReadChannel(PA0)==1){

		Stk_SetBusyWait(240000);  		/*20ms blocking delay to avoid debouncing*/

		if(Dio_ReadChannel(PA0)==1){
			
			TURN_0N_TIME++;
			TURN_OFF_TIME--;
		}
	
	}	
/******************************************************CHECKING FOR SW2 STATUS*************************************************/	
	if(Dio_ReadChannel(PA1)==1){

		Stk_SetBusyWait(240000);  		/*20ms blocking delay to avoid debouncing*/

		if(Dio_ReadChannel(PA1)==1){
			
			TURN_0N_TIME--;
			TURN_OFF_TIME++;
		}
	
	}	
/*****************************************************START LIGHTING AND DIMMING LED**********************************************************************/	
		DIO_WriteChannel(PA2, HIGH); 		

			/*ON TIME DURATION*/

			for(i=0;i<=TURN_0N_TIME;i++){
			
					Stk_SetBusyWait(12000000);  		/*1 second blocking delay*/	
			}

		Dio_FlipChannel(PA2);

				/*OFF TIME DURATION*/

			for(i=0; i<=TURN_OFF_TIME ; i++){
			
				Stk_SetBusyWait(12000000);				/*1 second blocking delay*/
			}


	}
	
}