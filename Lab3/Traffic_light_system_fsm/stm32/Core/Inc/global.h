/*
 * global.h
 *
 *  Created on: Oct 23, 2024
 *      Author: vinhd
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include <led_7_seg.h>
#include "software_timer.h"
#include "button.h"
#include "main.h"
#include "fsm_automatic.h"

#define INIT_SYSTEM			0
#define NORMAL_MODE  		1
#define MAN_RED_MODE 		2
#define MAN_YELLOW_MODE 	3
#define MAN_GREEN_MODE 		4

#define AUTO_RED 	 		11
#define AUTO_GREEN 	 		12
#define AUTO_YELLOW  		13
#define INIT 		 		14
#define INIT1 		 		15

extern int status;
extern int status1;

extern int duration_time_of_AUTO_RED;
extern int duration_time_of_AUTO_YELLOW;
extern int duration_time_of_AUTO_GREEN;

extern int buffer_duration_time; //save time++ mode 2,3,4









#endif /* INC_GLOBAL_H_ */
