/****************************************************************************************************************************************************************	

											MCU_HW_DEFINATIONS USING STRUCTS AND #DEFINE
											
*****************************************************************************************************************************************************************/											

#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_


#include "STD_TYPES.h"



/****************************************************************************************************************************
					FIRST: define BIT_BAND_ALIAS_BASE_ADDRESS

*****************************************************************************************************************************/
 

 #define BIT_BAND_ALIAS_BASE_ADDRESS  0x42000000    /*BIT BAND ALIAS OFFSET*/
 
 
 

/**************************************************************************************************************************** 
 
					SECOND: define BIT_BANDING_EQN

*****************************************************************************************************************************/

 /*commment: #define BIT_BANDING_ADDRESS(BYTE_OFFSET , BIT_NUMBER)                (volatile uint32*)(BIT_BAND_ALIAS_BASE_ADDRESS + (BYTE_OFFSET * 32 )+ (BIT_NUMBER * 4))*/
 
   #define BIT_BANDING(PERIPHRAL_OFFSET , REGISTER_OFFSET , BIT_NUMBER)	((volatile uint32*)(BIT_BAND_ALIAS_BASE_ADDRESS + ((PERIPHRAL_OFFSET + REGISTER_OFFSET) * 32 )))[BIT_NUMBER]
	
	
/**************************************************************************************************************************** 
 
THIRD: DEFINE PORT_BASE_ADDRESS AND PORT_OFFSET

*****************************************************************************************************************************/


#define  APB_GPIO_PORTA_BASE_ADDRESS			 0x40004000
#define  APB_GPIO_PORTB_BASE_ADDRESS			 0x40005000
#define  APB_GPIO_PORTC_BASE_ADDRESS			 0x40006000
#define  APB_GPIO_PORTD_BASE_ADDRESS			 0x40007000
#define  APB_GPIO_PORTE_BASE_ADDRESS			 0x40024000
#define  APB_GPIO_PORTF_BASE_ADDRESS 		     0x40025000  



#define  AHB_GPIO_PORTA_BASE_ADDRESS			 0x40058000
#define  AHB_GPIO_PORTB_BASE_ADDRESS			 0x40059000
#define  AHB_GPIO_PORTC_BASE_ADDRESS			 0x4005A000
#define  AHB_GPIO_PORTD_BASE_ADDRESS			 0x4005B000
#define  AHB_GPIO_PORTE_BASE_ADDRESS			 0x4005C000
#define  AHB_GPIO_PORTF_BASE_ADDRESS 		     0x4005D000  



#define  APB_GPIO_PORTA_OFFSET			 0x00004000
#define  APB_GPIO_PORTB_OFFSET			 0x00005000
#define  APB_GPIO_PORTC_OFFSET			 0x00006000
#define  APB_GPIO_PORTD_OFFSET			 0x00007000
#define  APB_GPIO_PORTE_OFFSET			 0x00024000
#define  APB_GPIO_PORTF_OFFSET 		     0x00025000  



#define  AHB_GPIO_PORTA_OFFSET			 0x00058000
#define  AHB_GPIO_PORTB_OFFSET			 0x00059000
#define  AHB_GPIO_PORTC_OFFSET			 0x0005A000
#define  AHB_GPIO_PORTD_OFFSET			 0x0005B000
#define  AHB_GPIO_PORTE_OFFSET			 0x0005C000
#define  AHB_GPIO_PORTF_OFFSET		     0x0005D000  
 

/**************************************************************************************************************************** 
 
FOURTH: DEFINE PERIPHRAL_OFFSET

*****************************************************************************************************************************/




#define GPIODATA_OFFSET                 0x000     
#define	GPIODIR_OFFSET					0x400
#define	GPIOIS_OFFSET					0x404
#define	GPIOIBE_OFFSET					0x408
#define	GPIOIEV_OFFSET					0x40C
#define	GPIOIM_OFFSET					0x410
#define	GPIORIS_OFFSET					0x414  
#define	GPIOMIS_OFFSET					0x418
#define	GPIOICR_OFFSET					0x41C
#define	GPIOAFSEL_OFFSET				0x420
#define	GPIODR2R_OFFSET					0x500
#define	GPIODR4R_OFFSET					0x504
#define	GPIODR8R_OFFSET					0x508
#define	GPIOODR_OFFSET					0x50C
#define	GPIOPUR_OFFSET					0x510
#define	GPIOPDR_OFFSET					0x514
#define	GPIOSLR_OFFSET					0x518
#define	GPIODEN_OFFSET					0x51C
#define	GPIOLOCK_OFFSET					0x520
#define	GPIOCR_OFFSET					0x524
#define	GPIOAMSEL_OFFSET				0x528
#define	GPIOPCTL_OFFSET					0x52C
#define	GPIOADCCTL_OFFSET				0x530
#define	GPIODMACTL_OFFSET				0x534
#define	GPIOPeriphID4_OFFSET			0xFD0
#define	GPIOPeriphID5_OFFSET			0xFD4
#define	GPIOPeriphID6_OFFSET			0xFD8
#define	GPIOPeriphID7_OFFSET			0xFDC
#define	GPIOPeriphID0_OFFSET			0xFE0
#define	GPIOPeriphID1_OFFSET			0xFE4
#define	GPIOPeriphID2_OFFSET			0xFE8
#define	GPIOPeriphID3_OFFSET			0xFEC
#define	GPIOPCelllD0_OFFSET				0xFF0
#define	GPIOPCelllD1_OFFSET				0xFF4
#define	GPIOPCelllD2_OFFSET				0xFF8
#define	GPIOPCelllD3_OFFSET				0xFFC


/**************************************************************************************************************************** 
 
FIFTH: DEFINE PERIPHRAL_ADDRESS

*****************************************************************************************************************************/

/*****************************************************AT APB_BUS*************************************************************/

#define APB_GPIOA_DATA             			((volatile uint32*)(APB_GPIO_PORTA_BASE_ADDRESS+GPIODATA_OFFSET))  // Defintion as a pointer to access it using indixing.     
#define APB_GPIOA_DIR						*((volatile uint32*)(APB_GPIO_PORTA_BASE_ADDRESS+GPIODIR_OFFSET))
#define APB_GPIOA_IS						*((volatile uint32*)(APB_GPIO_PORTA_BASE_ADDRESS+GPIOIS_OFFSET))
#define APB_GPIOA_IBE						*((volatile uint32*)(APB_GPIO_PORTA_BASE_ADDRESS+GPIOIBE_OFFSET))
#define APB_GPIOA_IEV						*((volatile uint32*)(APB_GPIO_PORTA_BASE_ADDRESS+GPIOIEV_OFFSET))
#define APB_GPIOA_IM						*((volatile uint32*)(APB_GPIO_PORTA_BASE_ADDRESS+GPIOIM_OFFSET))
#define APB_GPIOA_RIS						*((volatile uint32*)(APB_GPIO_PORTA_BASE_ADDRESS+GPIORIS_OFFSET))
#define APB_GPIOA_MIS						*((volatile uint32*)(APB_GPIO_PORTA_BASE_ADDRESS+GPIOMIS_OFFSET))
#define APB_GPIOA_ICR						*((volatile uint32*)(APB_GPIO_PORTA_BASE_ADDRESS+GPIOICR_OFFSET))
#define APB_GPIOA_AFSEL						*((volatile uint32*)(APB_GPIO_PORTA_BASE_ADDRESS+GPIOAFSEL_OFFSET))
#define APB_GPIOA_DR2R						*((volatile uint32*)(APB_GPIO_PORTA_BASE_ADDRESS+GPIODR2R_OFFSET))
#define APB_GPIOA_DR4R						*((volatile uint32*)(APB_GPIO_PORTA_BASE_ADDRESS+GPIODR4R_OFFSET))
#define APB_GPIOA_DR8R						*((volatile uint32*)(APB_GPIO_PORTA_BASE_ADDRESS+GPIODR8R_OFFSET))
#define APB_GPIOA_ODR						*((volatile uint32*)(APB_GPIO_PORTA_BASE_ADDRESS+GPIOODR_OFFSET))
#define APB_GPIOA_PUR						*((volatile uint32*)(APB_GPIO_PORTA_BASE_ADDRESS+GPIOPUR_OFFSET))
#define APB_GPIOA_SLR						*((volatile uint32*)(APB_GPIO_PORTA_BASE_ADDRESS+GPIOSLR_OFFSET))
#define APB_GPIOA_DEN						*((volatile uint32*)(APB_GPIO_PORTA_BASE_ADDRESS+GPIODEN_OFFSET))
#define APB_GPIOA_LOCK						*((volatile uint32*)(APB_GPIO_PORTA_BASE_ADDRESS+GPIOLOCK_OFFSET))
#define APB_GPIOA_CR						*((volatile uint32*)(APB_GPIO_PORTA_BASE_ADDRESS+GPIOCR_OFFSET))
#define APB_GPIOA_AMSEL						*((volatile uint32*)(APB_GPIO_PORTA_BASE_ADDRESS+GPIOAMSEL_OFFSET))
#define APB_GPIOA_PCTL						*((volatile uint32*)(APB_GPIO_PORTA_BASE_ADDRESS+GPIOPCTL_OFFSET))
#define APB_GPIOA_ADCCTL					*((volatile uint32*)(APB_GPIO_PORTA_BASE_ADDRESS+GPIOADCCTL_OFFSET))
#define APB_GPIOA_DMACTL					*((volatile uint32*)(APB_GPIO_PORTA_BASE_ADDRESS+GPIODMACTL_OFFSET))
#define APB_GPIOA_PeriphID4					*((volatile uint32*)(APB_GPIO_PORTA_BASE_ADDRESS+GPIOPeriphID4_OFFSET))
#define APB_GPIOA_PeriphID5					*((volatile uint32*)(APB_GPIO_PORTA_BASE_ADDRESS+GPIOPeriphID5_OFFSET))
#define APB_GPIOA_PeriphID6					*((volatile uint32*)(APB_GPIO_PORTA_BASE_ADDRESS+GPIOPeriphID6_OFFSET))
#define APB_GPIOA_PeriphID7					*((volatile uint32*)(APB_GPIO_PORTA_BASE_ADDRESS+GPIOPeriphID7_OFFSET))
#define APB_GPIOA_PeriphID0					*((volatile uint32*)(APB_GPIO_PORTA_BASE_ADDRESS+GPIOPeriphID0_OFFSET)
#define APB_GPIOA_PeriphID1					*((volatile uint32*)(APB_GPIO_PORTA_BASE_ADDRESS+GPIOPeriphID1_OFFSET))
#define APB_GPIOA_PeriphID2					*((volatile uint32*)(APB_GPIO_PORTA_BASE_ADDRESS+GPIOPeriphID2_OFFSET))
#define APB_GPIOA_PeriphID3					*((volatile uint32*)(APB_GPIO_PORTA_BASE_ADDRESS+GPIOPeriphID3_OFFSET))
#define APB_GPIOA_PCellID0					*((volatile uint32*)(APB_GPIO_PORTA_BASE_ADDRESS+GPIOPCelllD0_OFFSET))
#define APB_GPIOA_PCellID1					*((volatile uint32*)(APB_GPIO_PORTA_BASE_ADDRESS+GPIOPCelllD1_OFFSET))
#define APB_GPIOA_PCellID2					*((volatile uint32*)(APB_GPIO_PORTA_BASE_ADDRESS+GPIOPCelllD2_OFFSET))
#define APB_GPIOA_PCellID3					*((volatile uint32*)(APB_GPIO_PORTA_BASE_ADDRESS+GPIOPCelllD3_OFFSET))
					


