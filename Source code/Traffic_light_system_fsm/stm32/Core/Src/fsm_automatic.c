/*
 * fsm_automatic.c
 *
 *  Created on: Oct 23, 2024
 *      Author: vinhd
 */


#include "fsm_automatic.h"
#include "global.h"
#include "led_states.h"
#include "software_timer.h"
#include "main.h"
#include "fsm_manual.h"



void fsm_automatic_run(){
	switch(status){
		case INIT:
			//TODO
			state_init();
			status = AUTO_RED;
			setTimer1(duration_time_of_AUTO_RED);
			break;
		case AUTO_RED:
			//TODO
			state_red();
			if(timer1_flag == 1){
				status = AUTO_GREEN;
				setTimer1(duration_time_of_AUTO_GREEN);
			}

			break;
		case AUTO_GREEN:
			//TODO
			state_green();
			if(timer1_flag == 1){
				status = AUTO_YELLOW;
				setTimer1(duration_time_of_AUTO_YELLOW);
			}

			break;
		case AUTO_YELLOW:
			//TODO
			state_yellow();

			if(timer1_flag == 1){
				status = AUTO_RED;
				setTimer1(duration_time_of_AUTO_RED);
			}

			break;
		default:
			break;

	}
}

void fsm_automatic_run1(){
    switch(status1){
        case INIT1:
            //TODO
            state_init1();
            status1 = AUTO_GREEN;
            setTimer2(duration_time_of_AUTO_GREEN);
            break;
        case AUTO_RED:
            //TODO
            state_red1();
            if(timer2_flag == 1){
                status1 = AUTO_GREEN;
                setTimer2(duration_time_of_AUTO_GREEN);
            }
            break;
        case AUTO_GREEN:
            //TODO
            state_green1();

            if(timer2_flag == 1){
                status1 = AUTO_YELLOW;
                setTimer2(duration_time_of_AUTO_YELLOW);
            }
            break;
        case AUTO_YELLOW:
            //TODO
            state_yellow1();

            if(timer2_flag == 1){
                status1 = AUTO_RED;
                setTimer2(duration_time_of_AUTO_RED);
            }
            break;
        default:
            break;
    }
}





