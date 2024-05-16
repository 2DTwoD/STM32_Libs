#include "all_tasks.h"

extern Coil led;
extern SimpleInputDelayed button;
extern Counter counter;

void ledTask(void *pvParameters){
	while(1){
		led = button.isActive();
		counter += button.isActive();
		vTaskDelay(1);
	}
}