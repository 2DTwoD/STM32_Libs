#include "all_tasks.h"

extern AnalogMonitor adcMonitor;
extern Scale<float, int16_t> scale;
extern volatile uint16_t adcValues[];
extern Ramp ramp;
extern AnalogOut analogOut;
extern MovAvg avg;
extern TwoPosTim twoPos;
extern ThreePosReg threePosReg;
extern OnDelay onDelay;
extern OffDelay offDelay;
extern Pulse pulse;
bool strt;
bool rest;
bool reslt;
RFimpulse rise(FALL);

void testTask(void *pvParameters){
	int16_t tmp;
	while(1){
		adcMonitor = adcValues[0];
		
		avg = adcMonitor.get();
		
		scale = avg.get();
		
		ramp = scale.get();
		
		analogOut = avg.get();
		
		twoPos = avg.get();
		
		pulse = strt;
		rise = rest;
		if(rise.get()){
			pulse.reset();
		}
		reslt = pulse.get();
		//threePosReg = avg.get();
		vTaskDelay(1);
	}
}