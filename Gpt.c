
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Gpt.h"
#include "Gpt_Config.h"
#include "Gpt_Private.h"

void Gpt_Init(const Gpt_ConfigType*ConfigPtr){
	
	Gpt_ChannelMAxTick[Channel]= GptChannelTickValueMax;
	
	g_callBackPtr[Channel] =    Gpt_ConfigType->Gpt_aPtr;

	volatile Gpt_RegsType*Gpt= (volatile Gpt_RegsType*)TimerBaseAddress[Channel];

	CLR_BIT(Gpt->GPTMCTL , 0 );                  //disable timer

	Gpt->GPTMCFG = 0x04;                        //No Concatanation 
	
	Gpt->GPTMTAPR = GptChannelTickFrequency ;  // set prescaler

	Gpt->GPTMIMR = 0x0000;                    // disable all interrupts

	SET_BIT (Gpt->GPTMTAMR, 4);              //timer count up


	switch (GptChannelMode){
	
	case ONE_SHOOT: 
		SET_BIT	(Gpt->GPTMTAMR, 0); break;
	
	case PERIODIC :
		SET_BIT	(Gpt->GPTMTAMR, 1);  break;
	
	default:
		break;
	}
}


void Gpt_DisableNotification(Gpt_ChannelType Channel){
	
	volatile Gpt_RegsType*Gpt= (volatile Gpt_RegsType*)TimerBaseAddress[Channel];
	
	CLR_BIT(Gpt->GPTMIMR  , 0);
}

void Gpt_EnableNotification(Gpt_ChannelType Channel){
	
	volatile Gpt_RegsType*Gpt= (volatile Gpt_RegsType*)TimerBaseAddress[Channel];

	SET_BIT(Gpt->GPTMIMR ,0);
	
}

// #define Bit_Banding(PERIPHRAL_OFFSET , REGISTER_OFFSET , BIT_NUMBER)	((volatile uint32*)(BIT_BAND_ALIAS_BASE_ADDRESS + ((PERIPHRAL_OFFSET + REGISTER_OFFSET) * 32 )))[BIT_NUMBER]


void Gpt_StartTimer(Gpt_ChannelType Channel , Gpt_ValueType Value){

	volatile Gpt_RegsType*Gpt= (volatile Gpt_RegsType*)TimerBaseAddress[Channel];

	((Bit_Banding(GPT , 0x00C , 0)))=1;            //SET_BIT( Gpt->GPTMCTL ,0).......start timer.

	while((( Bit_Banding( GPT , 0x01C , 0)))== 0); //while(CHECK_BIT(GPTMRIS,0)) 
	
	((Bit_Banding(GPT , 0x01C , 0)))=1;			//SET_BIT( Gpt->GPTMRIS , 0)
}

void Gpt_StopTimer(Gpt_ChannelType Channel){

	volatile Gpt_RegsType*Gpt= (volatile Gpt_RegsType*)TimerBaseAddress[Channel];
	
	((Bit_Banding(GPT , 0x00C , 0)))= 0;           //CLR_BIT( Gpt->GPTMCTL ,0)........stop timer.

}

void Gpt_Notification_<Channel>(void){

	if(g_callBackPtr[Channel] != NULL_PTR)
	{
		(*g_callBackPtr[Channel])(); 
	}

}


Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType Channel){

	uint32 l_timerValue=0;
	
	volatile Gpt_RegsType*Gpt= (volatile Gpt_RegsType*)TimerBaseAddress[Channel];

	if(Channel <= 5){
		
		return (( Gpt->GPTMTAV >> Gpt->GPTMTAPR )&Gpt_ChannelMAxTick[Channel]); 
		
	}
	
	elseif(Channel <= 11){
	
		l_timerValue= ( Gpt->GPTMTAV >> Gpt->GPTMTAPR )|(Gpt->GPTMTAPV<<(32-(Gpt->GPTMTAPR)));
		
		l_timerValue=l_timerValue & Gpt_ChannelMAxTick[Channel];
		
		return l_timerValue;
	}

}

	Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType Channel){

	uint32 l_timerValue=0;
	
	volatile Gpt_RegsType*Gpt= (volatile Gpt_RegsType*)TimerBaseAddress[Channel];

	if(Channel <= 5){
		
		return ((Gpt_ChannelMAxTick[Channel])-(( Gpt->GPTMTAV >> Gpt->GPTMTAPR )&Gpt_ChannelMAxTick[Channel])); 
		
	}
	
	else if(Channel <= 11){
	
		l_timerValue= ( Gpt->GPTMTAV >> Gpt->GPTMTAPR )|(Gpt->GPTMTAPV<<(32-Gpt->GPTMTAPR));
		
		l_timerValue=l_timerValue&Gpt_ChannelMAxTick[Channel];
		
		return (Gpt_ChannelMAxTick[Channel]-l_timerValue);
	}

}

/* Timer0_32 is a predefined timer */

/**
Std_ReturnType Gpt_GetPredefTimerValue(Gpt_PredefTimerType PredefTimer , uint32*TimeValuePtr){

	switch(PredefTimer){
		
		case GPT_PREDEF_TIMER_1US_16BIT :
	
			*TimeValuePtr= 

			return E_OK;

        case GPT_PREDEF_TIMER_1US_24BIT :

			*TimeValuePtr=
			return E_OK;

		case GPT_PREDEF_TIMER_1US_32BIT :

			*TimeValuePtr=
			return E_OK;

		case GPT_PREDEF_TIMER_1000US_32BIT:       	 

			*TimeValuePtr=
			return E_OK;

 	    default:   

			return E_NOK;
		}
**/



