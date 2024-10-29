/*
 * led_7_seg.c
 *
 *  Created on: Oct 24, 2024
 *      Author: vinhd
 */

#include <led_7_seg.h>
#include "software_timer.h"
#include "global.h"
#include "main.h"
#include "fsm_manual.h"


//variables
//int num = 0;
int led_7_seg_buffer[4] = {0};
int index_led_7_seg = 0;
//int count = 0;



//functions
void display7SEG(int num) {
      switch(num) {
          case 0:
              //printf("Segments: a, b, c, d, e, f\n");
        	  HAL_GPIO_WritePin(GPIOB,SEG0_Pin,GPIO_PIN_RESET);
        	  HAL_GPIO_WritePin(GPIOB,SEG1_Pin,GPIO_PIN_RESET);
        	  HAL_GPIO_WritePin(GPIOB,SEG2_Pin,GPIO_PIN_RESET);
        	  HAL_GPIO_WritePin(GPIOB,SEG3_Pin,GPIO_PIN_RESET);
        	  HAL_GPIO_WritePin(GPIOB,SEG4_Pin,GPIO_PIN_RESET);
        	  HAL_GPIO_WritePin(GPIOB,SEG5_Pin,GPIO_PIN_RESET);
        	  HAL_GPIO_WritePin(GPIOB,SEG6_Pin,GPIO_PIN_SET);
              break;
          case 1:
//              printf("Segments: b, c\n");
        	  HAL_GPIO_WritePin(GPIOB,SEG0_Pin,GPIO_PIN_SET);
        	  HAL_GPIO_WritePin(GPIOB,SEG1_Pin,GPIO_PIN_RESET);
        	  HAL_GPIO_WritePin(GPIOB,SEG2_Pin,GPIO_PIN_RESET);
        	  HAL_GPIO_WritePin(GPIOB,SEG3_Pin,GPIO_PIN_SET);
        	  HAL_GPIO_WritePin(GPIOB,SEG4_Pin,GPIO_PIN_SET);
        	  HAL_GPIO_WritePin(GPIOB,SEG5_Pin,GPIO_PIN_SET);
        	  HAL_GPIO_WritePin(GPIOB,SEG6_Pin,GPIO_PIN_SET);
              break;
          case 2:
//              printf("Segments: a, b, d, e, g\n");
        	  HAL_GPIO_WritePin(GPIOB,SEG0_Pin,GPIO_PIN_RESET);
        	  HAL_GPIO_WritePin(GPIOB,SEG1_Pin,GPIO_PIN_RESET);
        	  HAL_GPIO_WritePin(GPIOB,SEG2_Pin,GPIO_PIN_SET);
        	  HAL_GPIO_WritePin(GPIOB,SEG3_Pin,GPIO_PIN_RESET);
        	  HAL_GPIO_WritePin(GPIOB,SEG4_Pin,GPIO_PIN_RESET);
        	  HAL_GPIO_WritePin(GPIOB,SEG5_Pin,GPIO_PIN_SET);
        	  HAL_GPIO_WritePin(GPIOB,SEG6_Pin,GPIO_PIN_RESET);
              break;
          case 3:
//              printf("Segments: a, b, c, d, g\n");
        	  HAL_GPIO_WritePin(GPIOB,SEG0_Pin,GPIO_PIN_RESET);
        	  HAL_GPIO_WritePin(GPIOB,SEG1_Pin,GPIO_PIN_RESET);
        	  HAL_GPIO_WritePin(GPIOB,SEG2_Pin,GPIO_PIN_RESET);
        	  HAL_GPIO_WritePin(GPIOB,SEG3_Pin,GPIO_PIN_RESET);
        	  HAL_GPIO_WritePin(GPIOB,SEG4_Pin,GPIO_PIN_SET);
        	  HAL_GPIO_WritePin(GPIOB,SEG5_Pin,GPIO_PIN_SET);
        	  HAL_GPIO_WritePin(GPIOB,SEG6_Pin,GPIO_PIN_RESET);
              break;
          case 4:
//              printf("Segments: b, c, f, g\n");
        	  HAL_GPIO_WritePin(GPIOB,SEG0_Pin,GPIO_PIN_SET);
        	  HAL_GPIO_WritePin(GPIOB,SEG1_Pin,GPIO_PIN_RESET);
        	  HAL_GPIO_WritePin(GPIOB,SEG2_Pin,GPIO_PIN_RESET);
        	  HAL_GPIO_WritePin(GPIOB,SEG3_Pin,GPIO_PIN_SET);
        	  HAL_GPIO_WritePin(GPIOB,SEG4_Pin,GPIO_PIN_SET);
        	  HAL_GPIO_WritePin(GPIOB,SEG5_Pin,GPIO_PIN_RESET);
        	  HAL_GPIO_WritePin(GPIOB,SEG6_Pin,GPIO_PIN_RESET);
              break;
          case 5:
//              printf("Segments: a, c, d, f, g\n");
        	  HAL_GPIO_WritePin(GPIOB,SEG0_Pin,GPIO_PIN_RESET);
        	  HAL_GPIO_WritePin(GPIOB,SEG1_Pin,GPIO_PIN_SET);
        	  HAL_GPIO_WritePin(GPIOB,SEG2_Pin,GPIO_PIN_RESET);
        	  HAL_GPIO_WritePin(GPIOB,SEG3_Pin,GPIO_PIN_RESET);
        	  HAL_GPIO_WritePin(GPIOB,SEG4_Pin,GPIO_PIN_SET);
        	  HAL_GPIO_WritePin(GPIOB,SEG5_Pin,GPIO_PIN_RESET);
        	  HAL_GPIO_WritePin(GPIOB,SEG6_Pin,GPIO_PIN_RESET);
              break;
          case 6:
//              printf("Segments: a, c, d, e, f, g\n");
        	  HAL_GPIO_WritePin(GPIOB,SEG0_Pin,GPIO_PIN_RESET);
        	  HAL_GPIO_WritePin(SEG1_GPIO_Port,SEG1_Pin,GPIO_PIN_SET);
        	  HAL_GPIO_WritePin(SEG2_GPIO_Port,SEG2_Pin,GPIO_PIN_RESET);
        	  HAL_GPIO_WritePin(SEG3_GPIO_Port,SEG3_Pin,GPIO_PIN_RESET);
        	  HAL_GPIO_WritePin(SEG4_GPIO_Port,SEG4_Pin,GPIO_PIN_RESET);
        	  HAL_GPIO_WritePin(SEG5_GPIO_Port,SEG5_Pin,GPIO_PIN_RESET);
        	  HAL_GPIO_WritePin(SEG6_GPIO_Port,SEG6_Pin,GPIO_PIN_RESET);
              break;
          case 7:
//              printf("Segments: a, b, c\n");
        	  HAL_GPIO_WritePin(GPIOB,SEG0_Pin,GPIO_PIN_RESET);
        	  HAL_GPIO_WritePin(GPIOB,SEG1_Pin,GPIO_PIN_RESET);
        	  HAL_GPIO_WritePin(GPIOB,SEG2_Pin,GPIO_PIN_RESET);
        	  HAL_GPIO_WritePin(GPIOB,SEG3_Pin,GPIO_PIN_SET);
        	  HAL_GPIO_WritePin(GPIOB,SEG4_Pin,GPIO_PIN_SET);
        	  HAL_GPIO_WritePin(GPIOB,SEG5_Pin,GPIO_PIN_SET);
        	  HAL_GPIO_WritePin(GPIOB,SEG6_Pin,GPIO_PIN_SET);
              break;
          case 8:
//              printf("Segments: a, b, c, d, e, f, g\n");
        	  HAL_GPIO_WritePin(GPIOB,SEG0_Pin,GPIO_PIN_RESET);
        	  HAL_GPIO_WritePin(GPIOB,SEG1_Pin,GPIO_PIN_RESET);
        	  HAL_GPIO_WritePin(GPIOB,SEG2_Pin,GPIO_PIN_RESET);
        	  HAL_GPIO_WritePin(GPIOB,SEG3_Pin,GPIO_PIN_RESET);
        	  HAL_GPIO_WritePin(GPIOB,SEG4_Pin,GPIO_PIN_RESET);
        	  HAL_GPIO_WritePin(GPIOB,SEG5_Pin,GPIO_PIN_RESET);
        	  HAL_GPIO_WritePin(GPIOB,SEG6_Pin,GPIO_PIN_RESET);
              break;
          case 9:
//              printf("Segments: a, b, c, d, f, g\n");
        	  HAL_GPIO_WritePin(GPIOB,SEG0_Pin,GPIO_PIN_RESET);
        	  HAL_GPIO_WritePin(GPIOB,SEG1_Pin,GPIO_PIN_RESET);
        	  HAL_GPIO_WritePin(GPIOB,SEG2_Pin,GPIO_PIN_RESET);
        	  HAL_GPIO_WritePin(GPIOB,SEG3_Pin,GPIO_PIN_RESET);
        	  HAL_GPIO_WritePin(GPIOB,SEG4_Pin,GPIO_PIN_SET);
        	  HAL_GPIO_WritePin(GPIOB,SEG5_Pin,GPIO_PIN_RESET);
        	  HAL_GPIO_WritePin(GPIOB,SEG6_Pin,GPIO_PIN_RESET);
              break;
          default:
        	    HAL_GPIO_WritePin(GPIOB,SEG0_Pin,GPIO_PIN_SET);
        	    HAL_GPIO_WritePin(GPIOB,SEG1_Pin,GPIO_PIN_SET);
        	    HAL_GPIO_WritePin(GPIOB,SEG2_Pin,GPIO_PIN_SET);
        	    HAL_GPIO_WritePin(GPIOB,SEG3_Pin,GPIO_PIN_SET);
        	    HAL_GPIO_WritePin(GPIOB,SEG4_Pin,GPIO_PIN_SET);
        	    HAL_GPIO_WritePin(GPIOB,SEG5_Pin,GPIO_PIN_SET);
        	    HAL_GPIO_WritePin(GPIOB,SEG6_Pin,GPIO_PIN_SET);
        	  break;
      }
  }




