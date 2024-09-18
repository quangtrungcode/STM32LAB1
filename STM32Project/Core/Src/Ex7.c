/*
 * Ex7.c
 *
 *  Created on: Sep 18, 2024
 *      Author: ADMIN
 */
#include "Ex7.h"
void clearAllClock(){
	  HAL_GPIO_WritePin(GPIOA, LED_PINS, SET);
  }
void Ex7_run(){
	clearAllClock();
}
