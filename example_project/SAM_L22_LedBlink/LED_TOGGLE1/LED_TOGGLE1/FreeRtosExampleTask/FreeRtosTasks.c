
#include "LedTasks.h"
#include "SerialPortTask.h"
#include "task.h"
#include "QueueExmplTasks.h"
#include "queue.h"
#include "ExamplTaskConfig.h"



TaskHandle_t sLedOnTask;
TaskHandle_t sLedffTask;
TaskHandle_t sSerialTaskOne;

#if (QUEUE_TASK)

 TaskHandle_t   sQueue1, sQueue2, sQueue3;
 QueueHandle_t xQueue1;
 uint8_t auQueue8Data [10] = "0123456789";
 uint8_t u8QueueDataIndex = 0u;

#endif


void vApplicationIdleHook( void )
{
	/* enter sleep mode*/
	__WFI();	
}


BaseType_t FreeRtosTasks(void)
{
BaseType_t u32RetType = 1u; 	


#if DEFAULT_TASK
#if 0
	
	u32RetType =  xTaskCreate( led_on,"LED_ON", 40, 0u, 1u,&sLedOnTask );

    if(u32RetType == 1u)
	{
		u32RetType =  xTaskCreate( led_off,"LED_FF", 40, 0u, 1u,&sLedffTask );
	}
#endif
	if(u32RetType == 1)
	{
		u32RetType =  xTaskCreate( sserial_task_one,"SERIAL_TASK_1", 80, 0u, 2u,&sSerialTaskOne );
	}
	if(u32RetType == 1)
	{
		u32RetType =  xTaskCreate( sserial_task_two,"SERIAL_TASK_2", 80, 0u, 2u,&sSerialTaskOne );		
	}
	
#elif (QUEUE_TASK)



	xQueue1 = xQueueCreate( 10, sizeof( int8_t ) );


	u32RetType =  xTaskCreate( queue_task_one,"SEND_1_Q_1", 40, 0u, 1u,&sQueue1 );
	if(u32RetType == 1)
	{
	//	u32RetType =  xTaskCreate( queue_task_two,"SEND_2_Q_1", 80, 0u, 1u,&sQueue2 );
	}
	if(u32RetType == 1)
	{
		u32RetType =  xTaskCreate( queue_task_three,"RECEIVE_1_Q_1", 80, 0u, 1u,&sQueue3 );
	}

#endif

return u32RetType;
}

