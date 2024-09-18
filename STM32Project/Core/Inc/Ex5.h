/*
 * Ex5.h
 *
 *  Created on: Sep 18, 2024
 *      Author: ADMIN
 */

#ifndef INC_EX5_H_
#define INC_EX5_H_

#include "main.h"

#define NUM_SEGMENTS 7
extern int counterred;
extern int counteryellow;
extern int countergreen;
extern int counter;
// Khai báo mảng cho các chân GPIO của LED 7 đoạn
extern GPIO_TypeDef* segmentPorts[2][NUM_SEGMENTS];
extern uint16_t segmentPins[2][NUM_SEGMENTS];

// Khai báo bảng ánh xạ các số cho LED 7 đoạn
extern const uint8_t segmentMap[10];
void settrafficlight1(GPIO_TypeDef* LED_GIPO_Port, uint16_t LED_Pin,GPIO_TypeDef* LED_1GIPO_Port, uint16_t LED_1Pin,GPIO_TypeDef* LED_2GIPO_Port, uint16_t LED_2Pin);
void display7SEG1(int ledNum, int num);
void Ex5_run();

#endif /* INC_EX5_H_ */
