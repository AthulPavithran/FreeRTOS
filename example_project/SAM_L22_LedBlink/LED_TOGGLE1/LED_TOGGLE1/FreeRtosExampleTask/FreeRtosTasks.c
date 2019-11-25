#include "LedTasks.h"
#include "task.h"


TaskHandle_t sLedOnTask;

BaseType_t FreeRtosTasks(void)
{
BaseType_t u32RetType; 	
	
u32RetType =  xTaskCreate( led_on,"LED_ON", 10, 0u, 1u,&sLedOnTask );
 
 
}