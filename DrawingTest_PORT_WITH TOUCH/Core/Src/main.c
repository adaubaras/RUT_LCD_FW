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
#include <stdio.h>
#include <string.h>

#include "CY8CMBR3xxx_APIs.h"
#include "CY8CMBR3xxx_Registers.h"
#include "MBR3_Configuration.h"
#include "stm32l5xx_hal_i2c.h"
#include "CY8CMBR3xxx_HostFunctions.c"

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

/***************************************
* Project Constants
***************************************/
#define SLAVE_ADDRESS                   0x37
#define LED_ON                          0x00
#define LED_OFF                         0x01
#define GPO_OUTPUT_GPO0_MASK            0x01
#define GPO_LOW                         0x00
#define PROXIMITY_DETECT                0x01
#define PROXIMITY_TOUCH                 0x01
#define BUTTON_TOUCH                    0x78
#define GPO_OUTPUT_STATE_OFFSET         0x01
#define GPO_OUTPUT_STATE_WRITE_LENGTH   0x02
#define GPO_OUTPUT_STATE_READ_LENGTH    0x01
#define GPO_CFG_HOST_CONTROL_EN         0xFF
#define GPO_OUTPUT_STATE_ALL_OFF        0xFF
#define GPO_CFG_WRITE_LENGTH            0x02

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

	     CY8CMBR3xxx_SENSORSTATUS sensorStatus;
	     uint8 prevProximityStatus = 0x00;
	     uint8 writeGPOOutputState[2] = {CY8CMBR3xxx_GPO_OUTPUT_STATE, 0x00};
	     uint8 writeGPOConfig[2] = {CY8CMBR3xxx_GPO_CFG, GPO_CFG_HOST_CONTROL_EN};

	     uint16 buttonData = 0x00;



/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c1;

SPI_HandleTypeDef hspi1;
DMA_HandleTypeDef hdma_spi1_tx;

UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */

char buff[64] = {0};

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_SPI1_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_I2C1_Init(void);
static void MX_NVIC_Init(void);
/* USER CODE BEGIN PFP */
void I2c_scanner(void);
void I2c_ALL_scanner(void);
void LCD_DRAW_image(void);
void SENSOR_Poll(void);
void MBR_configuration_init (void);
void Button_read (void);

/***************************************
* Delay Constants
***************************************/
#define PROX_LED_BLINK_DELAY            (50)
#define MBR3_BOOT_DELAY                 (1000)

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
	//  HAL_StatusTypeDef status;

	  /* Variables and structure declarations */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  HAL_PWREx_EnableVddIO2();


  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_SPI1_Init();
  MX_USART1_UART_Init();
  MX_I2C1_Init();

  /* Initialize interrupts */
  MX_NVIC_Init();
  /* USER CODE BEGIN 2 */

  /* Wait a second for the MBR3 device to bootup */
  HAL_Delay(MBR3_BOOT_DELAY);

  memset(buff, 0x00, sizeof(buff));
  sprintf(buff, "\r\nLCD Display Touch demo Application Started\r\n");
  HAL_UART_Transmit(&huart1, (uint8_t*)buff, strlen(buff), HAL_MAX_DELAY);

	ILI9341_Init();
	HAL_Delay(100);

	GUI_FillScreen(BLACK); //Blue
	HAL_Delay(10);
	GUI_UpdateScreen();

  /* Main loop execution begins */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

  	  while(1)
 	  {
		// I2c_scanner();
  		//I2c_ALL_scanner();
		// LCD_DRAW_image();
		 //MBR_configuration_init; //send MBR3 EZclick config file

		 //SENSOR_Poll();
		 Button_read();
//		 if (buttonData ==0x1|0x2|0x4|0x8)
//		 {
//	          HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_RESET);  // turn On LED2
//	          HAL_Delay(500);
//	          HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_SET); // turn Off LED2
//	          HAL_Delay(500);
//
//		 }

		// uint8 a=buttonData;

 		 if (buttonData == 0x01)
				{
					GUI_FillScreen(RED);
					HAL_Delay(10);
					GUI_UpdateScreen();
				}
		 if (buttonData == 0x02)
				{
					GUI_FillScreen(GREEN);
					HAL_Delay(10);
					GUI_UpdateScreen();
				}
		 if (buttonData == 0x04)
				{
					GUI_FillScreen(BLACK);
					HAL_Delay(10);
					GUI_UpdateScreen();
				}
		 if (buttonData == 0x08)
				{
					GUI_FillScreen(MAGENTA);
					HAL_Delay(10);
					GUI_UpdateScreen();
				}

		 if (buttonData == 0x10)
				{
					GUI_FillScreen(WHITE);
					HAL_Delay(10);
					GUI_UpdateScreen();
				}


//		GUI_FillScreen(0x7C0); //Blue
//		HAL_Delay(10);
//		GUI_UpdateScreen();

 	  }

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

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
  * @brief NVIC Configuration.
  * @retval None
  */
