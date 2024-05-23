#ifndef ALL_TASKS_H
#define ALL_TASKS_H
#include "stdint.h"

#include "FreeRTOS.h"
#include "task.h"

#include "coil.h"
#include "coil_with_timer.h"
#include "simple_input.h"
#include "counter.h"
#include "pid.h"
#include "analog_monitor.h"
#include "scale.h"
#include "moving_avg.h"
#include "ramp.h"
#include "pulse.h"
#include "analog_out.h"
#include "rf_impulse.h"
#include "sequence.h"

void ledTask(void *pvParameters);
void pidTask(void *pvParameters);
void testTask(void *pvParameters);

#endif //ALL_TASKS_H