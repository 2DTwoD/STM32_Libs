#include "coil.h"

//ProgrammCoil
bool ProgrammCoil::isActive(){
	return out;
}
void ProgrammCoil::setValue(bool value){
	out = value;
}
void ProgrammCoil::set(){
	setValue(true);
}
void ProgrammCoil::reset(){
	setValue(false);
}
void ProgrammCoil::toggle(){
	setValue(!isActive());
}
ProgrammCoil& ProgrammCoil::operator=(bool value){
	setValue(value);
	return *this;
}

//Coil
Coil::Coil(GPIO_TypeDef *gpio, uint8_t pin): GPIOcommon(gpio, pin) {
	if(pin < 8){
		setBitsInRegister(&gpio->CRL, 0x1111 << (4 * pin), 0b0001);
	} else {
		setBitsInRegister(&gpio->CRH, 0x1111 << (4 * pin - 32), 0b0001);
	}
}
bool Coil::isActive(){
	return (gpio->ODR & (1 << pin)) > 0;
}
void Coil::setValue(bool value){
	if(value){
		gpio->BSRR |= (1 << pin);
		return;
	}
	gpio->BRR |= (1 << pin);
}
Coil& Coil::operator=(bool value){
	setValue(value);
	return *this;
}

//CoilOnDelayed
CoilOnDelay::CoilOnDelay(GPIO_TypeDef *gpio, uint8_t pin, uint16_t delay): Coil(gpio, pin), OnDelayCommon(delay) {
}
void CoilOnDelay::update1ms() {
	OnDelayCommon::update();
	Coil::setValue(OnDelayCommon::get());
}
void CoilOnDelay::setValue(bool value){
	OnDelayCommon::set(value);
}
CoilOnDelay& CoilOnDelay::operator=(bool value){
	setValue(value);
	return *this;
}

//CoilOffDelayed
CoilOffDelay::CoilOffDelay(GPIO_TypeDef *gpio, uint8_t pin, uint16_t delay): Coil(gpio, pin), OffDelayCommon(delay) {
}
void CoilOffDelay::update1ms() {
	OffDelayCommon::update();
	Coil::setValue(OffDelayCommon::get());
}
void CoilOffDelay::setValue(bool value){
	OffDelayCommon::set(value);
}
CoilOffDelay& CoilOffDelay::operator=(bool value){
	setValue(value);
	return *this;
}

//CoilPulse
CoilPulse::CoilPulse(GPIO_TypeDef *gpio, uint8_t pin, uint16_t delay): Coil(gpio, pin), PulseCommon(delay) {
}
void CoilPulse::update1ms() {
	PulseCommon::update();
	Coil::setValue(PulseCommon::get());
}
void CoilPulse::setValue(bool value){
	PulseCommon::set(value);
}
CoilPulse& CoilPulse::operator=(bool value){
	setValue(value);
	return *this;
}