#define APB_GPIOB_DATA             			((volatile uint32*)(APB_GPIO_PORTB_BASE_ADDRESS+GPIODATA_OFFSET))     
#define APB_GPIOB_DIR						*((volatile uint32*)(APB_GPIO_PORTB_BASE_ADDRESS+GPIODIR_OFFSET))
#define APB_GPIOB_IS						*((volatile uint32*)(APB_GPIO_PORTB_BASE_ADDRESS+GPIOIS_OFFSET))
#define APB_GPIOB_IBE						*((volatile uint32*)(APB_GPIO_PORTB_BASE_ADDRESS+GPIOIBE_OFFSET))
#define APB_GPIOB_IEV						*((volatile uint32*)(APB_GPIO_PORTB_BASE_ADDRESS+GPIOIEV_OFFSET))
#define APB_GPIOB_IM						*((volatile uint32*)(APB_GPIO_PORTB_BASE_ADDRESS+GPIOIM_OFFSET))
#define APB_GPIOB_RIS						*((volatile uint32*)(APB_GPIO_PORTB_BASE_ADDRESS+GPIORIS_OFFSET))
#define APB_GPIOB_MIS						*((volatile uint32*)(APB_GPIO_PORTB_BASE_ADDRESS+GPIOMIS_OFFSET))
#define APB_GPIOB_ICR						*((volatile uint32*)(APB_GPIO_PORTB_BASE_ADDRESS+GPIOICR_OFFSET))
#define APB_GPIOB_AFSEL						*((volatile uint32*)(APB_GPIO_PORTB_BASE_ADDRESS+GPIOAFSEL_OFFSET))
#define APB_GPIOB_DR2R						*((volatile uint32*)(APB_GPIO_PORTB_BASE_ADDRESS+GPIODR2R_OFFSET))
#define APB_GPIOB_DR4R						*((volatile uint32*)(APB_GPIO_PORTB_BASE_ADDRESS+GPIODR4R_OFFSET))
#define APB_GPIOB_DR8R						*((volatile uint32*)(APB_GPIO_PORTB_BASE_ADDRESS+GPIODR8R_OFFSET))
#define APB_GPIOB_ODR						*((volatile uint32*)(APB_GPIO_PORTB_BASE_ADDRESS+GPIOODR_OFFSET))
#define APB_GPIOB_PUR						*((volatile uint32*)(APB_GPIO_PORTB_BASE_ADDRESS+GPIOPUR_OFFSET))
#define APB_GPIOB_SLR						*((volatile uint32*)(APB_GPIO_PORTB_BASE_ADDRESS+GPIOSLR_OFFSET))
#define APB_GPIOB_DEN						*((volatile uint32*)(APB_GPIO_PORTB_BASE_ADDRESS+GPIODEN_OFFSET))
#define APB_GPIOB_LOCK						*((volatile uint32*)(APB_GPIO_PORTB_BASE_ADDRESS+GPIOLOCK_OFFSET))
#define APB_GPIOB_CR						*((volatile uint32*)(APB_GPIO_PORTB_BASE_ADDRESS+GPIOCR_OFFSET))
#define APB_GPIOB_AMSEL						*((volatile uint32*)(APB_GPIO_PORTB_BASE_ADDRESS+GPIOAMSEL_OFFSET))
#define APB_GPIOB_PCTL						*((volatile uint32*)(APB_GPIO_PORTB_BASE_ADDRESS+GPIOPCTL_OFFSET))
#define APB_GPIOB_ADCCTL					*((volatile uint32*)(APB_GPIO_PORTB_BASE_ADDRESS+GPIOADCCTL_OFFSET))
#define APB_GPIOB_DMACTL					*((volatile uint32*)(APB_GPIO_PORTB_BASE_ADDRESS+GPIODMACTL_OFFSET))
#define APB_GPIOB_PeriphID4					*((volatile uint32*)(APB_GPIO_PORTB_BASE_ADDRESS+GPIOPeriphID4_OFFSET))
#define APB_GPIOB_PeriphID5					*((volatile uint32*)(APB_GPIO_PORTB_BASE_ADDRESS+GPIOPeriphID5_OFFSET))
#define APB_GPIOB_PeriphID6					*((volatile uint32*)(APB_GPIO_PORTB_BASE_ADDRESS+GPIOPeriphID6_OFFSET))
#define APB_GPIOB_PeriphID7					*((volatile uint32*)(APB_GPIO_PORTB_BASE_ADDRESS+GPIOPeriphID7_OFFSET))
#define APB_GPIOB_PeriphID0					*((volatile uint32*)(APB_GPIO_PORTB_BASE_ADDRESS+GPIOPeriphID0_OFFSET)
#define APB_GPIOB_PeriphID1					*((volatile uint32*)(APB_GPIO_PORTB_BASE_ADDRESS+GPIOPeriphID1_OFFSET))
#define APB_GPIOB_PeriphID2					*((volatile uint32*)(APB_GPIO_PORTB_BASE_ADDRESS+GPIOPeriphID2_OFFSET))
#define APB_GPIOB_PeriphID3					*((volatile uint32*)(APB_GPIO_PORTB_BASE_ADDRESS+GPIOPeriphID3_OFFSET))
#define APB_GPIOB_PCellID0					*((volatile uint32*)(APB_GPIO_PORTB_BASE_ADDRESS+GPIOPCelllD0_OFFSET))
#define APB_GPIOB_PCellID1					*((volatile uint32*)(APB_GPIO_PORTB_BASE_ADDRESS+GPIOPCelllD1_OFFSET))
#define APB_GPIOB_PCellID2					*((volatile uint32*)(APB_GPIO_PORTB_BASE_ADDRESS+GPIOPCelllD2_OFFSET))
#define APB_GPIOB_PCellID3					*((volatile uint32*)(APB_GPIO_PORTB_BASE_ADDRESS+GPIOPCelllD3_OFFSET))





#define APB_GPIOC_DATA             			((volatile uint32*)(APB_GPIO_PORTC_BASE_ADDRESS+GPIODATA_OFFSET))     
#define APB_GPIOC_DIR						*((volatile uint32*)(APB_GPIO_PORTC_BASE_ADDRESS+GPIODIR_OFFSET))
#define APB_GPIOC_IS						*((volatile uint32*)(APB_GPIO_PORTC_BASE_ADDRESS+GPIOIS_OFFSET))
#define APB_GPIOC_IBE						*((volatile uint32*)(APB_GPIO_PORTC_BASE_ADDRESS+GPIOIBE_OFFSET))
#define APB_GPIOC_IEV						*((volatile uint32*)(APB_GPIO_PORTC_BASE_ADDRESS+GPIOIEV_OFFSET))
#define APB_GPIOC_IM						*((volatile uint32*)(APB_GPIO_PORTC_BASE_ADDRESS+GPIOIM_OFFSET))
#define APB_GPIOC_RIS						*((volatile uint32*)(APB_GPIO_PORTC_BASE_ADDRESS+GPIORIS_OFFSET))
#define APB_GPIOC_MIS						*((volatile uint32*)(APB_GPIO_PORTC_BASE_ADDRESS+GPIOMIS_OFFSET))
#define APB_GPIOC_ICR						*((volatile uint32*)(APB_GPIO_PORTC_BASE_ADDRESS+GPIOICR_OFFSET))
#define APB_GPIOC_AFSEL						*((volatile uint32*)(APB_GPIO_PORTC_BASE_ADDRESS+GPIOAFSEL_OFFSET))
#define APB_GPIOC_DR2R						*((volatile uint32*)(APB_GPIO_PORTC_BASE_ADDRESS+GPIODR2R_OFFSET))
#define APB_GPIOC_DR4R						*((volatile uint32*)(APB_GPIO_PORTC_BASE_ADDRESS+GPIODR4R_OFFSET))
#define APB_GPIOC_DR8R						*((volatile uint32*)(APB_GPIO_PORTC_BASE_ADDRESS+GPIODR8R_OFFSET))
#define APB_GPIOC_ODR						*((volatile uint32*)(APB_GPIO_PORTC_BASE_ADDRESS+GPIOODR_OFFSET))
#define APB_GPIOC_PUR						*((volatile uint32*)(APB_GPIO_PORTC_BASE_ADDRESS+GPIOPUR_OFFSET))
#define APB_GPIOC_SLR						*((volatile uint32*)(APB_GPIO_PORTC_BASE_ADDRESS+GPIOSLR_OFFSET))
#define APB_GPIOC_DEN						*((volatile uint32*)(APB_GPIO_PORTC_BASE_ADDRESS+GPIODEN_OFFSET))
#define APB_GPIOC_LOCK						*((volatile uint32*)(APB_GPIO_PORTC_BASE_ADDRESS+GPIOLOCK_OFFSET))
#define APB_GPIOC_CR						*((volatile uint32*)(APB_GPIO_PORTC_BASE_ADDRESS+GPIOCR_OFFSET))
#define APB_GPIOC_AMSEL						*((volatile uint32*)(APB_GPIO_PORTC_BASE_ADDRESS+GPIOAMSEL_OFFSET))
#define APB_GPIOC_PCTL						*((volatile uint32*)(APB_GPIO_PORTC_BASE_ADDRESS+GPIOPCTL_OFFSET))
#define APB_GPIOC_ADCCTL					*((volatile uint32*)(APB_GPIO_PORTC_BASE_ADDRESS+GPIOADCCTL_OFFSET))
#define APB_GPIOC_DMACTL					*((volatile uint32*)(APB_GPIO_PORTC_BASE_ADDRESS+GPIODMACTL_OFFSET))
#define APB_GPIOC_PeriphID4					*((volatile uint32*)(APB_GPIO_PORTC_BASE_ADDRESS+GPIOPeriphID4_OFFSET))
#define APB_GPIOC_PeriphID5					*((volatile uint32*)(APB_GPIO_PORTC_BASE_ADDRESS+GPIOPeriphID5_OFFSET))
#define APB_GPIOC_PeriphID6					*((volatile uint32*)(APB_GPIO_PORTC_BASE_ADDRESS+GPIOPeriphID6_OFFSET))
#define APB_GPIOC_PeriphID7					*((volatile uint32*)(APB_GPIO_PORTC_BASE_ADDRESS+GPIOPeriphID7_OFFSET))
#define APB_GPIOC_PeriphID0					*((volatile uint32*)(APB_GPIO_PORTC_BASE_ADDRESS+GPIOPeriphID0_OFFSET)
#define APB_GPIOC_PeriphID1					*((volatile uint32*)(APB_GPIO_PORTC_BASE_ADDRESS+GPIOPeriphID1_OFFSET))
#define APB_GPIOC_PeriphID2					*((volatile uint32*)(APB_GPIO_PORTC_BASE_ADDRESS+GPIOPeriphID2_OFFSET))
#define APB_GPIOC_PeriphID3					*((volatile uint32*)(APB_GPIO_PORTC_BASE_ADDRESS+GPIOPeriphID3_OFFSET))
#define APB_GPIOC_PCellID0					*((volatile uint32*)(APB_GPIO_PORTC_BASE_ADDRESS+GPIOPCelllD0_OFFSET))
#define APB_GPIOC_PCellID1					*((volatile uint32*)(APB_GPIO_PORTC_BASE_ADDRESS+GPIOPCelllD1_OFFSET))
#define APB_GPIOC_PCellID2					*((volatile uint32*)(APB_GPIO_PORTC_BASE_ADDRESS+GPIOPCelllD2_OFFSET))
#define APB_GPIOC_PCellID3					*((volatile uint32*)(APB_GPIO_PORTC_BASE_ADDRESS+GPIOPCelllD3_OFFSET))




