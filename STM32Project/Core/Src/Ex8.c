/*
 * Ex8.c
 *
 *  Created on: Sep 18, 2024
 *      Author: ADMIN
 */
#include "Ex8.h"
int counter=0;
GPIO_TypeDef* segmentPorts[12] = {
          LED0_GPIO_Port, LED1_GPIO_Port,LED2_GPIO_Port,LED3_GPIO_Port,LED4_GPIO_Port,LED5_GPIO_Port,
		  LED6_GPIO_Port,LED7_GPIO_Port,LED8_GPIO_Port,LED9_GPIO_Port,LED10_GPIO_Port,LED11_GPIO_Port};
uint16_t segmentPins[12]={LED0_Pin,LED1_Pin,LED2_Pin,LED3_Pin,LED4_Pin,LED5_Pin,LED6_Pin,LED7_Pin
      	                          ,LED8_Pin,LED9_Pin,LED10_Pin,LED11_Pin};
void setNumberOnClock(int num) {
          	  HAL_GPIO_WritePin(segmentPorts[num], segmentPins[num], RESET);
          	  HAL_GPIO_WritePin(GPIOA, LED_PINS & ~ segmentPins[num], SET);
        }
void Ex8_run(){
	if(counter>=12) counter=0;
	setNumberOnClock(counter++);
}

