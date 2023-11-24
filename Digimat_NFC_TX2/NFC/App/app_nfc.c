
/**
  ******************************************************************************
  * File Name          :  app_nfc.c
  * Description        : This file provides code for the configuration
  *                      of the STMicroelectronics.X-CUBE-NFC4.2.0.1 instances.
  ******************************************************************************
  *
  * COPYRIGHT 2023 STMicroelectronics
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software
  * distributed under the License is distributed on an "AS IS" BASIS,
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  ******************************************************************************
  */

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "app_nfc.h"
#include "main.h"

/* Includes ------------------------------------------------------------------*/
#include "nfc04a1_nfctag.h"

/** @defgroup ST25_Nucleo
  * @{
  */

/** @defgroup Main
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Global variables ----------------------------------------------------------*/
volatile uint8_t GPOActivated = 0;
ST25DV_FIELD_STATUS fieldpresence;

/* Private functions ---------------------------------------------------------*/
void MX_NFC4_GPO_Init(void);
void MX_NFC4_GPO_Process(void);
void BSP_GPO_Callback(void);

void MX_NFC_Init(void)
{
  /* USER CODE BEGIN SV */

  /* USER CODE END SV */

  /* USER CODE BEGIN NFC4_Library_Init_PreTreatment */

  /* USER CODE END NFC4_Library_Init_PreTreatment */

  /* Initialize the peripherals and the NFC4 components */

  MX_NFC4_GPO_Init();

  /* USER CODE BEGIN SV */

  /* USER CODE END SV */

  /* USER CODE BEGIN NFC4_Library_Init_PostTreatment */

  /* USER CODE END NFC4_Library_Init_PostTreatment */
}
/*
 * LM background task
 */
void MX_NFC_Process(void)
{
  /* USER CODE BEGIN NFC4_Library_Process */
	 if( GPOActivated == 1 )
	    {
		 uint32_t return_value= NFC04A1_NFCTAG_GetRFField_Dyn(NFC04A1_NFCTAG_INSTANCE, &fieldpresence );
	 if( fieldpresence == ST25DV_FIELD_ON )
	      {
	        NFC04A1_LED_On( GREEN_LED );
	      }
	      else
	      {
	        NFC04A1_LED_Off( GREEN_LED );
	      }

	    }
  /* USER CODE END NFC4_Library_Process */
}

  /**
  * @brief  Initialize the NFC4 GPO Example
  * @retval None
  */
void MX_NFC4_GPO_Init(void)
{

 const ST25DV_PASSWD st25dv_i2c_password = {.MsbPasswd = 0, .LsbPasswd=0};
  /* Configuration of X-NUCLEO-NFC04A1                                          */
  /******************************************************************************/
  /* Init of the Leds on X-NUCLEO-NFC04A1 board */
  NFC04A1_LED_Init(GREEN_LED );
  NFC04A1_LED_Init(BLUE_LED );
  NFC04A1_LED_Init(YELLOW_LED );
  NFC04A1_LED_On( GREEN_LED );
  HAL_Delay( 300 );
  NFC04A1_LED_On( BLUE_LED );
  HAL_Delay( 300 );
  NFC04A1_LED_On( YELLOW_LED );
  HAL_Delay( 300 );

  /* Init ST25DV driver */
  while( NFC04A1_NFCTAG_Init(NFC04A1_NFCTAG_INSTANCE) != NFCTAG_OK );

  /* Set EXTI settings for GPO Interrupt */
  NFC04A1_GPO_Init();

    /* Present configuration password */
  NFC04A1_NFCTAG_PresentI2CPassword(NFC04A1_NFCTAG_INSTANCE, st25dv_i2c_password );

  /* Set GPO Configuration */
  NFC04A1_NFCTAG_ConfigIT(NFC04A1_NFCTAG_INSTANCE,ST25DV_GPO_ENABLE_MASK | ST25DV_GPO_FIELDCHANGE_MASK );

  /* Init done */
  NFC04A1_LED_Off( GREEN_LED );
  HAL_Delay( 300 );
  NFC04A1_LED_Off( BLUE_LED );
  HAL_Delay( 300 );
  NFC04A1_LED_Off( YELLOW_LED );
  HAL_Delay( 300 );

}

/**
  * @brief  Process of the NFC4 GPO application
  * @retval None
  */
void MX_NFC4_GPO_Process(void)
{

    if( GPOActivated == 1 )
    {
      /* Switch on the GREEN LED according to the field */
      NFC04A1_NFCTAG_GetRFField_Dyn(NFC04A1_NFCTAG_INSTANCE, &fieldpresence );
      if( fieldpresence == ST25DV_FIELD_ON )
      {
        NFC04A1_LED_On( GREEN_LED );
      }
      else
      {
        NFC04A1_LED_Off( GREEN_LED );
      }
      GPOActivated = 0;
    }
}

/**
  * @brief  NFC4 GPO callback
  * @retval None
  */
void BSP_GPO_Callback(void)
{
  /* Prevent unused argument(s) compilation warning */
  GPOActivated = 1;
  /* This function should be implemented by the user application.
     It is called into this driver when an event on Button is triggered. */
}

#ifdef __cplusplus
}
#endif

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
