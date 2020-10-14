/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
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
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "gui.h"
#include "ili9341.h"
//#include "xpt2046.h"
#include <stdio.h>
#include <string.h>


#include "0.c"
#include "19.c"
#include "21.c"
#include "25.c"
#include "26.c"
#include "20.c"
#include "22.c"
#include "16.c"
#include "24.c"

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
SPI_HandleTypeDef hspi1;
DMA_HandleTypeDef hdma_spi1_tx;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_SPI1_Init(void);
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
  MX_DMA_Init();
  MX_SPI1_Init();
  /* USER CODE BEGIN 2 */
// __HAL_SPI_DISABLE(&hspi3);
  	//  x = y = 0;
  	  ILI9341_Init();
  	  GUI_FillScreen(WHITE);
  	  GUI_UpdateScreen();
  	  GUI_FillScreen(RED);
  	  GUI_UpdateScreen();
  	  GUI_FillScreen(GREEN);
  	  GUI_UpdateScreen();
  	  GUI_FillScreen(BLUE);
  	  GUI_UpdateScreen();

  	//  GUI_FillScreen(BLACK);
  	//  GUI_UpdateScreen();

  //	ILI9341_SetWindow(0, 0, 240, 320);
  //	 ILI9341_SetWindow(0, 0, 240, 320);
  //	  GUI_FillScreen(BLACK);
  //	  GUI_UpdateScreen();

//  GUI_WriteSquare (100, 100, BLUE);
//  GUI_WriteSquare (200, 100, YELLOW);
//  GUI_UpdateScreen();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */




		//  GUI_NormalizeXY((int16_t *)&x, (int16_t *)&y);
		//  GUI_WriteSquare(x, y, GREEN);
	//	  sprintf((char *)str, "%d %d\n", x, y);

	//  GUI_UpdateScreen();
	  //ILI9341_SetWindow(0, 0, 240, 240);
	  //-----------------------
	  //static __IO uint8_t Done;
//	  uint32_t image_data_logo = 0;
//
//		// HAL_SPI_Transmit_DMA supports the translation size until 0xffff
//		// So, I need to separate bitmap
//		for (uint32_t y = 0; y <  GUI_HEIGHT; y += 80) {
//			ILI9341_SetWindow(0, y, GUI_WIDTH-1, y+80-1);
//		//Done = 0;
//			ILI9341_DrawBitmap(GUI_WIDTH, 80, &image_data_0[image_data_logo]);
//
//			image_data_logo += 80*GUI_WIDTH*2;
//	//while (Done == 0)
//				;
//			HAL_Delay(250);
//	}

	  HAL_Delay(2000);

	  uint32_t 	image_data_logo = 0;

			// HAL_SPI_Transmit_DMA supports the translation size until 0xffff
			// So, I need to separate bitmap
			for (uint32_t y = 0; y <  GUI_HEIGHT; y += 80) {
				ILI9341_SetWindow(0, y, GUI_WIDTH-1, y+80-1);
			//Done = 0;
				ILI9341_DrawBitmap(GUI_WIDTH, 80, &image_data_20[image_data_logo]);

				image_data_logo += 80*GUI_WIDTH*2;
		//while (Done == 0)

				HAL_Delay(250);
			}
		HAL_Delay(2000);
//
//					image_data_logo = 0;
//
//				// HAL_SPI_Transmit_DMA supports the translation size until 0xffff
//				// So, I need to separate bitmap
//				for (uint32_t y = 0; y <  GUI_HEIGHT; y += 80) {
//					ILI9341_SetWindow(0, y, GUI_WIDTH-1, y+80-1);
//				//Done = 0;
//					ILI9341_DrawBitmap(GUI_WIDTH, 80, &image_data_21[image_data_logo]);
//
//					image_data_logo += 80*GUI_WIDTH*2;
//			//while (Done == 0)
//						;
//					HAL_Delay(250);
//				}

//				HAL_Delay(500);
//
						image_data_logo = 0;

					// HAL_SPI_Transmit_DMA supports the translation size until 0xffff
					// So, I need to separate bitmap
					for (uint32_t y = 0; y <  GUI_HEIGHT; y += 80) {
						ILI9341_SetWindow(0, y, GUI_WIDTH-1, y+80-1);
					//Done = 0;
						ILI9341_DrawBitmap(GUI_WIDTH, 80, &image_data_24[image_data_logo]);

						image_data_logo += 80*GUI_WIDTH*2;
				//while (Done == 0)

						HAL_Delay(250);
					}
					HAL_Delay(2000);

							image_data_logo = 0;

						// HAL_SPI_Transmit_DMA supports the translation size until 0xffff
						// So, I need to separate bitmap
						for (uint32_t y = 0; y <  GUI_HEIGHT; y += 80) {
							ILI9341_SetWindow(0, y, GUI_WIDTH-1, y+80-1);
						//Done = 0;
							ILI9341_DrawBitmap(GUI_WIDTH, 80, &image_data_19[image_data_logo]);

							image_data_logo += 80*GUI_WIDTH*2;
					//while (Done == 0)

							HAL_Delay(250);
						}
	  //-----------------------
	  //ILI9341_DrawBitmap(240, 240, image_data_logo_320_240_24bit);




	//GUI_UpdateScreen();
//	GUI_FillScreen(RED);
	//ILI9341_SetWindow(0, 0, 240, 320); */
  // ILI9341_SetWindow(0, 0, 240, 320);
  // ILI9341_DrawBitmap(240, 320, image_data_0);

	HAL_Delay(1000);

	//

		//  HAL_UART_Transmit(&huart1, str, strlen((char *)str), 1000);
  	  //}
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

  /** Configure the main internal regulator output voltage 
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE0) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 3;
  RCC_OscInitStruct.PLL.PLLN = 55;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief SPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI1_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */

  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  /* USER CODE END SPI1_Init 1 */
  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_64;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 7;
  hspi1.Init.CRCLength = SPI_CRC_LENGTH_DATASIZE;
  hspi1.Init.NSSPMode = SPI_NSS_PULSE_ENABLE;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI1_Init 2 */

  /* USER CODE END SPI1_Init 2 */

}

/** 
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void) 
{

  /* DMA controller clock enable */
  __HAL_RCC_DMAMUX1_CLK_ENABLE();
  __HAL_RCC_DMA1_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA1_Channel1_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Channel1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Channel1_IRQn);

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
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOG_CLK_ENABLE();
  HAL_PWREx_EnableVddIO2();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(DCX_GPIO_Port, DCX_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LED_CTRL_GPIO_Port, LED_CTRL_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(ENABLE_GPIO_Port, ENABLE_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOG, SPI1_NSS_Pin|RESET_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(T_CS_GPIO_Port, T_CS_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LED1_Pin|LED2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : DCX_Pin */
  GPIO_InitStruct.Pin = DCX_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
  HAL_GPIO_Init(DCX_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : LED_CTRL_Pin */
  GPIO_InitStruct.Pin = LED_CTRL_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LED_CTRL_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : ENABLE_Pin */
  GPIO_InitStruct.Pin = ENABLE_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(ENABLE_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : SPI1_NSS_Pin */
  GPIO_InitStruct.Pin = SPI1_NSS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(SPI1_NSS_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : T_CS_Pin */
  GPIO_InitStruct.Pin = T_CS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(T_CS_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : RESET_Pin */
  GPIO_InitStruct.Pin = RESET_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(RESET_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : LED1_Pin LED2_Pin */
  GPIO_InitStruct.Pin = LED1_Pin|LED2_Pin;
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
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
