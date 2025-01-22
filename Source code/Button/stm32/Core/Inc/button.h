/*
 * button.h
 *
 *  Created on: Oct 7, 2024
 *      Author: vinhd
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"
#define NORMAL_STATE 1   //GPIO set
#define PRESSED_STATE 0  //Reset

//extern int button1_flag;


int isButton1Pressed();
void getKeyInput();

#endif /* INC_BUTTON_H_ */
