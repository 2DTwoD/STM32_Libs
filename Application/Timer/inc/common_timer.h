#ifndef CUSTOM_TIMER_H
#define CUSTOM_TIMER_H
#include "stdint.h"
#include "interfaces.h"

class CommonTimer: public IUpdated1ms {
	protected:
		uint16_t period;
		uint16_t curTime;
		bool go;
		bool impulse;
	public:
		CommonTimer(uint16_t period);
		void update1ms() override;
		uint16_t getPeriod();
		void setPeriod(uint16_t value);
		uint16_t getCurrentTime();
		void setCurrentTime(uint16_t value);
		void start();
		void pause();
		void stop();
		void reset();
		void prepareAndStart();
		void finish();
		void setStart(bool value);
		CommonTimer& operator=(bool value);
		virtual bool started();
	  bool notStarted();
		bool finished();
		bool notFinished();
		bool finishedImpulse();
		bool inWork();
		bool isFree();
};

#endif //CUSTOM_TIMER_H