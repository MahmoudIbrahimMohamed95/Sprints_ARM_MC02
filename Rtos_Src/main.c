/*
 * FreeRTOS Kernel V10.2.0
 * Copyright (C) 2019 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://www.FreeRTOS.org
 * http://aws.amazon.com/freertos
 *
 * 1 tab == 4 spaces!
 */

/* 
	NOTE : Tasks run in system mode and the scheduler runs in Supervisor mode.
	The processor MUST be in supervisor mode when vTaskStartScheduler is 
	called.  The demo applications included in the FreeRTOS.org download switch
	to supervisor mode prior to main being called.  If you are not using one of
	these demo application projects then ensure Supervisor mode is used.
*/


/*
 * Creates all the demo application tasks, then starts the scheduler.  The WEB
 * documentation provides more details of the demo application tasks.
 * 
 * Main.c also creates a task called "Check".  This only executes every three 
 * seconds but has the highest priority so is guaranteed to get processor time.  
 * Its main function is to check that all the other tasks are still operational.
 * Each task (other than the "flash" tasks) maintains a unique count that is 
 * incremented each time the task successfully completes its function.  Should 
 * any error occur within such a task the count is permanently halted.  The 
 * check task inspects the count of each task to ensure it has changed since
 * the last time the check task executed.  If all the count variables have 
 * changed all the tasks are still executing error free, and the check task
 * toggles the onboard LED.  Should any task contain an error at any time 
 * the LED toggle rate will change from 3 seconds to 500ms.
 *
 */

/* Standard includes. */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"
	
#include "lpc21xx.h"

/* Peripheral includes. */
#include "serial.h"
#include "GPIO.h"
#include  "queue.h"

/*-----------------------------------------------------------*/

/* Constants to setup I/O and processor. */
#define mainBUS_CLK_FULL	( ( unsigned char ) 0x01 )

/* Constants for the ComTest demo application tasks. */
#define mainCOM_TEST_BAUD_RATE	( ( unsigned long ) 115200 )


/*
 * Configure the processor for use with the Keil demo board.  This is very
 * minimal as most of the setup is managed by the settings in the project
 * file.
 */

static void prvSetupHardware( void );
void vTaskGetRunTimeStats(char*pcWriteBuffer) ;

/*-----------------------------------------------------------*/
volatile int Button1_Misses=0;
volatile int Button2_Misses=0;
volatile int PeriodicTransmit_Misses=0;
volatile int Uart_Misses=0;
volatile int Task5_Misses=0;
volatile int Task6_Misses=0;

TaskHandle_t Button_1_MonitorHandler = NULL;

TaskHandle_t Button_2_MonitorHandler = NULL;

TaskHandle_t Periodic_TransmitterHandler = NULL;

TaskHandle_t Uart_RecieverHandler = NULL;

TaskHandle_t Task_5Handler = NULL;

TaskHandle_t Task_6Handler = NULL;

QueueHandle_t Global_QueueHandler = NULL;

/*may be array*/
int Task_1_InTime ,Task_1_OutTime , Task_1_TotalTime ;
int Task_2_InTime ,Task_2_OutTime , Task_2_TotalTime ;
int Task_3_InTime ,Task_3_OutTime , Task_3_TotalTime ;
int Task_4_InTime ,Task_4_OutTime , Task_4_TotalTime ;
int Task_5_InTime ,Task_5_OutTime , Task_5_TotalTime ;
int Task_6_InTime ,Task_6_OutTime , Task_6_TotalTime ;
int System_Time;
int Cpu_Load;


struct Message
{
   char  MessageID;
   char*TaskData;
	
}  TaskA_Button_On ,TaskA_Button_Off , TaskB_Button_On , TaskB_Button_Off , PeriodicTransmit_Message , UART_Recieve;

char RunTimeStats[190];


void Button_1_Monitor( void * pvParameters )
{		
		int i,Tick=0;

		int	End_Time=0 , Start_Time=0;

		int ButtonState_1=0;
		
	  TickType_t xLastWakeTime = xTaskGetTickCount();

	 vTaskSetApplicationTaskTag(
                        NULL,
                        (void*)1 );

		TaskA_Button_On.MessageID= 0x01 ;
		TaskA_Button_On.TaskData= "Button_One_on.." ;

		TaskA_Button_Off.MessageID = 0x02 ;
		TaskA_Button_Off.TaskData = "Button_One_Off.";

		
	
	for( ;; )

		{  
		
			ButtonState_1=GPIO_read(PORT_0, PIN0);

			if(ButtonState_1 == 1){

				Tick++;

			if(Tick==2){

					xQueueSend( Global_QueueHandler,
										&TaskA_Button_On,
										(( TickType_t )0) );
					Tick=0;

			  }			
			}

			else{
			
			xQueueSend( Global_QueueHandler,
									&TaskA_Button_Off,
									(( TickType_t )0) );
		
			Tick=0;			

			}
			
				End_Time=xTaskGetTickCount();

				if((End_Time - Start_Time)>5){

						Button1_Misses++;
				}

					vTaskDelayUntil( &xLastWakeTime, 5 );

					Start_Time=xTaskGetTickCount();
		}

}



