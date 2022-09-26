#ifndef PWM_H_
#define PWM_H_

typedef enum{

        PWM_TIMER0_16_32 ,PWM_TIMER1_16_32 ,PWM_TIMER2_16_32 ,PWM_TIMER3_16_32 ,PWM_TIMER4_16_32 ,PWM_TIMER5_16_32

	,PWM_TIMER0_32_64 ,PWM_TIMER1_32_64 ,PWM_TIMER2_32_64 ,PWM_TIMER3_32_64 ,PWM_TIMER4_32_64 ,PWM_TIMER5_32_64

}Pwm_ChannelType;


typedef uint32   Pwm_ValueType;
typedef uint32   Pwm_RegsType;

//typedef  void(*Pwm_Notification)(void);

//Pwm_Notification Pwm_aPtr;

typedef struct{

Pwm_ChannelType  Channel;

Pwm_ValueType	 PwmChannelTickFrequency;

Pwm_ValueType    PwmChannelStartValue;  

Pwm_ValueType    PwmChannelMatchValue;


}Pwm_ConfigType;

void Pwm_Init(const Pwm_ConfigType*ConfigPtr);
void Pwm_DisableNotification(Pwm_ChannelType Channel);
void Pwm_EnableNotification(Pwm_ChannelType Channel);
void Pwm_StartTimer(Pwm_ChannelType Channel , Pwm_ValueType Value ,Pwm_ValueType MatchValue);
void Pwm_StopTimer(Pwm_ChannelType Channel);

#endif