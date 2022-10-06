#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Stk.h"
#include "Stk_Private.h"


static volatile void (*Stk_CallBackPtr)(void) = NULL_PTR;

void Stk_Init(const Stk_ConfigType* ConfigPtr){

    switch (ConfigPtr->Stk_Int){
 
        case STK_INT_EN:   
           SET_BIT (STK_STCTRL , 1); break;
 
        case STK_INT_DIS: 
           CLR_BIT( STK_STCTRL , 1); break;
 
        default: break;  
    }
    switch (ConfigPtr->Stk_Clock){
 
        case STK_PIOSC_DIV4 :   
  
           CLR_BIT (STK_STCTRL , 2); break;
 
        case STK_SYSTEM_CLOCK: 
  
           SET_BIT(STK_STCTRL , 2); break;
 
        default: break;  
    }
 
    Stk_CallBackPtr= ConfigPtr->Stk_Notification;

}

void Stk_SetBusyWait(Stk_ValueType Stk_Value){     

    STK_STRELOAD= Stk_Value;

		SET_BIT(STK_STCTRL , 0);

		while((GET_BIT(STK_STCTRL , 16))==0){
			continue;
		}

        CLR_BIT(STK_STCTRL , 0);

        STK_STRELOAD= 0;

        STK_STCURRENT=0;
}

void Stk_SetIntervalPeriodic(Stk_ValueType Stk_Value){

        SET_BIT(STK_STCTRL , 0);

        STK_STRELOAD= Stk_Value;

}


void Stk_StopTimer(void){

    CLR_BIT(STK_STCTRL , 0);

        STK_STRELOAD= 0;

        STK_STCURRENT=0;
}


Stk_ValueType Stk_GetTimeElapsed(void){

    return (STK_STRELOAD - STK_STCURRENT );
}


Stk_ValueType Stk_GetTimeRemaining(void){

    return STK_STCURRENT;
}

void SysTick_Handler(void){

    if(Stk_CallBackPtr != NULL_PTR){

         Stk_CallBackPtr();   

    }
}