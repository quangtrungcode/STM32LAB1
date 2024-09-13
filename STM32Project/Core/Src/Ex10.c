/*
 * Ex10.c
 *
 *  Created on: Sep 13, 2024
 *      Author: ADMIN
 */
#include "Ex10.h"
int second=0;
int minute=0;
int hour=0;
GPIO_TypeDef* segmentPorts[12] = {LED0_GPIO_Port, LED1_GPIO_Port,LED2_GPIO_Port,LED3_GPIO_Port,LED4_GPIO_Port,
LED5_GPIO_Port,LED6_GPIO_Port,LED7_GPIO_Port,LED8_GPIO_Port,LED9_GPIO_Port,LED10_GPIO_Port,LED11_GPIO_Port};  // LED 1
uint16_t segmentPins[12]={LED0_Pin,LED1_Pin,LED2_Pin,LED3_Pin
  ,LED4_Pin,LED5_Pin,LED6_Pin,LED7_Pin,LED8_Pin,LED9_Pin,LED10_Pin,LED11_Pin};
void setClock(int num){
        	HAL_GPIO_WritePin(segmentPorts[num], segmentPins[num], RESET);
        }
void clearClock(int num){
        	HAL_GPIO_WritePin(segmentPorts[num], segmentPins[num], SET);
        }
void setClockBegin(int hour,int minute,int second){
        	HAL_GPIO_WritePin(segmentPorts[hour], segmentPins[hour], RESET);
        if(minute%5==0)	HAL_GPIO_WritePin(segmentPorts[minute/5], segmentPins[minute/5], RESET);
        if(second%5==0)	HAL_GPIO_WritePin(segmentPorts[second/5], segmentPins[second/5], RESET);
        HAL_Delay(2000);
        }
