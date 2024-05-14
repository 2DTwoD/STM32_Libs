#ifndef MONITOR_H
#define MONITOR_H

#include "stdint.h"
#include "interfaces.h"
#include "common_timer.h"
#include "common.h"

enum TRES_TYPE {
	LL = 0, 
	HL, 
	LH, 
	HH	
};

class Monitor: public IUpdated1ms{
	private:
		float in;
		float inLimits[2]{0.0f, 100.0f};
		float tresholds[4]{5.0f, 10.0f, 90.0f, 95.0f};
		CommonTimer* tresDelays[4];
		void setValueMax(float limit);
		void setValueMin(float limit);
	public:
		Monitor(float valueMin, float valueMax);
		~Monitor();
		void update1ms() override;
		void set(float value);
		float get();
		void setTreshold(TRES_TYPE tresType, uint16_t value);
		void setTresDelay(TRES_TYPE tresType, uint16_t del);
		bool isHighAlarm();
		bool isHighWarn();
		bool isLowWarn();
		bool isLowAlarm();
		Monitor& operator=(float value);
		float *const getInRef();
};

#endif //MONITOR_H