void Button_2_Monitor( void * pvParameters )
{
		
		 int i,Tick=0;

		 int	ButtonState_2=0;
			
		 int Start_Time=0 , End_Time=0; 

		 TickType_t xLastWakeTime = xTaskGetTickCount();

		
		 vTaskSetApplicationTaskTag(
                        NULL,
                        (void*)2 );

	
		TaskB_Button_On.MessageID= 0x03 ;
		TaskB_Button_On.TaskData= "Button_Two_On.." ;

		TaskB_Button_Off.MessageID = 0x04 ;
		TaskB_Button_Off.TaskData = "Button_Two_Off.";

		for( ;; )

		{
				ButtonState_2=GPIO_read(PORT_0, PIN1);
				
				if(ButtonState_2==1){

					Tick++;
					if(Tick==2){
					xQueueSend( Global_QueueHandler,
											&TaskB_Button_On,
											(( TickType_t ) 0 ) );

						
						Tick=0;

					}
			}

				else{
							
					xQueueSend( Global_QueueHandler,
									&TaskB_Button_Off,
									(( TickType_t ) 0 ) );

					Tick=0;		
				}
				
				
					End_Time=xTaskGetTickCount();
					if((End_Time - Start_Time)>5){

						Button2_Misses++;
					}
				

					vTaskDelayUntil( &xLastWakeTime, 5 );

					Start_Time=xTaskGetTickCount();
    }

}



void Periodic_Transmitter( void * pvParameters )
{
	int i=0;
	int Start_Time=0 , End_Time=0;

		TickType_t xLastWakeTime = xTaskGetTickCount();

		vTaskSetApplicationTaskTag(
                        NULL,
                        (void*)3 );

		PeriodicTransmit_Message.MessageID=0x05;

		PeriodicTransmit_Message.TaskData= "HEY TASK3 HERE";

	for( ;; )
	
	{
			xQueueSend( Global_QueueHandler,
									&PeriodicTransmit_Message,
									(( TickType_t ) 0 )==pdPASS );
		
	
			
			End_Time=xTaskGetTickCount();

			if((End_Time - Start_Time)>10){

						PeriodicTransmit_Misses++;
					}
				
					vTaskDelayUntil( &xLastWakeTime, 10 );

					
					Start_Time=xTaskGetTickCount();							
				}
}

void Uart_Reciever( void * pvParameters )
{
		int i=0;
	int Start_Time=0;int End_Time=0;	
	TickType_t xLastWakeTime = xTaskGetTickCount();

		 vTaskSetApplicationTaskTag(
                        NULL,
                        (void*)4 );

	
	
	for( ;; ){

		if( Global_QueueHandler != NULL )
		{
					xQueueReceive( Global_QueueHandler,
                         &( UART_Recieve),
                         (( TickType_t )3) == pdPASS) ;

		}

		
		xSerialPutChar('\n');
		vSerialPutString( (const signed char*)UART_Recieve.TaskData,14);
	

		End_Time=xTaskGetTickCount();
	 
		if((End_Time - Start_Time)>2){
						Uart_Misses++;				
		}
				
				

					vTaskDelayUntil( &xLastWakeTime, 2 );

				
					
					Start_Time=xTaskGetTickCount();
		}

}


void Task_5( void * pvParameters )
{
		int i=0;
		int Start_Time=0, End_Time=0;

		TickType_t xLastWakeTime = xTaskGetTickCount();

		vTaskSetApplicationTaskTag(
                        NULL,
                        (void*)5 );

		for( ;; )

		{
			        /* Task code goes here. */

				for(i=0;i<34000;i++){
			
					i=i;
				}
		
				/* Wait for the next cycle.*/
				End_Time=xTaskGetTickCount();

				if((End_Time - Start_Time)>1){
						Task5_Misses++;
					}
					
					
			vTaskDelayUntil( &xLastWakeTime ,1 );

			Start_Time=xTaskGetTickCount();

		}

}


void Task_6( void * pvParameters )
{
	
	int j;

	int End_Time=0 , Start_Time=0;
	
	TickType_t xLastWakeTime = xTaskGetTickCount();

		 vTaskSetApplicationTaskTag(
                        NULL,
                        (void*)6 );


		for( ;; )

		{
				  /* Task code goes here. */
				
					for(j=0;j<63000;j++){
			
						j=j;
	
					}
      
			
				/* Wait for the next cycle.*/
			
			End_Time=xTaskGetTickCount();
					if((End_Time - Start_Time)>10){

						Task6_Misses++;
				
					}



						vTaskDelayUntil( &xLastWakeTime,10 );

						Start_Time=xTaskGetTickCount();
				
		}

}

