/*
 * Ex3.c
 *
 *  Created on: 13 thg 9, 2024
 *      Author: ADMIN
 */
#include "Ex3.h"
int counter=0;
void settrafficlight1(GPIO_TypeDef* LED_GIPO_Port, uint16_t LED_Pin,GPIO_TypeDef* LED_1GIPO_Port, uint16_t LED_1Pin,GPIO_TypeDef* LED_2GIPO_Port, uint16_t LED_2Pin)
  {
	  HAL_GPIO_WritePin(LED_GIPO_Port, LED_Pin, SET);
	  HAL_GPIO_WritePin(LED_1GIPO_Port, LED_1Pin, RESET);
	  HAL_GPIO_WritePin(LED_2GIPO_Port, LED_2Pin, RESET);
  }
void Ex3_run(){
	if(counter>=10) counter=0;
	counter++;
	settrafficlight1(LED_RED1_GPIO_Port, LED_RED1_Pin, LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, LED_GREEN1_GPIO_Port, LED_GREEN1_Pin);
	settrafficlight1(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, LED_RED2_GPIO_Port, LED_RED2_Pin, LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin) ;
	HAL_Delay(3000);
	settrafficlight1(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, LED_RED2_GPIO_Port, LED_RED2_Pin);
	HAL_Delay(2000);
	settrafficlight1(LED_RED2_GPIO_Port, LED_RED2_Pin, LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, LED_GREEN2_GPIO_Port, LED_GREEN2_Pin);
	settrafficlight1(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, LED_RED1_GPIO_Port, LED_RED1_Pin, LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin);
	HAL_Delay(3000);
	settrafficlight1(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, LED_RED1_GPIO_Port, LED_RED1_Pin);
	HAL_Delay(2000);
	if(counter<=3){
		settrafficlight1(LED_RED1_GPIO_Port, LED_RED1_Pin, LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, LED_GREEN1_GPIO_Port, LED_GREEN1_Pin);
		settrafficlight1(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, LED_RED2_GPIO_Port, LED_RED2_Pin, LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin) ;
	}
	if(counter>3&&counter<=5){
		settrafficlight1(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, LED_RED2_GPIO_Port, LED_RED2_Pin);
	}
	if(counter>5&&counter<=8){
		settrafficlight1(LED_RED2_GPIO_Port, LED_RED2_Pin, LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, LED_GREEN2_GPIO_Port, LED_GREEN2_Pin);
		settrafficlight1(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, LED_RED1_GPIO_Port, LED_RED1_Pin, LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin);
	}
	if(counter>8&&counter<=10){
		settrafficlight1(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, LED_RED1_GPIO_Port, LED_RED1_Pin);
	}
}
