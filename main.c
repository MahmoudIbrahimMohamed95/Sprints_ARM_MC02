#include "STD_TYPES.h"
#include "BIT_MATH.h" 
#include "Nvic.h"
#include "Mcu.h"
#include "Gpio_Dio.h"
#include "Gpio_Port.h"
#include "Pwm.h"
#include "Gpt.h"

/*Working on default Clock of Keil 12MHz*/
int main(void){

	Port_ConfigType port_Cfg={PB4 , OUTPUT , PWM , FLOATING ,  FOUR_mA };

	Pwm_ConfigType Pwm_Cfg = {PWM_TIMER0_16_32 , 4 , 0 , 0xFF};

	Gpt_ConfigType Gpt_Cfg = {TIMER1_16_32 , 4 , 0xFFFF , ONE_SHOOT , NULL } ;

	Pwm_Init(&Pwm_Cfg);

	Gpt_Init(&Gpt_Cfg );

	while(1){

		Pwm_StartTimer(PWM_TIMER0_16_32 , 0 , 0xFF);

		Gpt_StartTimer(TIMER1_16_32  , 26000);

		Pwm_StopTimer(PWM_TIMER0_16_32);	

	}

}
