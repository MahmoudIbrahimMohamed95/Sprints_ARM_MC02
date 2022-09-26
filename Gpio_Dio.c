/******************************************************************************************************************************
*	FILE DESCRIPTION
*	-------------------------------------------------------------------------------------------------------------------------
*				\File 	 : Dio.c

*				\*brief	 :
*
*				\*details:
*****************************************************************************************************************************/


/****************************************************************************************************************************

*	INCLUDES

****************************************************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Gpio_Dio.h"
#include "Gpio_Dio_Cfg.h"
#include "Gpio_Private.h"

/****************************************************************************************************************************

*	LOCAL MACROS CONSTANT\FUNCTIONS

****************************************************************************************************************************/


#define Bit_Banding(PERIPHRAL_OFFSET , REGISTER_OFFSET , BIT_NUMBER)	((volatile uint32*)(BIT_BAND_ALIAS_BASE_ADDRESS + ((PERIPHRAL_OFFSET + REGISTER_OFFSET) * 32 )))[BIT_NUMBER]



    

/****************************************************************************************************************************

*	LOCAL DATA

****************************************************************************************************************************/



/****************************************************************************************************************************

*	GLOBAL DATA

****************************************************************************************************************************/



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

/*
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId){

	if(ChannelId <= 43){

		switch(ChannelId){
		
		case PA0:	return 	Bit_Banding(APB_GPIO_PORTA_OFFSET , GPIODATA_OFFSET , ChannelId);   
		case PA1:	return 	Bit_Banding(APB_GPIO_PORTA_OFFSET , GPIODATA_OFFSET , ChannelId);	
		case PA2:	return 	Bit_Banding(APB_GPIO_PORTA_OFFSET , GPIODATA_OFFSET , ChannelId);
		case PA3:	return 	Bit_Banding(APB_GPIO_PORTA_OFFSET , GPIODATA_OFFSET , ChannelId);
		case PA4:	return 	Bit_Banding(APB_GPIO_PORTA_OFFSET , GPIODATA_OFFSET , ChannelId);	
		case PA5:	return 	Bit_Banding(APB_GPIO_PORTA_OFFSET , GPIODATA_OFFSET , ChannelId);	
		case PA6:	return 	Bit_Banding(APB_GPIO_PORTA_OFFSET , GPIODATA_OFFSET , ChannelId);
		case PA7:	return 	Bit_Banding(APB_GPIO_PORTA_OFFSET , GPIODATA_OFFSET , ChannelId);

		case PB0:	return 	Bit_Banding(APB_GPIO_PORTB_OFFSET , GPIODATA_OFFSET , (ChannelId-8));
		case PB1:	return 	Bit_Banding(APB_GPIO_PORTB_OFFSET , GPIODATA_OFFSET , (ChannelId-8));
		case PB2:	return 	Bit_Banding(APB_GPIO_PORTB_OFFSET , GPIODATA_OFFSET , (ChannelId-8));
		case PB3:	return 	Bit_Banding(APB_GPIO_PORTB_OFFSET , GPIODATA_OFFSET , (ChannelId-8));
		case PB4:	return 	Bit_Banding(APB_GPIO_PORTB_OFFSET , GPIODATA_OFFSET , (ChannelId-8));
		case PB5:	return 	Bit_Banding(APB_GPIO_PORTB_OFFSET , GPIODATA_OFFSET , (ChannelId-8));
		case PB6:	return 	Bit_Banding(APB_GPIO_PORTB_OFFSET , GPIODATA_OFFSET , (ChannelId-8));
		case PB7:	return 	Bit_Banding(APB_GPIO_PORTB_OFFSET , GPIODATA_OFFSET , (ChannelId-8));
		
		case PC0:	return 	Bit_Banding(APB_GPIO_PORTC_OFFSET , GPIODATA_OFFSET ,(ChannelId-16));
		case PC1:	return 	Bit_Banding(APB_GPIO_PORTC_OFFSET , GPIODATA_OFFSET , (ChannelId-16));
		case PC2:	return 	Bit_Banding(APB_GPIO_PORTC_OFFSET , GPIODATA_OFFSET , (ChannelId-16));
		case PC3:	return 	Bit_Banding(APB_GPIO_PORTC_OFFSET , GPIODATA_OFFSET , (ChannelId-16));
		case PC4:	return 	Bit_Banding(APB_GPIO_PORTC_OFFSET , GPIODATA_OFFSET , (ChannelId-16));
		case PC5:	return 	Bit_Banding(APB_GPIO_PORTC_OFFSET , GPIODATA_OFFSET , (ChannelId-16));
		case PC6:	return 	Bit_Banding(APB_GPIO_PORTC_OFFSET , GPIODATA_OFFSET , (ChannelId-16));
		case PC7:	return 	Bit_Banding(APB_GPIO_PORTC_OFFSET , GPIODATA_OFFSET , (ChannelId-16));
	
		case PD0:	return  Bit_Banding(APB_GPIO_PORTD_OFFSET , GPIODATA_OFFSET , (ChannelId-24));
		case PD1:	return 	Bit_Banding(APB_GPIO_PORTD_OFFSET , GPIODATA_OFFSET , (ChannelId-24));
		case PD2:	return 	Bit_Banding(APB_GPIO_PORTD_OFFSET , GPIODATA_OFFSET , (ChannelId-24));
		case PD3:	return 	Bit_Banding(APB_GPIO_PORTD_OFFSET , GPIODATA_OFFSET , (ChannelId-24));
		case PD4:	return 	Bit_Banding(APB_GPIO_PORTD_OFFSET , GPIODATA_OFFSET , (ChannelId-24));
		case PD5:	return 	Bit_Banding(APB_GPIO_PORTD_OFFSET , GPIODATA_OFFSET , (ChannelId-24));
		case PD6:	return 	Bit_Banding(APB_GPIO_PORTD_OFFSET , GPIODATA_OFFSET , (ChannelId-24);
		case PD7:	return 	Bit_Banding(APB_GPIO_PORTD_OFFSET , GPIODATA_OFFSET , (ChannelId-24));
		
		case PE0:	return 	Bit_Banding(APB_GPIO_PORTA_OFFSET , GPIODATA_OFFSET , (ChannelId-32));
		case PE1:	return 	Bit_Banding(APB_GPIO_PORTA_OFFSET , GPIODATA_OFFSET , (ChannelId-32));
		case PE2:	return 	Bit_Banding(APB_GPIO_PORTA_OFFSET , GPIODATA_OFFSET , (ChannelId-32));
		case PE3:	return 	Bit_Banding(APB_GPIO_PORTA_OFFSET , GPIODATA_OFFSET , (ChannelId-32));
		case PE4:	return 	Bit_Banding(APB_GPIO_PORTA_OFFSET , GPIODATA_OFFSET , (ChannelId-32);
		case PE5:	return 	Bit_Banding(APB_GPIO_PORTA_OFFSET , GPIODATA_OFFSET , (ChannelId-32));
	
		case PF0:	return 	Bit_Banding(APB_GPIO_PORTA_OFFSET , GPIODATA_OFFSET , (ChannelId-38));
		case PF1:	return 	Bit_Banding(APB_GPIO_PORTA_OFFSET , GPIODATA_OFFSET , (ChannelId-38));
		case PF2:	return 	Bit_Banding(APB_GPIO_PORTA_OFFSET , GPIODATA_OFFSET , (ChannelId-38));
		case PF3:	return 	Bit_Banding(APB_GPIO_PORTA_OFFSET , GPIODATA_OFFSET , (ChannelId-38));
		case PF4:	return 	Bit_Banding(APB_GPIO_PORTA_OFFSET , GPIODATA_OFFSET , (ChannelId-38));
		
		default: break;
		}
	}
}

*/

