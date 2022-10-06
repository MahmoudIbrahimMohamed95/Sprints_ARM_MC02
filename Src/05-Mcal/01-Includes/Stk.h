#ifndef STK_H_
#define STK_H_

typedef enum{

    STK_INT_EN , STK_INT_DIS
}Stk_IntType;

typedef enum{

    STK_PIOSC_DIV4 , STK_SYSTEM_CLOCK
}Stk_ClockType;

typedef  uint32  Stk_ValueType;

typedef  void(*Stk_NotificationType)(void);

typedef struct{

Stk_IntType       Stk_Int;

Stk_ClockType     Stk_Clock;

Stk_NotificationType  Stk_Notification;    

}Stk_ConfigType;

void Stk_Init(const Stk_ConfigType* ConfigPtr);

void Stk_SetBusyWait(Stk_ValueType Stk_Value);

void Stk_SetIntervalPeriodic(Stk_ValueType Stk_Value);

void Stk_StartTimer(Stk_ValueType Stk_Value);

void Stk_StopTimer(void);

Stk_ValueType Stk_GetTimeElapsed(void);

Stk_ValueType Stk_GetTimeRemaining(void);
void SysTick_Handler(void);
#endif