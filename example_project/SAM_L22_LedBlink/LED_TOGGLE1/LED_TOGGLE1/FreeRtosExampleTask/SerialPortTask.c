
#include "SerialPortTask.h"
#include "stdio_serial.h"
#include "task.h"


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
