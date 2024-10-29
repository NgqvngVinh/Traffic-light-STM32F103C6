/*
 * button.c
 *
 *  Created on: Oct 13, 2024
 *      Author: vinhd
 */


#include <led_7_seg.h>
#include "button.h"


static GPIO_TypeDef* buttonPort[NO_OF_BUTTONS] = {BUTTON1_GPIO_Port, BUTTON2_GPIO_Port, BUTTON3_GPIO_Port}; //lưu trữ cổng
static uint16_t buttonPin[NO_OF_BUTTONS] = {BUTTON1_Pin, BUTTON2_Pin, BUTTON3_Pin};							//lưu trữ chân


// Bộ đệm cho việc chống dội
static GPIO_PinState debounceButtonBuffer0[NO_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer1[NO_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer2[NO_OF_BUTTONS];
static GPIO_PinState buttonBuffer[NO_OF_BUTTONS]; // Bộ đệm lưu trạng thái nút sau khi chống dội


//flag
static uint8_t flagForButtonPress[NO_OF_BUTTONS]; // Cờ cho việc nhấn nút hơn 2 giây
static uint8_t flagForButtonPress_2s[NO_OF_BUTTONS]; // Cờ cho việc nhấn nút hơn 2 giây


//counter
static uint16_t counterForButtonPress_2s[NO_OF_BUTTONS] = {0};// Bộ đếm thời gian nhấn nút
//int time_for_button_press = 200;


//vari
enum ButtonState buttonState[NO_OF_BUTTONS];
extern int mode;





void button_init(){
    for(int i = 0; i < NO_OF_BUTTONS; i++){
        buttonState[i] = BUTTON_RELEASED;
        flagForButtonPress[i] = 0;
        flagForButtonPress_2s[i] = 0;
        counterForButtonPress_2s[i] = 0;
        buttonBuffer[i] = BUTTON_IS_RELEASED;
        debounceButtonBuffer0[i] = BUTTON_IS_RELEASED;
        debounceButtonBuffer1[i] = BUTTON_IS_RELEASED;
        debounceButtonBuffer2[i] = BUTTON_IS_RELEASED;
    }
}




//function
int is_button_pressed(uint8_t index){
	if(index >= NO_OF_BUTTONS) return 0;
	if(flagForButtonPress[index]){
		flagForButtonPress[index] = 0;
		return 1;
	}
	return 0;
}


//int is_button_pressed_2s(uint8_t index){
//	if(index >= NO_OF_BUTTONS) return 0;
//		if(flagForButtonPress_2s[index]){
//			flagForButtonPress_2s[index] = 0;
//			return 1;
//		}
//		return 0;
//}
//int is_button_released(int index){
//	if(buttonBuffer[index] == BUTTON_IS_RELEASED) return 1;
//	return 0;
//}
//int is_button_held(uint8_t index){
//    if(index >= NO_OF_BUTTONS) return 0;
//    return (buttonBuffer[index] == BUTTON_IS_PRESSED);
//}

void button_reading(void){
    for(uint8_t i = 0; i < NO_OF_BUTTONS; i++) {
        debounceButtonBuffer0[i] = debounceButtonBuffer1[i];
        debounceButtonBuffer1[i] = debounceButtonBuffer2[i];
        debounceButtonBuffer2[i] = HAL_GPIO_ReadPin(buttonPort[i], buttonPin[i]);

        if(debounceButtonBuffer0[i] == debounceButtonBuffer1[i] && debounceButtonBuffer1[i] == debounceButtonBuffer2[i]){
            // Trạng thái nút nhấn đã ổn định
            if(buttonBuffer[i] != debounceButtonBuffer2[i]){
                // Trạng thái nút nhấn đã thay đổi
                buttonBuffer[i] = debounceButtonBuffer2[i];

                if(debounceButtonBuffer2[i] == BUTTON_IS_PRESSED){
                    // Nút nhấn chuyển từ thả sang nhấn
                    flagForButtonPress[i] = 1;
                    counterForButtonPress_2s[i] = DURATION_FOR_AUTO_INCREASING; // Đặt bộ đếm
                } else {
                    // Nút nhấn chuyển từ nhấn sang thả
                    counterForButtonPress_2s[i] = 0;
                    flagForButtonPress[i] = 0;
                    flagForButtonPress_2s[i] = 0;
                }
            }
//            } else {
//                // Trạng thái nút nhấn không thay đổi
//                if(debounceButtonBuffer2[i] == BUTTON_IS_PRESSED){
//                    // Nút nhấn đang được giữ
//                    if(counterForButtonPress_2s[i] > 0){
//                        counterForButtonPress_2s[i]--;
//                        if(counterForButtonPress_2s[i] == 0){
//                            // Đặt cờ khi nút được nhấn giữ hơn 2 giây
//                            flagForButtonPress_2s[i] = 1;
//                        }
//                    }
//                }
//            }
				else if(debounceButtonBuffer2[i] == BUTTON_IS_PRESSED && counterForButtonPress_2s[i] > 0){
								counterForButtonPress_2s[i]--;
								if(counterForButtonPress_2s[i] == 0){
//									flagForButtonPress_2s[i] = 1;
									flagForButtonPress[i] = 1;
									counterForButtonPress_2s[i] = DURATION_FOR_AUTO_INCREASING;

								}
							}
        }
    }
}



//buttonState
//void fsm_for_input_processing(void){
//    for(int i = 0; i < NO_OF_BUTTONS; i++){
//        switch(buttonState[i]){
//            case BUTTON_RELEASED:
//                if (is_button_pressed(i)){
//                    buttonState[i] = BUTTON_PRESSED;
//                    // Thực hiện hành động khi nút được nhấn nhanh
//                    //TODO từ thả->giữ
//                	HAL_GPIO_TogglePin(D13_GPIO_Port,D13_Pin);
//
//
//                }
//                break;
//            case BUTTON_PRESSED:
//                if (!is_button_held(i)){
//                    buttonState[i] = BUTTON_RELEASED;
//
//                } else {
//                    if (is_button_pressed_2s(i)){
//                        buttonState[i] = BUTTON_PRESSED_MORE_THAN_2_SECOND;
//
//                    }
//                }
//
//                break;
//            case BUTTON_PRESSED_MORE_THAN_2_SECOND:
//            	//TODO Nhấn giữ
//            	HAL_GPIO_TogglePin(D13_GPIO_Port,D13_Pin);
//                if (!is_button_held(i)){
//                    buttonState[i] = BUTTON_RELEASED;
//                    //TODO từ giữ->thả
//                	HAL_GPIO_TogglePin(D13_GPIO_Port,D13_Pin);
//                }
//                break;
//        }
//    }
//}


//void fsm_for_input_processing(void){
//    for(int i = 0; i < NO_OF_BUTTONS; i++){
//        switch(buttonState[i]){
//            case BUTTON_RELEASED:
//                if (is_button_pressed(i)){
//                    buttonState[i] = BUTTON_PRESSED;
//                    // Thực hiện hành động khi nút được nhấn nhanh
//                    //TODO từ thả->giữ
//                	HAL_GPIO_TogglePin(D13_GPIO_Port,D13_Pin);
//
//
//                }
//                break;
//            case BUTTON_PRESSED:
//            	//!is_button_pressed
//                if (!is_button_held(i)){
//                    buttonState[i] = BUTTON_RELEASED;
//
//
//                if (is_button_pressed_2s(i)){
//                        buttonState[i] = BUTTON_PRESSED_MORE_THAN_2_SECOND;
//                    }
//
//
//                break;
//            case BUTTON_PRESSED_MORE_THAN_2_SECOND:
//            	//TODO Nhấn giữ
//            	HAL_GPIO_TogglePin(D13_GPIO_Port,D13_Pin);
//
//
//                if (buttonBuffer[i] == BUTTON_IS_RELEASED ){
//                    buttonState[i] = BUTTON_RELEASED;
//                    //TODO từ giữ->thả
//                	HAL_GPIO_TogglePin(D13_GPIO_Port,D13_Pin);
//                }
//                break;
//        }
//    }
//}


//void Mode_count_Buffer(void){
//	switch(buttonState[0]){
//	case BUTTON_RELEASED:
//		//TODO thả -> nhấn
//		if(is_button_pressed(0) == 1){
//			mode++;
//			if(mode > 4){
//				mode = 1;
//			}
//	        update_2_led_buffer_left(mode); // Cập nhật giá trị LED dựa trên mode
//
//			buttonState[0] = BUTTON_PRESSED;
//
//		}
//		break;
//
//	case BUTTON_PRESSED:
//		if(!is_button_held(0)){
//			buttonState[0] = BUTTON_RELEASED;
//		}
//
//		if(is_button_pressed_2s(0) == 1){
//			buttonState[0] = BUTTON_PRESSED_MORE_THAN_2_SECOND;
//		}
//		break;
//
//	case BUTTON_PRESSED_MORE_THAN_2_SECOND:
//		//TODO đang giữ
//		if(is_button_pressed_2s(0) == 1){
//			mode++;
//			if(mode > 4) mode = 0;
//		}
//        update_2_led_buffer_left(mode); // Cập nhật giá trị LED dựa trên mode
//
//
//        if (!is_button_held(0)){
//            buttonState[0] = BUTTON_RELEASED;
//            //TODO giữ -> thả
//        }
//        break;
//	}
//}







