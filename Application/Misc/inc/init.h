#ifndef INIT_H
#define INIT_H
#include "stm32f10x.h"
#include "common.h"
#include "common_timer.h"

void commonInit();
void rccInit();
void tickInit();
void adcInit();
void pwmInit();

#endif //INIT_H