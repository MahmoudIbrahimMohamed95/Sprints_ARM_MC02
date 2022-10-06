#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Nvic.h"
#include "Nvic_Private.h"

void Nvic_IntCtrlInit(const Nvic_ConfigType* ConfigPtr){

    uint32 priority_Indix= (ConfigPtr->IntCtrl_Interrupt) / 4;

    uint32 priority_Shifting= (ConfigPtr->IntCtrl_Interrupt) % 4;

    NVIC_PRI[priority_Indix] =  ((ConfigPtr->Periority)<<((priority_Shifting * 8)+5)); 
		

}


void Nvic_IntEnable (IntCtrl_InterruptType InterruptType){

    if(InterruptType<=31){

        SET_BIT( NVIC_EN0 ,InterruptType);

    }
    else if(InterruptType <= 63){

    
        SET_BIT( NVIC_EN1 ,(InterruptType-32));    

    }
    else if(InterruptType <= 95){

        SET_BIT( NVIC_EN2 ,(InterruptType-64));

    }
		else if(InterruptType <= 127){

        SET_BIT( NVIC_EN3 ,(InterruptType-96));

    }
    else{

        ;

        }
}

void Nvic_IntDisable (IntCtrl_InterruptType InterruptType){

    
    if(InterruptType<=31){

        SET_BIT( NVIC_DIS0 ,InterruptType);

    }
    else if(InterruptType <= 63){

    
        SET_BIT( NVIC_DIS1 ,(InterruptType-32));    

    }
    else if(InterruptType <= 95){

        SET_BIT( NVIC_DIS2 ,(InterruptType-64));

    }
		else if(InterruptType <= 127){

        SET_BIT( NVIC_DIS3 ,(InterruptType-96));

    }
    else{

        ;

        }

}

void Nvic_SetPendingFlag (IntCtrl_InterruptType InterruptType){

    
    if(InterruptType<=31){

        SET_BIT( NVIC_PEND0 ,InterruptType);

    }
    else if(InterruptType <= 63){

    
        SET_BIT( NVIC_PEND1 ,(InterruptType-32));    

    }
    else if(InterruptType <= 95){

        SET_BIT( NVIC_PEND2 ,(InterruptType-64));

    }
    else{

        ;

        }


}

void Nvic_ClearPendingFlag (IntCtrl_InterruptType InterruptType){

    
    if(InterruptType<=31){

        SET_BIT( NVIC_UNPEND0 ,InterruptType);

    }
    else if(InterruptType <= 63){

    
        SET_BIT( NVIC_UNPEND1 ,(InterruptType-32));    

    }
    else if(InterruptType <= 95){

        SET_BIT( NVIC_UNPEND2 ,(InterruptType-64));

    }
    else{

        ;

        }
        
}
void Nvic_TriggerSwInt (IntCtrl_InterruptType InterruptType){


    NVIC_SWTRIG= InterruptType;

}