/*
 * Ex8.h
 *
 *  Created on: Sep 13, 2024
 *      Author: ADMIN
 */

#ifndef INC_EX8_H_
#define INC_EX8_H_
#define LED_PINS (LED0_Pin|LED1_Pin|LED2_Pin|LED3_Pin|LED4_Pin|LED5_Pin|LED6_Pin|LED7_Pin|LED8_Pin|LED9_Pin|LED10_Pin|LED11_Pin)
#include "main.h"
extern int counter;
extern GPIO_TypeDef* segmentPorts[12];
extern uint16_t segmentPins[12];
void setNumberOnClock(int num);
void Ex8_run();
#endif /* INC_EX8_H_ */
