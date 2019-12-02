
#include "QueueExmplTasks.h"
#include "SerialPortTask.h"
#include "stdio_serial.h"
#include "task.h"
#include "FreeRtosTasks.h"
#include "queue.h"
#include "string.h"


void queue_task_one(void)
{

	BaseType_t xStatus;
	while(1)
	{
		taskYIELD(); 
		
			if(u8QueueDataIndex >= sizeof(auQueue8Data))
			{
				u8QueueDataIndex = 0u;
			}
			xStatus = xQueueSendToBack( xQueue1, &auQueue8Data[u8QueueDataIndex++] , pdMS_TO_TICKS( 60000 ) );
	
		  if( xStatus != pdPASS )
		  {

			  puts("error\r\n");
		  }
			 
		 
		  
	}
	
}
void queue_task_two(void)
{
	
	
}
void queue_task_three(void)
{
	BaseType_t xStatus;
	uint8_t autRecData[10];
	uint8_t u8RecIndex = 0u;
	memset(autRecData, 0u, sizeof(autRecData));
	while(1)
	{
		taskYIELD(); 
		if(u8RecIndex >= sizeof(auQueue8Data))
		{
			u8RecIndex = 0;
			memset(autRecData, 0u, sizeof(autRecData));
		}
		xStatus = xQueueReceive( xQueue1, &autRecData[u8RecIndex], pdMS_TO_TICKS( 50000 ) );
		if(xStatus == pdPASS)
		{
			putchar(autRecData[u8RecIndex++]);
			
		}
		else
		{
			puts("error..\r\n");
		}
	}
	
}


