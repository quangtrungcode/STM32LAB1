/*
 * Ex10.h
 *
 *  Created on: Sep 13, 2024
 *      Author: ADMIN
 */

#ifndef INC_EX10_H_
#define INC_EX10_H_

#include "main.h"
extern int second;
extern int minute;
extern int hour;
extern GPIO_TypeDef* segmentPorts[12];
extern uint16_t segmentPins[12];
void setNumberOnClock(int num);
void clearNumberOnClock(int num);
void Ex10_run();
void setClockBegin(int hour,int minute,int second);

#endif /* INC_EX10_H_ */
