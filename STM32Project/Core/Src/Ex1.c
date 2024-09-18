/*
 * Ex1.c
 *
 *  Created on: Sep 16, 2024
 *      Author: ADMIN
 */
#include "Ex1.h"
int counter=0;
void Ex1_run(){
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

