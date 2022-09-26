#ifndef GPT_H_
#define GPT_H_

#include "Gpt_Config.h"

#define GPT_PREDEF_TIMER_1US_16BIT          0
#define GPT_PREDEF_TIMER_1US_24BIT          1
#define GPT_PREDEF_TIMER_1US_32BIT          2
#define GPT_PREDEF_TIMER_1000US_32BIT       3



static volatile void (*g_callBackPtr[12])(void) = {NULL_PTR};

uint64 Gpt_ChannelMAxTick[12]={0};


/*****************************************************************************************************************************
												GPT.h
*****************************************************************************************************************************/

typedef enum{

	TIMER0_16_32 ,TIMER1_16_32 ,TIMER2_16_32 ,TIMER3_16_32 ,TIMER4_16_32 ,TIMER5_16_32

	TIMER0_32_64 ,TIMER1_32_64 ,TIMER2_32_64 ,TIMER3_32_64 ,TIMER4_32_64 ,TIMER5_32_64

}Gpt_ChannelType;


typedef uint32 Gpt_ValueType;


typedef enum{

	ONE_SHOOT , PERIODIC

}Gpt_ModeType;

typedef  void(*Gpt_Notification)(void);

typedef struct{

Gpt_ChannelType  Channel;

Gpt_ValueType	 GptChannelTickFrequency;

Gpt_ValueType    GptChannelTickValueMax;  //note that this is max value in bits position ex:0b1111

Gpt_ModeType	 GptChannelMode;

Gpt_Notification Gpt_aPtr;


}Gpt_ConfigType;



void Gpt_Init(const Gpt_ConfigType*ConfigPtr);
void Gpt_DisableNotification(Gpt_ChannelType Channel);
void Gpt_EnableNotification(Gpt_ChannelType Channel);

void Gpt_StartTimer(Gpt_ChannelType Channel , Gpt_ValueType Value);
void Gpt_StopTimer(Gpt_ChannelType Channel);
void Gpt_Notification_<Channel>(void);

Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType Channel);
Std_ReturnType Gpt_GetPredefTimerValue(Gpt_PredefTimerType PredefTimer , uint32*TimeValuePtr);
Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType Channel);

#endif