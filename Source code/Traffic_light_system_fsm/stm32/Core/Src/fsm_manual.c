/*
 * fsm_manual.c
 *
 *  Created on: Oct 27, 2024
 *      Author: vinhd
 */

#include "fsm_manual.h"
#include "global.h"
#include "led_states.h"
#include "button.h"
#include "main.h"
#include "led_7_seg.h"
#include "fsm_automatic.h"

extern int mode;

void fsm_manual_run(){
	switch(mode){
		case INIT_SYSTEM:
			  button_init();
			  status = INIT;
			  status1 = INIT1;
			  setTimer0(25);
			  setTimer6(50);
			  mode = NORMAL_MODE;

			break;
		case NORMAL_MODE:
				  update_2_led_7_seg_buffer_left(timer1_counter/100);
				  update_2_led_7_seg_buffer_right(timer2_counter/100);
				  fsm_automatic_run();
				  fsm_automatic_run1();


					if(is_button_pressed(0) == 1){
						clearTimer1();
						clearTimer2();
						status = AUTO_RED;
						status1 = AUTO_RED;
					    setTimer6(50);
					    buffer_duration_time = duration_time_of_AUTO_RED;
					    mode = MAN_RED_MODE;

					}

			break;
		case MAN_RED_MODE:
					update_2_led_7_seg_buffer_left(mode);
					update_2_led_7_seg_buffer_right(buffer_duration_time/100);

					if(timer6_flag == 1){
						blinkind_led_traffic_x();
						blinkind_led_traffic_y();
						setTimer6(50);
					}
					if(is_button_pressed(0) == 1){
						clearTimer6();
						status = AUTO_YELLOW;
						status1 = AUTO_YELLOW;
						setTimer6(50);
						buffer_duration_time = duration_time_of_AUTO_YELLOW;
						mode = MAN_YELLOW_MODE;
					}
					if(is_button_pressed(1) == 1){
						buffer_duration_time = (buffer_duration_time + 100) % 10000;

					}
					if(is_button_pressed(2) == 1){
						duration_time_of_AUTO_RED = buffer_duration_time;
					}

			break;
		case MAN_GREEN_MODE:
					update_2_led_7_seg_buffer_left(mode);
					update_2_led_7_seg_buffer_right(buffer_duration_time/100);
					if(timer6_flag == 1){
						blinkind_led_traffic_x();
						blinkind_led_traffic_y();
						setTimer6(50);
					}
					if(is_button_pressed(0) == 1){
						clearTimer6();
						status = INIT;
						status1 = INIT1;
						setTimer6(50);

						mode = NORMAL_MODE;
					}
					if(is_button_pressed(1) == 1){
						buffer_duration_time = (buffer_duration_time + 100) % 10000;

					}
					if(is_button_pressed(2) == 1){
						duration_time_of_AUTO_GREEN = buffer_duration_time;
						if(duration_time_of_AUTO_RED != duration_time_of_AUTO_GREEN + duration_time_of_AUTO_YELLOW){
							duration_time_of_AUTO_RED = duration_time_of_AUTO_GREEN + duration_time_of_AUTO_YELLOW;
						}
					}

			break;
		case MAN_YELLOW_MODE:
			update_2_led_7_seg_buffer_left(mode);
			update_2_led_7_seg_buffer_right(buffer_duration_time/100);
			if(timer6_flag == 1){
				blinkind_led_traffic_x();
				blinkind_led_traffic_y();
				setTimer6(50);
			}
			if(is_button_pressed(0) == 1){
				clearTimer6();
				status = AUTO_GREEN;
				status1 = AUTO_GREEN;
				setTimer6(50);
				buffer_duration_time = duration_time_of_AUTO_GREEN;
				mode = MAN_GREEN_MODE;
			}
			if(is_button_pressed(1) == 1){
				buffer_duration_time = (buffer_duration_time + 100) % 10000;

			}
			if(is_button_pressed(2) == 1){
				duration_time_of_AUTO_YELLOW = buffer_duration_time;
			}

			break;
		default:
			break;
	}
}

