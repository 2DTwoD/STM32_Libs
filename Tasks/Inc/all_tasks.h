#ifndef ALL_TASKS_H
#define ALL_TASKS_H
#include "stdint.h"

#include "FreeRTOS.h"
#include "task.h"

#include "coil.h"
#include "common_timer.h"
#include "simple_input.h"
#include "analog_monitor.h"
#include "analog_out.h"
#include "pid.h"
#include "scale.h"
#include "moving_avg.h"
#include "two_pos.h"
#include "three_pos.h"
#include "mux.h"
#include "switch_delay.h"
#include "on_delay.h"
#include "off_delay.h"
#include "pulse.h"
#include "rf_impulse.h"
#include "counter.h"

void ledTask(void *pvParameters);
void pidTask(void *pvParameters);
void testTask(void *pvParameters);

#endif //ALL_TASKS_H