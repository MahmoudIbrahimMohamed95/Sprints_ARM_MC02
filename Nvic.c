#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Nvic.h"
#include "Nvic_Cfg.h"
#include "Nvic_Private.h"

void IntCtrl_Init(void){

 SCB_APINT=		0x00004000;

 NVIC_EN0=		0x00004000;
 NVIC_EN1=		0x00004000;
 NVIC_EN2=		0x00004000;
 NVIC_EN3=		0x00004000;
 NVIC_EN4=		0x00004000;
/*
 NVIC_DIS0=				
 NVIC_DIS1=		
 NVIC_DIS2=		
 NVIC_DIS3=		
 NVIC_DIS4=		


 NVIC_PRI0=			
 NVIC_PRI1=		
 NVIC_PRI2=		
 NVIC_PRI3=		
 NVIC_PRI4=		
 NVIC_PRI5=		
 NVIC_PRI6=		
 NVIC_PRI7=		
 NVIC_PRI8=		
 NVIC_PRI9=		
 NVIC_PRI10=		
 NVIC_PRI11=		
 NVIC_PRI12=		
 NVIC_PRI13=		
 NVIC_PRI14=		
 NVIC_PRI15=		
 NVIC_PRI16=		
 NVIC_PRI17=		
 NVIC_PRI18=		
*/
}
