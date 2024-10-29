/*
 * Led_states.c
 *
 *  Created on: Oct 9, 2024
 *      Author: vinhd
 */

#include "Led_states.h"



void state_init(){
			HAL_GPIO_WritePin(LR_GPIO_Port, LR_Pin, 1);
			HAL_GPIO_WritePin(LG_GPIO_Port, LG_Pin, 1);
			HAL_GPIO_WritePin(LY_GPIO_Port, LY_Pin, 1);
}

void state_red(){
	HAL_GPIO_WritePin(LR_GPIO_Port, LR_Pin, 0);
	HAL_GPIO_WritePin(LG_GPIO_Port, LG_Pin, 1);
	HAL_GPIO_WritePin(LY_GPIO_Port, LY_Pin, 1);
}

void state_green(){
	HAL_GPIO_WritePin(LR_GPIO_Port, LR_Pin, 1);
	HAL_GPIO_WritePin(LG_GPIO_Port, LG_Pin, 0);
	HAL_GPIO_WritePin(LY_GPIO_Port, LY_Pin, 1);
}

void state_yellow(){
	HAL_GPIO_WritePin(LR_GPIO_Port, LR_Pin, 1);
	HAL_GPIO_WritePin(LG_GPIO_Port, LG_Pin, 1);
	HAL_GPIO_WritePin(LY_GPIO_Port, LY_Pin, 0);
}

