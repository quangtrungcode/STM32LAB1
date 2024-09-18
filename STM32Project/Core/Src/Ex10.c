/*
 * Ex10.c
 *
 *  Created on: Sep 18, 2024
 *      Author: ADMIN
 */
#include "Ex10.h"
int second=55;
int minute=59;
int hour=3;
//int counter=0;
//GPIO_TypeDef* segmentPorts[12] = {LED0_GPIO_Port, LED1_GPIO_Port,LED2_GPIO_Port,LED3_GPIO_Port,LED4_GPIO_Port,
//LED5_GPIO_Port,LED6_GPIO_Port,LED7_GPIO_Port,LED8_GPIO_Port,LED9_GPIO_Port,LED10_GPIO_Port,LED11_GPIO_Port};  // LED 1
//uint16_t segmentPins[12]={LED0_Pin,LED1_Pin,LED2_Pin,LED3_Pin
//  ,LED4_Pin,LED5_Pin,LED6_Pin,LED7_Pin,LED8_Pin,LED9_Pin,LED10_Pin,LED11_Pin};
void setNumberOnClock1(int num){
        	HAL_GPIO_WritePin(segmentPorts[num], segmentPins[num], RESET);
        }
void clearNumberOnClock1(int num){
        	HAL_GPIO_WritePin(segmentPorts[num], segmentPins[num], SET);
        }
void Ex10_run(){
	if(counter>=0) {
		counter=-1;
		setClockBegin( hour, minute, second);
	}
	   //  second++;
		  	  if (second >= 60) {
		  	          second = 0;
		  	          minute++;
		  	          setNumberOnClock1((minute / 5+12)%12);
		           if(((minute / 5+11)%12)!=hour&&((minute / 5+11)%12)!=second) clearNumberOnClock1(((minute / 5+11)%12));
		  	  if (minute >= 60) {
		  	              minute = 0;
		  	              hour++;
		  	              setNumberOnClock1((hour+12)%12);
		  	              if((hour+11)%12!=0) clearNumberOnClock1((hour+11)%12);
		  	              if (hour >= 12) {
		  	                  hour = 0;
		  	              }
		  	          }
		  	      }
		  	      setNumberOnClock1((second / 5+12)%12);
		  if(((second / 5+11)%12)!=hour&&((second / 5+11)%12)!=(minute/5+12)%12) clearNumberOnClock1(((second / 5+11)%12));
		  second++;
}
void setClockBegin(int hour,int minute,int second){
        	HAL_GPIO_WritePin(segmentPorts[hour], segmentPins[hour], RESET);
        if(minute%5==0)	HAL_GPIO_WritePin(segmentPorts[minute/5], segmentPins[minute/5], RESET);
        if(second%5==0)	HAL_GPIO_WritePin(segmentPorts[second/5], segmentPins[second/5], RESET);
        HAL_GPIO_WritePin(GPIOA, LED_PINS & ~ (segmentPins[hour]|segmentPins[minute/5]|segmentPins[second/5]), SET);
     //   HAL_Delay(2000);
        }

