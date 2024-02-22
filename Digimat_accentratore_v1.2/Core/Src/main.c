/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "app_bluenrg_ms.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>

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
TIM_HandleTypeDef htim3;

UART_HandleTypeDef huart1;
UART_HandleTypeDef huart6;

/* USER CODE BEGIN PV */
//
//uint8_t response[16];
//char c;
//
//char* msg1 = {"AT"};
//char* msg_rst = {"ATZ"};
////char* msg_at_appeui = {"AT+APPEUI"};
////char* msg_at_verbose = {"AT+VERB=1"};
//char* msg_ate = {"ATE=1"};
//
//
////char* msg2 = {"AT+APPEUI=0000000000000001"};
////char* msg3 = {"AT+AK=00000000000000000000000000000001"};
//char* msg2 = {"AT+APPEUI=1234567890ABCDEF"};
//char* msg3 = {"AT+AK=1234567890ABCDEF1234567890ABCDEF"};
//char* msg9 = {"AT+JRX1DT=5000"};
//char* msg10 = {"AT+JRX2DT=10000"};
//char* msg4 = {"AT+JOIN=1"};
//char* msg5 = {"AT+SEND=15,23062023,0"};
//char* msg_ascii = {"AT+SEND=15,303132,0"};
//char* msg6 = {"AT+BAND=0"};
//char msg7[64];
//char msg8[120];
//short int i;
//uint8_t risposta_uart[50];
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_USART6_UART_Init(void);
static void MX_TIM3_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
//void modem_at_cmd(char* buffer, int n){
//
//	for(uint8_t i=0; i<n; i++) {
//		HAL_UART_Transmit(&huart1, (uint8_t*) buffer+i, 1, 100);
//		//printf("tx: %c\n",buffer[i]);
//		HAL_UART_Receive(&huart1, &c, 1, 100);
//		//printf("rx: %c\n",c);
//	}
//
//	//	memset(response,0,sizeof(response));
//	char tredici='\r';
//	HAL_UART_Transmit(&huart1, (uint8_t*) &tredici, 1, 100);
//	//	printf("tx: %c\n",tredici);
//	HAL_UART_Receive(&huart1, &c, 1, 100);
//	//	printf("rx: %c\n",c);
//	int i=0;
//	memset(risposta_uart,0,sizeof(risposta_uart));
//	do {
//		//		if (lora.readable()) {
//		HAL_UART_Receive(&huart1,(uint8_t *) &c, 1, 100);
//		//printf("rx: %c",c);
//		risposta_uart[i]=c;
//		i++;
//
//		//	} while(c!='#' && c!='\r'&& c!=' ' && c!='\n');
//	} while(c!=' ');
//	printf("%s",risposta_uart);
//}
//
//HAL_StatusTypeDef wait4join(){
//	memset(risposta_uart,0,sizeof(risposta_uart));
//	HAL_StatusTypeDef timeout_expired;
//	do {
//		//		if(HAL_UART_Receive(&huart1, (uint8_t *) &response, 1, 100)){
//		//			//        if (lora.readable()) {
//		//
//		//			printf("response: %s\n",response);
//		//		}
//		timeout_expired=HAL_UART_Receive(&huart1,(uint8_t *) &c, 1, 6000);
////		printf("timeout_expried=%d\n\r",timeout_expired);
//		printf("la risposta e: %c\n\r",c);
//		if(timeout_expired==HAL_TIMEOUT){
//			printf("Join fallito per timeout\n\r");
//			return HAL_TIMEOUT;
//		}
//		risposta_uart[i]=c;
//		i++;
//
//	}while(c!='d');
//
//	return HAL_OK;
//}

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
	MX_USART1_UART_Init();
	MX_USART6_UART_Init();
	MX_TIM3_Init();
	MX_BlueNRG_MS_Init();
	/* USER CODE BEGIN 2 */
	//	HAL_Delay(2000);
	//	printf("Test seriale no pc\r\n");
//	modem_at_cmd(msg1,(int)strlen(msg1));
//	printf("Inviato AT\r\n");
//	HAL_Delay(1000);
//	//	//	printf("Verbose\r\n");
//	//	//  	modem_at_cmd(msg_at_verbose,(int)strlen(msg_at_verbose));
//	//	//	printf("Verbose attivato\r\n");
//	//
//	//
//	//
//	HAL_Delay(1000);
//	modem_at_cmd(msg6,(int)strlen(msg6));
//	printf("Inviato band\r\n");
//
//
//	HAL_Delay(1000);
//	modem_at_cmd(msg2,(int)strlen(msg2));
//	printf("Inviato EUI\r\n");
//	HAL_Delay(1000);
//
//	//	HAL_Delay(1000);
//	//	modem_at_cmd(msg_at_appeui,(int)strlen(msg_at_appeui));
//	//	printf("Inviato band\r\n");
//
//
//	modem_at_cmd(msg3,(int)strlen(msg3));
//	printf("Inviato AK\r\n");
//	HAL_Delay(1000);
//	modem_at_cmd("AT+DC=0",7);
//	printf("Disabled DUTY Cycle\r\n");
//	HAL_Delay(1000);
////	modem_at_cmd("AT+ADR=1",8);
////	printf("Enabled ADR\r\n");
////	HAL_Delay(1000);
//	//	    modem_at_cmd(msg9,(int)strlen(msg9));
//	//		  	    printf("Inviato JOIN Delay RX1\r\n");
//	//		  	    modem_at_cmd(msg10,(int)strlen(msg10));
//	//		  	    printf("Inviato JOIN Delay RX2\r\n");
//	//		  	modem_at_cmd(msg4,(int)strlen(msg4));
//	//
//	//	printf("Inviato JOIN\r\n");
//	//	HAL_Delay(1000);
//	//	wait4join();
//	//	HAL_Delay(1000);
//	//	//	modem_at_cmd(msg5,(int)strlen(msg5));
//	//	//	printf("Inviato send\r\n");
//	//	HAL_Delay(1000);
//	//	modem_at_cmd(msg_ascii,(int)strlen(msg_ascii));
//	//	printf("Inviato send msg_not_ascii\r\n");
//	//
//
//	do{
//			modem_at_cmd(msg4,(int)strlen(msg4));
//			printf("Inviato JOIN\r\n");
//			HAL_Delay(100);
//		}
//		while (HAL_OK!=wait4join());
//	printf("wait 4 JOIN completato\r\n");
//
//
//	printf("Initialization..\r\n");

	HAL_GPIO_WritePin(GNSS_RST_GPIO_Port, GNSS_RST_Pin, 0);
	HAL_Delay(1);
	HAL_GPIO_WritePin(GNSS_RST_GPIO_Port, GNSS_RST_Pin, 1);

