/*
 * led_states.h
 *
 *  Created on: Oct 23, 2024
 *      Author: vinhd
 */

#ifndef INC_LED_STATES_H_
#define INC_LED_STATES_H_

#include "global.h"
#include "main.h"

void state_init();
void state_red();
void state_green();
void state_yellow();

void state_red1();
void state_green1();
void state_yellow1();

void turn_on_traffic_led_x();
void turn_on_traffic_led_y();

void blinkind_led_traffic_x();
void blinkind_led_traffic_y();


#endif /* INC_LED_STATES_H_ */