#define APB_GPIOD_DATA             			((volatile uint32*) (APB_GPIO_PORTD_BASE_ADDRESS+GPIODATA_OFFSET))     
#define APB_GPIOD_DIR						*((volatile uint32*)(APB_GPIO_PORTD_BASE_ADDRESS+GPIODIR_OFFSET))
#define APB_GPIOD_IS						*((volatile uint32*)(APB_GPIO_PORTD_BASE_ADDRESS+GPIOIS_OFFSET))
#define APB_GPIOD_IBE						*((volatile uint32*)(APB_GPIO_PORTD_BASE_ADDRESS+GPIOIBE_OFFSET))
#define APB_GPIOD_IEV						*((volatile uint32*)(APB_GPIO_PORTD_BASE_ADDRESS+GPIOIEV_OFFSET))
#define APB_GPIOD_IM						*((volatile uint32*)(APB_GPIO_PORTD_BASE_ADDRESS+GPIOIM_OFFSET))
#define APB_GPIOD_RIS						*((volatile uint32*)(APB_GPIO_PORTD_BASE_ADDRESS+GPIORIS_OFFSET))
#define APB_GPIOD_MIS						*((volatile uint32*)(APB_GPIO_PORTD_BASE_ADDRESS+GPIOMIS_OFFSET))
#define APB_GPIOD_ICR						*((volatile uint32*)(APB_GPIO_PORTD_BASE_ADDRESS+GPIOICR_OFFSET))
#define APB_GPIOD_AFSEL						*((volatile uint32*)(APB_GPIO_PORTD_BASE_ADDRESS+GPIOAFSEL_OFFSET))
#define APB_GPIOD_DR2R						*((volatile uint32*)(APB_GPIO_PORTD_BASE_ADDRESS+GPIODR2R_OFFSET))
#define APB_GPIOD_DR4R						*((volatile uint32*)(APB_GPIO_PORTD_BASE_ADDRESS+GPIODR4R_OFFSET))
#define APB_GPIOD_DR8R						*((volatile uint32*)(APB_GPIO_PORTD_BASE_ADDRESS+GPIODR8R_OFFSET))
#define APB_GPIOD_ODR						*((volatile uint32*)(APB_GPIO_PORTD_BASE_ADDRESS+GPIOODR_OFFSET))
#define APB_GPIOD_PUR						*((volatile uint32*)(APB_GPIO_PORTD_BASE_ADDRESS+GPIOPUR_OFFSET))
#define APB_GPIOD_SLR						*((volatile uint32*)(APB_GPIO_PORTD_BASE_ADDRESS+GPIOSLR_OFFSET))
#define APB_GPIOD_DEN						*((volatile uint32*)(APB_GPIO_PORTD_BASE_ADDRESS+GPIODEN_OFFSET))
#define APB_GPIOD_LOCK						*((volatile uint32*)(APB_GPIO_PORTD_BASE_ADDRESS+GPIOLOCK_OFFSET))
#define APB_GPIOD_CR						*((volatile uint32*)(APB_GPIO_PORTD_BASE_ADDRESS+GPIOCR_OFFSET))
#define APB_GPIOD_AMSEL						*((volatile uint32*)(APB_GPIO_PORTD_BASE_ADDRESS+GPIOAMSEL_OFFSET))
#define APB_GPIOD_PCTL						*((volatile uint32*)(APB_GPIO_PORTD_BASE_ADDRESS+GPIOPCTL_OFFSET))
#define APB_GPIOD_ADCCTL					*((volatile uint32*)(APB_GPIO_PORTD_BASE_ADDRESS+GPIOADCCTL_OFFSET))
#define APB_GPIOD_DMACTL					*((volatile uint32*)(APB_GPIO_PORTD_BASE_ADDRESS+GPIODMACTL_OFFSET))
#define APB_GPIOD_PeriphID4					*((volatile uint32*)(APB_GPIO_PORTD_BASE_ADDRESS+GPIOPeriphID4_OFFSET))
#define APB_GPIOD_PeriphID5					*((volatile uint32*)(APB_GPIO_PORTD_BASE_ADDRESS+GPIOPeriphID5_OFFSET))
#define APB_GPIOD_PeriphID6					*((volatile uint32*)(APB_GPIO_PORTD_BASE_ADDRESS+GPIOPeriphID6_OFFSET))
#define APB_GPIOD_PeriphID7					*((volatile uint32*)(APB_GPIO_PORTD_BASE_ADDRESS+GPIOPeriphID7_OFFSET))
#define APB_GPIOD_PeriphID0					*((volatile uint32*)(APB_GPIO_PORTD_BASE_ADDRESS+GPIOPeriphID0_OFFSET)
#define APB_GPIOD_PeriphID1					*((volatile uint32*)(APB_GPIO_PORTD_BASE_ADDRESS+GPIOPeriphID1_OFFSET))
#define APB_GPIOD_PeriphID2					*((volatile uint32*)(APB_GPIO_PORTD_BASE_ADDRESS+GPIOPeriphID2_OFFSET))
#define APB_GPIOD_PeriphID3					*((volatile uint32*)(APB_GPIO_PORTD_BASE_ADDRESS+GPIOPeriphID3_OFFSET))
#define APB_GPIOD_PCellID0					*((volatile uint32*)(APB_GPIO_PORTD_BASE_ADDRESS+GPIOPCelllD0_OFFSET))
#define APB_GPIOD_PCellID1					*((volatile uint32*)(APB_GPIO_PORTD_BASE_ADDRESS+GPIOPCelllD1_OFFSET))
#define APB_GPIOD_PCellID2					*((volatile uint32*)(APB_GPIO_PORTD_BASE_ADDRESS+GPIOPCelllD2_OFFSET))
#define APB_GPIOD_PCellID3					*((volatile uint32*)(APB_GPIO_PORTD_BASE_ADDRESS+GPIOPCelllD3_OFFSET))




#define APB_GPIOE_DATA             			((volatile uint32*) (APB_GPIO_PORTE_BASE_ADDRESS+GPIODATA_OFFSET))     
#define APB_GPIOE_DIR						*((volatile uint32*)(APB_GPIO_PORTE_BASE_ADDRESS+GPIODIR_OFFSET))
#define APB_GPIOE_IS						*((volatile uint32*)(APB_GPIO_PORTE_BASE_ADDRESS+GPIOIS_OFFSET))
#define APB_GPIOE_IBE						*((volatile uint32*)(APB_GPIO_PORTE_BASE_ADDRESS+GPIOIBE_OFFSET))
#define APB_GPIOE_IEV						*((volatile uint32*)(APB_GPIO_PORTE_BASE_ADDRESS+GPIOIEV_OFFSET))
#define APB_GPIOE_IM						*((volatile uint32*)(APB_GPIO_PORTE_BASE_ADDRESS+GPIOIM_OFFSET))
#define APB_GPIOE_RIS						*((volatile uint32*)(APB_GPIO_PORTE_BASE_ADDRESS+GPIORIS_OFFSET))
#define APB_GPIOE_MIS						*((volatile uint32*)(APB_GPIO_PORTE_BASE_ADDRESS+GPIOMIS_OFFSET))
#define APB_GPIOE_ICR						*((volatile uint32*)(APB_GPIO_PORTE_BASE_ADDRESS+GPIOICR_OFFSET))
#define APB_GPIOE_AFSEL						*((volatile uint32*)(APB_GPIO_PORTE_BASE_ADDRESS+GPIOAFSEL_OFFSET))
#define APB_GPIOE_DR2R						*((volatile uint32*)(APB_GPIO_PORTE_BASE_ADDRESS+GPIODR2R_OFFSET))
#define APB_GPIOE_DR4R						*((volatile uint32*)(APB_GPIO_PORTE_BASE_ADDRESS+GPIODR4R_OFFSET))
#define APB_GPIOE_DR8R						*((volatile uint32*)(APB_GPIO_PORTE_BASE_ADDRESS+GPIODR8R_OFFSET))
#define APB_GPIOE_ODR						*((volatile uint32*)(APB_GPIO_PORTE_BASE_ADDRESS+GPIOODR_OFFSET))
#define APB_GPIOE_PUR						*((volatile uint32*)(APB_GPIO_PORTE_BASE_ADDRESS+GPIOPUR_OFFSET))
#define APB_GPIOE_SLR						*((volatile uint32*)(APB_GPIO_PORTE_BASE_ADDRESS+GPIOSLR_OFFSET))
#define APB_GPIOE_DEN						*((volatile uint32*)(APB_GPIO_PORTE_BASE_ADDRESS+GPIODEN_OFFSET))
#define APB_GPIOE_LOCK						*((volatile uint32*)(APB_GPIO_PORTE_BASE_ADDRESS+GPIOLOCK_OFFSET))
#define APB_GPIOE_CR						*((volatile uint32*)(APB_GPIO_PORTE_BASE_ADDRESS+GPIOCR_OFFSET))
#define APB_GPIOE_AMSEL						*((volatile uint32*)(APB_GPIO_PORTE_BASE_ADDRESS+GPIOAMSEL_OFFSET))
#define APB_GPIOE_PCTL						*((volatile uint32*)(APB_GPIO_PORTE_BASE_ADDRESS+GPIOPCTL_OFFSET))
#define APB_GPIOE_ADCCTL					*((volatile uint32*)(APB_GPIO_PORTE_BASE_ADDRESS+GPIOADCCTL_OFFSET))
#define APB_GPIOE_DMACTL					*((volatile uint32*)(APB_GPIO_PORTE_BASE_ADDRESS+GPIODMACTL_OFFSET))
#define APB_GPIOE_PeriphID4					*((volatile uint32*)(APB_GPIO_PORTE_BASE_ADDRESS+GPIOPeriphID4_OFFSET))
#define APB_GPIOE_PeriphID5					*((volatile uint32*)(APB_GPIO_PORTE_BASE_ADDRESS+GPIOPeriphID5_OFFSET))
#define APB_GPIOE_PeriphID6					*((volatile uint32*)(APB_GPIO_PORTE_BASE_ADDRESS+GPIOPeriphID6_OFFSET))
#define APB_GPIOE_PeriphID7					*((volatile uint32*)(APB_GPIO_PORTE_BASE_ADDRESS+GPIOPeriphID7_OFFSET))
#define APB_GPIOE_PeriphID0					*((volatile uint32*)(APB_GPIO_PORTE_BASE_ADDRESS+GPIOPeriphID0_OFFSET)
#define APB_GPIOE_PeriphID1					*((volatile uint32*)(APB_GPIO_PORTE_BASE_ADDRESS+GPIOPeriphID1_OFFSET))
#define APB_GPIOE_PeriphID2					*((volatile uint32*)(APB_GPIO_PORTE_BASE_ADDRESS+GPIOPeriphID2_OFFSET))
#define APB_GPIOE_PeriphID3					*((volatile uint32*)(APB_GPIO_PORTE_BASE_ADDRESS+GPIOPeriphID3_OFFSET))
#define APB_GPIOE_PCellID0					*((volatile uint32*)(APB_GPIO_PORTE_BASE_ADDRESS+GPIOPCelllD0_OFFSET))
#define APB_GPIOE_PCellID1					*((volatile uint32*)(APB_GPIO_PORTE_BASE_ADDRESS+GPIOPCelllD1_OFFSET))
#define APB_GPIOE_PCellID2					*((volatile uint32*)(APB_GPIO_PORTE_BASE_ADDRESS+GPIOPCelllD2_OFFSET))
#define APB_GPIOE_PCellID3					*((volatile uint32*)(APB_GPIO_PORTE_BASE_ADDRESS+GPIOPCelllD3_OFFSET))





