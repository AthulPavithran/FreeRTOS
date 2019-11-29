
#include "SerialPortTask.h"
#include "stdio_serial.h"
#include "task.h"


void sserial_task_one(void)
{
	TickType_t xLastWakeTime;
	xLastWakeTime = xTaskGetTickCount();
	while(1)
	{
				
		puts("---01.\r\n");
		vTaskDelay( 500);
		//	 vTaskDelayUntil(xLastWakeTime, 500);
	}
	vTaskDelete("SERIAL_TASK_1");

}
