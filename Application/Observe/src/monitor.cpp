#include "monitor.h"

Monitor::Monitor(float valueMin, float valueMax){
	inLimits[0] = valueMin;
	setValueMax(valueMax);
	tresDelays[0] = new CommonTimer(200);
	tresDelays[1] = new CommonTimer(200);
	tresDelays[2] = new CommonTimer(200);
	tresDelays[3] = new CommonTimer(200);
}
Monitor::~Monitor(){
	for(int i = 0; i < 4; i++){
		delete tresDelays[i];
	}
}
void Monitor::setValueMin(float limit){
	inLimits[0] = min(limit, inLimits[1]);
}
void Monitor::setValueMax(float limit){
	inLimits[1] = max(limit, inLimits[0]);
}
void Monitor::update1ms(){
	float range = getRange(inLimits);
	*tresDelays[0] = in * 100 / range <= tresholds[LL];
	*tresDelays[1] = in * 100 / range <= tresholds[HL];
	*tresDelays[2] = in * 100 / range >= tresholds[LH];
	*tresDelays[3] = in * 100 / range >= tresholds[HH];
	for(int i = 0; i < 4; i++){
		tresDelays[i]->update1ms();
	}
}
float Monitor::get(){
	return in;
}
void Monitor::set(float value){
	in = limit(value, inLimits[0], inLimits[1]);
}
void Monitor::setTreshold(TRES_TYPE tresType, uint16_t value){
	tresholds[tresType] = value;
}
void Monitor::setTresDelay(TRES_TYPE tresType, uint16_t del){
	tresDelays[tresType]->setPeriod(del);
}
bool Monitor::isHighAlarm(){
	return tresDelays[HH]->finished();
}
bool Monitor::isHighWarn(){
	return tresDelays[LH]->finished();
}
bool Monitor::isLowWarn(){
	return tresDelays[HL]->finished();
}
bool Monitor::isLowAlarm(){
	return tresDelays[LL]->finished();
}
Monitor& Monitor::operator=(float value){
	set(value);
	return *this;
}
float *const Monitor::getInRef(){
	return &in;
}