//	HAL_TIM_Base_Start_IT(&htim3);

	/* USER CODE END 2 */

	/* Infinite loop */
	/* USER CODE BEGIN WHILE */
	while (1)
	{
		/* USER CODE END WHILE */

		MX_BlueNRG_MS_Process();
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

	/** Configure the main internal regulator output voltage
	 */
	__HAL_RCC_PWR_CLK_ENABLE();
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);

	/** Initializes the RCC Oscillators according to the specified parameters
	 * in the RCC_OscInitTypeDef structure.
	 */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
	RCC_OscInitStruct.PLL.PLLM = 16;
	RCC_OscInitStruct.PLL.PLLN = 336;
	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
	RCC_OscInitStruct.PLL.PLLQ = 7;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
	{
		Error_Handler();
	}

	/** Initializes the CPU, AHB and APB buses clocks
	 */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
			|RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
	{
		Error_Handler();
	}
}

/**
 * @brief TIM3 Initialization Function
 * @param None
 * @retval None
 */
static void MX_TIM3_Init(void)
{

	/* USER CODE BEGIN TIM3_Init 0 */

	/* USER CODE END TIM3_Init 0 */

	TIM_ClockConfigTypeDef sClockSourceConfig = {0};
	TIM_MasterConfigTypeDef sMasterConfig = {0};

	/* USER CODE BEGIN TIM3_Init 1 */

	/* USER CODE END TIM3_Init 1 */
	htim3.Instance = TIM3;
	htim3.Init.Prescaler = 42000-1;
	htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim3.Init.Period = 20000-1;
	htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
	{
		Error_Handler();
	}
	sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
	if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
	{
		Error_Handler();
	}
	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
	{
		Error_Handler();
	}
	/* USER CODE BEGIN TIM3_Init 2 */

	/* USER CODE END TIM3_Init 2 */

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
	if (HAL_UART_Init(&huart1) != HAL_OK)
	{
		Error_Handler();
	}
	/* USER CODE BEGIN USART1_Init 2 */

	/* USER CODE END USART1_Init 2 */

}

/**
 * @brief USART6 Initialization Function
 * @param None
 * @retval None
 */
static void MX_USART6_UART_Init(void)
{

	/* USER CODE BEGIN USART6_Init 0 */

	/* USER CODE END USART6_Init 0 */

	/* USER CODE BEGIN USART6_Init 1 */

	/* USER CODE END USART6_Init 1 */
	huart6.Instance = USART6;
	huart6.Init.BaudRate = 9600;
	huart6.Init.WordLength = UART_WORDLENGTH_8B;
	huart6.Init.StopBits = UART_STOPBITS_1;
	huart6.Init.Parity = UART_PARITY_NONE;
	huart6.Init.Mode = UART_MODE_TX_RX;
	huart6.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart6.Init.OverSampling = UART_OVERSAMPLING_16;
	if (HAL_UART_Init(&huart6) != HAL_OK)
	{
		Error_Handler();
	}
	/* USER CODE BEGIN USART6_Init 2 */

	/* USER CODE END USART6_Init 2 */

}

/**
 * @brief GPIO Initialization Function
 * @param None
 * @retval None
 */
static void MX_GPIO_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	/* USER CODE BEGIN MX_GPIO_Init_1 */
	/* USER CODE END MX_GPIO_Init_1 */

	/* GPIO Ports Clock Enable */
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOH_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1|GPIO_PIN_8|GPIO_PIN_9, GPIO_PIN_RESET);

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GNSS_RST_GPIO_Port, GNSS_RST_Pin, GPIO_PIN_RESET);

	/*Configure GPIO pin : PA0 */
	GPIO_InitStruct.Pin = GPIO_PIN_0;
	GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	/*Configure GPIO pins : PA1 PA8 PA9 */
	GPIO_InitStruct.Pin = GPIO_PIN_1|GPIO_PIN_8|GPIO_PIN_9;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	/*Configure GPIO pin : GNSS_RST_Pin */
	GPIO_InitStruct.Pin = GNSS_RST_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GNSS_RST_GPIO_Port, &GPIO_InitStruct);

	/* EXTI interrupt init*/
	HAL_NVIC_SetPriority(EXTI0_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(EXTI0_IRQn);

	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

	/* USER CODE BEGIN MX_GPIO_Init_2 */
	/* USER CODE END MX_GPIO_Init_2 */
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