#define APB_GPIOF_DATA             			 ((volatile uint32*) (APB_GPIO_PORTF_BASE_ADDRESS+GPIODATA_OFFSET))     
#define APB_GPIOF_DIR						*((volatile uint32*)(APB_GPIO_PORTF_BASE_ADDRESS+GPIODIR_OFFSET))
#define APB_GPIOF_IS						*((volatile uint32*)(APB_GPIO_PORTF_BASE_ADDRESS+GPIOIS_OFFSET))
#define APB_GPIOF_IBE						*((volatile uint32*)(APB_GPIO_PORTF_BASE_ADDRESS+GPIOIBE_OFFSET))
#define APB_GPIOF_IEV						*((volatile uint32*)(APB_GPIO_PORTF_BASE_ADDRESS+GPIOIEV_OFFSET))
#define APB_GPIOF_IM						*((volatile uint32*)(APB_GPIO_PORTF_BASE_ADDRESS+GPIOIM_OFFSET))
#define APB_GPIOF_RIS						*((volatile uint32*)(APB_GPIO_PORTF_BASE_ADDRESS+GPIORIS_OFFSET))
#define APB_GPIOF_MIS						*((volatile uint32*)(APB_GPIO_PORTF_BASE_ADDRESS+GPIOMIS_OFFSET))
#define APB_GPIOF_ICR						*((volatile uint32*)(APB_GPIO_PORTF_BASE_ADDRESS+GPIOICR_OFFSET))
#define APB_GPIOF_AFSEL						*((volatile uint32*)(APB_GPIO_PORTF_BASE_ADDRESS+GPIOAFSEL_OFFSET))
#define APB_GPIOF_DR2R						*((volatile uint32*)(APB_GPIO_PORTF_BASE_ADDRESS+GPIODR2R_OFFSET))
#define APB_GPIOF_DR4R						*((volatile uint32*)(APB_GPIO_PORTF_BASE_ADDRESS+GPIODR4R_OFFSET))
#define APB_GPIOF_DR8R						*((volatile uint32*)(APB_GPIO_PORTF_BASE_ADDRESS+GPIODR8R_OFFSET))
#define APB_GPIOF_ODR						*((volatile uint32*)(APB_GPIO_PORTF_BASE_ADDRESS+GPIOODR_OFFSET))
#define APB_GPIOF_PUR						*((volatile uint32*)(APB_GPIO_PORTF_BASE_ADDRESS+GPIOPUR_OFFSET))
#define APB_GPIOF_SLR						*((volatile uint32*)(APB_GPIO_PORTF_BASE_ADDRESS+GPIOSLR_OFFSET))
#define APB_GPIOF_DEN						*((volatile uint32*)(APB_GPIO_PORTF_BASE_ADDRESS+GPIODEN_OFFSET))
#define APB_GPIOF_LOCK						*((volatile uint32*)(APB_GPIO_PORTF_BASE_ADDRESS+GPIOLOCK_OFFSET))
#define APB_GPIOF_CR						*((volatile uint32*)(APB_GPIO_PORTF_BASE_ADDRESS+GPIOCR_OFFSET))
#define APB_GPIOF_AMSEL						*((volatile uint32*)(APB_GPIO_PORTF_BASE_ADDRESS+GPIOAMSEL_OFFSET))
#define APB_GPIOF_PCTL						*((volatile uint32*)(APB_GPIO_PORTF_BASE_ADDRESS+GPIOPCTL_OFFSET))
#define APB_GPIOF_ADCCTL					*((volatile uint32*)(APB_GPIO_PORTF_BASE_ADDRESS+GPIOADCCTL_OFFSET))
#define APB_GPIOF_DMACTL					*((volatile uint32*)(APB_GPIO_PORTF_BASE_ADDRESS+GPIODMACTL_OFFSET))
#define APB_GPIOF_PeriphID4					*((volatile uint32*)(APB_GPIO_PORTF_BASE_ADDRESS+GPIOPeriphID4_OFFSET))
#define APB_GPIOF_PeriphID5					*((volatile uint32*)(APB_GPIO_PORTF_BASE_ADDRESS+GPIOPeriphID5_OFFSET))
#define APB_GPIOF_PeriphID6					*((volatile uint32*)(APB_GPIO_PORTF_BASE_ADDRESS+GPIOPeriphID6_OFFSET))
#define APB_GPIOF_PeriphID7					*((volatile uint32*)(APB_GPIO_PORTF_BASE_ADDRESS+GPIOPeriphID7_OFFSET))
#define APB_GPIOF_PeriphID0					*((volatile uint32*)(APB_GPIO_PORTF_BASE_ADDRESS+GPIOPeriphID0_OFFSET)
#define APB_GPIOF_PeriphID1					*((volatile uint32*)(APB_GPIO_PORTF_BASE_ADDRESS+GPIOPeriphID1_OFFSET))
#define APB_GPIOF_PeriphID2					*((volatile uint32*)(APB_GPIO_PORTF_BASE_ADDRESS+GPIOPeriphID2_OFFSET))
#define APB_GPIOF_PeriphID3					*((volatile uint32*)(APB_GPIO_PORTF_BASE_ADDRESS+GPIOPeriphID3_OFFSET))
#define APB_GPIOF_PCellID0					*((volatile uint32*)(APB_GPIO_PORTF_BASE_ADDRESS+GPIOPCelllD0_OFFSET))
#define APB_GPIOF_PCellID1					*((volatile uint32*)(APB_GPIO_PORTF_BASE_ADDRESS+GPIOPCelllD1_OFFSET))
#define APB_GPIOF_PCellID2					*((volatile uint32*)(APB_GPIO_PORTF_BASE_ADDRESS+GPIOPCelllD2_OFFSET))
#define APB_GPIOF_PCellID3					*((volatile uint32*)(APB_GPIO_PORTF_BASE_ADDRESS+GPIOPCelllD3_OFFSET))




/*****************************************************AT AHB_BUS*************************************************************/





#define AHB_GPIOA_DATA             			((volatile uint32*)(AHB_GPIO_PORTA_BASE_ADDRESS+GPIODATA_OFFSET))  // Defintion as a pointer to access it using indixing.     
#define AHB_GPIOA_DIR						*((volatile uint32*)(AHB_GPIO_PORTA_BASE_ADDRESS+GPIODIR_OFFSET))
#define AHB_GPIOA_IS						*((volatile uint32*)(AHB_GPIO_PORTA_BASE_ADDRESS+GPIOIS_OFFSET))
#define AHB_GPIOA_IBE						*((volatile uint32*)(AHB_GPIO_PORTA_BASE_ADDRESS+GPIOIBE_OFFSET))
#define AHB_GPIOA_IEV						*((volatile uint32*)(AHB_GPIO_PORTA_BASE_ADDRESS+GPIOIEV_OFFSET))
#define AHB_GPIOA_IM						*((volatile uint32*)(AHB_GPIO_PORTA_BASE_ADDRESS+GPIOIM_OFFSET))
#define AHB_GPIOA_RIS						*((volatile uint32*)(AHB_GPIO_PORTA_BASE_ADDRESS+GPIORIS_OFFSET))
#define AHB_GPIOA_MIS						*((volatile uint32*)(AHB_GPIO_PORTA_BASE_ADDRESS+GPIOMIS_OFFSET))
#define AHB_GPIOA_ICR						*((volatile uint32*)(AHB_GPIO_PORTA_BASE_ADDRESS+GPIOICR_OFFSET))
#define AHB_GPIOA_AFSEL						*((volatile uint32*)(AHB_GPIO_PORTA_BASE_ADDRESS+GPIOAFSEL_OFFSET))
#define AHB_GPIOA_DR2R						*((volatile uint32*)(AHB_GPIO_PORTA_BASE_ADDRESS+GPIODR2R_OFFSET))
#define AHB_GPIOA_DR4R						*((volatile uint32*)(AHB_GPIO_PORTA_BASE_ADDRESS+GPIODR4R_OFFSET))
#define AHB_GPIOA_DR8R						*((volatile uint32*)(AHB_GPIO_PORTA_BASE_ADDRESS+GPIODR8R_OFFSET))
#define AHB_GPIOA_ODR						*((volatile uint32*)(AHB_GPIO_PORTA_BASE_ADDRESS+GPIOODR_OFFSET))
#define AHB_GPIOA_PUR						*((volatile uint32*)(AHB_GPIO_PORTA_BASE_ADDRESS+GPIOPUR_OFFSET))
#define AHB_GPIOA_SLR						*((volatile uint32*)(AHB_GPIO_PORTA_BASE_ADDRESS+GPIOSLR_OFFSET))
#define AHB_GPIOA_DEN						*((volatile uint32*)(AHB_GPIO_PORTA_BASE_ADDRESS+GPIODEN_OFFSET))
#define AHB_GPIOA_LOCK						*((volatile uint32*)(AHB_GPIO_PORTA_BASE_ADDRESS+GPIOLOCK_OFFSET))
#define AHB_GPIOA_CR						*((volatile uint32*)(AHB_GPIO_PORTA_BASE_ADDRESS+GPIOCR_OFFSET))
#define AHB_GPIOA_AMSEL						*((volatile uint32*)(AHB_GPIO_PORTA_BASE_ADDRESS+GPIOAMSEL_OFFSET))
#define AHB_GPIOA_PCTL						*((volatile uint32*)(AHB_GPIO_PORTA_BASE_ADDRESS+GPIOPCTL_OFFSET))
#define AHB_GPIOA_ADCCTL					*((volatile uint32*)(AHB_GPIO_PORTA_BASE_ADDRESS+GPIOADCCTL_OFFSET))
#define AHB_GPIOA_DMACTL					*((volatile uint32*)(AHB_GPIO_PORTA_BASE_ADDRESS+GPIODMACTL_OFFSET))
#define AHB_GPIOA_PeriphID4					*((volatile uint32*)(AHB_GPIO_PORTA_BASE_ADDRESS+GPIOPeriphID4_OFFSET))
#define AHB_GPIOA_PeriphID5					*((volatile uint32*)(AHB_GPIO_PORTA_BASE_ADDRESS+GPIOPeriphID5_OFFSET))
#define AHB_GPIOA_PeriphID6					*((volatile uint32*)(AHB_GPIO_PORTA_BASE_ADDRESS+GPIOPeriphID6_OFFSET))
#define AHB_GPIOA_PeriphID7					*((volatile uint32*)(AHB_GPIO_PORTA_BASE_ADDRESS+GPIOPeriphID7_OFFSET))
#define AHB_GPIOA_PeriphID0					*((volatile uint32*)(AHB_GPIO_PORTA_BASE_ADDRESS+GPIOPeriphID0_OFFSET)
#define AHB_GPIOA_PeriphID1					*((volatile uint32*)(AHB_GPIO_PORTA_BASE_ADDRESS+GPIOPeriphID1_OFFSET))
#define AHB_GPIOA_PeriphID2					*((volatile uint32*)(AHB_GPIO_PORTA_BASE_ADDRESS+GPIOPeriphID2_OFFSET))
#define AHB_GPIOA_PeriphID3					*((volatile uint32*)(AHB_GPIO_PORTA_BASE_ADDRESS+GPIOPeriphID3_OFFSET))
#define AHB_GPIOA_PCellID0					*((volatile uint32*)(AHB_GPIO_PORTA_BASE_ADDRESS+GPIOPCelllD0_OFFSET))
#define AHB_GPIOA_PCellID1					*((volatile uint32*)(AHB_GPIO_PORTA_BASE_ADDRESS+GPIOPCelllD1_OFFSET))
#define AHB_GPIOA_PCellID2					*((volatile uint32*)(AHB_GPIO_PORTA_BASE_ADDRESS+GPIOPCelllD2_OFFSET))
#define AHB_GPIOA_PCellID3					*((volatile uint32*)(AHB_GPIO_PORTA_BASE_ADDRESS+GPIOPCelllD3_OFFSET))
					


