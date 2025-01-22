/*
 * button.h
 *
 *  Created on: Oct 13, 2024
 *      Author: vinhd
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_
#include "main.h"
//end include



// Số lượng nút nhấn
#define NO_OF_BUTTONS 3

// Thời gian ngắt timer là 10ms, để đạt 2 giây, cần 200 lần ngắt
#define DURATION_FOR_AUTO_INCREASING 200

// Định nghĩa trạng thái nút nhấn
#define BUTTON_IS_PRESSED GPIO_PIN_RESET
#define BUTTON_IS_RELEASED GPIO_PIN_SET


enum ButtonState {BUTTON_RELEASED, BUTTON_PRESSED, BUTTON_PRESSED_MORE_THAN_2_SECOND};


int is_button_pressed(unsigned char index);
int is_button_pressed_2s(unsigned char index);
int is_button_released(int index);

void button_reading(void);
void fsm_for_input_processing(void) ;


void button_init();
void Mode_count_Buffer();
extern int mode;

#endif /* INC_BUTTON_H_ */
