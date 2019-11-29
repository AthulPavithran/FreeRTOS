#include "LedTasks.h"
#include "task.h"







void led_on(void)
{
		TickType_t xLastWakeTime;
		xLastWakeTime = xTaskGetTickCount();
	while(1)
	{
		
		 port_pin_set_output_level(LED_0_PIN, true);
		 vTaskDelay( 500);
	//	 vTaskDelayUntil(xLastWakeTime, 500);
	}
	vTaskDelete("LED_ON");
	
}

/*periodic function*/
/* periodicity is 250 milli seconds*/
void led_off(void)
{
	TickType_t xLastWakeTime;
	xLastWakeTime = xTaskGetTickCount();
	while(1)
	{
		port_pin_set_output_level(LED_0_PIN, false);
	//	vTaskDelayUntil(xLastWakeTime, pdMS_TO_TICKS( 500 ));
	//vTaskDelayUntil(xLastWakeTime, 500);
	   	vTaskDelay( 500);

	}
	vTaskDelete("LED_OFF");
}



