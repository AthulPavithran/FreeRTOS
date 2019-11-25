#include "LedTasks.h"







void led_on(void)
{
	while(1)
	{
		
		 port_pin_set_output_level(LED_0_PIN, true);
	}
	
}


void led_off(void)
{
	while(1)
	{
		port_pin_set_output_level(LED_0_PIN, false);
		
	}
	
}



