#ifndef _EVENT_H_
#define _EVENT_H_

#include <stdint.h>

enum events {
	EV_TICK_1MS = 0,
	EV_TICK_100MS,
	EV_WAKEUP,
	EV_MAX
};

void event_push(uint8_t idx);
uint8_t event_probe(uint8_t idx);

#endif
