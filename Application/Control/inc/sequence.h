#ifndef SEQUENCE_H
#define SEQUENCE_H
#include "rf_impulse.h"

class Sequence: private RFimpulse{
	private:
		bool strt;
		bool lck;
		bool fin;
	public:
		Sequence();
		void reset();
		void start(bool value);
		void lock(bool value);
		void finish(bool value);
		bool started();
		bool locked();
		bool finished();
		bool finishedImpulse();
};

#endif //SEQUENCE_H