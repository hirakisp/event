#include "event.h"
#include <stdint.h>

struct event_data {
	uint8_t count;
	uint8_t count_shadow;
	uint8_t data[8];
};

static struct event_data events[EV_MAX];

void event_push(uint8_t idx)
{
	if (idx < EV_MAX)
		events[idx].count++;
}

uint8_t event_probe(uint8_t idx)
{
	if (idx < EV_MAX) {
		if (events[idx].count != events[idx].count_shadow) {
			events[idx].count_shadow = events[idx].count;
			return 1;
		}
	}
	return 0;
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == TIM6)
    	event_push(EV_TICK_1MS);
}
