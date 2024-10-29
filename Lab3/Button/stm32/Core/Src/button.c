/*
 * button.c
 *
 *  Created on: Oct 7, 2024
 *      Author: vinhd
 */

#ifndef SRC_BUTTON_C_
#define SRC_BUTTON_C_
#include "button.h"

int button1_flag = 0;

int KeyReg0 = NORMAL_STATE;
int KeyReg1 = NORMAL_STATE;

int KeyReg2 = NORMAL_STATE; //State hien tai
int KeyReg3 = NORMAL_STATE; //State da xu ly tu KeyReg2
int TimerForKeyPress = 200;



int isButton1Pressed(){
	if(button1_flag == 1){
		button1_flag = 0;
		return 1;
	}
	else
		return 0;
}


void subKeyProcess(){
	button1_flag = 1;
}


void getKeyInput(){
	KeyReg0 = KeyReg1;
	KeyReg1 = KeyReg2;
	KeyReg2 = HAL_GPIO_ReadPin(Button1_GPIO_Port, Button1_Pin);
	if( (KeyReg0 == KeyReg1) && (KeyReg1 == KeyReg2)){
		if(KeyReg3 != KeyReg2){
			KeyReg3 = KeyReg2;
			if(KeyReg2 == PRESSED_STATE){
				//TODO
				subKeyProcess();
				TimerForKeyPress = 200;
			}
		}
		else{
			TimerForKeyPress--;
			if(TimerForKeyPress == 0){
				//TODO
				KeyReg3 = NORMAL_STATE;
			}
		}
	}
}


#endif /* SRC_BUTTON_C_ */
