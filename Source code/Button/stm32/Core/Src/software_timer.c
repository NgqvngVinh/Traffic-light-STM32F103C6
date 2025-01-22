/*
 * software_timer.c
 *
 *  Created on: Oct 7, 2024
 *      Author: vinhd
 */

#ifndef SRC_SOFTWARE_TIMER_C_
#define SRC_SOFTWARE_TIMER_C_
#include "software_timer.h"

int Timer1 = 0;
int timer1_flag = 0;
void setTimer1(int duration){
	Timer1 = duration;
	timer1_flag = 0;
}
void TimerRun(){
	if(Timer1 > 0){
		Timer1--;
		if(Timer1 <=0){
			timer1_flag = 1;
		}

	}
}

#endif /* SRC_SOFTWARE_TIMER_C_ */
