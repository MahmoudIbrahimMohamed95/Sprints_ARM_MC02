/*****************************************************************************************************************************
*FILE DESCRIPTION
*-----------------------------------------------------------------------------------------------------------------------------
*		FILE: Gpio_DIO.h

*	Module:   Gpio_DIO_H

*DESCRIPTION: header file for GPIO Periphral interface

*
*****************************************************************************************************************************/

#ifndef GPIO_DIO_H_
#define GPIO_DIO_H_

typedef enum{

	PA0 , PA1 , PA2 , PA3 , PA4 , PA5 , PA6 , PA7 , PB0 , PB1 , PB2 , PB3 , PB4 , PB5 , PB6 , PB7,

	PC0 , PC1 , PC2 , PC3 , PC4 , PC5 , PC6 , PC7 , PD0 , PD1 , PD2 , PD3 , PD4 , PD5 , PD6 , PD7,

	PE0 , PE1 , PE2 , PE3 , PE4 , PE5  , PF0 , PF1 , PF2 , PF3 , PF4

}Dio_ChannelType;

typedef enum{

	PORTA , PORTB , PORTC , PORTD , PORTE , PORTF

}Dio_PortType;

typedef enum{

	 LOW , HIGH 

}Dio_LevelType;

typedef uint32 Dio_PortLevelType ;   /* uint32 not uint8 to avoid warning of implicit conversion*/


/****************************************************************************************************************************
*	GLOBAL DATA PROTOTYPES
****************************************************************************************************************************/


/****************************************************************************************************************************
*	GLOBAL FUNCTION PROTOTYPES
****************************************************************************************************************************/

Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);

void DIO_WriteChannel(Dio_ChannelType ChannelId , Dio_LevelType Level);

Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);

void Dio_WritePort (Dio_PortType PortId , Dio_PortLevelType Level);

Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);

/****************************************************************************************************************************
*	\syntax:
*	\Description     :
*	\sync\Async      :
*	\Reentrancy      :
*	\Parameters (in) :
*	\Parameters (out):
*	\Return value	 :
*************************************************************************************************************************/

		/*write function prototype*/
		
#endif 	/*DIO_H*/

/***************************************************************************************************************************
*	END OF FILE :Mcu_Hw.h
***************************************************************************************************************************/