void onoff_gates_led(int index){
	switch(index){
	case 0:
		HAL_GPIO_WritePin( GPIOA, EN0_Pin, RESET);
		HAL_GPIO_WritePin( GPIOA, EN1_Pin, SET);
		HAL_GPIO_WritePin( GPIOA, EN2_Pin, SET);
		HAL_GPIO_WritePin( GPIOA, EN3_Pin, SET);
		break;
	case 1:
		HAL_GPIO_WritePin( GPIOA, EN0_Pin, SET);
		HAL_GPIO_WritePin( GPIOA, EN1_Pin, RESET);
		HAL_GPIO_WritePin( GPIOA, EN2_Pin, SET);
		HAL_GPIO_WritePin( GPIOA, EN3_Pin, SET);
		break;
	case 2:
		HAL_GPIO_WritePin( GPIOA, EN0_Pin, SET);
		HAL_GPIO_WritePin( GPIOA, EN1_Pin, SET);
		HAL_GPIO_WritePin( GPIOA, EN2_Pin, RESET);
		HAL_GPIO_WritePin( GPIOA, EN3_Pin, SET);
		break;
	case 3:
		HAL_GPIO_WritePin( GPIOA, EN0_Pin, SET);
		HAL_GPIO_WritePin( GPIOA, EN1_Pin, SET);
		HAL_GPIO_WritePin( GPIOA, EN2_Pin, SET);
		HAL_GPIO_WritePin( GPIOA, EN3_Pin, RESET);
		break;
	default:
		HAL_GPIO_WritePin( GPIOA, EN0_Pin, SET);
		HAL_GPIO_WritePin( GPIOA, EN1_Pin, SET);
		HAL_GPIO_WritePin( GPIOA, EN2_Pin, SET);
		HAL_GPIO_WritePin( GPIOA, EN3_Pin, SET);
		break;
	}
}