/****************************************************************************************************************************
													ANOTHER IMPLEMINTATION
****************************************************************************************************************************/

Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId){

	if(ChannelId <= 42){
		if(ChannelId <= 7){
			return 	Bit_Banding(APB_GPIO_PORTA_OFFSET , GPIODATA_OFFSET , ChannelId);
		}
		else if(ChannelId <= 15){
			return 	Bit_Banding(APB_GPIO_PORTB_OFFSET , GPIODATA_OFFSET , (ChannelId-8));
		}
		else if(ChannelId <= 23){
			return 	Bit_Banding(APB_GPIO_PORTC_OFFSET , GPIODATA_OFFSET , (ChannelId-16));
		}
		else if(ChannelId <= 31){
			return 	Bit_Banding(APB_GPIO_PORTD_OFFSET , GPIODATA_OFFSET , (ChannelId-24));
		}
		else if(ChannelId <= 37){
			return 	Bit_Banding(APB_GPIO_PORTA_OFFSET , GPIODATA_OFFSET , (ChannelId-32));
		}
		else if(ChannelId <= 42){
			return 	Bit_Banding(APB_GPIO_PORTA_OFFSET , GPIODATA_OFFSET , (ChannelId-38));
		}
		else{
			;  
		}
	}
	
}	



DIO_WriteChannel(Dio_ChannelType ChannelId , Dio_LevelType Level){
	
	if(Level==LOW || Level==HIGH){
	
		switch(ChannelId){
		
		case PA0: 	APB_PORTA->GPIO_DATA[1]   = Level; break;  

		case PA1:	APB_PORTA->GPIO_DATA[2]   = Level; break;

		case PA2:	APB_PORTA->GPIO_DATA[4]   = Level; break;

		case PA3:	APB_PORTA->GPIO_DATA[8]   = Level; break;	

		case PA4:	APB_PORTA->GPIO_DATA[16]  = Level; break;

		case PA5:	APB_PORTA->GPIO_DATA[32]  = Level; break;

		case PA6:	APB_PORTA->GPIO_DATA[64]  = Level; break;	

		case PA7:	APB_PORTA->GPIO_DATA[128] = Level; break;	

		case PB0:	APB_PORTB->GPIO_DATA[1]=   Level; break;

		case PB1:	APB_PORTB->GPIO_DATA[2]=   Level; break;

		case PB2:	APB_PORTB->GPIO_DATA[4]=   Level; break;

		case PB3:	APB_PORTB->GPIO_DATA[8]=   Level; break;

		case PB4:	APB_PORTB->GPIO_DATA[16]=  Level; break;

		case PB5:	APB_PORTB->GPIO_DATA[32]=  Level; break;

		case PB6:	APB_PORTB->GPIO_DATA[64]=  Level; break;

		case PB7:	APB_PORTB->GPIO_DATA[128]= Level; break;

		
		case PC0:	APB_PORTC->GPIO_DATA[1]=    Level; break;

		case PC1:	APB_PORTC->GPIO_DATA[2]=    Level; break;

		case PC2:	APB_PORTC->GPIO_DATA[4]=    Level; break;

		case PC3:	APB_PORTC->GPIO_DATA[8]=    Level; break;

		case PC4:	APB_PORTC->GPIO_DATA[16]=   Level; break;

		case PC5:	APB_PORTC->GPIO_DATA[32]=   Level; break;

		case PC6:	APB_PORTC->GPIO_DATA[64]=   Level; break;

		case PC7:	APB_PORTC->GPIO_DATA[128]=  Level; break;

	
		case PD0:	APB_PORTD->GPIO_DATA[1]=    Level; break;

		case PD1:	APB_PORTD->GPIO_DATA[2]=    Level; break;

		case PD2:	APB_PORTD->GPIO_DATA[4]=    Level; break;

		case PD3:	APB_PORTD->GPIO_DATA[8]=    Level; break;

		case PD4:	APB_PORTD->GPIO_DATA[16]=   Level; break;

		case PD5:	APB_PORTD->GPIO_DATA[32]=   Level; break;

		case PD6:	APB_PORTD->GPIO_DATA[64]=   Level; break;

		case PD7:	APB_PORTD->GPIO_DATA[128]=  Level; break;
		
		case PE0:	APB_PORTE->GPIO_DATA[1]=   Level; break;

		case PE1:	APB_PORTE->GPIO_DATA[2]=   Level; break;

		case PE2:	APB_PORTE->GPIO_DATA[4]=   Level; break;

		case PE3:	APB_PORTE->GPIO_DATA[8]=   Level; break;

		case PE4:	APB_PORTE->GPIO_DATA[16]=  Level; break;

		case PE5:	APB_PORTE->GPIO_DATA[32]=  Level; break;

	
		case PF0:	APB_PORTF->GPIO_DATA[1]=   Level; break;

		case PF1:	APB_PORTF->GPIO_DATA[2]=   Level; break;

		case PF2:	APB_PORTF->GPIO_DATA[4]=   Level; break;

		case PF3:	APB_PORTF->GPIO_DATA[8]=   Level; break;

		case PF4:	APB_PORTF->GPIO_DATA[16]=  Level; break;

		default:
		
			break;
	
		}		
	
	}

}

