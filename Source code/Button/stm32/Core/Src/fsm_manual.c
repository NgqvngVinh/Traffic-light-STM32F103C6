/*
 * fsm_manual.c
 *
 *  Created on: Oct 8, 2024
 *      Author: vinhd
 */


#include "fsm_manual.h"
#include "Led_states.h"

void fsm_manual_run(){
	switch(status){
	case MAN_RED:
		state_red();

		if(timer1_flag == 1){
			status = AUTO_RED;
			setTimer1(500);
		}
		if(isButton1Pressed() == 1){
			status = MAN_GREEN;
			setTimer1(1000);
		}
		break;
	case MAN_GREEN:
		state_green();

		if(timer1_flag == 1){
			status = AUTO_GREEN;
			setTimer1(500);
		}
		if(isButton1Pressed() == 1){
			status = MAN_YELLOW;
			setTimer1(1000);
		}
		break;
	case MAN_YELLOW:
		state_yellow();

		if(timer1_flag == 1){
			status = AUTO_RED;
			setTimer1(500);
		}
		if(isButton1Pressed() == 1){
			status = MAN_RED;
			setTimer1(1000);
		}
		break;
	}
}
