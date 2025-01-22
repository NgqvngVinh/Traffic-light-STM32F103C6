/*
 * led_states.c
 *
 *  Created on: Oct 23, 2024
 *      Author: vinhd
 */


#include "led_states.h"
#include "global.h"



void state_init(){
	HAL_GPIO_WritePin(LRx_GPIO_Port, LRx_Pin, 1);
	HAL_GPIO_WritePin(LGx_GPIO_Port, LGx_Pin, 1);
	HAL_GPIO_WritePin(LYx_GPIO_Port, LYx_Pin, 1);
}

void state_red(){
	HAL_GPIO_WritePin(LRx_GPIO_Port, LRx_Pin, 0);
	HAL_GPIO_WritePin(LGx_GPIO_Port, LGx_Pin, 1);
	HAL_GPIO_WritePin(LYx_GPIO_Port, LYx_Pin, 1);
}

void state_green(){
	HAL_GPIO_WritePin(LRx_GPIO_Port, LRx_Pin, 1);
	HAL_GPIO_WritePin(LGx_GPIO_Port, LGx_Pin, 0);
	HAL_GPIO_WritePin(LYx_GPIO_Port, LYx_Pin, 1);
}

void state_yellow(){
	HAL_GPIO_WritePin(LRx_GPIO_Port, LRx_Pin, 1);
	HAL_GPIO_WritePin(LGx_GPIO_Port, LGx_Pin, 1);
	HAL_GPIO_WritePin(LYx_GPIO_Port, LYx_Pin, 0);
}


void state_init1(){
	HAL_GPIO_WritePin(LRy_GPIO_Port, LRy_Pin, 1);
	HAL_GPIO_WritePin(LGy_GPIO_Port, LGy_Pin, 1);
	HAL_GPIO_WritePin(LYy_GPIO_Port, LYy_Pin, 1);
}


void state_red1(){
	HAL_GPIO_WritePin(LRy_GPIO_Port, LRy_Pin, 0);
	HAL_GPIO_WritePin(LGy_GPIO_Port, LGy_Pin, 1);
	HAL_GPIO_WritePin(LYy_GPIO_Port, LYy_Pin, 1);
}
void state_green1(){
	HAL_GPIO_WritePin(LRy_GPIO_Port, LRy_Pin, 1);
	HAL_GPIO_WritePin(LGy_GPIO_Port, LGy_Pin, 0);
	HAL_GPIO_WritePin(LYy_GPIO_Port, LYy_Pin, 1);
}
void state_yellow1(){
	HAL_GPIO_WritePin(LRy_GPIO_Port, LRy_Pin, 1);
	HAL_GPIO_WritePin(LGy_GPIO_Port, LGy_Pin, 1);
	HAL_GPIO_WritePin(LYy_GPIO_Port, LYy_Pin, 0);
}


void turn_on_traffic_led_x(){
	switch(status){  //tí chỉnh biến chỗ này
		case AUTO_RED:
			HAL_GPIO_WritePin(GPIOA, LRx_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, LYx_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, LGx_Pin, SET);
			break;
		case AUTO_YELLOW:
			HAL_GPIO_WritePin(GPIOA, LRx_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, LYx_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, LGx_Pin, SET);
			break;
		case AUTO_GREEN:
			HAL_GPIO_WritePin(GPIOA, LRx_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, LYx_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, LGx_Pin, RESET);
			break;
		default:
			break;
	}
}
void turn_on_traffic_led_y(){
	switch(status1){
		case AUTO_RED:
			HAL_GPIO_WritePin(GPIOA, LRy_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, LYy_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, LGy_Pin, SET);
			break;
		case AUTO_YELLOW:
			HAL_GPIO_WritePin(GPIOA, LRy_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, LYy_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, LGy_Pin, SET);
			break;
		case AUTO_GREEN:
			HAL_GPIO_WritePin(GPIOA, LRy_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, LYy_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, LGy_Pin, RESET);
			break;
		default:
			break;
	}
}

void blinkind_led_traffic_x(){
	switch(status){
		case AUTO_RED:
			HAL_GPIO_TogglePin(GPIOA, LRx_Pin);
			HAL_GPIO_WritePin(GPIOA, LYx_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, LGx_Pin, SET);
			break;
		case AUTO_YELLOW:
			HAL_GPIO_WritePin(GPIOA, LRx_Pin, SET);
			HAL_GPIO_TogglePin(GPIOA, LYx_Pin);
			HAL_GPIO_WritePin(GPIOA, LGx_Pin, SET);
			break;
		case AUTO_GREEN:
			HAL_GPIO_WritePin(GPIOA, LRx_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, LYx_Pin, SET);
			HAL_GPIO_TogglePin(GPIOA, LGx_Pin);
			break;
		default:
			break;
		}
}

void blinkind_led_traffic_y(){
	switch(status1){
			case AUTO_RED:
				HAL_GPIO_TogglePin(GPIOA, LRy_Pin);
				HAL_GPIO_WritePin(GPIOA, LYy_Pin, SET);
				HAL_GPIO_WritePin(GPIOA, LGy_Pin, SET);
			break;
			case AUTO_YELLOW:
				HAL_GPIO_WritePin(GPIOA, LRy_Pin, SET);
				HAL_GPIO_TogglePin(GPIOA, LYy_Pin);
				HAL_GPIO_WritePin(GPIOA, LGy_Pin, SET);
			break;
			case AUTO_GREEN:
				HAL_GPIO_WritePin(GPIOA, LRy_Pin, SET);
				HAL_GPIO_WritePin(GPIOA, LYy_Pin, SET);
				HAL_GPIO_TogglePin(GPIOA, LGy_Pin);
			break;
			default:
			break;
		}
}








