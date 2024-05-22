#include "all_tasks.h"

extern CoilOffDelay led;
extern SimpleInputDelayed button;
extern Counter counter;

void ledTask(void *pvParameters){
	while(1){
		led = button.isActive();
		//counter += button.isActive();
		vTaskDelay(1);
	}
}