void vApplicationTickHook( void ){
	 
	/**ManChester**/

}
void vApplicationIdleHook( void ){

	GPIO_write(PORT_0, PIN8, PIN_IS_HIGH);
	GPIO_write(PORT_0, PIN8, PIN_IS_LOW);
				/*
									GPIO_write(PORT_0 ,PIN2, PIN_IS_LOW);
									GPIO_write(PORT_0 ,PIN3, PIN_IS_LOW);
									GPIO_write(PORT_0 ,PIN4, PIN_IS_LOW);
									GPIO_write(PORT_0 ,PIN5, PIN_IS_LOW);
									GPIO_write(PORT_0 ,PIN6, PIN_IS_LOW);
									GPIO_write(PORT_0 ,PIN7, PIN_IS_LOW);			*/
}

/*
 * Application entry point:
 * Starts all the other tasks, then starts the scheduler. 
 */
int main( void )
{
	/* Setup the hardware for use with the Keil demo board. */

	prvSetupHardware();

	Global_QueueHandler = xQueueCreate( 3, sizeof( UART_Recieve) );
	
	xTaskPeriodicCreate(
                    Button_1_Monitor,               /* Function that implements the task. */
    
										"Button 1 Monitor",             /* Text name for the task. */
                    100,                            /* Stack size in words, not bytes. */
                    ( void * ) 0,                   /* Parameter passed into the task. */
                    1,                              /* Priority at which the task is created. */
										&Button_1_MonitorHandler ,      /* Used to pass out the created task's handle. */
										50);														/*Task Periodicity which is equal to it's Dead Line*/
	
	xTaskPeriodicCreate(
                    Button_2_Monitor,                /* Function that implements the task. */
                    "Button 2 Monitor",              /* Text name for the task. */
                    100,                             /* Stack size in words, not bytes. */
                    ( void * ) 0,                    /* Parameter passed into the task. */
											2,                               /* Priority at which the task is created. */
										&Button_2_MonitorHandler,        /* Used to pass out the created task's handle. */
										50);															/*Task Periodicity which is equal to it's Dead Line*/
	
	xTaskPeriodicCreate(
										Periodic_Transmitter,             /* Function that implements the task. */
                    "Periodic Transmitter",           /* Text name for the task. */
                    100,                              /* Stack size in words, not bytes. */
                    ( void * ) 0,                     /* Parameter passed into the task. */
                   2,                                /* Priority at which the task is created. */
                    &Periodic_TransmitterHandler,     /* Used to pass out the created task's handle. */
										100);															/*Task Periodicity which is equal to it's Dead Line*/
	
	xTaskPeriodicCreate(
                    Uart_Reciever,                    /* Function that implements the task. */
                    "Uart Reciever",                  /* Text name for the task. */
                    100,                              /* Stack size in words, not bytes. */
                    ( void * ) 0,                     /* Parameter passed into the task. */
                    2,                                /* Priority at which the task is created. */
                    &Uart_RecieverHandler,            /* Used to pass out the created task's handle. */
										20);															/*Task Periodicity which is equal to it's Dead Line*/
		
	xTaskPeriodicCreate(
                    Task_5,                    				/* Function that implements the task. */
                    "Task 5",                  				/* Text name for the task. */
                    100,                              /* Stack size in words, not bytes. */
                    ( void * ) 0,                     /* Parameter passed into the task. */
                    2,                                /* Priority at which the task is created. */
                    &Task_5Handler,            				/* Used to pass out the created task's handle. */
										10);															/*Task Periodicity which is equal to it's Dead Line*/
										

	xTaskPeriodicCreate(
                    Task_6,                    				/* Function that implements the task. */
                    "Task 6",                  				/* Text name for the task. */
                    100,                              /* Stack size in words, not bytes. */
                    ( void * ) 0,                     /* Parameter passed into the task. */
                    2,                                /* Priority at which the task is created. */
                    &Task_6Handler ,     							      /* Used to pass out the created task's handle. */
										100 );														/*Task Periodicity which is equal to it's Dead Line*/										
	
	
	/* Now all the tasks have been started - start the scheduler.

	NOTE : Tasks run in system mode and the scheduler runs in Supervisor mode.
	The processor MUST be in supervisor mode when vTaskStartScheduler is 
	called.  The demo applications included in the FreeRTOS.org download switch
	to supervisor mode prior to main being called.  If you are not using one of
	these demo application projects then ensure Supervisor mode is used here. */


	vTaskStartScheduler();

										
	/* Should never reach here!  If you do then there was not enough heap
	available for the idle task to be created. */


	for( ;; );


}
/*-----------------------------------------------------------*/

/* Function to reset timer 1 */
void timer1Reset(void)
{
	T1TCR |= 0x2;
	T1TCR &= ~0x2;
}

/* Function to initialize and start timer 1 */
static void configTimer1(void)
{
	T1PR = 1000;
	T1TCR |= 0x1;
}

static void prvSetupHardware( void )
{
	/* Perform the hardware setup required.  This is minimal as most of the
	setup is managed by the settings in the project file. */

	/* Configure UART */
	xSerialPortInitMinimal(mainCOM_TEST_BAUD_RATE);

	/* Configure GPIO */
	GPIO_init();
	
	/* Config trace timer 1 and read T1TC to get current tick */
	configTimer1();

	/* Setup the peripheral bus to be the same as the PLL output. */
	VPBDIV = mainBUS_CLK_FULL;
}
/*-----------------------------------------------------------*/


