/******************************************************************************************************************************
*	FILE DESCRIPTION
*	-------------------------------------------------------------------------------------------------------------------------
*				\File 	 : Port.c

*				\*brief	 :
*
*				\*details:
*****************************************************************************************************************************/


/****************************************************************************************************************************

*	INCLUDES

****************************************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Gpio_Port.h"
#include "Gpio_Port_Cfg.h"
#include "Gpio_Private.h"




/****************************************************************************************************************************

*	LOCAL MACROS CONSTANT\FUNCTIONS

****************************************************************************************************************************/



/****************************************************************************************************************************

*	LOCAL DATA

****************************************************************************************************************************/



/****************************************************************************************************************************

*	GLOBAL DATA

****************************************************************************************************************************/
static uint8 pinIndix=0;

static uint8 portType=0;



/****************************************************************************************************************************

*	LOCAL FUNCTION PROTOTYPE

****************************************************************************************************************************/



/****************************************************************************************************************************

*	LOCAL FUNCTION

****************************************************************************************************************************/



/****************************************************************************************************************************

*	GLOBAL FUNCTIONS

****************************************************************************************************************************/


/*************************************************************************************************************************
*	\syntax:
*	\Description     :
*	\sync\Async      :
*	\Reentrancy      :
*	\Parameters (in) :
*	\Parameters (out):
*	\Return value	 :		:Std_ReturnType E_Ok

											E_NOT_OK
*************************************************************************************************************************/

