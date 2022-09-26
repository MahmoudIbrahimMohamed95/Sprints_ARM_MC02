#ifndef MCU_H_
#define MCU_H_



#define MCU_EXT_RESET        1
#define MCU_POR_RESET        2
#define MCU_BOR_RESET        4
#define MCU_WDT0_RESET       8
#define MCU_SW_RESET  	    16
#define MCU_WDT1_RESET      32
#define MCU_MOSCFAIL_RESET  65536


typedef uint32 Mcu_RawResetType;
typedef uint8  Std_ReturnType;

typedef enum{

	UNLOCKED , LOCKED

}Mcu_PllStatusType;


typedef enum{

	 MOSC ,PIOSC , PIOSC_DIV_FOUR ,  LFIOSC , HIBERNATION, PIOSC_PLL , MOSC_PLL

}Mcu_ClockType;


typedef enum{

	WDT0 , WDT1 , TIMER0 , TIMER1  , TIMER2 , TIMER3 , TIMER4 , TIMER5 , PORTA 
	
	,PORTB , PORTC , PORTD , PORTE , PORTF , uDMA , HIBERNATION_MODULE ,UART0
	
   ,UART1, UART2 , UART3 , UART4 , UART5 , UART6 , UART7 ,SSI3 ,SSI2 , SSI1 ,SSI0

	,I2C3 , I2C2 , I2C1 ,I2C0 , USB , CAN0 , CAN1 , ADC0 , ADC1 , ANALOG_COMPARATOR , 
	
	PWM0 , PWM1, QUAD_ENCODER0 ,QUAD_ENCODER1, EEPROM ,  TIMER0_32_64, TIMER1_32_64 

	,TIMER2_32_64 , TIMER3_32_64 , TIMER4_32_64 , TIMER5_32_64  

}Mcu_PeriphralClockGates;


typedef enum{

	DISABLE , ENABLE

}Mcu_SwReset;


typedef struct{

Mcu_ClockType            clockType;

Mcu_PeriphralClockGates   periphralClock;

Mcu_SwReset               softwareReset;

}Mcu_ConfigType;

Mcu_RawResetType Mcu_GetResetRawValue(void);
void Mcu_PerformReset(void);
void Mcu_Init(const Mcu_ConfigType*ConfigPtr);
Std_ReturnType Mcu_InitClock(Mcu_ClockType  ClockSetting);
Std_ReturnType Mcu_DistributePllClock(void);
Mcu_PllStatusType Mcu_GetPllStatus(void);


#endif
