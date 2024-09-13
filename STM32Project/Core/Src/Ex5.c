/*
 * Ex5.c
 *
 *  Created on: 13 thg 9, 2024
 *      Author: ADMIN
 */
#include "Ex5.h"
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
  void settrafficlight1(GPIO_TypeDef* LED_GIPO_Port, uint16_t LED_Pin,GPIO_TypeDef* LED_1GIPO_Port, uint16_t LED_1Pin,GPIO_TypeDef* LED_2GIPO_Port, uint16_t LED_2Pin){
    	  HAL_GPIO_WritePin(LED_GIPO_Port, LED_Pin, SET);
    	  HAL_GPIO_WritePin(LED_1GIPO_Port, LED_1Pin, RESET);
    	  HAL_GPIO_WritePin(LED_2GIPO_Port, LED_2Pin, RESET);
      }
  void display7SEG(int ledNum, int num) {
        for (int i = 0; i < NUM_SEGMENTS; i++) {
            HAL_GPIO_WritePin(segmentPorts[ledNum][i], segmentPins[ledNum][i],
                              (segmentMap[num] & (0b10000000 >> i)) ? RESET : SET);
        }
    }
  void process(){
  	  settrafficlight1(LED_RED1_GPIO_Port, LED_RED1_Pin, LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, LED_GREEN1_GPIO_Port, LED_GREEN1_Pin);
  	  settrafficlight1(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, LED_RED2_GPIO_Port, LED_RED2_Pin, LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin) ;
        for(int i=5;i>=2;i--){
      	  display7SEG(0, counterred--);
      	  display7SEG(1, countergreen--);
      	  HAL_Delay(1000);
        }
        settrafficlight1(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, LED_RED2_GPIO_Port, LED_RED2_Pin);
  	  for(int i=2;i>=0;i--){
  		  display7SEG(0, counterred--);
  		  display7SEG(1, counteryellow--);
  		  HAL_Delay(1000);
  		  if(i<=0){
  			  counterred=6;
  			  counteryellow=2;
  			  countergreen=3;
  		  }
  	  }
  	  settrafficlight1(LED_RED2_GPIO_Port, LED_RED2_Pin, LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, LED_GREEN2_GPIO_Port, LED_GREEN2_Pin);
  	  settrafficlight1(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, LED_RED1_GPIO_Port, LED_RED1_Pin, LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin);
  	  for(int i=5;i>=2;i--){
  	      	  display7SEG(1, counterred--);
  	      	  display7SEG(0, countergreen--);
  	      	HAL_Delay(1000);
  	  }
  	  settrafficlight1(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, LED_RED1_GPIO_Port, LED_RED1_Pin);
  	  for(int i=2;i>=0;i--){
  		  	  display7SEG(1, counterred--);
  	  		  display7SEG(0, counteryellow--);
  	  		HAL_Delay(1000);
  	  		if(i<=0){
  	  			counterred=6;
  	  			counteryellow=2;
  	  			countergreen=3;
  	  		}
  	  }
    }
