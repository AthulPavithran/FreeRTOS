#include "LedTasks.h"
#include "SerialPortTask.h"
#include "task.h"


TaskHandle_t sLedOnTask;
TaskHandle_t sLedffTask;
TaskHandle_t sSerialTaskOne;


void vApplicationIdleHook( void )
{
	/* enter sleep mode*/
	__WFI();	
}


BaseType_t FreeRtosTasks(void)
{
BaseType_t u32RetType; 	
	
	u32RetType =  xTaskCreate( led_on,"LED_ON", 40, 0u, 1u,&sLedOnTask );

    if(u32RetType == 1u)
	{
		u32RetType =  xTaskCreate( led_off,"LED_FF", 40, 0u, 1u,&sLedffTask );
	}
	if(u32RetType == 1)
	{
		u32RetType =  xTaskCreate( sserial_task_one,"SERIAL_TASK_1", 80, 0u, 1u,&sSerialTaskOne );
	}

return u32RetType;
}

