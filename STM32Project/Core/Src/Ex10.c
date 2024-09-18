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
        }

