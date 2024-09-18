/*
 * Ex3.h
 *
 *  Created on: Sep 18, 2024
 *      Author: ADMIN
 */

#ifndef INC_EX3_H_
#define INC_EX3_H_
#include "main.h"
extern int counter;
void settrafficlight1(GPIO_TypeDef* LED_GIPO_Port, uint16_t LED_Pin,GPIO_TypeDef* LED_1GIPO_Port, uint16_t LED_1Pin,GPIO_TypeDef* LED_2GIPO_Port, uint16_t LED_2Pin);
void Ex3_run();

#endif /* INC_EX3_H_ */
