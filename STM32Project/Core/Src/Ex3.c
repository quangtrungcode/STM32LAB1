/*
 * Ex3.c
 *
 *  Created on: 13 thg 9, 2024
 *      Author: ADMIN
 */
#include "Ex3.h"
void settrafficlight1(GPIO_TypeDef* LED_GIPO_Port, uint16_t LED_Pin,GPIO_TypeDef* LED_1GIPO_Port, uint16_t LED_1Pin,GPIO_TypeDef* LED_2GIPO_Port, uint16_t LED_2Pin)
  {
	  HAL_GPIO_WritePin(LED_GIPO_Port, LED_Pin, SET);
	  HAL_GPIO_WritePin(LED_1GIPO_Port, LED_1Pin, RESET);
	  HAL_GPIO_WritePin(LED_2GIPO_Port, LED_2Pin, RESET);
  }