#define AHB_GPIOB_DATA             			((volatile uint32*)(AHB_GPIO_PORTB_BASE_ADDRESS+GPIODATA_OFFSET))     
#define AHB_GPIOB_DIR						*((volatile uint32*)(AHB_GPIO_PORTB_BASE_ADDRESS+GPIODIR_OFFSET))
#define AHB_GPIOB_IS						*((volatile uint32*)(AHB_GPIO_PORTB_BASE_ADDRESS+GPIOIS_OFFSET))
#define AHB_GPIOB_IBE						*((volatile uint32*)(AHB_GPIO_PORTB_BASE_ADDRESS+GPIOIBE_OFFSET))
#define AHB_GPIOB_IEV						*((volatile uint32*)(AHB_GPIO_PORTB_BASE_ADDRESS+GPIOIEV_OFFSET))
#define AHB_GPIOB_IM						*((volatile uint32*)(AHB_GPIO_PORTB_BASE_ADDRESS+GPIOIM_OFFSET))
#define AHB_GPIOB_RIS						*((volatile uint32*)(AHB_GPIO_PORTB_BASE_ADDRESS+GPIORIS_OFFSET))
#define AHB_GPIOB_MIS						*((volatile uint32*)(AHB_GPIO_PORTB_BASE_ADDRESS+GPIOMIS_OFFSET))
#define AHB_GPIOB_ICR						*((volatile uint32*)(AHB_GPIO_PORTB_BASE_ADDRESS+GPIOICR_OFFSET))
#define AHB_GPIOB_AFSEL						*((volatile uint32*)(AHB_GPIO_PORTB_BASE_ADDRESS+GPIOAFSEL_OFFSET))
#define AHB_GPIOB_DR2R						*((volatile uint32*)(AHB_GPIO_PORTB_BASE_ADDRESS+GPIODR2R_OFFSET))
#define AHB_GPIOB_DR4R						*((volatile uint32*)(AHB_GPIO_PORTB_BASE_ADDRESS+GPIODR4R_OFFSET))
#define AHB_GPIOB_DR8R						*((volatile uint32*)(AHB_GPIO_PORTB_BASE_ADDRESS+GPIODR8R_OFFSET))
#define AHB_GPIOB_ODR						*((volatile uint32*)(AHB_GPIO_PORTB_BASE_ADDRESS+GPIOODR_OFFSET))
#define AHB_GPIOB_PUR						*((volatile uint32*)(AHB_GPIO_PORTB_BASE_ADDRESS+GPIOPUR_OFFSET))
#define AHB_GPIOB_SLR						*((volatile uint32*)(AHB_GPIO_PORTB_BASE_ADDRESS+GPIOSLR_OFFSET))
#define AHB_GPIOB_DEN						*((volatile uint32*)(AHB_GPIO_PORTB_BASE_ADDRESS+GPIODEN_OFFSET))
#define AHB_GPIOB_LOCK						*((volatile uint32*)(AHB_GPIO_PORTB_BASE_ADDRESS+GPIOLOCK_OFFSET))
#define AHB_GPIOB_CR						*((volatile uint32*)(AHB_GPIO_PORTB_BASE_ADDRESS+GPIOCR_OFFSET))
#define AHB_GPIOB_AMSEL						*((volatile uint32*)(AHB_GPIO_PORTB_BASE_ADDRESS+GPIOAMSEL_OFFSET))
#define AHB_GPIOB_PCTL						*((volatile uint32*)(AHB_GPIO_PORTB_BASE_ADDRESS+GPIOPCTL_OFFSET))
#define AHB_GPIOB_ADCCTL					*((volatile uint32*)(AHB_GPIO_PORTB_BASE_ADDRESS+GPIOADCCTL_OFFSET))
#define AHB_GPIOB_DMACTL					*((volatile uint32*)(AHB_GPIO_PORTB_BASE_ADDRESS+GPIODMACTL_OFFSET))
#define AHB_GPIOB_PeriphID4					*((volatile uint32*)(AHB_GPIO_PORTB_BASE_ADDRESS+GPIOPeriphID4_OFFSET))
#define AHB_GPIOB_PeriphID5					*((volatile uint32*)(AHB_GPIO_PORTB_BASE_ADDRESS+GPIOPeriphID5_OFFSET))
#define AHB_GPIOB_PeriphID6					*((volatile uint32*)(AHB_GPIO_PORTB_BASE_ADDRESS+GPIOPeriphID6_OFFSET))
#define AHB_GPIOB_PeriphID7					*((volatile uint32*)(AHB_GPIO_PORTB_BASE_ADDRESS+GPIOPeriphID7_OFFSET))
#define AHB_GPIOB_PeriphID0					*((volatile uint32*)(AHB_GPIO_PORTB_BASE_ADDRESS+GPIOPeriphID0_OFFSET)
#define AHB_GPIOB_PeriphID1					*((volatile uint32*)(AHB_GPIO_PORTB_BASE_ADDRESS+GPIOPeriphID1_OFFSET))
#define AHB_GPIOB_PeriphID2					*((volatile uint32*)(AHB_GPIO_PORTB_BASE_ADDRESS+GPIOPeriphID2_OFFSET))
#define AHB_GPIOB_PeriphID3					*((volatile uint32*)(AHB_GPIO_PORTB_BASE_ADDRESS+GPIOPeriphID3_OFFSET))
#define AHB_GPIOB_PCellID0					*((volatile uint32*)(AHB_GPIO_PORTB_BASE_ADDRESS+GPIOPCelllD0_OFFSET))
#define AHB_GPIOB_PCellID1					*((volatile uint32*)(AHB_GPIO_PORTB_BASE_ADDRESS+GPIOPCelllD1_OFFSET))
#define AHB_GPIOB_PCellID2					*((volatile uint32*)(AHB_GPIO_PORTB_BASE_ADDRESS+GPIOPCelllD2_OFFSET))
#define AHB_GPIOB_PCellID3					*((volatile uint32*)(AHB_GPIO_PORTB_BASE_ADDRESS+GPIOPCelllD3_OFFSET))





