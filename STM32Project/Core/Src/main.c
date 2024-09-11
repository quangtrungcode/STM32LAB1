/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include <main.h>

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  void settrafficlight1(GPIO_TypeDef* LED_GIPO_Port, uint16_t LED_Pin,GPIO_TypeDef* LED_1GIPO_Port, uint16_t LED_1Pin,GPIO_TypeDef* LED_2GIPO_Port, uint16_t LED_2Pin)
    {
  	  HAL_GPIO_WritePin(LED_GIPO_Port, LED_Pin, SET);
  	  HAL_GPIO_WritePin(LED_1GIPO_Port, LED_1Pin, RESET);
  	  HAL_GPIO_WritePin(LED_2GIPO_Port, LED_2Pin, RESET);
    }

  GPIO_TypeDef* segmentPorts[2][NUM_SEGMENTS] = {
      {a1_GPIO_Port, b1_GPIO_Port, c1_GPIO_Port, d1_GPIO_Port, e1_GPIO_Port, f1_GPIO_Port, g1_GPIO_Port},  // LED 1
      {a2_GPIO_Port, b2_GPIO_Port, c2_GPIO_Port, d2_GPIO_Port, e2_GPIO_Port, f2_GPIO_Port, g2_GPIO_Port}   // LED 2
  };

  // Mảng lưu chân GPIO của từng đoạn cho 2 LED
  uint16_t segmentPins[2][NUM_SEGMENTS] = {
      {a1_Pin, b1_Pin, c1_Pin, d1_Pin, e1_Pin, f1_Pin, g1_Pin},  // LED 1
      {a2_Pin, b2_Pin, c2_Pin, d2_Pin, e2_Pin, f2_Pin, g2_Pin}   // LED 2
  };

  // Mảng lưu trữ các giá trị tương ứng với các số từ 0 đến 9
  const uint8_t segmentMap[10] = {
      0b11111100,  // Số 0: a,b,c,d,e,f sáng (g tắt)
      0b01100000,  // Số 1: b,c sáng (a,d,e,f,g tắt)
      0b11011010,  // Số 2: a,b,d,e,g sáng (c,f tắt)
      0b11110010,  // Số 3: a,b,c,d,g sáng (e,f tắt)
      0b01100110,  // Số 4: b,c,f,g sáng (a,d,e tắt)
      0b10110110,  // Số 5: a,c,d,f,g sáng (b,e tắt)
      0b10111110,  // Số 6: a,c,d,e,f,g sáng (b tắt)
      0b11100000,  // Số 7: a,b,c sáng (d,e,f,g tắt)
      0b11111110,  // Số 8: a,b,c,d,e,f,g sáng
      0b11110110   // Số 9: a,b,c,d,f,g sáng (e tắt)
  };

  // Hàm hiển thị số trên nhiều LED 7 đoạn
  void display7SEG(int ledNum, int num) {
      for (int i = 0; i < NUM_SEGMENTS; i++) {
          HAL_GPIO_WritePin(segmentPorts[ledNum][i], segmentPins[ledNum][i],
                            (segmentMap[num] & (0b10000000 >> i)) ? RESET : SET);
      }
  }

  int counterred=6;
  int counteryellow=2;
  int countergreen=3;
  void process(){
	  settrafficlight1(LED_RED1_GPIO_Port, LED_RED1_Pin, LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, LED_GREEN1_GPIO_Port, LED_GREEN1_Pin);
	  settrafficlight1(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, LED_RED2_GPIO_Port, LED_RED2_Pin, LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin) ;
      for(int i=5;i>=2;i--){
    	  display7SEG(0, counterred--);
    	  display7SEG(1, countergreen--);
    	 // if(i>2) HAL_Delay(1000);
    	  HAL_Delay(1000);
      }
     // counterred++;
      settrafficlight1(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, LED_RED2_GPIO_Port, LED_RED2_Pin);
	  for(int i=2;i>=0;i--){
		  if(i<0){
		  			  counterred=6;
		  			  counteryellow=2;
		  			  countergreen=3;
		  			  break;
		  		  }
		  display7SEG(0, counterred--);
		  display7SEG(1, counteryellow--);
		 // if(i>0) HAL_Delay(1000);
		  HAL_Delay(1000);
//		  if(i<=0){
//			  counterred=5;
//			  counteryellow=2;
//			  countergreen=3;
//		  }
//		  else{
//			  counterred=5;
//			  counteryellow=2;
//			  countergreen=3;
//		  }
	  }

	  settrafficlight1(LED_RED2_GPIO_Port, LED_RED2_Pin, LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, LED_GREEN2_GPIO_Port, LED_GREEN2_Pin);
	  settrafficlight1(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, LED_RED1_GPIO_Port, LED_RED1_Pin, LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin);
	  for(int i=5;i>=2;i--){
	      	  display7SEG(1, counterred--);
	      	  display7SEG(0, countergreen--);
	      	 // if(i>2) HAL_Delay(1000);
	      	HAL_Delay(1000);
	  }
	 // counterred++;
	  settrafficlight1(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, LED_RED1_GPIO_Port, LED_RED1_Pin);
	  for(int i=2;i>=0;i--){
	  		if(i<0){
	  			counterred=6;
	  			counteryellow=2;
	  			countergreen=3;
	  			break;
	  		}
		  	  display7SEG(1, counterred--);
	  		  display7SEG(0, counteryellow--);
//	  		  if(i>0) HAL_Delay(1000);
//	  		  else{
//	  			counterred=5;
//	  			counteryellow=2;
//	  			countergreen=3;
//	  		  }
	  		HAL_Delay(1000);
//	  		if(i<=0){
//	  			counterred=5;
//	  			counteryellow=2;
//	  			countergreen=3;
//	  		}
	  }
  }
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	    process();

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED_RED2_Pin|LED_YELLOW2_Pin|LED_GREEN2_Pin|LED_RED1_Pin
                          |LED_YELLOW1_Pin|LED_GREEN1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, a1_Pin|b1_Pin|c1_Pin|d2_Pin
                          |e2_Pin|f2_Pin|g2_Pin|d1_Pin
                          |e1_Pin|f1_Pin|g1_Pin|a2_Pin
                          |b2_Pin|c2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LED_RED2_Pin LED_YELLOW2_Pin LED_GREEN2_Pin LED_RED1_Pin
                           LED_YELLOW1_Pin LED_GREEN1_Pin */
  GPIO_InitStruct.Pin = LED_RED2_Pin|LED_YELLOW2_Pin|LED_GREEN2_Pin|LED_RED1_Pin
                          |LED_YELLOW1_Pin|LED_GREEN1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : a1_Pin b1_Pin c1_Pin d2_Pin
                           e2_Pin f2_Pin g2_Pin d1_Pin
                           e1_Pin f1_Pin g1_Pin a2_Pin
                           b2_Pin c2_Pin */
  GPIO_InitStruct.Pin = a1_Pin|b1_Pin|c1_Pin|d2_Pin
                          |e2_Pin|f2_Pin|g2_Pin|d1_Pin
                          |e1_Pin|f1_Pin|g1_Pin|a2_Pin
                          |b2_Pin|c2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
