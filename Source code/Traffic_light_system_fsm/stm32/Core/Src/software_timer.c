/*
 * software_timer.c
 *
 *  Created on: Oct 13, 2024
 *      Author: vinhd
 */


#include "software_timer.h"
#include "main.h"
#include "led_7_seg.h"


//timer0 -> led_7_seg
//timer1 -> đèn ngang
//timer2 -> đèn dọc
//timer3->Mode_count(test button0)
//timer4->(button1) 			*chưa dùng
//timer5->button2   			*chưa dùng
//timer6->blinky 4 led





int timer0_counter = 0, timer1_counter = 0, timer2_counter = 0, timer3_counter = 0, timer4_counter, timer5_counter, timer6_counter;
int timer0_flag = 0, timer1_flag = 0, timer2_flag = 0, timer3_flag = 0, timer4_flag = 0, timer5_flag = 0, timer6_flag = 0;
int TIMER_CYCLE = 1;


void setTimer0(int duration) {
    timer0_counter = duration / TIMER_CYCLE;
    timer0_flag = 0;
}
void setTimer1(int duration) {
    timer1_counter = duration / TIMER_CYCLE;
    timer1_flag = 0;
}
void setTimer2(int duration) {
    timer2_counter = duration / TIMER_CYCLE;
    timer2_flag = 0;
}
//void setTimer3(int duration) {
//    timer3_counter = duration / TIMER_CYCLE;
//    timer3_flag = 0;
//}
//void setTimer4(int duration){
//	timer4_counter = duration / TIMER_CYCLE;
//	timer4_flag = 0;
//}
//void setTimer5(int duration){
//	timer5_counter = duration / TIMER_CYCLE;
//	timer5_flag = 0;
//}
void setTimer6(int duration){
	timer6_counter = duration / TIMER_CYCLE;
	timer6_flag = 0;
}



//void clearTimer0(){
//	timer0_counter = 0;
//	timer0_flag = 0;
//}
void clearTimer1(){
	timer1_counter = 0;
	timer1_flag = 0;
}
void clearTimer2(){
	timer2_counter = 0;
	timer2_flag = 0;
}
//void clearTimer3(){
//	timer3_counter = 0;
//	timer3_flag = 0;
//}
//void clearTimer4(){
//	timer4_counter = 0;
//	timer4_flag = 0;
//}
//void clearTimer5(){
//	timer5_counter = 0;
//	timer5_flag = 0;
//}
void clearTimer6(){
	timer6_counter = 0;
	timer6_flag = 0;
}



void timer_run() {
    if (timer0_counter > 0) {
        timer0_counter--;
        if (timer0_counter == 0) timer0_flag = 1;
    }
    if (timer1_counter > 0) {
        timer1_counter--;
        if (timer1_counter == 0) timer1_flag = 1;
    }
    if (timer2_counter > 0) {
        timer2_counter--;
        if (timer2_counter == 0) timer2_flag = 1;
    }
//    if (timer3_counter > 0) {
//        timer3_counter--;
//        if (timer3_counter == 0){
//        	timer3_flag = 1;
//        }
//    }
//    if (timer4_counter > 0) {
//        timer4_counter--;
//        if (timer4_counter == 0){
//        	timer4_flag = 1;
//        }
//    }
//    if (timer5_counter > 0) {
//        timer5_counter--;
//        if (timer5_counter == 0){
//        	timer5_flag = 1;
//        }
//    }
    if (timer6_counter > 0) {
        timer6_counter--;
        if (timer6_counter == 0){
        	timer6_flag = 1;
        }
    }

}
