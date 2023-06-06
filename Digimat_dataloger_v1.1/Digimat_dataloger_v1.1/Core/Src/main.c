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
#include "fatfs.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "iks01a3_motion_sensors.h"
#include "iks01a3_motion_sensors_ex.h"

//#include "custom_mems_conf.h"
//#include "lsm6dso.h"


#include "fatfs_sd.h"
#include "string.h"
#include "stdio.h"

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

TIM_HandleTypeDef htim3;

UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */
volatile IKS01A3_MOTION_SENSOR_Axes_t misure_accelerometro[DIM];
volatile int contatore_acquisizioni=0;

uint8_t stringa[]="prova funzione";
uint32_t tempo=0;

float result;
//
//LSM6DSO_IO_t bus_accelerometro;
//LSM6DSO_Object_t accelerometro;
//LSM6DSO_Axes_t misure_accelerometro;

int acquisizione=0;
uint8_t nome_file[30];

typedef enum enum_stato_data_logger{
	WAIT_FOR_START=0,
	WAIT_FOR_OPEN_FILE,
	WAIT_FOR_STOP,
	WAIT_FOR_CLOSE_FILE

} stato_data_logger_t;

stato_data_logger_t stato_data_logger;


/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_SPI1_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_TIM3_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

FATFS fs;  // file system
FIL fil; // File
FILINFO fno;
FRESULT fresult;  // result
UINT br, bw;  // File read/write count

/**** capacity related *****/
volatile FATFS *pfs;
volatile DWORD fre_clust;
volatile uint32_t total, free_space;

#define BUFFER_SIZE 512
volatile char buffer[BUFFER_SIZE];  // to store strings..

int i=0;

int bufsize (char *buf)
{
	int i=0;
	while (*buf++ != '\0') i++;
	return i;
}

void clear_buffer (void)
{
	for (int i=0; i<BUFFER_SIZE; i++) buffer[i] = '\0';
}

