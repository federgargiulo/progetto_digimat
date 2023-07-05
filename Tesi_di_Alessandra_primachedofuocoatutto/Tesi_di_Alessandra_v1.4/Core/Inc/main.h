/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define PRESS_DRDY_Pin GPIO_PIN_12
#define PRESS_DRDY_GPIO_Port GPIOG
#define ACC_CK_Pin GPIO_PIN_3
#define ACC_CK_GPIO_Port GPIOB
#define ENV_SD_Pin GPIO_PIN_7
#define ENV_SD_GPIO_Port GPIOB
#define MIC_SD_Pin GPIO_PIN_3
#define MIC_SD_GPIO_Port GPIOI
#define HUM_TEMP_DRDY_Pin GPIO_PIN_11
#define HUM_TEMP_DRDY_GPIO_Port GPIOG
#define ACC_SI_Pin GPIO_PIN_5
#define ACC_SI_GPIO_Port GPIOB
#define ENV_CK_Pin GPIO_PIN_8
#define ENV_CK_GPIO_Port GPIOB
#define MEM_W_Pin GPIO_PIN_6
#define MEM_W_GPIO_Port GPIOI
#define MEM_SO_Pin GPIO_PIN_5
#define MEM_SO_GPIO_Port GPIOE
#define MIC_CK_Pin GPIO_PIN_1
#define MIC_CK_GPIO_Port GPIOI
#define COM_TX_Pin GPIO_PIN_12
#define COM_TX_GPIO_Port GPIOC
#define COM_RX_Pin GPIO_PIN_2
#define COM_RX_GPIO_Port GPIOD
#define USER_LED_Pin GPIO_PIN_5
#define USER_LED_GPIO_Port GPIOD
#define ACC_SO_Pin GPIO_PIN_4
#define ACC_SO_GPIO_Port GPIOB
#define MEM_HOLD_Pin GPIO_PIN_5
#define MEM_HOLD_GPIO_Port GPIOI
#define SWDIO_Pin GPIO_PIN_13
#define SWDIO_GPIO_Port GPIOA
#define SWCLK_Pin GPIO_PIN_14
#define SWCLK_GPIO_Port GPIOA
#define MEM_CS_Pin GPIO_PIN_4
#define MEM_CS_GPIO_Port GPIOI
#define MEM_SI_Pin GPIO_PIN_6
#define MEM_SI_GPIO_Port GPIOE
#define MEM_CK_Pin GPIO_PIN_2
#define MEM_CK_GPIO_Port GPIOE
#define ACC_INT2_Pin GPIO_PIN_4
#define ACC_INT2_GPIO_Port GPIOG
#define ACC_INT1_Pin GPIO_PIN_3
#define ACC_INT1_GPIO_Port GPIOG
#define ACC_CS_Pin GPIO_PIN_2
#define ACC_CS_GPIO_Port GPIOG
#define SMBDATA_Pin GPIO_PIN_0
#define SMBDATA_GPIO_Port GPIOF
#define SMBALERT_Pin GPIO_PIN_2
#define SMBALERT_GPIO_Port GPIOF
#define SMBCLK_Pin GPIO_PIN_1
#define SMBCLK_GPIO_Port GPIOF
#define AUX_IO_Pin GPIO_PIN_4
#define AUX_IO_GPIO_Port GPIOF
#define IOLINK_COM_TX_Pin GPIO_PIN_2
#define IOLINK_COM_TX_GPIO_Port GPIOA
#define IOLINK_OL_Pin GPIO_PIN_8
#define IOLINK_OL_GPIO_Port GPIOE
#define IOLINK_OL_EXTI_IRQn EXTI9_5_IRQn
#define IOLINK_EN_DIAG_Pin GPIO_PIN_7
#define IOLINK_EN_DIAG_GPIO_Port GPIOE
#define IOLINK_EN_DIAG_EXTI_IRQn EXTI9_5_IRQn
#define PB1_Pin GPIO_PIN_1
#define PB1_GPIO_Port GPIOB
#define IOLINK_COM_RX_Pin GPIO_PIN_3
#define IOLINK_COM_RX_GPIO_Port GPIOA
#define PB0_Pin GPIO_PIN_0
#define PB0_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */
#define DIM 2000
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
