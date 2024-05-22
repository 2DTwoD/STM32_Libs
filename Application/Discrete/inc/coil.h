#ifndef COIL_H
#define COIL_H

#include "stm32f10x.h"
#include "interfaces.h"
#include "gpio_common.h"
#include "common.h"
#include "common_timer.h"
#include "on_delay.h"
#include "off_delay.h"
#include "pulse.h"


class ProgrammCoil: public ISwitch{
	private:
		bool out;
	public:
		virtual bool isActive() override;
		virtual void setValue(bool value);
		void set();
		void reset();
		void toggle();
		ProgrammCoil& operator=(bool value);
};

class Coil: public GPIOcommon, public ProgrammCoil {
  public:
		Coil(GPIO_TypeDef *gpio, uint8_t pin);
	
		bool isActive() override;
	
		void setValue(bool value) override;
	
		Coil& operator=(bool value);
};

class CoilOnDelay: private OnDelayCommon, public Coil, public IUpdated1ms {
  public:
		CoilOnDelay(GPIO_TypeDef *gpio, uint8_t pin, uint16_t delay);
	
		void update1ms() override;
	
		void setValue(bool value) override;
	
		CoilOnDelay& operator=(bool value);
};

class CoilOffDelay: private OffDelayCommon, public Coil, public IUpdated1ms {
  public:
		using Coil::set;
		using Coil::reset;
		CoilOffDelay(GPIO_TypeDef *gpio, uint8_t pin, uint16_t delay);
	
		void update1ms() override;
	
		void setValue(bool value) override;
	
		CoilOffDelay& operator=(bool value);
};

class CoilPulse: private PulseCommon, public Coil, public IUpdated1ms  {
  public:
		using Coil::set;
		using Coil::reset;
		CoilPulse(GPIO_TypeDef *gpio, uint8_t pin, uint16_t delay);
	
		void update1ms() override;
	
		void setValue(bool value) override;
	
		CoilPulse& operator=(bool value);
};
#endif //COIL_H