#include "LedTasks.h"
#include "task.h"


TaskHandle_t sLedOnTask;
TaskHandle_t sLedffTask;


BaseType_t FreeRtosTasks(void)
{
BaseType_t u32RetType; 	
	
	u32RetType =  xTaskCreate( led_on,"LED_ON", 40, 0u, 1u,&sLedOnTask );

    if(u32RetType == 1u)
	{
		u32RetType =  xTaskCreate( led_off,"LED_FF", 40, 0u, 1u,&sLedffTask );
	}
	

return u32RetType;
}