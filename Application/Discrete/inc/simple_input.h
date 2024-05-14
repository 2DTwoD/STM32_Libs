#ifndef SIMPLE_INPUT_H
#define SIMPLE_INPUT_H
#include "stm32f10x.h"
#include "common.h"
#include "interfaces.h"
#include "gpio_common.h"
#include "common_timer.h"

//SimpleInput
class SimpleInput: public GPIOcommon, public ISwitch{
	public:
		SimpleInput(GPIO_TypeDef *gpio, uint8_t pin);
	
		bool isActive() override;
};

//SimpleInputDelayed (implements IUpdated1ms)
class SimpleInputDelayed: public SimpleInput, public CommonTimer {
	public:
		SimpleInputDelayed(GPIO_TypeDef *gpio, uint8_t pin, uint16_t delay);
		void update1ms() override;
		bool isActive() override;
};

#endif //SIMPLE_INPUT_H