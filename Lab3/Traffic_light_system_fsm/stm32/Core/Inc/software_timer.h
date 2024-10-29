/*
 * software_timer.h
 *
 *  Created on: Oct 13, 2024
 *      Author: vinhd
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer0_flag, timer1_flag, timer2_flag, timer3_flag, timer4_flag, timer5_flag, timer6_flag;
extern int timer0_counter, timer1_counter, timer2_counter, timer3_counter, timer4_counter, timer5_counter, timer6_counter;



void setTimer0(int duration);
void setTimer1(int duration);
void setTimer2(int duration);
void setTimer3(int duration);
void setTimer4(int duration);
void setTimer5(int duration);
void setTimer6(int duration);


void clearTimer0();
void clearTimer1();
void clearTimer2();
void clearTimer3();
void clearTimer4();
void clearTimer5();
void clearTimer6();

int get_time_of_counter0();
int get_time_of_counter1();
int get_time_of_counter2();
int get_time_of_counter3();
int get_time_of_counter4();
int get_time_of_counter5();
int get_time_of_counter6();

int is_timer0_timeout();
int is_timer1_timeout();
int is_timer2_timeout();
int is_timer3_timeout();
int is_timer4_timeout();
int is_timer5_timeout();
int is_timer6_timeout();

















#endif /* INC_SOFTWARE_TIMER_H_ */