//original
//void testgate(){
//	if(timer3_flag == 1){
//		count++;
////		num++;
//		switch(count){
//		case 1:
//			display7SEG(led_7_seg_buffer[1]);
//			break;
//		case 2:
//			display7SEG(led_7_seg_buffer[2]);
//			break;
//		case 3:
//			display7SEG(led_7_seg_buffer[3]);
//			break;
//		case 4:
//			display7SEG(led_7_seg_buffer[4]);
//			break;
//		default:
//			break;
//	}
//
//		if(count >= 4){
//			count = 0;
//		}
//
//	if(timer3_flag == 1){
//		num++;
//		onoff_gates_led(num);
//
//		if(num >= 2){
//			num = 0;
//		}
//	}
//	setTimer3(100);
//}
//}


void update_2_led_7_seg_buffer_left(int number){
	led_7_seg_buffer[0] = (number / 10);
	led_7_seg_buffer[1] = (number % 10);
}
void update_2_led_7_seg_buffer_right(int number){
	led_7_seg_buffer[2] = (number / 10);
	led_7_seg_buffer[3] = (number % 10);
}


//void Mode_count(){
//    if(timer3_flag == 1) {
//        count++;
//        if(count == 1) {
//            onoff_gates_led(1);
//            display7SEG(led_7_seg_buffer[0]); // Hiển thị LED 1
//        } else if(count == 2) {
//            onoff_gates_led(2);
//            display7SEG(led_7_seg_buffer[1]); // Hiển thị LED 2
//        }
//        if(count >= 2) {
//            count = 0;
//        }
//        setTimer3(25);
//    }
//}


void led_7_seg_run(){
	onoff_gates_led(index_led_7_seg);
	display7SEG(led_7_seg_buffer[index_led_7_seg]);

	if(timer0_flag == 1){
		index_led_7_seg = (index_led_7_seg + 1)%4;
		setTimer0(25);
	}

}