/*****************************************************************************************************************************

													ANOTHER IMPLEMENTATION
												
*****************************************************************************************************************************


DIO_WriteChannel(Dio_ChannelType ChannelId , Dio_LevelType Level){
	
	uint8 channel_index=2;
	
	
	if(Level==Low  || Level==HIGH){
		
		if(ChannelId <= 7){
	
			if (ChannelId==0){
		
				APB_PORTA->GPIO_DATA[1]= Level;
		
			}

			elseif(ChannelId==1){
			
				APB_PORTA->GPIO_DATA[1]= Level;
			}

			else{
				for(uint8 i = 2 ; i <= ChannelId ;i++){
			
					channel_index*=2;
			}
				
				APB_PORTA->GPIO_DATA[channel_index]= Level;	
		}
		
		elseif(ChannelId <= 15){

			ChannelId-=8;
			
			if (ChannelId==0){
		
				APB_PORTB->GPIO_DATA[1]= Level;
		
			}

			elseif(ChannelId==1){
			
				APB_PORTB->GPIO_DATA[1]= Level;
			}

			else{
				for(uint8 i = 2 ; i <= ChannelId ;i++){
			
					channel_index*=2;
			}
				
				APB_PORTB->GPIO_DATA[channel_index]= Level;	
			
		}
		
		elseif(ChannelId <= 23){
			
			ChannelId-=16;
			
			if (ChannelId==0){
		
				APB_PORTC->GPIO_DATA[1]= Level;
		
			}

			elseif(ChannelId==1){
			
				APB_PORTC->GPIO_DATA[1]= Level;
			}

			else{
				for(uint8 i = 2 ; i <= ChannelId ;i++){
			
					channel_index*=2;
			}
				
				APB_PORTC->GPIO_DATA[channel_index]= Level;	
		}
			
		
		
		elseif(ChannelId <= 31){
		
			ChannelId-=24;
			
			if (ChannelId==0){
		
				APB_PORTD->GPIO_DATA[1]= Level;
		
			}

			elseif(ChannelId==1){
			
				APB_PORTD->GPIO_DATA[1]= Level;
			}

			else{
				for(uint8 i = 2 ; i <= ChannelId ;i++){
			
					channel_index*=2;
			}
				
				APB_PORTD->GPIO_DATA[channel_index]= Level;	
		
		}
		
		elseif(ChannelId <= 37){

			ChannelId-=32;
			
			if (ChannelId==0){
		
				APB_PORTE->GPIO_DATA[1]= Level;
		
			}

			elseif(ChannelId==1){
			
				APB_PORTE->GPIO_DATA[1]= Level;
			}

			else{
				for(uint8 i = 2 ; i <= ChannelId ;i++){
			
					channel_index*=2;
			}
				
				APB_PORTE->GPIO_DATA[channel_index]= Level;	
		
		}
		
		elseif(ChannelId <= 42){
		
			ChannelId-=38;
			
			if (ChannelId==0){
		
				APB_PORTF->GPIO_DATA[1]= Level;
		
			}

			elseif(ChannelId==1){
			
				APB_PORTF->GPIO_DATA[1]= Level;
			}

			else{
				for(uint8 i = 2 ; i <= ChannelId ;i++){
			
					channel_index*=2;
			}
				
				APB_PORTF->GPIO_DATA[channel_index]= Level;	
		
		}
		
		else{
			;
		}
	}
}

********************************************************************************************************************************************/
	
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId){

	switch(PortId){
	
	case PORTA: return APB_PORTA->GPIO_DATA[255];
	case PORTB:	return APB_PORTB->GPIO_DATA[255];
	case PORTC:	return APB_PORTC->GPIO_DATA[255];
	case PORTD:	return APB_PORTD->GPIO_DATA[255];
	case PORTE:	return APB_PORTE->GPIO_DATA[255];
	case PORTF:	return APB_PORTF->GPIO_DATA[255];
	
	}

}

