/*
 * Ex1.c
 *
 *  Created on: Sep 18, 2024
 *      Author: ADMIN
 */
#include "Ex1.h"
int counter=0;
void Ex1_run(){
//			 HAL_GPIO_WritePin(GPIOA, LED_GREEN_Pin, SET);
//			 HAL_GPIO_WritePin(GPIOB, a2_Pin|b2_Pin|c2_Pin|d2_Pin|e2_Pin|f2_Pin|g2_Pin, SET);
//			 HAL_GPIO_WritePin(GPIOB, a1_Pin|b1_Pin|c1_Pin|d1_Pin|e1_Pin|f1_Pin|g1_Pin, SET);
	if(counter>=4) counter=0;
	counter++;
	if(counter<=2) {
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, RESET);  // Đèn đỏ sáng
	  HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);
	}
	else {
			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
			HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, RESET);
		}
}

