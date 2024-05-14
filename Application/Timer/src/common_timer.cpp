#include "common_timer.h"

//CommonDelay implementation
CommonTimer::CommonTimer(uint16_t period){
	this->period = period;
}
void CommonTimer::update1ms(){
	if(started()){
		if(finished()) return;
		curTime++;
		return;
	}
	impulse = false;
	curTime = 0;
}
uint16_t CommonTimer::getPeriod(){
	return period;
}
void CommonTimer::setPeriod(uint16_t value){
	period = value;
}
uint16_t CommonTimer::getCurrentTime(){
	return curTime;
}
void CommonTimer::setCurrentTime(uint16_t value){
	curTime = value;
}
void CommonTimer::start(){
	go = true;
}
void CommonTimer::pause(){
	go = false;
}
void CommonTimer::stop(){
	pause();
	reset();
}
void CommonTimer::reset(){
	curTime = 0;
	impulse = false;
}
void CommonTimer::prepareAndStart(){
	stop();
	start();
}
void CommonTimer::finish(){
	start();
	curTime = period;
}
void CommonTimer::setStart(bool value){
	if(value){
		start();
	} else {
		stop();
	}
}
CommonTimer& CommonTimer::operator=(bool value){
	setStart(value);
	return *this;
}
bool CommonTimer::started(){
	return go;
}
bool CommonTimer::notStarted(){
	return !go;
}
bool CommonTimer::finished(){
 return curTime >= period;
}
bool CommonTimer::notFinished(){
 return curTime < period;
}
bool CommonTimer::finishedImpulse(){
	bool result = finished() && !impulse;
	if (finished()) impulse = true;
	return result;
}
bool CommonTimer::inWork(){
	return started() && notFinished();
}
bool CommonTimer::isFree(){
	return notStarted() || finished();
}
