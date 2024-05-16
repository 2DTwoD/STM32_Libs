#include "sequence.h"

Sequence::Sequence(): RFimpulse(RISE){
}
void Sequence::reset(){
	strt = false;
	fin = false;
	RFimpulse::set(false);
}
void Sequence::start(bool value){
	if(value){
		strt = true;
	}
}
void Sequence::lock(bool value){
	lck = value;
}
void Sequence::finish(bool value){
	if(value){
		fin = true;
		RFimpulse::set(true);
	}
}

bool Sequence::started(){
	return strt && !lck;
}
bool Sequence::locked(){
	return lck;
}
bool Sequence::finished(){
	return fin;
}
bool Sequence::finishedImpulse(){
	return RFimpulse::get();
}
