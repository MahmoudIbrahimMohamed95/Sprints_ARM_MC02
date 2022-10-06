#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Pwm.h"
#include "Pwm_Private.h"

void Pwm_Init(const Pwm_ConfigType* ConfigPtr){
 
	
	volatile Gpt_RegsType*Pwm= (volatile Gpt_RegsType*)Pwm_TimerBaseAddress[ConfigPtr->Channel];

	CLR_BIT(Pwm->GPTMCTL , 0 );                  /*disable timer*/

	Pwm->GPTMCFG = 0x00000004;                 /*No Concatanation */
	
	Pwm->GPTMIMR = 0x0000;                    /* disable all interrupts*/

	SET_BIT (Pwm->GPTMTAMR , 3);              /*PWM MODE*/

	CLR_BIT (Pwm->GPTMTAMR , 2);		    /*No INPUT CAPTURE*/

	SET_BIT (Pwm->GPTMTAMR , 1);	          /*periodoc*/

	SET_BIT (Pwm->GPTMTAMR , 0);		   /*periodic*/
	
	CLR_BIT(Pwm->GPTMCTL , 6);			   /*non inverting*/

	Pwm->GPTMTAPR = ConfigPtr->PwmChannelTickFrequency ;  /* set prescaler */

}

void Pwm_StartTimer(Pwm_ChannelType Channel , Pwm_ValueType Value , Pwm_ValueType MatchValue){

	volatile Gpt_RegsType*Pwm= (volatile Gpt_RegsType*)Pwm_TimerBaseAddress[Channel];

	volatile uint32 Pwm_Offset = (Pwm_TimerBaseAddress[Channel]-0x40000000);


	Pwm->GPTMTAILR= Value;		
	
	Pwm->GPTMTAMATCHR= MatchValue;
	
	(BIT_BANDING(Pwm_Offset , 0x00C , 0))=1;                     /*SET_BIT( Pwm->GPTMCTL ,0).......Start timer.*/
}

void Pwm_SetMatchValue(Pwm_ChannelType Channel , Pwm_ValueType MatchValue){

		volatile Gpt_RegsType*Pwm= (volatile Gpt_RegsType*)Pwm_TimerBaseAddress[Channel];

		Pwm->GPTMTAMATCHR= MatchValue;

	
}

void Pwm_StopTimer(Pwm_ChannelType Channel){

	volatile Gpt_RegsType*Pwm= (volatile Gpt_RegsType*)Pwm_TimerBaseAddress[Channel];

	volatile uint32 Pwm_Offset = (Pwm_TimerBaseAddress[Channel]-0x40000000);

	((BIT_BANDING(Pwm_Offset , 0x00C , 0)))= 0;           /*CLR_BIT( Gpt->GPTMCTL ,0)........stop timer.*/

	Pwm->GPTMTAILR=0;

	Pwm->GPTMTAMATCHR=0;
}

void Pwm_DisableNotification(Pwm_ChannelType Channel){

	volatile Pwm_RegsType*Pwm= (volatile Pwm_RegsType*)Pwm_TimerBaseAddress[Channel];

	volatile uint32 Pwm_Offset = (Pwm_TimerBaseAddress[Channel]-0x40000000);
	
	((BIT_BANDING(Pwm_Offset , 0x00C , 0)))= 0;           /*CLR_BIT( Gpt->GPTMCTL ,0)........stop timer.*/

	((BIT_BANDING(Pwm_Offset , 0x004 , 9)))= 1;           /*CLR_BIT( Gpt->GPTMAMR ,9)........disable Pwm Interrupt.*/

	((BIT_BANDING(Pwm_Offset , 0x00C , 0)))= 1;           /*CLR_BIT( Gpt->GPTMCTL ,0)........start timer.*/

}

void Pwm_EnableNotification(Pwm_ChannelType Channel){

	volatile Pwm_RegsType*Pwm= (volatile Pwm_RegsType*)Pwm_TimerBaseAddress[Channel];

	volatile uint32 Pwm_Offset = (Pwm_TimerBaseAddress[Channel]-0x40000000);

	((BIT_BANDING(Pwm_Offset , 0x00C , 0)))= 0;           /*CLR_BIT( Gpt->GPTMCTL ,0)........stop timer.*/

	((BIT_BANDING(Pwm_Offset , 0x00C , 2)))= 0;           /*CLR_BIT( Gpt->GPTMCTL ,2)........edge detect interrrupt positive edge*/

	((BIT_BANDING(Pwm_Offset , 0x00C , 3)))= 0;           /*CLR_BIT( Gpt->GPTMCTL ,2)........edge detect interrrupt positive edge*/

	((BIT_BANDING(Pwm_Offset , 0x004 , 9)))= 1;           /*CLR_BIT( Gpt->GPTMAMR ,9)........enable Pwm Interrupt.*/

	((BIT_BANDING(Pwm_Offset , 0x00C , 0)))= 1;           /*CLR_BIT( Gpt->GPTMCTL ,0)........start timer.*/

}
