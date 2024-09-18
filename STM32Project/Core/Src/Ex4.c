/*
 * Ex4.c
 *
 *  Created on: Sep 18, 2024
 *      Author: ADMIN
 */
#include "Ex4.h"
void display7SEG(int num) {
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
      HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, (segmentMap[num] & 0b10000000) ? GPIO_PIN_RESET : GPIO_PIN_SET);
      HAL_GPIO_WritePin(b1_GPIO_Port, b1_Pin, (segmentMap[num] & 0b01000000) ? GPIO_PIN_RESET : GPIO_PIN_SET);
      HAL_GPIO_WritePin(c1_GPIO_Port, c1_Pin, (segmentMap[num] & 0b00100000) ? GPIO_PIN_RESET : GPIO_PIN_SET);
      HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, (segmentMap[num] & 0b00010000) ? GPIO_PIN_RESET : GPIO_PIN_SET);
      HAL_GPIO_WritePin(e1_GPIO_Port, e1_Pin, (segmentMap[num] & 0b00001000) ? GPIO_PIN_RESET : GPIO_PIN_SET);
      HAL_GPIO_WritePin(f1_GPIO_Port, f1_Pin, (segmentMap[num] & 0b00000100) ? GPIO_PIN_RESET : GPIO_PIN_SET);
      HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, (segmentMap[num] & 0b00000010) ? GPIO_PIN_RESET : GPIO_PIN_SET);
  }

