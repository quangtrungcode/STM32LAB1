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
      HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, (segmentMap[num] & 0b10000000) ? GPIO_PIN_RESET : GPIO_PIN_SET);
      HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, (segmentMap[num] & 0b01000000) ? GPIO_PIN_RESET : GPIO_PIN_SET);
      HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, (segmentMap[num] & 0b00100000) ? GPIO_PIN_RESET : GPIO_PIN_SET);
      HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, (segmentMap[num] & 0b00010000) ? GPIO_PIN_RESET : GPIO_PIN_SET);
      HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, (segmentMap[num] & 0b00001000) ? GPIO_PIN_RESET : GPIO_PIN_SET);
      HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, (segmentMap[num] & 0b00000100) ? GPIO_PIN_RESET : GPIO_PIN_SET);
      HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, (segmentMap[num] & 0b00000010) ? GPIO_PIN_RESET : GPIO_PIN_SET);
  }

