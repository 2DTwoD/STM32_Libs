#include "all_tasks.h"

extern Coil led;
extern SwitchDelay ledDelay;
extern SwitchDelay buttonDelay;
extern ProgrammCoil ledSwitch;
//extern AnalogMonitor adcMonitor;
extern AnalogOut analogOut;
extern Scale<float, uint16_t> scale;
extern volatile uint16_t adcValues[];
extern ThreePosReg threePosReg;
extern SimpleInputDelayed button;
Counter counter(RISE_FALL, 100);

void ledTask(void *pvParameters){
	
	while(1){
		//taskENTER_CRITICAL();
		/*if(ledDelay.finishedImpulse()){
			led = !led.isActive();
			ledDelay.reset();
		}*/

		//taskEXIT_CRITICAL();
		/*if(button.finishedImpulse()){
			led.toggle();
		}*/
		led = button.isActive();
		counter += button.isActive();
		vTaskDelay(1);
	}
}