void Port_Init(const Port_ConfigType* ConfigPtr ){
	

	if((ConfigPtr->pinType)<=7){
		
		pinIndix=ConfigPtr->pinType;
		portType= GPIO_PORTA;
	}	

	else if((ConfigPtr->pinType)<=15){
		
		pinIndix=ConfigPtr->pinType - 8;
		portType= GPIO_PORTB;
	}

	else if((ConfigPtr->pinType)<=23){
		
		pinIndix=ConfigPtr->pinType - 16;
		portType= GPIO_PORTC;
	}

	else if((ConfigPtr->pinType)<=31){
		
		pinIndix=ConfigPtr->pinType - 24 ;
		portType= GPIO_PORTD;
	}
	
	else if((ConfigPtr->pinType)<=37){
		
		pinIndix=ConfigPtr->pinType - 32 ;
		portType= GPIO_PORTE;
	}
	
	else if((ConfigPtr->pinType)<=42){
		
		pinIndix=ConfigPtr->pinType - 38 ;
		portType= GPIO_PORTF;
	}
	else{
		;
	}

	switch(portType){
	
	case GPIO_PORTA:
		Bit_Banding(APB_GPIO_PORTA_OFFSET , GPIODATA_OFFSET , pinIndex)= 0 ;
		Bit_Banding(APB_GPIO_PORTA_OFFSET , GPIODEN_OFFSET , pinIndex)= 1 ;

	case GPIO_PORTB:	
		Bit_Banding(APB_GPIO_PORTB_OFFSET , GPIODATA_OFFSET , pinIndex)= 0 ;
		Bit_Banding(APB_GPIO_PORTA_OFFSET , GPIODEN_OFFSET , pinIndex)= 1 ;
			
	case GPIO_PORTC:
		  Bit_Banding(APB_GPIO_PORTC_OFFSET , GPIODATA_OFFSET , pinIndex)= 0 ;
	    Bit_Banding(APB_GPIO_PORTA_OFFSET , GPIODEN_OFFSET , pinIndex)= 1 ;

	case GPIO_PORTD:
        Bit_Banding(APB_GPIO_PORTD_OFFSET , GPIODATA_OFFSET , pinIndex)= 0 ;
		    Bit_Banding(APB_GPIO_PORTA_OFFSET , GPIODEN_OFFSET , pinIndex)= 1 ;

	case GPIO_PORTE:
		Bit_Banding(APB_GPIO_PORTE_OFFSET , GPIODATA_OFFSET , pinIndex)= 0 ;
		Bit_Banding(APB_GPIO_PORTA_OFFSET , GPIODEN_OFFSET , pinIndex)= 1 ;

	case GPIO_PORTF:
		Bit_Banding(APB_GPIO_PORTF_OFFSET , GPIODATA_OFFSET , pinIndex)= 0 ;
		Bit_Banding(APB_GPIO_PORTA_OFFSET , GPIODEN_OFFSET , pinIndex)= 1 ;

	default:break;

	}

	switch(ConfigPtr->directionType){
	
	case INPUT:
	case OUTPUT:

		if(portType == GPIO_PORTA){
				
			Bit_Banding(APB_GPIO_PORTA_OFFSET , GPIODIR_OFFSET , pinIndex)= ConfigPtr->directionType ;

			break;
		}

		else if(portType == GPIO_PORTB){
			
			Bit_Banding(APB_GPIO_PORTB_OFFSET , GPIODIR_OFFSET , pinIndex)= ConfigPtr->directionType ;

			break;
		}
		
		else if(portType == GPIO_PORTC){

			Bit_Banding(APB_GPIO_PORTC_OFFSET , GPIODIR_OFFSET , pinIndex)= ConfigPtr->directionType ;
			
			break;
		}
		
		else if(portType == GPIO_PORTD){

			Bit_Banding(APB_GPIO_PORTD_OFFSET , GPIODIR_OFFSET , pinIndex)= ConfigPtr->directionType ;

			break;
		}
		
		else if(portType == GPIO_PORTE){

			Bit_Banding(APB_GPIO_PORTE_OFFSET , GPIODIR_OFFSET , pinIndex)= ConfigPtr->directionType ;

			break;
		}
		
		else if(portType == GPIO_PORTF){

			Bit_Banding(APB_GPIO_PORTF_OFFSET , GPIODIR_OFFSET , pinIndex)= ConfigPtr->directionType ;

			break;
		}
		else{
			break;
		}
	default:
			break;	

	}
	
	switch(ConfigPtr->pinMode){
	
		case DIO :
		case UART:
		case SSI :
		case I2C :
		
			break;
		
		case PWM :
		            /* Getting PWM from PORTA only M1PWM2......PA6   &&  M1 PWM3..........PA7 */

		if(portType == GPIO_PORTA){
		
			Bit_Banding(APB_GPIO_PORTA_OFFSET , GPIOCTL_OFFSET , ((pinIndex*4)+0))= 1 ;
			Bit_Banding(APB_GPIO_PORTA_OFFSET , GPIOCTL_OFFSET , ((pinIndex*4)+1))= 0 ;
			Bit_Banding(APB_GPIO_PORTA_OFFSET , GPIOCTL_OFFSET , ((pinIndex*4)+2))= 1 ;
			Bit_Banding(APB_GPIO_PORTA_OFFSET , GPIOCTL_OFFSET , ((pinIndex*4)+3))= 0 ;
		}
			break;
		
		case CAN :
		case ADC :
		
			break ;
	}

	switch(ConfigPtr->PinInternalAttachType){
	
		case OPEN_DRAIN  :  	
		
		if(portType == GPIO_PORTA){
				
			Bit_Banding(APB_GPIO_PORTA_OFFSET , GPIOODR_OFFSET , pinIndex)= 1 ;

			break;
		}

		else if(portType == GPIO_PORTB){
			
			Bit_Banding(APB_GPIO_PORTB_OFFSET , GPIOODR_OFFSET , pinIndex)= 1;

			break;
		}
		
		else if(portType == GPIO_PORTC){

			Bit_Banding(APB_GPIO_PORTC_OFFSET , GPIOODR_OFFSET , pinIndex)= 1;
			
			break;
		}
		
		else if(portType == GPIO_PORTD){

			Bit_Banding(APB_GPIO_PORTD_OFFSET , GPIOODR_OFFSET , pinIndex)= 1 ;

			break;
		}
		
		else if(portType == GPIO_PORTE){

			Bit_Banding(APB_GPIO_PORTE_OFFSET , GPIOODR_OFFSET , pinIndex)= 1;

			break;
		}
		
		else if(portType == GPIO_PORTF){

			Bit_Banding(APB_GPIO_PORTF_OFFSET , GPIOODR_OFFSET , pinIndex)= 1;

			break;
		}
		else{
			break;
		}
	
	
		case PULL_UP :   
		
		
		if(portType == GPIO_PORTA){
				
			Bit_Banding(APB_GPIO_PORTA_OFFSET , GPIOPUR_OFFSET , pinIndex)= 1 ;

			break;
		}

		else if(portType == GPIO_PORTB){
			
			Bit_Banding(APB_GPIO_PORTB_OFFSET , GPIOPUR_OFFSET , pinIndex)= 1;

			break;
		}
		
		else if(portType == GPIO_PORTC){

			Bit_Banding(APB_GPIO_PORTC_OFFSET , GPIOPUR_OFFSET , pinIndex)= 1;
			
			break;
		}
		
		else if(portType == GPIO_PORTD){

			Bit_Banding(APB_GPIO_PORTD_OFFSET , GPIOPUR_OFFSET , pinIndex)= 1 ;

			break;
		}
		
		else if(portType == GPIO_PORTE){

			Bit_Banding(APB_GPIO_PORTE_OFFSET , GPIOPUR_OFFSET , pinIndex)= 1;

			break;
		}
		
		else if(portType == GPIO_PORTF){

			Bit_Banding(APB_GPIO_PORTF_OFFSET , GPIOPUR_OFFSET , pinIndex)= 1;

			break;
		}
		else{
			break;
		}

		case PULL_DOWN  :	
		
		
		if(portType == GPIO_PORTA){
				
			Bit_Banding(APB_GPIO_PORTA_OFFSET , GPIOPDR_OFFSET , pinIndex)= 1 ;

			break;
		}

		else if(portType == GPIO_PORTB){
			
			Bit_Banding(APB_GPIO_PORTB_OFFSET , GPIOPDR_OFFSET , pinIndex)= 1;

			break;
		}
		
		else if(portType == GPIO_PORTC){

			Bit_Banding(APB_GPIO_PORTC_OFFSET , GPIOPDR_OFFSET , pinIndex)= 1;
			
			break;
		}
		
		else if(portType == GPIO_PORTD){

			Bit_Banding(APB_GPIO_PORTD_OFFSET , GPIOPDR_OFFSET , pinIndex)= 1 ;

			break;
		}
		
		else if(portType == GPIO_PORTE){

			Bit_Banding(APB_GPIO_PORTE_OFFSET , GPIOPDR_OFFSET , pinIndex)= 1;

			break;
		}
		
		else if(portType == GPIO_PORTF){

			Bit_Banding(APB_GPIO_PORTF_OFFSET , GPIOPDR_OFFSET , pinIndex)= 1;

			break;
		}
		else{
			break;
		}
	
		default: break;
		
	}

	switch(ConfigPtr->pinOutPutCurrentType){
	
	case TWO_mA:
	
			
		if(portType == GPIO_PORTA){
				
			Bit_Banding(APB_GPIO_PORTA_OFFSET , GPIODR2R_OFFSET , pinIndex)= 1 ;

			break;
		}

		else if(portType == GPIO_PORTB){
			
			Bit_Banding(APB_GPIO_PORTB_OFFSET , GPIODR2R_OFFSET , pinIndex)= 1;

			break;
		}
		
		else if(portType == GPIO_PORTC){

			Bit_Banding(APB_GPIO_PORTC_OFFSET , GPIODR2R_OFFSET , pinIndex)= 1;
			
			break;
		}
		
		else if(portType == GPIO_PORTD){

			Bit_Banding(APB_GPIO_PORTD_OFFSET , GPIODR2R_OFFSET , pinIndex)= 1 ;

			break;
		}
		
		else if(portType == GPIO_PORTE){

			Bit_Banding(APB_GPIO_PORTE_OFFSET , GPIODR2R_OFFSET , pinIndex)= 1;

			break;
		}
		
		else if(portType == GPIO_PORTF){

			Bit_Banding(APB_GPIO_PORTF_OFFSET , GPIODR2R_OFFSET , pinIndex)= 1;

			break;
		}
		else{
			break;
		}
	
	
	
	
	case FOUR_mA:
			
		if(portType == GPIO_PORTA){
				
			Bit_Banding(APB_GPIO_PORTA_OFFSET , GPIODR4R_OFFSET , pinIndex)= 1 ;

			break;
		}

		else if(portType == GPIO_PORTB){
			
			Bit_Banding(APB_GPIO_PORTB_OFFSET , GPIODR4R_OFFSET , pinIndex)= 1;

			break;
		}
		
		else if(portType == GPIO_PORTC){

			Bit_Banding(APB_GPIO_PORTC_OFFSET , GPIODR4R_OFFSET , pinIndex)= 1;
			
			break;
		}
		
		else if(portType == GPIO_PORTD){

			Bit_Banding(APB_GPIO_PORTD_OFFSET , GPIODR4R_OFFSET , pinIndex)= 1 ;

			break;
		}
		
		else if(portType == GPIO_PORTE){

			Bit_Banding(APB_GPIO_PORTE_OFFSET , GPIODR4R_OFFSET , pinIndex)= 1;

			break;
		}
		
		else if(portType == GPIO_PORTF){

			Bit_Banding(APB_GPIO_PORTF_OFFSET , GPIODR4R_OFFSET , pinIndex)= 1;

			break;
		}
		else{
			break;
		}
	
	
	case EIGHT_mA:
		
		if(portType == GPIO_PORTA){
				
			Bit_Banding(APB_GPIO_PORTA_OFFSET , GPIODR8R_OFFSET , pinIndex)= 1 ;

			break;
		}

		else if(portType == GPIO_PORTB){
			
			Bit_Banding(APB_GPIO_PORTB_OFFSET , GPIODR8R_OFFSET , pinIndex)= 1;

			break;
		}
		
		else if(portType == GPIO_PORTC){

			Bit_Banding(APB_GPIO_PORTC_OFFSET , GPIODR8R_OFFSET , pinIndex)= 1;
			
			break;
		}
		
		else if(portType == GPIO_PORTD){

			Bit_Banding(APB_GPIO_PORTD_OFFSET , GPIODR8R_OFFSET , pinIndex)= 1 ;

			break;
		}
		
		else if(portType == GPIO_PORTE){

			Bit_Banding(APB_GPIO_PORTE_OFFSET , GPIODR8R_OFFSET , pinIndex)= 1;

			break;
		}
		
		else if(portType == GPIO_PORTF){

			Bit_Banding(APB_GPIO_PORTF_OFFSET , GPIODR8R_OFFSET , pinIndex)= 1;

			break;
		}
		else{
			break;
		}
	
		default: break;
	
	}
	
	
}


/*************************************************************************************************************************

* 	END OF FILE: Dio.c

**************************************************************************************************************************/