static void MX_NVIC_Init(void)
{
  /* I2C1_EV_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(I2C1_EV_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(I2C1_EV_IRQn);
}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.Timing = 0x30606DA3;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Analogue filter 
  */
  if (HAL_I2CEx_ConfigAnalogFilter(&hi2c1, I2C_ANALOGFILTER_DISABLE) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Digital filter 
  */
  if (HAL_I2CEx_ConfigDigitalFilter(&hi2c1, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

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
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  huart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart1.Init.ClockPrescaler = UART_PRESCALER_DIV1;
  huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetTxFifoThreshold(&huart1, UART_TXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetRxFifoThreshold(&huart1, UART_RXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_DisableFifoMode(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

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
  __HAL_RCC_GPIOA_CLK_ENABLE();
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

/*******************************************************************************
* Function Name: Button_read
********************************************************************************
*
* Summary:
*  This function reads button status.
*/
void Button_read(void)
{
		if (TRUE == CY8CMBR3xxx_ReadDualByte(SLAVE_ADDRESS, CY8CMBR3xxx_BUTTON_STAT,  &buttonData))
			{
				/* Indicate a success using GREEN LED */
			  memset(buff, 0x00, sizeof(buff));
			  uint8 i= buttonData;
			  sprintf(buff, "button press stat: 0x%X\r\n", i);
			  HAL_UART_Transmit(&huart1, (uint8_t*)buff, strlen(buff), HAL_MAX_DELAY);
			}
}



void MBR_configuration_init (void)
{
	/* Configure the MBR3 device with configuration data from EzClick */
	if (TRUE == CY8CMBR3xxx_Configure(SLAVE_ADDRESS, &CY8CMBR3110_configuration[0]))
		{
			/* Indicate a success using GREEN LED */
		  memset(buff, 0x00, sizeof(buff));
		  sprintf(buff, "CY8CMBR3xxx is configured\r\n");
		  HAL_UART_Transmit(&huart1, (uint8_t*)buff, strlen(buff), HAL_MAX_DELAY);

			/* Make Prox LED Host Controlled */
			CY8CMBR3xxx_WriteData(SLAVE_ADDRESS, writeGPOConfig, GPO_CFG_WRITE_LENGTH);
			sprintf(buff, "Make Prox LED Host Controlled\r\n");
			HAL_UART_Transmit(&huart1, (uint8_t*)buff, strlen(buff), HAL_MAX_DELAY);
		}
	else
	{
		/* Indicate a failure using RED LED */
		sprintf(buff, "MBR3 was not configured properly\r\n");
		HAL_UART_Transmit(&huart1, (uint8_t*)buff, strlen(buff), HAL_MAX_DELAY);
		/* Do nothing. MBR3 was not configured properly */
		while(1);
	}
}

void SENSOR_Poll(void)
{
    if (TRUE == CY8CMBR3xxx_ReadSensorStatus(SLAVE_ADDRESS, &sensorStatus))
    {
        /* Proceed if the Proximity Status changed for PS0 */

            sprintf(buff, "SENSSOR DATA READ\r\n");
            HAL_UART_Transmit(&huart1, (uint8_t*)buff, strlen(buff), HAL_MAX_DELAY);
            /* Proceed if a Proximity Touch event or a Button Touch event was detected */
            /* Make corresponding LED on GPO glow as long as a touch is detected */
            /* and turn that LED off when the finger is lifted */
          //  writeGPOOutputState[GPO_OUTPUT_STATE_OFFSET] = ~sensorStatus.buttonStatus;
         //   CY8CMBR3xxx_WriteData(SLAVE_ADDRESS, writeGPOOutputState, GPO_OUTPUT_STATE_WRITE_LENGTH);
            HAL_Delay(50);

    }
    else
    {
        /* Indicate a failure using RED LED */

        sprintf(buff, "I2C communication error happened while reading status\r\n");
        HAL_UART_Transmit(&huart1, (uint8_t*)buff, strlen(buff), HAL_MAX_DELAY);

        /* Do nothing. I2C communication error happened while reading status */
        while(1);
    }
}

void LCD_DRAW_image(void)
{
HAL_Delay(1000);
uint32_t 	image_data_logo = 0;
		// HAL_SPI_Transmit_DMA supports the translation size until 0xffff
		// So, I need to separate bitmap
		for (uint32_t y = 0; y <  GUI_HEIGHT; y += 80)
		{
			ILI9341_SetWindow(0, y, GUI_WIDTH-1, y+80-1);
			//Done = 0;
			ILI9341_DrawBitmap(GUI_WIDTH, 80, &image_data_22[image_data_logo]);
			image_data_logo += 80*GUI_WIDTH*2;
			//while (Done == 0)
			HAL_Delay(250);
		}
	HAL_Delay(2000);
}
void I2c_ALL_scanner(void)
{

for(uint8_t i = 0x0; i < 0xFF; i++)
	    {
		sprintf(buff, "Scan address.. 0x%X\r\n", i);
		HAL_UART_Transmit(&huart1, (uint8_t*)buff, strlen(buff), HAL_MAX_DELAY);
	      if(HAL_I2C_IsDeviceReady(&hi2c1, (uint16_t)(i<<1), 10, 2)!= HAL_OK)
	      {
	        /*Toggle User LED1*/
	        HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
	        /*Device found!*/
	          memset(buff, 0x00, sizeof(buff));
	      //    sprintf(buff, "Touch controller not detected!!!! 0x%X\r\n");
	          HAL_UART_Transmit(&huart1, (uint8_t*)buff, strlen(buff), HAL_MAX_DELAY);
	      }
	      else
	      {
	        /*Device found!*/
	          memset(buff, 0x00, sizeof(buff));
	          sprintf(buff, "Address found: 0x%X\r\n", i);
	          HAL_UART_Transmit(&huart1, (uint8_t*)buff, strlen(buff), HAL_MAX_DELAY);
	          HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);
	        for(uint8_t j = 0; j < 5; j++)
	        {
	          HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_RESET);
	          HAL_Delay(50);
	          HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_SET);
	          HAL_Delay(50);
	        }
	      }
	      HAL_Delay(100);
	    }
}

void I2c_scanner(void)
{
    sprintf(buff, "Scanning I2C BUS...\r\n");
    HAL_UART_Transmit(&huart1, (uint8_t*)buff, strlen(buff), HAL_MAX_DELAY);
    uint8 stat=1;
	while (stat)
	{
	stat=0;
		uint16 i=0x37;
	  stat=HAL_I2C_IsDeviceReady(&hi2c1, i<<1, 10, 1000);
	  HAL_Delay(10);
	  if( stat ==HAL_OK )
		  {
		  memset(buff, 0x00, sizeof(buff));
		  sprintf(buff, "Address found: 0x%X\r\n", i);
		  HAL_UART_Transmit(&huart1, (uint8_t*)buff, strlen(buff), HAL_MAX_DELAY);
		  HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);
		  HAL_Delay(500);
		  }
	}
}


/*******************************************************************************
* Function Name: Host_LowLevelWrite
********************************************************************************
*
* Summary:
*  This API writes to the register map of the CY8CMBR3xxx device using the I2C
*  communication protocol. The implementation is host processor dependent and
*  you may need to update the API code to suit your host.
*
* Parameters:
*  uint8 slaveAddress:
*   The I2C address of the CY8CMBR3xxx device. Valid range: 8 - 119
*
*  uint8 *writeBuffer:
*   The buffer from which data is written to the device.
*
*   The first element should always contain the location of the register
*   of the device to write to. This value can be within 0 – 251.
*
*   Each successive element should contain the data to be written to that
*   register and the successive registers. These elements can have a value
*   between 0 – 255. The number of data bytes can be between 0 and 128.
*
*  uint8 numberOfBytes:
*   Number of bytes to be written, equal to the number of elements in the
*   buffer (i.e. number of data bytes + 1)
*
* Pre:
*  The I2C interface should be enabled and working before this Low Level
*  API can be called. Also make sure that the Global Interrupts are also
*  enabled (if required)
*
* Post:
*  N/A
*
* Return:
*  status
*    Value                Description
*    TRUE                 Write process was successful
*    FALSE                Write process was not successful
*
*******************************************************************************/
bool Host_LowLevelWrite(uint8 slaveAddress, uint8 *writeBuffer, uint8 numberOfBytes)
{
    bool status = FALSE;                                       /* Default return is FALSE if anything goes wrong */
   // uint32 localBufStatus = 0;             /* Error status variable */
    uint8 retryCount = CY8CMBR3xxx_RETRY_TIMES;                /* Retry count, in case of any issue */
   // if(HAL_I2C_IsDeviceReady(&hi2c1, slaveAddress<<1, 10, 1000)==HAL_OK)


    	while (HAL_I2C_Master_Transmit(&hi2c1, slaveAddress<<1, writeBuffer, numberOfBytes, 10000) != HAL_OK)
    	{
    		if (HAL_I2C_GetError(&hi2c1) != HAL_I2C_ERROR_AF)
    		    {
    		      Error_Handler();
    		    }
    	}


   // HAL_I2C_IsDeviceReady(&hi2c1, (uint16_t)(i<<1), 2, 2)
    status = (retryCount)? TRUE: FALSE;
    return status;

}



/*******************************************************************************
* Function Name: Host_LowLevelRead
********************************************************************************
*
* Summary:
*  This API reads from the register map of the CY8CMBR3xxx device using the
*  I2C communication protocol. The implementation is host processor dependent
*  and you may need to update the API code to suit your host.
*
* Parameters:
*  uint8 slaveAddress:
*   The I2C address of the CY8CMBR3xxx device. Valid range: 8 - 119
*
*  uint8 *readBuffer:
*   The buffer to be updated with the data read from the device.
*
*   The register location to read from should be set prior to calling
*   this API. Each successive element to contain the data read from that
*   register and the successive registers. These elements can have a value
*   between 0 – 255.
*
*  uint8 numberOfBytes:
*   Number of data bytes to be read, equal to the number of elements in
*   the buffer. Valid range: 1 – 252
*
* Pre:
*  The I2C interface should be enabled and working before this Low Level
*  API can be called. Also make sure that the Global Interrupts are also
*  enabled (if required)
*
* Post:
*  N/A
*
* Return:
*  status
*    Value                Description
*    TRUE                 Read process was successful
*    FALSE                Read process was not successful
*
*******************************************************************************/
bool Host_LowLevelRead(uint8 slaveAddress, uint8 *readBuffer, uint8 numberOfBytes)
{
    bool status = FALSE;                                       /* Default return is FALSE if anything goes wrong */
 //   uint32 localBufStatus = HAL_OK;             /* Error status variable */
    uint8 retryCount = CY8CMBR3xxx_RETRY_TIMES;                /* Retry count, in case of any issue */
   // localBufStatus = SCB_I2CMasterWriteBuf(slaveAddress, writeBuffer, numberOfBytes, SCB_I2C_MODE_COMPLETE_XFER);
  //  if(HAL_I2C_IsDeviceReady(&hi2c1, slaveAddress<<1, 10, 1000)==HAL_OK)
//    {
//    HAL_I2C_Master_Receive(&hi2c1, slaveAddress<<1, writeBuffer, numberOfBytes, 10000);
	while (HAL_I2C_Master_Receive(&hi2c1, slaveAddress<<1, readBuffer, numberOfBytes, 10000) != HAL_OK)
		if (HAL_I2C_GetError(&hi2c1) != HAL_I2C_ERROR_AF)
			{
			  Error_Handler();
			}

//    }
   // HAL_I2C_IsDeviceReady(&hi2c1, (uint16_t)(i<<1), 2, 2)

    /* Check whether the transaction was successful or it timed-out */
    status = (retryCount)? TRUE: FALSE;

    return status;
}


void Host_LowLevelDelay(uint16 milliseconds)
{
	HAL_Delay((uint32) milliseconds);
}
/* USER CODE END 4 */
/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
	  /* USER CODE BEGIN Error_Handler_Debug */
	  HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_RESET);
	  while(1)
	  {
	    HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
	    HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);
	    HAL_Delay(100);
	  }


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
