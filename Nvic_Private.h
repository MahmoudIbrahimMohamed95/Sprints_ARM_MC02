
#ifndef Nvic_PRIVATE_H_

#define Nvic_PRIVATE_H_

#define SCB_APINT		*((volatile uint32*)(0xE000E000+0xD0C)) 

#define NVIC_EN0		*((volatile uint32*)(0xE000E000+0x100))
#define	NVIC_EN1		*((volatile uint32*)(0xE000E000+0x104))
#define	NVIC_EN2		*((volatile uint32*)(0xE000E000+0x108))
#define	NVIC_EN3		*((volatile uint32*)(0xE000E000+0x10C))
#define	NVIC_EN4		*((volatile uint32*)(0xE000E000+0x110))

#define NVIC_DIS0		*((volatile uint32*)(0xE000E000+0x180))		
#define NVIC_DIS1		*((volatile uint32*)(0xE000E000+0x184))
#define NVIC_DIS2		*((volatile uint32*)(0xE000E000+0x188))
#define NVIC_DIS3		*((volatile uint32*)(0xE000E000+0x18C))
#define NVIC_DIS4		*((volatile uint32*)(0xE000E000+0x190))



#define NVIC_PEND0		*((volatile uint32*)(0xE000E000+0x200))		
#define NVIC_PEND1		*((volatile uint32*)(0xE000E000+0x204))
#define NVIC_PEND2		*((volatile uint32*)(0xE000E000+0x208))
#define NVIC_PEND3		*((volatile uint32*)(0xE000E000+0x20C))
#define NVIC_PEND4		*((volatile uint32*)(0xE000E000+0x210))


#define NVIC_UNPEND0		*((volatile uint32*)(0xE000E000+0x280))		
#define NVIC_UNPEND1		*((volatile uint32*)(0xE000E000+0x284))
#define NVIC_UNPEND2		*((volatile uint32*)(0xE000E000+0x288))
#define NVIC_UNPEND3		*((volatile uint32*)(0xE000E000+0x28C))
#define NVIC_UNPEND4		*((volatile uint32*)(0xE000E000+0x290))



#define NVIC_ACTIVE0		*((volatile uint32*)(0xE000E000+0x300))		
#define NVIC_ACTIVE1		*((volatile uint32*)(0xE000E000+0x304))
#define NVIC_ACTIVE2		*((volatile uint32*)(0xE000E000+0x308))
#define NVIC_ACTIVE3		*((volatile uint32*)(0xE000E000+0x30C))
#define NVIC_ACTIVE4		*((volatile uint32*)(0xE000E000+0x310))



#define NVIC_PRI0		*((volatile uint32*)(0xE000E000+0x400))		
#define NVIC_PRI1		*((volatile uint32*)(0xE000E000+0x404))
#define NVIC_PRI2		*((volatile uint32*)(0xE000E000+0x408))
#define NVIC_PRI3		*((volatile uint32*)(0xE000E000+0x40C))
#define NVIC_PRI4		*((volatile uint32*)(0xE000E000+0x410))
#define NVIC_PRI5		*((volatile uint32*)(0xE000E000+0x414))
#define NVIC_PRI6		*((volatile uint32*)(0xE000E000+0x418))
#define NVIC_PRI7		*((volatile uint32*)(0xE000E000+0x41C))
#define NVIC_PRI8		*((volatile uint32*)(0xE000E000+0x420))
#define NVIC_PRI9		*((volatile uint32*)(0xE000E000+0x424))
#define NVIC_PRI10		*((volatile uint32*)(0xE000E000+0x428))
#define NVIC_PRI11		*((volatile uint32*)(0xE000E000+0x42C))
#define NVIC_PRI12		*((volatile uint32*)(0xE000E000+0x430))
#define NVIC_PRI13		*((volatile uint32*)(0xE000E000+0x434))
#define NVIC_PRI14		*((volatile uint32*)(0xE000E000+0x438))
#define NVIC_PRI15		*((volatile uint32*)(0xE000E000+0x43C))
#define NVIC_PRI16		*((volatile uint32*)(0xE000E000+0x440))
#define NVIC_PRI17		*((volatile uint32*)(0xE000E000+0x444))
#define NVIC_PRI18		*((volatile uint32*)(0xE000E000+0x448))


#endif


