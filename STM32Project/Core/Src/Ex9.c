/*
 * Ex9.c
 *
 *  Created on: Sep 18, 2024
 *      Author: ADMIN
 */
#include "Ex9.h"
#include "Ex6.h"
void clearNumberOnClock(int num) {
          	 HAL_GPIO_WritePin(segmentPorts[num], segmentPins[num], SET);
          	 HAL_GPIO_WritePin(GPIOA, LED_PINS & ~ segmentPins[num], RESET);
        }
void Ex9_run(){
	if(counter>=12) counter=0;
		  clearNumberOnClock(counter++);
}