void send_uart (char *string)
{
	uint8_t len = strlen (string);
	HAL_UART_Transmit(&huart2, (uint8_t *) string, len, HAL_MAX_DELAY);  // transmit in blocking mode
}


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
	MX_SPI1_Init();
	MX_USART2_UART_Init();
	MX_FATFS_Init();
	MX_TIM3_Init();
	/* USER CODE BEGIN 2 */

	HAL_Delay (500);
	//	bus_accelerometro.Init=BSP_I2C1_Init;
	//	bus_accelerometro.DeInit=BSP_I2C1_DeInit;
	//	bus_accelerometro.ReadReg=BSP_I2C1_ReadReg;
	//	bus_accelerometro.WriteReg=BSP_I2C1_WriteReg;
	//	bus_accelerometro.Address=LSM6DSO_I2C_ADD_H;
	//
	//	LSM6DSO_RegisterBusIO(&accelerometro, &bus_accelerometro);
	//	LSM6DSO_Init(&accelerometro);
	//	LSM6DSO_ACC_Enable(&accelerometro);


	//
	//	if (IKS01A3_MOTION_SENSOR_Init(IKS01A3_LSM6DSO_0, MOTION_ACCELERO)==HAL_OK){
	//		IKS01A3_MOTION_SENSOR_Enable(IKS01A3_LSM6DSO_0, MOTION_ACCELERO);
	//	}
	//
	//	//	fresult = f_mount(NULL, "/", 1);
	//	fresult = f_mount(&fs, "/", 1);
	//	if (fresult != FR_OK) send_uart ("ERROR!!! in mounting SD CARD...\n\n");
	//	else send_uart("SD CARD mounted successfully...\n\n");
	//	/* Create second file with read write access and open it */
	//	fresult = f_open(&fil, "file4.txt", FA_CREATE_ALWAYS | FA_WRITE);
	//	IKS01A3_MOTION_SENSOR_GetAxes(IKS01A3_LSM6DSO_0, MOTION_ACCELERO, &misure_accelerometro);
	//	//	LSM6DSO_ACC_GetAxes(&accelerometro, &misure_accelerometro);
	//
	//
	//	sprintf((char *)buffer, "misure x: %ld, misure y: %ld, misure z: %ld ",misure_accelerometro.x, misure_accelerometro.y, misure_accelerometro.z );
	//	//	sprintf((char *)buffer, "misure x:, misure y:, misure z");
	//	tempo= HAL_GetTick();
	//	fresult = f_write(&fil, buffer, bufsize(buffer), &bw);
	//	tempo=HAL_GetTick() -tempo;
	//	/* Close file */
	//	f_close(&fil);
	//	f_sync(&fil);
	//
	//	/* Unmount SDCARD */
	//	fresult = f_mount(NULL, "/", 1);
	//	if (fresult == FR_OK) send_uart ("SD CARD UNMOUNTED successfully...\n");
	//
	//
	//	if(IKS01A3_MOTION_SENSOR_Disable(IKS01A3_LSM6DSO_0, MOTION_ACCELERO)==HAL_OK){
	//		IKS01A3_MOTION_SENSOR_DeInit(IKS01A3_LSM6DSO_0);
	//	}

	/* USER CODE END 2 */

	/* Infinite loop */
	/* USER CODE BEGIN WHILE */
	stato_data_logger= WAIT_FOR_START;
	HAL_TIM_Base_Init(&htim3);
	while (1)
	{
		/* USER CODE END WHILE */

		/* USER CODE BEGIN 3 */

		switch (stato_data_logger){

		case WAIT_FOR_START:

			if(HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin)== GPIO_PIN_RESET){
				stato_data_logger=WAIT_FOR_OPEN_FILE;
				acquisizione=0;
				contatore_acquisizioni=0;
				fresult = f_mount(&fs, "/", 1);
				if (fresult != FR_OK) send_uart ("ERROR!!! in mounting SD CARD...\n\n");
				else send_uart("SD CARD mounted successfully...\n\n");
				if (IKS01A3_MOTION_SENSOR_Init(IKS01A3_LSM6DSO_0, MOTION_ACCELERO)==HAL_OK){
					IKS01A3_MOTION_SENSOR_SetOutputDataRate(IKS01A3_LSM6DSO_0, MOTION_ACCELERO, 3332);
					IKS01A3_MOTION_SENSOR_Enable(IKS01A3_LSM6DSO_0, MOTION_ACCELERO);
					IKS01A3_MOTION_SENSOR_GetOutputDataRate(IKS01A3_LSM6DSO_0, MOTION_ACCELERO, &result);
				}
			}
			break;

		case WAIT_FOR_OPEN_FILE:
			HAL_Delay(10);
			acquisizione++;



			sprintf(nome_file, "acqusizione_%d.txt ",acquisizione);
			fresult = f_open(&fil, nome_file, FA_CREATE_ALWAYS | FA_WRITE);
			send_uart("file creato");
			sprintf((char *)buffer, "X[mg],Y[mg],Z[mg]\r\n");
			fresult = f_write(&fil, buffer, bufsize(buffer), &bw);
			HAL_TIM_Base_Start_IT(&htim3);
			stato_data_logger=WAIT_FOR_STOP;
			break;

		case WAIT_FOR_STOP:
			if(contatore_acquisizioni>=DIM){
				HAL_TIM_Base_Stop_IT(&htim3);
				contatore_acquisizioni=0;
				stato_data_logger=WAIT_FOR_CLOSE_FILE;
			}

			if(HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin)== GPIO_PIN_RESET){
				stato_data_logger=WAIT_FOR_CLOSE_FILE;
				HAL_TIM_Base_Stop_IT(&htim3);
			}

			break;

		case WAIT_FOR_CLOSE_FILE:{
			for(int i=0; i<DIM; i++){
				sprintf((char *)buffer, "%ld,%ld,%ld\r\n",misure_accelerometro[i].x, misure_accelerometro[i].y, misure_accelerometro[i].z );
				fresult = f_write(&fil, buffer, bufsize(buffer), &bw);
			}
			f_close(&fil);
			f_sync(&fil);
			fresult = f_mount(NULL, "/", 1);
			if (fresult == FR_OK)
				send_uart ("SD CARD UNMOUNTED successfully...\n");
			if(IKS01A3_MOTION_SENSOR_Disable(IKS01A3_LSM6DSO_0, MOTION_ACCELERO)==HAL_OK){
				IKS01A3_MOTION_SENSOR_DeInit(IKS01A3_LSM6DSO_0);
			}

			stato_data_logger=WAIT_FOR_START;

			break;
		}
		default:
			break;
		}








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
	hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_128;
	hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
	hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
	hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
	hspi1.Init.CRCPolynomial = 10;
	if (HAL_SPI_Init(&hspi1) != HAL_OK)
	{
		Error_Handler();
	}
	/* USER CODE BEGIN SPI1_Init 2 */

	/* USER CODE END SPI1_Init 2 */

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
	htim3.Init.Prescaler = 84-1;
	htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim3.Init.Period = 1000-1;
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
 * @brief USART2 Initialization Function
 * @param None
 * @retval None
 */
static void MX_USART2_UART_Init(void)
{

	/* USER CODE BEGIN USART2_Init 0 */

	/* USER CODE END USART2_Init 0 */

	/* USER CODE BEGIN USART2_Init 1 */

	/* USER CODE END USART2_Init 1 */
	huart2.Instance = USART2;
	huart2.Init.BaudRate = 115200;
	huart2.Init.WordLength = UART_WORDLENGTH_8B;
	huart2.Init.StopBits = UART_STOPBITS_1;
	huart2.Init.Parity = UART_PARITY_NONE;
	huart2.Init.Mode = UART_MODE_TX_RX;
	huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart2.Init.OverSampling = UART_OVERSAMPLING_16;
	if (HAL_UART_Init(&huart2) != HAL_OK)
	{
		Error_Handler();
	}
	/* USER CODE BEGIN USART2_Init 2 */

	/* USER CODE END USART2_Init 2 */

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
	HAL_GPIO_WritePin(GPIOA, SD_CS_Pin|LD2_Pin, GPIO_PIN_RESET);

	/*Configure GPIO pin : B1_Pin */
	GPIO_InitStruct.Pin = B1_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

	/*Configure GPIO pins : SD_CS_Pin LD2_Pin */
	GPIO_InitStruct.Pin = SD_CS_Pin|LD2_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

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
