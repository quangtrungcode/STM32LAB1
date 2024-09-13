/*
 * Ex6.h
 *
 *  Created on: 13 thg 9, 2024
 *      Author: ADMIN
 */

#ifndef INC_EX6_H_
#define INC_EX6_H_

#include "main.h"
extern int counter;
extern GPIO_TypeDef* segmentPorts[12];
extern uint16_t segmentPins[12];
void TurnOnEveryClock(int num);

#endif /* INC_EX6_H_ */
