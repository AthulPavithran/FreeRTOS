
#include "SerialPortTask.h"
#include "stdio_serial.h"
#include "task.h"
#include "semphr.h"
#include "FreeRtosTasks.h"


#define PRIORITY_TEST      1
#define VTASKDELAY_TEST    0


void sserial_task_one(void)
{
	TickType_t xLastWakeTime;
	xLastWakeTime = xTaskGetTickCount();
	while(1)
	{
#if (VTASKDELAY_TEST)	
		puts("---01.\r\n");
		vTaskDelay( 100);
		//	 vTaskDelayUntil(xLastWakeTime, 500);
#elif (PRIORITY_TEST)
		puts("---01.\r\n");
		puts("---01.\r\n");
		puts("---01.\r\n");
		UBaseType_t uxPriority = uxTaskPriorityGet( "SERIAL_TASK_2" );
		vTaskPrioritySet( NULL, ( uxPriority - 1 ) );		
		vTaskPrioritySet( "SERIAL_TASK_2", ( uxPriority + 1 ) );


#endif
	}
	vTaskDelete("SERIAL_TASK_1");

}

void sserial_task_two(void)
{
	TickType_t xLastWakeTime;
	xLastWakeTime = xTaskGetTickCount();
	while(1)
	{
		
#if (VTASKDELAY_TEST)
		puts("---02.\r\n");
		vTaskDelay( 100);
		//	 vTaskDelayUntil(xLastWakeTime, 500);
#elif (PRIORITY_TEST)

		puts("---02.\r\n");
		puts("---02.\r\n");
		puts("---02.\r\n");
		
		UBaseType_t uxPriority = uxTaskPriorityGet( "SERIAL_TASK_1" );
		
		vTaskPrioritySet( NULL, ( uxPriority - 1 ) );
		vTaskPrioritySet( "SERIAL_TASK_1", ( uxPriority + 1 ) );

#endif

	}
	vTaskDelete("SERIAL_TASK_2");

}


void sserial_task_three(void)
{
	TickType_t xLastWakeTime;
	xLastWakeTime = xTaskGetTickCount();
	while(1)
	{
		

	}
	vTaskDelete("SERIAL_TASK_2");

}

void serial_task_four(void)
{
	
	while(1)
	{
		
	 xSemaphoreTake( xMutex, pdMS_TO_TICKS( 50000 ) );	
	 puts("How are you\r\n");
	 xSemaphoreGive( xMutex );
	 taskYIELD();
		
	}
	
}

void serial_task_five(void)
{
	
	while(1)
	{
		xSemaphoreTake( xMutex, pdMS_TO_TICKS( 50000 ) );
		puts("I am good\r\n");
		xSemaphoreGive( xMutex );
		taskYIELD();
		
		
	}
	
}