#define AHB_GPIOC_DATA             			((volatile uint32*)(AHB_GPIO_PORTC_BASE_ADDRESS+GPIODATA_OFFSET))     
#define AHB_GPIOC_DIR						*((volatile uint32*)(AHB_GPIO_PORTC_BASE_ADDRESS+GPIODIR_OFFSET))
#define AHB_GPIOC_IS						*((volatile uint32*)(AHB_GPIO_PORTC_BASE_ADDRESS+GPIOIS_OFFSET))
#define AHB_GPIOC_IBE						*((volatile uint32*)(AHB_GPIO_PORTC_BASE_ADDRESS+GPIOIBE_OFFSET))
#define AHB_GPIOC_IEV						*((volatile uint32*)(AHB_GPIO_PORTC_BASE_ADDRESS+GPIOIEV_OFFSET))
#define AHB_GPIOC_IM						*((volatile uint32*)(AHB_GPIO_PORTC_BASE_ADDRESS+GPIOIM_OFFSET))
#define AHB_GPIOC_RIS						*((volatile uint32*)(AHB_GPIO_PORTC_BASE_ADDRESS+GPIORIS_OFFSET))
#define AHB_GPIOC_MIS						*((volatile uint32*)(AHB_GPIO_PORTC_BASE_ADDRESS+GPIOMIS_OFFSET))
#define AHB_GPIOC_ICR						*((volatile uint32*)(AHB_GPIO_PORTC_BASE_ADDRESS+GPIOICR_OFFSET))
#define AHB_GPIOC_AFSEL						*((volatile uint32*)(AHB_GPIO_PORTC_BASE_ADDRESS+GPIOAFSEL_OFFSET))
#define AHB_GPIOC_DR2R						*((volatile uint32*)(AHB_GPIO_PORTC_BASE_ADDRESS+GPIODR2R_OFFSET))
#define AHB_GPIOC_DR4R						*((volatile uint32*)(AHB_GPIO_PORTC_BASE_ADDRESS+GPIODR4R_OFFSET))
#define AHB_GPIOC_DR8R						*((volatile uint32*)(AHB_GPIO_PORTC_BASE_ADDRESS+GPIODR8R_OFFSET))
#define AHB_GPIOC_ODR						*((volatile uint32*)(AHB_GPIO_PORTC_BASE_ADDRESS+GPIOODR_OFFSET))
#define AHB_GPIOC_PUR						*((volatile uint32*)(AHB_GPIO_PORTC_BASE_ADDRESS+GPIOPUR_OFFSET))
#define AHB_GPIOC_SLR						*((volatile uint32*)(AHB_GPIO_PORTC_BASE_ADDRESS+GPIOSLR_OFFSET))
#define AHB_GPIOC_DEN						*((volatile uint32*)(AHB_GPIO_PORTC_BASE_ADDRESS+GPIODEN_OFFSET))
#define AHB_GPIOC_LOCK						*((volatile uint32*)(AHB_GPIO_PORTC_BASE_ADDRESS+GPIOLOCK_OFFSET))
#define AHB_GPIOC_CR						*((volatile uint32*)(AHB_GPIO_PORTC_BASE_ADDRESS+GPIOCR_OFFSET))
#define AHB_GPIOC_AMSEL						*((volatile uint32*)(AHB_GPIO_PORTC_BASE_ADDRESS+GPIOAMSEL_OFFSET))
#define AHB_GPIOC_PCTL						*((volatile uint32*)(AHB_GPIO_PORTC_BASE_ADDRESS+GPIOPCTL_OFFSET))
#define AHB_GPIOC_ADCCTL					*((volatile uint32*)(AHB_GPIO_PORTC_BASE_ADDRESS+GPIOADCCTL_OFFSET))
#define AHB_GPIOC_DMACTL					*((volatile uint32*)(AHB_GPIO_PORTC_BASE_ADDRESS+GPIODMACTL_OFFSET))
#define AHB_GPIOC_PeriphID4					*((volatile uint32*)(AHB_GPIO_PORTC_BASE_ADDRESS+GPIOPeriphID4_OFFSET))
#define AHB_GPIOC_PeriphID5					*((volatile uint32*)(AHB_GPIO_PORTC_BASE_ADDRESS+GPIOPeriphID5_OFFSET))
#define AHB_GPIOC_PeriphID6					*((volatile uint32*)(AHB_GPIO_PORTC_BASE_ADDRESS+GPIOPeriphID6_OFFSET))
#define AHB_GPIOC_PeriphID7					*((volatile uint32*)(AHB_GPIO_PORTC_BASE_ADDRESS+GPIOPeriphID7_OFFSET))
#define AHB_GPIOC_PeriphID0					*((volatile uint32*)(AHB_GPIO_PORTC_BASE_ADDRESS+GPIOPeriphID0_OFFSET)
#define AHB_GPIOC_PeriphID1					*((volatile uint32*)(AHB_GPIO_PORTC_BASE_ADDRESS+GPIOPeriphID1_OFFSET))
#define AHB_GPIOC_PeriphID2					*((volatile uint32*)(AHB_GPIO_PORTC_BASE_ADDRESS+GPIOPeriphID2_OFFSET))
#define AHB_GPIOC_PeriphID3					*((volatile uint32*)(AHB_GPIO_PORTC_BASE_ADDRESS+GPIOPeriphID3_OFFSET))
#define AHB_GPIOC_PCellID0					*((volatile uint32*)(AHB_GPIO_PORTC_BASE_ADDRESS+GPIOPCelllD0_OFFSET))
#define AHB_GPIOC_PCellID1					*((volatile uint32*)(AHB_GPIO_PORTC_BASE_ADDRESS+GPIOPCelllD1_OFFSET))
#define AHB_GPIOC_PCellID2					*((volatile uint32*)(AHB_GPIO_PORTC_BASE_ADDRESS+GPIOPCelllD2_OFFSET))
#define AHB_GPIOC_PCellID3					*((volatile uint32*)(AHB_GPIO_PORTC_BASE_ADDRESS+GPIOPCelllD3_OFFSET))




#define AHB_GPIOD_DATA             			((volatile uint32*) (AHB_GPIO_PORTD_BASE_ADDRESS+GPIODATA_OFFSET))     
#define AHB_GPIOD_DIR						*((volatile uint32*)(AHB_GPIO_PORTD_BASE_ADDRESS+GPIODIR_OFFSET))
#define AHB_GPIOD_IS						*((volatile uint32*)(AHB_GPIO_PORTD_BASE_ADDRESS+GPIOIS_OFFSET))
#define AHB_GPIOD_IBE						*((volatile uint32*)(AHB_GPIO_PORTD_BASE_ADDRESS+GPIOIBE_OFFSET))
#define AHB_GPIOD_IEV						*((volatile uint32*)(AHB_GPIO_PORTD_BASE_ADDRESS+GPIOIEV_OFFSET))
#define AHB_GPIOD_IM						*((volatile uint32*)(AHB_GPIO_PORTD_BASE_ADDRESS+GPIOIM_OFFSET))
#define AHB_GPIOD_RIS						*((volatile uint32*)(AHB_GPIO_PORTD_BASE_ADDRESS+GPIORIS_OFFSET))
#define AHB_GPIOD_MIS						*((volatile uint32*)(AHB_GPIO_PORTD_BASE_ADDRESS+GPIOMIS_OFFSET))
#define AHB_GPIOD_ICR						*((volatile uint32*)(AHB_GPIO_PORTD_BASE_ADDRESS+GPIOICR_OFFSET))
#define AHB_GPIOD_AFSEL						*((volatile uint32*)(AHB_GPIO_PORTD_BASE_ADDRESS+GPIOAFSEL_OFFSET))
#define AHB_GPIOD_DR2R						*((volatile uint32*)(AHB_GPIO_PORTD_BASE_ADDRESS+GPIODR2R_OFFSET))
#define AHB_GPIOD_DR4R						*((volatile uint32*)(AHB_GPIO_PORTD_BASE_ADDRESS+GPIODR4R_OFFSET))
#define AHB_GPIOD_DR8R						*((volatile uint32*)(AHB_GPIO_PORTD_BASE_ADDRESS+GPIODR8R_OFFSET))
#define AHB_GPIOD_ODR						*((volatile uint32*)(AHB_GPIO_PORTD_BASE_ADDRESS+GPIOODR_OFFSET))
#define AHB_GPIOD_PUR						*((volatile uint32*)(AHB_GPIO_PORTD_BASE_ADDRESS+GPIOPUR_OFFSET))
#define AHB_GPIOD_SLR						*((volatile uint32*)(AHB_GPIO_PORTD_BASE_ADDRESS+GPIOSLR_OFFSET))
#define AHB_GPIOD_DEN						*((volatile uint32*)(AHB_GPIO_PORTD_BASE_ADDRESS+GPIODEN_OFFSET))
#define AHB_GPIOD_LOCK						*((volatile uint32*)(AHB_GPIO_PORTD_BASE_ADDRESS+GPIOLOCK_OFFSET))
#define AHB_GPIOD_CR						*((volatile uint32*)(AHP_GPIO_PORTD_BASE_ADDRESS+GPIOCR_OFFSET))
#define AHB_GPIOD_AMSEL						*((volatile uint32*)(AHB_GPIO_PORTD_BASE_ADDRESS+GPIOAMSEL_OFFSET))
#define AHB_GPIOD_PCTL						*((volatile uint32*)(AHB_GPIO_PORTD_BASE_ADDRESS+GPIOPCTL_OFFSET))
#define AHB_GPIOD_ADCCTL					*((volatile uint32*)(AHB_GPIO_PORTD_BASE_ADDRESS+GPIOADCCTL_OFFSET))
#define AHB_GPIOD_DMACTL					*((volatile uint32*)(AHB_GPIO_PORTD_BASE_ADDRESS+GPIODMACTL_OFFSET))
#define AHB_GPIOD_PeriphID4					*((volatile uint32*)(AHB_GPIO_PORTD_BASE_ADDRESS+GPIOPeriphID4_OFFSET))
#define AHB_GPIOD_PeriphID5					*((volatile uint32*)(AHB_GPIO_PORTD_BASE_ADDRESS+GPIOPeriphID5_OFFSET))
#define AHB_GPIOD_PeriphID6					*((volatile uint32*)(AHB_GPIO_PORTD_BASE_ADDRESS+GPIOPeriphID6_OFFSET))
#define AHB_GPIOD_PeriphID7					*((volatile uint32*)(AHB_GPIO_PORTD_BASE_ADDRESS+GPIOPeriphID7_OFFSET))
#define AHB_GPIOD_PeriphID0					*((volatile uint32*)(AHB_GPIO_PORTD_BASE_ADDRESS+GPIOPeriphID0_OFFSET)
#define AHB_GPIOD_PeriphID1					*((volatile uint32*)(AHB_GPIO_PORTD_BASE_ADDRESS+GPIOPeriphID1_OFFSET))
#define AHB_GPIOD_PeriphID2					*((volatile uint32*)(AHB_GPIO_PORTD_BASE_ADDRESS+GPIOPeriphID2_OFFSET))
#define AHB_GPIOD_PeriphID3					*((volatile uint32*)(AHB_GPIO_PORTD_BASE_ADDRESS+GPIOPeriphID3_OFFSET))
#define AHB_GPIOD_PCellID0					*((volatile uint32*)(AHB_GPIO_PORTD_BASE_ADDRESS+GPIOPCelllD0_OFFSET))
#define AHB_GPIOD_PCellID1					*((volatile uint32*)(AHB_GPIO_PORTD_BASE_ADDRESS+GPIOPCelllD1_OFFSET))
#define AHB_GPIOD_PCellID2					*((volatile uint32*)(AHB_GPIO_PORTD_BASE_ADDRESS+GPIOPCelllD2_OFFSET))
#define AHB_GPIOD_PCellID3					*((volatile uint32*)(AHB_GPIO_PORTD_BASE_ADDRESS+GPIOPCelllD3_OFFSET))