void Dio_WritePort(Dio_PortType PortId , Dio_PortLevelType Level){
	
	switch(PortId){
	
	case PORTA: APB_PORTA->GPIO_DATA[255]=Level;    break;  /*PIOA_DATA[255]=Level case register definition using #define */
	case PORTB:	APB_PORTB->GPIO_DATA[255]=Level;  	break;
	case PORTC:	APB_PORTC->GPIO_DATA[255]=Level;	  break;
	case PORTD:	APB_PORTD->GPIO_DATA[255]=Level;	  break;
	case PORTE:	APB_PORTE->GPIO_DATA[63] =Level;	  break;
	case PORTF:	APB_PORTF->GPIO_DATA[31] =Level;	  break;
	
	}
	
}

Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId){
	
	if(ChannelId <= 42){
	
		if(ChannelId <= 7){

			if (Bit_Banding(APB_GPIO_PORTA_OFFSET , GPIODATA_OFFSET , ChannelId) == 1 ){
		
				Bit_Banding(APB_GPIO_PORTA_OFFSET , GPIODATA_OFFSET , ChannelId)= 0;
				
				return LOW;
			}
			else{
				Bit_Banding(APB_GPIO_PORTA_OFFSET , GPIODATA_OFFSET , ChannelId)=1;
				
				return HIGH;
			}
		}
		else if(ChannelId <= 15){
		
			if	( Bit_Banding(APB_GPIO_PORTB_OFFSET , GPIODATA_OFFSET , (ChannelId-8))==1){
				  Bit_Banding(APB_GPIO_PORTA_OFFSET , GPIODATA_OFFSET , (ChannelId-8))=0;
				
				return LOW;
			 }
			 else{
				
				Bit_Banding(APB_GPIO_PORTA_OFFSET , GPIODATA_OFFSET , (ChannelId-8))=1;   /*operation inside array index MISRA doesn't agree :)*/

				return HIGH;
			}
		}
		else if(ChannelId <= 23){
			 	
			if	( Bit_Banding(APB_GPIO_PORTB_OFFSET , GPIODATA_OFFSET , (ChannelId-16))==1){
				
				  Bit_Banding(APB_GPIO_PORTA_OFFSET , GPIODATA_OFFSET , (ChannelId-16))=0;

				  return LOW;
			 }
			 else{
				
				Bit_Banding(APB_GPIO_PORTA_OFFSET , GPIODATA_OFFSET , (ChannelId-16))=1;   /*operation inside array index MISRA doesn't agree :)*/

				return HIGH;
			}
		}
		else if(ChannelId <= 31){
			 	
			if	( Bit_Banding(APB_GPIO_PORTB_OFFSET , GPIODATA_OFFSET , (ChannelId-24))==1){
				
				  Bit_Banding(APB_GPIO_PORTA_OFFSET , GPIODATA_OFFSET , (ChannelId-24))=0;

				  return LOW;
			 }
			 else{
				
				Bit_Banding(APB_GPIO_PORTA_OFFSET , GPIODATA_OFFSET , (ChannelId-24))=1;   /*operation inside array index MISRA doesn't agree :)*/

				return HIGH;
			}
			
		}
		else if(ChannelId <= 37){
			 	
			if	( Bit_Banding(APB_GPIO_PORTB_OFFSET , GPIODATA_OFFSET , (ChannelId-32))==1){
				  Bit_Banding(APB_GPIO_PORTA_OFFSET , GPIODATA_OFFSET , (ChannelId-32))=0;

				  return LOW;
			 }
			 else{
				
				Bit_Banding(APB_GPIO_PORTA_OFFSET , GPIODATA_OFFSET , (ChannelId-32))=1;   /*operation inside array index MISRA doesn't agree :)*/

				return HIGH;
			}		

		}

		else if(ChannelId <= 42){
			 	
			if	( Bit_Banding(APB_GPIO_PORTB_OFFSET , GPIODATA_OFFSET , (ChannelId-38))==1){
				  Bit_Banding(APB_GPIO_PORTA_OFFSET , GPIODATA_OFFSET , (ChannelId-38))=0;

				  return LOW;
			 }
			 else{
				
				Bit_Banding(APB_GPIO_PORTA_OFFSET , GPIODATA_OFFSET , (ChannelId-38))=1;   /*operation inside array index MISRA doesn't agree :) */

				return HIGH;
			}
			
		}

		else{
			;  /*donothing*/
		}
	
	}		

}




