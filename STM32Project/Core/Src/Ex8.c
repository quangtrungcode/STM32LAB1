/*
 * Ex8.c
 *
 *  Created on: Sep 18, 2024
 *      Author: ADMIN
 */
#include "Ex8.h"
void setNumberOnClock(int num) {
          	  HAL_GPIO_WritePin(segmentPorts[num], segmentPins[num], RESET);
          	  HAL_GPIO_WritePin(GPIOA, LED_PINS & ~ segmentPins[num], SET);
        }
void Ex8_run(){
	if(counter>=12) counter=0;
	setNumberOnClock(counter++);
}

