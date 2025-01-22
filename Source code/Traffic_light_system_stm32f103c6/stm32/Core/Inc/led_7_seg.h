/*
 * leg_7_seg.h
 *
 *  Created on: Oct 24, 2024
 *      Author: vinhd
 */

#ifndef INC_LED_7_SEG_H_
#define INC_LED_7_SEG_H_

#include "global.h"
#include "main.h"
#include "fsm_automatic.h"
#include "fsm_manual.h"

void display7SEG(int num);
void onoff_gates_led(int num);




extern int mode;
extern int led_7_seg_buffer[4];
//void Mode_count();

void update_2_led_buffer_left(int number);
void update_2_led_buffer_right(int number);

void led_7_seg_run();
extern int index_led_7_seg;



#endif /* INC_LED_7_SEG_H_ */