#define AHB_GPIOE_DATA             			((volatile uint32*) (AHB_GPIO_PORTE_BASE_ADDRESS+GPIODATA_OFFSET))     
#define AHB_GPIOE_DIR						*((volatile uint32*)(AHB_GPIO_PORTE_BASE_ADDRESS+GPIODIR_OFFSET))
#define AHB_GPIOE_IS						*((volatile uint32*)(AHB_GPIO_PORTE_BASE_ADDRESS+GPIOIS_OFFSET))
#define AHB_GPIOE_IBE						*((volatile uint32*)(AHB_GPIO_PORTE_BASE_ADDRESS+GPIOIBE_OFFSET))
#define AHB_GPIOE_IEV						*((volatile uint32*)(AHB_GPIO_PORTE_BASE_ADDRESS+GPIOIEV_OFFSET))
#define AHB_GPIOE_IM						*((volatile uint32*)(AHB_GPIO_PORTE_BASE_ADDRESS+GPIOIM_OFFSET))
#define AHB_GPIOE_RIS						*((volatile uint32*)(AHB_GPIO_PORTE_BASE_ADDRESS+GPIORIS_OFFSET))
#define AHB_GPIOE_MIS						*((volatile uint32*)(AHB_GPIO_PORTE_BASE_ADDRESS+GPIOMIS_OFFSET))
#define AHB_GPIOE_ICR						*((volatile uint32*)(AHB_GPIO_PORTE_BASE_ADDRESS+GPIOICR_OFFSET))
#define AHB_GPIOE_AFSEL						*((volatile uint32*)(AHB_GPIO_PORTE_BASE_ADDRESS+GPIOAFSEL_OFFSET))
#define AHB_GPIOE_DR2R						*((volatile uint32*)(AHB_GPIO_PORTE_BASE_ADDRESS+GPIODR2R_OFFSET))
#define AHB_GPIOE_DR4R						*((volatile uint32*)(AHB_GPIO_PORTE_BASE_ADDRESS+GPIODR4R_OFFSET))
#define AHB_GPIOE_DR8R						*((volatile uint32*)(AHB_GPIO_PORTE_BASE_ADDRESS+GPIODR8R_OFFSET))
#define AHB_GPIOE_ODR						*((volatile uint32*)(AHB_GPIO_PORTE_BASE_ADDRESS+GPIOODR_OFFSET))
#define AHB_GPIOE_PUR						*((volatile uint32*)(AHB_GPIO_PORTE_BASE_ADDRESS+GPIOPUR_OFFSET))
#define AHB_GPIOE_SLR						*((volatile uint32*)(AHB_GPIO_PORTE_BASE_ADDRESS+GPIOSLR_OFFSET))
#define AHB_GPIOE_DEN						*((volatile uint32*)(AHB_GPIO_PORTE_BASE_ADDRESS+GPIODEN_OFFSET))
#define AHB_GPIOE_LOCK						*((volatile uint32*)(AHB_GPIO_PORTE_BASE_ADDRESS+GPIOLOCK_OFFSET))
#define AHB_GPIOE_CR						*((volatile uint32*)(AHB_GPIO_PORTE_BASE_ADDRESS+GPIOCR_OFFSET))
#define AHB_GPIOE_AMSEL						*((volatile uint32*)(AHB_GPIO_PORTE_BASE_ADDRESS+GPIOAMSEL_OFFSET))
#define AHB_GPIOE_PCTL						*((volatile uint32*)(AHB_GPIO_PORTE_BASE_ADDRESS+GPIOPCTL_OFFSET))
#define AHB_GPIOE_ADCCTL					*((volatile uint32*)(AHB_GPIO_PORTE_BASE_ADDRESS+GPIOADCCTL_OFFSET))
#define AHB_GPIOE_DMACTL					*((volatile uint32*)(AHB_GPIO_PORTE_BASE_ADDRESS+GPIODMACTL_OFFSET))
#define AHB_GPIOE_PeriphID4					*((volatile uint32*)(AHB_GPIO_PORTE_BASE_ADDRESS+GPIOPeriphID4_OFFSET))
#define AHB_GPIOE_PeriphID5					*((volatile uint32*)(AHB_GPIO_PORTE_BASE_ADDRESS+GPIOPeriphID5_OFFSET))
#define AHB_GPIOE_PeriphID6					*((volatile uint32*)(AHB_GPIO_PORTE_BASE_ADDRESS+GPIOPeriphID6_OFFSET))
#define AHB_GPIOE_PeriphID7					*((volatile uint32*)(AHB_GPIO_PORTE_BASE_ADDRESS+GPIOPeriphID7_OFFSET))
#define AHB_GPIOE_PeriphID0					*((volatile uint32*)(AHB_GPIO_PORTE_BASE_ADDRESS+GPIOPeriphID0_OFFSET)
#define AHB_GPIOE_PeriphID1					*((volatile uint32*)(AHB_GPIO_PORTE_BASE_ADDRESS+GPIOPeriphID1_OFFSET))
#define AHB_GPIOE_PeriphID2					*((volatile uint32*)(AHB_GPIO_PORTE_BASE_ADDRESS+GPIOPeriphID2_OFFSET))
#define AHB_GPIOE_PeriphID3					*((volatile uint32*)(AHB_GPIO_PORTE_BASE_ADDRESS+GPIOPeriphID3_OFFSET))
#define AHB_GPIOE_PCellID0					*((volatile uint32*)(AHB_GPIO_PORTE_BASE_ADDRESS+GPIOPCelllD0_OFFSET))
#define AHB_GPIOE_PCellID1					*((volatile uint32*)(AHB_GPIO_PORTE_BASE_ADDRESS+GPIOPCelllD1_OFFSET))
#define AHB_GPIOE_PCellID2					*((volatile uint32*)(AHB_GPIO_PORTE_BASE_ADDRESS+GPIOPCelllD2_OFFSET))
#define AHB_GPIOE_PCellID3					*((volatile uint32*)(AHB_GPIO_PORTE_BASE_ADDRESS+GPIOPCelllD3_OFFSET))





#define AHB_GPIOF_DATA             			 ((volatile uint32*) (AHB_GPIO_PORTF_BASE_ADDRESS+GPIODATA_OFFSET))     
#define AHB_GPIOF_DIR						*((volatile uint32*)(AHB_GPIO_PORTF_BASE_ADDRESS+GPIODIR_OFFSET))
#define AHB_GPIOF_IS						*((volatile uint32*)(AHB_GPIO_PORTF_BASE_ADDRESS+GPIOIS_OFFSET))
#define AHB_GPIOF_IBE						*((volatile uint32*)(AHB_GPIO_PORTF_BASE_ADDRESS+GPIOIBE_OFFSET))
#define AHB_GPIOF_IEV						*((volatile uint32*)(AHB_GPIO_PORTF_BASE_ADDRESS+GPIOIEV_OFFSET))
#define AHB_GPIOF_IM						*((volatile uint32*)(AHB_GPIO_PORTF_BASE_ADDRESS+GPIOIM_OFFSET))
#define AHB_GPIOF_RIS						*((volatile uint32*)(AHB_GPIO_PORTF_BASE_ADDRESS+GPIORIS_OFFSET))
#define AHB_GPIOF_MIS						*((volatile uint32*)(AHB_GPIO_PORTF_BASE_ADDRESS+GPIOMIS_OFFSET))
#define AHB_GPIOF_ICR						*((volatile uint32*)(AHB_GPIO_PORTF_BASE_ADDRESS+GPIOICR_OFFSET))
#define AHB_GPIOF_AFSEL						*((volatile uint32*)(AHB_GPIO_PORTF_BASE_ADDRESS+GPIOAFSEL_OFFSET))
#define AHB_GPIOF_DR2R						*((volatile uint32*)(AHB_GPIO_PORTF_BASE_ADDRESS+GPIODR2R_OFFSET))
#define AHB_GPIOF_DR4R						*((volatile uint32*)(AHB_GPIO_PORTF_BASE_ADDRESS+GPIODR4R_OFFSET))
#define AHB_GPIOF_DR8R						*((volatile uint32*)(AHB_GPIO_PORTF_BASE_ADDRESS+GPIODR8R_OFFSET))
#define AHB_GPIOF_ODR						*((volatile uint32*)(AHB_GPIO_PORTF_BASE_ADDRESS+GPIOODR_OFFSET))
#define AHB_GPIOF_PUR						*((volatile uint32*)(AHB_GPIO_PORTF_BASE_ADDRESS+GPIOPUR_OFFSET))
#define AHB_GPIOF_SLR						*((volatile uint32*)(AHB_GPIO_PORTF_BASE_ADDRESS+GPIOSLR_OFFSET))
#define AHB_GPIOF_DEN						*((volatile uint32*)(AHB_GPIO_PORTF_BASE_ADDRESS+GPIODEN_OFFSET))
#define AHB_GPIOF_LOCK						*((volatile uint32*)(AHB_GPIO_PORTF_BASE_ADDRESS+GPIOLOCK_OFFSET))
#define AHB_GPIOF_CR						*((volatile uint32*)(AHB_GPIO_PORTF_BASE_ADDRESS+GPIOCR_OFFSET))
#define AHB_GPIOF_AMSEL						*((volatile uint32*)(AHB_GPIO_PORTF_BASE_ADDRESS+GPIOAMSEL_OFFSET))
#define AHB_GPIOF_PCTL						*((volatile uint32*)(AHB_GPIO_PORTF_BASE_ADDRESS+GPIOPCTL_OFFSET))
#define AHB_GPIOF_ADCCTL					*((volatile uint32*)(AHB_GPIO_PORTF_BASE_ADDRESS+GPIOADCCTL_OFFSET))
#define AHB_GPIOF_DMACTL					*((volatile uint32*)(AHB_GPIO_PORTF_BASE_ADDRESS+GPIODMACTL_OFFSET))
#define AHB_GPIOF_PeriphID4					*((volatile uint32*)(AHB_GPIO_PORTF_BASE_ADDRESS+GPIOPeriphID4_OFFSET))
#define AHB_GPIOF_PeriphID5					*((volatile uint32*)(AHB_GPIO_PORTF_BASE_ADDRESS+GPIOPeriphID5_OFFSET))
#define AHB_GPIOF_PeriphID6					*((volatile uint32*)(AHB_GPIO_PORTF_BASE_ADDRESS+GPIOPeriphID6_OFFSET))
#define AHB_GPIOF_PeriphID7					*((volatile uint32*)(AHB_GPIO_PORTF_BASE_ADDRESS+GPIOPeriphID7_OFFSET))
#define AHB_GPIOF_PeriphID0					*((volatile uint32*)(AHB_GPIO_PORTF_BASE_ADDRESS+GPIOPeriphID0_OFFSET)
#define AHB_GPIOF_PeriphID1					*((volatile uint32*)(AHB_GPIO_PORTF_BASE_ADDRESS+GPIOPeriphID1_OFFSET))
#define AHB_GPIOF_PeriphID2					*((volatile uint32*)(AHB_GPIO_PORTF_BASE_ADDRESS+GPIOPeriphID2_OFFSET))
#define AHB_GPIOF_PeriphID3					*((volatile uint32*)(AHB_GPIO_PORTF_BASE_ADDRESS+GPIOPeriphID3_OFFSET))
#define AHB_GPIOF_PCellID0					*((volatile uint32*)(AHB_GPIO_PORTF_BASE_ADDRESS+GPIOPCelllD0_OFFSET))
#define AHB_GPIOF_PCellID1					*((volatile uint32*)(AHB_GPIO_PORTF_BASE_ADDRESS+GPIOPCelllD1_OFFSET))
#define AHB_GPIOF_PCellID2					*((volatile uint32*)(AHB_GPIO_PORTF_BASE_ADDRESS+GPIOPCelllD2_OFFSET))
#define AHB_GPIOF_PCellID3					*((volatile uint32*)(AHB_GPIO_PORTF_BASE_ADDRESS+GPIOPCelllD3_OFFSET))



/**************************************************************************************************************************** 
 
SIXTH: DEFINE BIT_ADDRESS                  "BIT_BANDING"

*****************************************************************************************************************************/

