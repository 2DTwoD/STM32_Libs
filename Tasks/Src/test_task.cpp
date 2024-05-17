#include "all_tasks.h"

extern volatile uint16_t adcValues[];
extern AnalogMonitor adcMonitor;
extern Scale<float, int16_t> scale;
extern MovAvg avg;
extern Ramp ramp;
extern Pulse pulse;
extern AnalogOut analogOut;
RFimpulse rise(FALL);
uint8_t step = 0;
Sequence seq(&step, 0);
bool strt;
bool rest;
bool reslt;
bool seq_start;
bool seq_lock;
bool seq_finish;

void testTask(void *pvParameters){
	int16_t tmp;
	while(1){
		adcMonitor = adcValues[0];
		
		avg = adcMonitor.get();
		
		scale = avg.get();
		
		ramp = scale.get();
		
		analogOut = avg.get();
		
		pulse = strt;
		rise = rest;
		if(rise.get()){
			pulse.reset();
		}
		reslt = pulse.get();
		//threePosReg = avg.get();
		seq.start(seq_start);
		seq.lock(seq_lock);
		seq.finish(seq_finish);
		if(seq.finishedImpulse()){
			int tmp = 0;
		}
		vTaskDelay(1);
	}
}