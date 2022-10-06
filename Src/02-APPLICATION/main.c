#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Mcu.h"
#include "Stk.h"
#include "Gpio_Dio.h"
#include "Gpio_Port.h"
#include "Pwm.h"
#include "main.h"

#define TURN_0N_TIME      5

#define TURN_OFF_TIME     5

/*define externs in main for keil simulator use */

extern Mcu_ConfigType Mcu_Config[2];
extern Stk_ConfigType Stk_Config;
extern Pwm_ConfigType Pwm_Config;
extern Port_ConfigType Port_Config;


int main(void){
	
	uint16 i=0;

	for(i=0 ;i<2 ; i++){

		Mcu_Init(&Mcu_Config[i]);

	}
	
	Port_Init(&Port_Config);

/*	Pwm_Init (&Pwm_Config);  */

	Stk_Init(&Stk_Config);

	   

	DIO_WriteChannel(PF3, LOW); 

	while(1){

	/*	Pwm_StartTimer(PWM_TIMER1_16_32 , 0xFFF , 0xFFF);*/  

			
	/*LIGHT LED by increasing duty cycle*/

		DIO_WriteChannel(PF3, HIGH);  
		
	/*	for(i=0xFFF ; i > 0 ;i--){

			Pwm_SetMatchValue(PWM_TIMER1_16_32 , i);
			Stk_SetBusyWait(0xFFFF);

		}	
*/
		/*ON TIME DURATION*/

		for(i=0;i<=TURN_0N_TIME;i++){
			
				Stk_SetBusyWait(12000000);
		
		}

		/*DIM LED  by decreasing duty cyle */

	/*	
		for(i=0 ; i < 0xFFF ;i++){

			Pwm_SetMatchValue(PWM_TIMER1_16_32 , i);   
			Stk_SetBusyWait(0xFFFF);

		}
*/


		/*Stop PWM*/

		/*		Pwm_StopTimer(PWM_TIMER1_16_32);  */  
		
	Dio_FlipChannel(PF3);

		/*OFF TIME DURATION*/

	for(i=0; i<=TURN_OFF_TIME ; i++){
			
				Stk_SetBusyWait(12000000);
		
		}

		/*OFF TIME DURATION*/
	}
	
}