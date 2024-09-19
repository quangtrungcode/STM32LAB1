/*
 * Ex5.c
 *
 *  Created on: Sep 18, 2024
 *      Author: ADMIN
 */
#include "Ex5.h"
#include "Ex1.h"
#include "Ex3.h"
  int counterred=6;
  int counteryellow=2;
  int countergreen=3;
GPIO_TypeDef* segmentPorts[2][NUM_SEGMENTS] = {
      {a1_GPIO_Port, b1_GPIO_Port, c1_GPIO_Port, d1_GPIO_Port, e1_GPIO_Port, f1_GPIO_Port, g1_GPIO_Port},
      {a2_GPIO_Port, b2_GPIO_Port, c2_GPIO_Port, d2_GPIO_Port, e2_GPIO_Port, f2_GPIO_Port, g2_GPIO_Port}
  };
  uint16_t segmentPins[2][NUM_SEGMENTS] = {
      {a1_Pin, b1_Pin, c1_Pin, d1_Pin, e1_Pin, f1_Pin, g1_Pin},
      {a2_Pin, b2_Pin, c2_Pin, d2_Pin, e2_Pin, f2_Pin, g2_Pin}
  };
  const uint8_t segmentMap[10] = {
        0b11111100,
        0b01100000,
        0b11011010,
        0b11110010,
        0b01100110,
        0b10110110,
        0b10111110,
        0b11100000,
        0b11111110,
        0b11110110
    };
  void display7SEG1(int ledNum, int num) {
        for (int i = 0; i < NUM_SEGMENTS; i++) {
            HAL_GPIO_WritePin(segmentPorts[ledNum][i], segmentPins[ledNum][i],
                              (segmentMap[num] & (0b10000000 >> i)) ? RESET : SET);
        }
    }
  void Ex5_run(){
	  HAL_GPIO_WritePin(GPIOA, LED_RED_Pin|LED_YELLOW_Pin|LED_GREEN_Pin, SET);
	  if(counter>=14) counter=0;
	  counter++;
	  if(counter<=4){
		  settrafficlight1(LED_RED1_GPIO_Port, LED_RED1_Pin, LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, LED_GREEN1_GPIO_Port, LED_GREEN1_Pin);
	  	  settrafficlight1(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, LED_RED2_GPIO_Port, LED_RED2_Pin, LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin) ;
	      display7SEG1(0, counterred--);
	      display7SEG1(1, countergreen--);
	  }
	  if(counter>4&&counter<=7){
		  settrafficlight1(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, LED_RED2_GPIO_Port, LED_RED2_Pin);
		  display7SEG1(0, counterred--);
		  display7SEG1(1, counteryellow--);
		  if(counter>=7){
			  counterred=6;
			  counteryellow=2;
			  countergreen=3;
		  }
	  }
	  if(counter>7&&counter<=11){
		  settrafficlight1(LED_RED2_GPIO_Port, LED_RED2_Pin, LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, LED_GREEN2_GPIO_Port, LED_GREEN2_Pin);
		  settrafficlight1(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, LED_RED1_GPIO_Port, LED_RED1_Pin, LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin);
		  display7SEG1(1, counterred--);
		  display7SEG1(0, countergreen--);
	  }
	  if(counter>11&&counter<=14){
		 settrafficlight1(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, LED_RED1_GPIO_Port, LED_RED1_Pin);
		 display7SEG1(1, counterred--);
		 display7SEG1(0, counteryellow--);
		 if(counter>=14){
		 	  counterred=6;
		 	  counteryellow=2;
		 	  countergreen=3;
		 }
	  }
    }

