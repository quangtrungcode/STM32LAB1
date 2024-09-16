/*
 * Ex2.c
 *
 *  Created on: Sep 16, 2024
 *      Author: ADMIN
 */
#include "Ex2.h"
int counter=0;
void Ex2_run(){
	if(counter>=10) counter=0;
	counter++;
	if(counter<=5){
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, RESET);  // Đèn đỏ sáng
		HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);
	    HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);
	}
	if(counter>5&&counter<=8){
		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, RESET);
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);
	}
	if(counter>8){
		HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, RESET); // Đèn vàng sáng
	    HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
	}
}
