/*
 * Ex8.h
 *
 *  Created on: Sep 13, 2024
 *      Author: ADMIN
 */

#ifndef INC_EX8_H_
#define INC_EX8_H_

#include "main.h"
extern int counter;
extern GPIO_TypeDef* segmentPorts[12];
extern uint16_t segmentPins[12];
void setNumberOnClock(int num);
void Ex8_run();
#endif /* INC_EX8_H_ */
