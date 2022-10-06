#ifndef GPT_H_
#define GPT_H_

static volatile void (*Gpt_callBackPtr[12])(void) = {NULL_PTR , NULL_PTR , NULL_PTR , NULL_PTR , NULL_PTR , NULL_PTR , NULL_PTR , NULL_PTR 

, NULL_PTR , NULL_PTR , NULL_PTR , NULL_PTR};

static volatile uint32 Gpt_ChannelMaxTick[12]={0};



typedef enum{

	TIMER0_16_32 ,TIMER1_16_32 ,TIMER2_16_32 ,TIMER3_16_32 ,TIMER4_16_32 ,TIMER5_16_32

	,TIMER0_32_64 ,TIMER1_32_64 ,TIMER2_32_64 ,TIMER3_32_64 ,TIMER4_32_64 ,TIMER5_32_64

}Gpt_ChannelType;

typedef enum{

	GPT_PREDEF_TIMER_100US_32BIT , GPT_PREDEF_TIMER_1US_16BIT , GPT_PREDEF_TIMER_1US_24BIT , GPT_PREDEF_TIMER_1US_32BIT    

}Gpt_PredefTimerType;

typedef enum{

	ONE_SHOOT , PERIODIC

}Gpt_ModeType;



typedef uint32  Gpt_ValueType;



typedef  void(*Gpt_NotificationType)(void);

typedef struct{

Gpt_ChannelType  Channel;

Gpt_ValueType	      GptChannelTickFrequency;  /*Prescaler*/

Gpt_ValueType         GptChannelTickValueMax;  /*note that this is max value in bits position ex:0b1111*/

Gpt_ModeType	      GptChannelMode;

Gpt_NotificationType  Gpt_Notification;


}Gpt_ConfigType;



void Gpt_Init(const Gpt_ConfigType*ConfigPtr);
void Gpt_DisableNotification(Gpt_ChannelType Channel);
void Gpt_EnableNotification(Gpt_ChannelType Channel);
void Gpt_StartTimer(Gpt_ChannelType Channel , Gpt_ValueType Value);
void Gpt_StopTimer(Gpt_ChannelType Channel);
Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType Channel);
Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType Channel);
void Gpt_PredefTimerInit(Gpt_PredefTimerType PredefTimer);
Std_ReturnType Gpt_GetPredefTimerValue(Gpt_PredefTimerType PredefTimer , uint32*TimeValuePtr);

#endif