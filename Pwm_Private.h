#ifndef GPT_PRIVATE_H_
#define GPT_PRIVATE_H_

#include "STD_TYPES.h"
/****************************************************************************************************************************
											Register Mapping
****************************************************************************************************************************/

#define GPTMPP   0xFC0   /* last register base address*/



#define TIMER0_16_32_BaseAddress  ((volatile uint32*)0x40030000)										
#define TIMER1_16_32_BaseAddress  ((volatile uint32*)0x40031000)
#define TIMER2_16_32_BaseAddress  ((volatile uint32*)0x40032000)
#define TIMER3_16_32_BaseAddress  ((volatile uint32*)0x40033000)
#define TIMER4_16_32_BaseAddress  ((volatile uint32*)0x40034000)
#define TIMER5_16_32_BaseAddress  ((volatile uint32*)0x40035000)



#define TIMER0_32_64_BaseAddress  ((volatile uint32*)0x40036000)										
#define TIMER1_32_64_BaseAddress  ((volatile uint32*)0x40037000)
#define TIMER2_32_64_BaseAddress  ((volatile uint32*)0x4004C000)
#define TIMER3_32_64_BaseAddress  ((volatile uint32*)0x4004D000)
#define TIMER4_32_64_BaseAddress  ((volatile uint32*)0x4004E000)
#define TIMER5_32_64_BaseAddress  ((volatile uint32*)0x4004F000)



typedef struct{

volatile uint32 GPTMCFG;

volatile uint32 GPTMTAMR;

volatile uint32 GPTMTBMR;

volatile uint32 GPTMCTL;

volatile uint32 GPTMSYNC[2];

volatile uint32 GPTMIMR;

volatile uint32 GPTMRIS;

volatile uint32 GPTMMIS;

volatile uint32 GPTMICR;

volatile uint32 GPTMTAILR;

volatile uint32 GPTMTBILR;

volatile uint32 GPTMTAMATCHR;

volatile uint32 GPTMTAMBTCHR;

volatile uint32 GPTMTAPR;

volatile uint32 GPTMTBPR;

volatile uint32 GPTMTAPMR;

volatile uint32 GPTMTBPMR;

volatile uint32 GPTMTAR;

volatile uint32 GPTMTBR;

volatile uint32 GPTMTAV;

volatile uint32 GPTMTBV;

volatile uint32 GPTMRTCPD;

volatile uint32 GPTMTAPS;

volatile uint32 GPTMTBPS;

volatile uint32 GPTMTAPV;

volatile uint32 GPTMTBPV;


}Gpt_RegsType;

const volatile uint32*TimerBaseAddress[12]={

  TIMER0_16_32_BaseAddress  , TIMER1_16_32_BaseAddress 
 ,TIMER2_16_32_BaseAddress  , TIMER3_16_32_BaseAddress
 ,TIMER4_16_32_BaseAddress  , TIMER5_16_32_BaseAddress
 ,TIMER0_32_64_BaseAddress  , TIMER1_32_64_BaseAddress 
 ,TIMER2_32_64_BaseAddress  , TIMER3_32_64_BaseAddress 
 ,TIMER4_32_64_BaseAddress  , TIMER5_32_64_BaseAddress

};

#endif
