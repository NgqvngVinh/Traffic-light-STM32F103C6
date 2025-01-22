/*
 * fsm_automatic.c
 *
 *  Created on: Oct 7, 2024
 *      Author: vinhd
 */

#ifndef SRC_FSM_AUTOMATIC_C_
#define SRC_FSM_AUTOMATIC_C_
#include "fsm_automatic.h"
#include "Led_states.h"

void fsm_automatic_run(){
	switch(status){
	case INIT:
		//TODO
		state_init();
		status = AUTO_RED;
		setTimer1(500);
//		isButton1Pressed();
		break;
	case AUTO_RED:
		//TODO
		state_red();

		if(timer1_flag == 1){
			status = AUTO_GREEN;
			setTimer1(300);
		}
		if(isButton1Pressed() == 1){
			status = MAN_RED;
			setTimer1(1000);
		}
		break;
	case AUTO_GREEN:
		//TODO
		state_green();

		if(timer1_flag == 1){
			status = AUTO_YELLOW;
//			isButton1Pressed();
			setTimer1(200);
		}
		break;
	case AUTO_YELLOW:
		//TODO
		state_yellow();

		if(timer1_flag == 1){
			status = AUTO_RED;
//			isButton1Pressed();
			setTimer1(300);
		}
		break;
	default:
		break;

}
}

#endif /* SRC_FSM_AUTOMATIC_C_ */