#define APB_GPIO_PORTA_PIN0                 BIT_BANDING(APB_GPIO_PORTA_OFFSET , GPIODATA_OFFSET , 0)
#define APB_GPIO_PORTA_PIN1                 BIT_BANDING(APB_GPIO_PORTA_OFFSET , GPIODATA_OFFSET , 1)
#define APB_GPIO_PORTA_PIN2                 BIT_BANDING(APB_GPIO_PORTA_OFFSET , GPIODATA_OFFSET , 2)
#define APB_GPIO_PORTA_PIN3                 BIT_BANDING(APB_GPIO_PORTA_OFFSET , GPIODATA_OFFSET , 3)
#define APB_GPIO_PORTA_PIN4                 BIT_BANDING(APB_GPIO_PORTA_OFFSET , GPIODATA_OFFSET , 4)
#define APB_GPIO_PORTA_PIN5                 BIT_BANDING(APB_GPIO_PORTA_OFFSET , GPIODATA_OFFSET , 5)
#define APB_GPIO_PORTA_PIN6                 BIT_BANDING(APB_GPIO_PORTA_OFFSET , GPIODATA_OFFSET , 6)
#define APB_GPIO_PORTA_PIN7                 BIT_BANDING(APB_GPIO_PORTA_OFFSET , GPIODATA_OFFSET , 7)


#define APB_GPIO_PORTB_PIN0                 BIT_BANDING(APB_GPIO_PORTB_OFFSET , GPIODATA_OFFSET , 0)
#define APB_GPIO_PORTB_PIN1                 BIT_BANDING(APB_GPIO_PORTB_OFFSET , GPIODATA_OFFSET , 1)
#define APB_GPIO_PORTB_PIN2                 BIT_BANDING(APB_GPIO_PORTB_OFFSET , GPIODATA_OFFSET , 2)
#define APB_GPIO_PORTB_PIN3                 BIT_BANDING(APB_GPIO_PORTB_OFFSET , GPIODATA_OFFSET , 3)
#define APB_GPIO_PORTB_PIN4                 BIT_BANDING(APB_GPIO_PORTB_OFFSET , GPIODATA_OFFSET , 4)
#define APB_GPIO_PORTB_PIN5                 BIT_BANDING(APB_GPIO_PORTB_OFFSET , GPIODATA_OFFSET , 5)
#define APB_GPIO_PORTB_PIN6                 BIT_BANDING(APB_GPIO_PORTB_OFFSET , GPIODATA_OFFSET , 6)
#define APB_GPIO_PORTB_PIN7                 BIT_BANDING(APB_GPIO_PORTB_OFFSET , GPIODATA_OFFSET , 7)


#define APB_GPIO_PORTC_PIN0                 BIT_BANDING(APB_GPIO_PORTC_OFFSET , GPIODATA_OFFSET , 0)
#define APB_GPIO_PORTC_PIN1                 BIT_BANDING(APB_GPIO_PORTC_OFFSET , GPIODATA_OFFSET , 1)
#define APB_GPIO_PORTC_PIN2                 BIT_BANDING(APB_GPIO_PORTC_OFFSET , GPIODATA_OFFSET , 2)
#define APB_GPIO_PORTC_PIN3                 BIT_BANDING(APB_GPIO_PORTC_OFFSET , GPIODATA_OFFSET , 3)
#define APB_GPIO_PORTC_PIN4                 BIT_BANDING(APB_GPIO_PORTC_OFFSET , GPIODATA_OFFSET , 4)
#define APB_GPIO_PORTC_PIN5                 BIT_BANDING(APB_GPIO_PORTC_OFFSET , GPIODATA_OFFSET , 5)
#define APB_GPIO_PORTC_PIN6                 BIT_BANDING(APB_GPIO_PORTC_OFFSET , GPIODATA_OFFSET , 6)
#define APB_GPIO_PORTC_PIN7                 BIT_BANDING(APB_GPIO_PORTC_OFFSET , GPIODATA_OFFSET , 7)



#define APB_GPIO_PORTD_PIN0                 BIT_BANDING(APB_GPIO_PORTD_OFFSET , GPIODATA_OFFSET , 0)
#define APB_GPIO_PORTD_PIN1                 BIT_BANDING(APB_GPIO_PORTD_OFFSET , GPIODATA_OFFSET , 1)
#define APB_GPIO_PORTD_PIN2                 BIT_BANDING(APB_GPIO_PORTD_OFFSET , GPIODATA_OFFSET , 2)
#define APB_GPIO_PORTD_PIN3                 BIT_BANDING(APB_GPIO_PORTD_OFFSET , GPIODATA_OFFSET , 3)
#define APB_GPIO_PORTD_PIN4                 BIT_BANDING(APB_GPIO_PORTD_OFFSET , GPIODATA_OFFSET , 4)
#define APB_GPIO_PORTD_PIN5                 BIT_BANDING(APB_GPIO_PORTD_OFFSET , GPIODATA_OFFSET , 5)
#define APB_GPIO_PORTD_PIN6                 BIT_BANDING(APB_GPIO_PORTD_OFFSET , GPIODATA_OFFSET , 6)
#define APB_GPIO_PORTD_PIN7                 BIT_BANDING(APB_GPIO_PORTD_OFFSET , GPIODATA_OFFSET , 7)



#define APB_GPIO_PORTE_PIN0                 BIT_BANDING(APB_GPIO_PORTE_OFFSET , GPIODATA_OFFSET , 0)
#define APB_GPIO_PORTE_PIN1                 BIT_BANDING(APB_GPIO_PORTE_OFFSET , GPIODATA_OFFSET , 1)
#define APB_GPIO_PORTE_PIN2                 BIT_BANDING(APB_GPIO_PORTE_OFFSET , GPIODATA_OFFSET , 2)
#define APB_GPIO_PORTE_PIN3                 BIT_BANDING(APB_GPIO_PORTE_OFFSET , GPIODATA_OFFSET , 3)
#define APB_GPIO_PORTE_PIN4                 BIT_BANDING(APB_GPIO_PORTE_OFFSET , GPIODATA_OFFSET , 4)
#define APB_GPIO_PORTE_PIN5                 BIT_BANDING(APB_GPIO_PORTE_OFFSET , GPIODATA_OFFSET , 5)
#define APB_GPIO_PORTE_PIN6                 BIT_BANDING(APB_GPIO_PORTE_OFFSET , GPIODATA_OFFSET , 6)
#define APB_GPIO_PORTE_PIN7                 BIT_BANDING(APB_GPIO_PORTE_OFFSET , GPIODATA_OFFSET , 7)




#define APB_GPIO_PORTF_PIN0                 BIT_BANDING(APB_GPIO_PORTF_OFFSET , GPIODATA_OFFSET , 0)
#define APB_GPIO_PORTF_PIN1                 BIT_BANDING(APB_GPIO_PORTF_OFFSET , GPIODATA_OFFSET , 1)
#define APB_GPIO_PORTF_PIN2                 BIT_BANDING(APB_GPIO_PORTF_OFFSET , GPIODATA_OFFSET , 2)
#define APB_GPIO_PORTF_PIN3                 BIT_BANDING(APB_GPIO_PORTF_OFFSET , GPIODATA_OFFSET , 3)
#define APB_GPIO_PORTF_PIN4                 BIT_BANDING(APB_GPIO_PORTF_OFFSET , GPIODATA_OFFSET , 4)
#define APB_GPIO_PORTF_PIN5                 BIT_BANDING(APB_GPIO_PORTF_OFFSET , GPIODATA_OFFSET , 5)
#define APB_GPIO_PORTF_PIN6                 BIT_BANDING(APB_GPIO_PORTF_OFFSET , GPIODATA_OFFSET , 6)
#define APB_GPIO_PORTF_PIN7                 BIT_BANDING(APB_GPIO_PORTF_OFFSET , GPIODATA_OFFSET , 7)



/**************************************************************************************************************************** 
 
SIXTH: REGISTER_DEFINATION_USING_STRUCT     "STRUCT DEFINATIONS"

*****************************************************************************************************************************/


typedef struct{

	volatile uint32	GPIO_DATA[256]	;                      
	volatile uint32	GPIODIR			;			
	volatile uint32	GPIOIS			;			
	volatile uint32	GPIOIBE			;			
	volatile uint32	GPIOIEV			;			
	volatile uint32	GPIOIM			;			
	volatile uint32	GPIORIS			;			  
	volatile uint32	GPIOMIS			;			
	volatile uint32	GPIOICR			;			
	volatile uint32	GPIOAFSEL		;			
	volatile uint32	GPIODR2R		;			
	volatile uint32	GPIODR4R		;			
	volatile uint32	GPIODR8R		;			
	volatile uint32	GPIODODR		;			
	volatile uint32	GPIOPUR			;			
  volatile 	uint32	GPIOPDR			;			
	volatile uint32	GPIOSLR			;			
	volatile uint32	GPIODEN			;			
	volatile uint32	GPIOLOCK		;			
	volatile uint32	GPIOCR			;			
	volatile uint32	GPIOAMSEL		;			
	volatile uint32	GPIOPCTL		;			
	volatile uint32	GPIOADCCTL		;			
	volatile uint32	GPIODMACTL		;			
	volatile uint32	GPIOPeriphID4	;			
	volatile uint32	GPIOPeriphID5	;			
	volatile uint32	GPIOPeriphID6	;			
	volatile uint32	GPIOPeriphID7	;			
	volatile uint32	GPIOPeriphID0	;			
	volatile uint32	GPIOPeriphID1	;			
	volatile uint32	GPIOPeriphID2	;		
	volatile uint32	GPIOPeriphID3	;			
	volatile uint32	GPIOPCelllD0	;			
	volatile uint32	GPIOPCelllD1	;			
	volatile uint32	GPIOPCelllD2	;			
	volatile uint32	GPIOPCelllD3	;			
	
	}GPIO_TYPE;
	
#define APB_PORTA                      ( (volatile GPIO_TYPE*) APB_GPIO_PORTA_BASE_ADDRESS)		
#define APB_PORTB                      ( (volatile GPIO_TYPE*) APB_GPIO_PORTB_BASE_ADDRESS)			
#define APB_PORTC                       ((volatile GPIO_TYPE*) APB_GPIO_PORTC_BASE_ADDRESS)			
#define APB_PORTD                       ((volatile GPIO_TYPE*) APB_GPIO_PORTD_BASE_ADDRESS)			
#define APB_PORTE                       ((volatile GPIO_TYPE*) APB_GPIO_PORTE_BASE_ADDRESS)			 
#define APB_PORTF                       ((volatile GPIO_TYPE*) APB_GPIO_PORTF_BASE_ADDRESS) 		       



#define AHB_PORTA				    	 (volatile GPIO_TYPE*)AHB_GPIO_PORTA_BASE_ADDRESS			 
#define AHB_PORTB 			    	         (volatile GPIO_TYPE*)AHB_GPIO_PORTB_BASE_ADDRESS			 
#define AHB_PORTC		    		         (volatile GPIO_TYPE*)AHB_GPIO_PORTC_BASE_ADDRESS			 
#define	AHB_PORTD		  	    		 (volatile GPIO_TYPE*)AHB_GPIO_PORTD_BASE_ADDRESS			 
#define AHB_PORTE 					 (volatile GPIO_TYPE*)AHB_GPIO_PORTE_BASE_ADDRESS			 
#define AHB_PORTF				         (volatile GPIO_TYPE*)AHB_GPIO_PORTF_BASE_ADDRESS 		       


#endif