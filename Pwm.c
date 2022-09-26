#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Pwm.h"
#include "Pwm_Cfg.h"
#include "Pwm_Private.h"

void Pwm_Init(const Pwm_ConfigType* ConfigPtr){
 
	
	volatile Pwm_RegsType*Pwm= (volatile Gpt_RegsType*)TimerBaseAddress[Channel];

	CLR_BIT(Pwm->GPTMCTL , 0 );                  //disable timer

	Pwm->GPTMCFG = 0x00000004;                 //No Concatanation 
	
	Pwm->GPTMIMR = 0x0000;                    // disable all interrupts

	SET_BIT (Pwm->GPTMTAMR , 3);              //PWM MODE

	CLR_BIT (Pwm->GPTMTAMR , 2);		  //No INPUT CAPTURE

	SET_BIT (Pwm->GPTMTAMR , 1);	          //periodoc

	SET_BIT (Pwm->GPTMTAMR , 0);		   //periodic
	
	CLR_BIT(Pwm->GPTMCTL , 6);			   //non inverting

	Pwm->GPTMTAPR = PwmChannelTickFrequency ;  // set prescaler

}



void Pwm_StartTimer(Gpt_ChannelType Channel , Pwm_ValueType Value , Pwm_ValueType MatchValue){

	volatile Pwm_RegsType*Pwm= (volatile Gpt_RegsType*)TimerBaseAddress[Channel];
	
	Pwm->GPTMTAILR= Value;		

	Pwm->GPTMTAMATCHR= MatchValue;
	
	((Bit_Banding(Pwm , 0x00C , 0)))=1;                     //SET_BIT( Pwm->GPTMCTL ,0).......Start timer.

}


void Gpt_StopTimer(Pwm_ChannelType Channel){

	volatile Pwm_RegsType*Gpt= (volatile Gpt_RegsType*)TimerBaseAddress[Channel];
	
	((Bit_Banding(Pwm , 0x00C , 0)))= 0;           //CLR_BIT( Gpt->GPTMCTL ,0)........stop timer.

}
