/*
 * Ex9.h
 *
 *  Created on: Sep 13, 2024
 *      Author: ADMIN
 */

#ifndef INC_EX9_H_
#define INC_EX9_H_

#include "main.h"
extern int counter;
extern GPIO_TypeDef* segmentPorts[12];
extern uint16_t segmentPins[12];
void clearNumberOnClock(int num);

#endif /* INC_EX9_H_ */
