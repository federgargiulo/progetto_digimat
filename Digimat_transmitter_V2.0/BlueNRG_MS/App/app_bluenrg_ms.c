/**
 ******************************************************************************
 * @file    app_bluenrg_ms.c
 * @author  SRA Application Team
 * @brief   BlueNRG-M0 initialization and applicative code
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

/* Includes ------------------------------------------------------------------*/
#include "app_bluenrg_ms.h"

#include "hci_tl.h"
#include "sample_service.h"
#include "role_type.h"
#include "bluenrg_utils.h"
#include "bluenrg_gatt_server.h"
#include "bluenrg_gap_aci.h"
#include "bluenrg_gatt_aci.h"
#include "bluenrg_hal_aci.h"

/* USER CODE BEGIN Includes */
#include "iks01a3_motion_sensors.h"
#include "iks01a3_motion_sensors_ex.h"
#include "iks01a3_env_sensors.h"
#include "iks01a3_env_sensors_ex.h"
#define ARM_MATH_CM4
#include "arm_math.h"
#include <stdio.h>
#include <stdlib.h>

typedef enum
{
	Bearing_Healthy       = 0x01U,
	Bearing_Broken    = 0x00U
} Stato_cuscinetto;

/* USER CODE END Includes */

/* Private defines -----------------------------------------------------------*/
/**
 * Define the role here only if it is not already defined in the project options
 * For the CLIENT_ROLE comment the line below
 * For the SERVER_ROLE uncomment the line below
 */
//#define SERVER_ROLE

#define BDADDR_SIZE 6

/* Private macros ------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
uint8_t bnrg_expansion_board = IDB04A1; /* at startup, suppose the X-NUCLEO-IDB04A1 is used */
static volatile uint8_t user_button_init_state = 1;
static volatile uint8_t user_button_pressed = 0;

#ifdef SERVER_ROLE
BLE_RoleTypeDef BLE_Role = SERVER;
#else
BLE_RoleTypeDef BLE_Role = CLIENT;
#endif

extern volatile uint8_t set_connectable;
extern volatile int     connected;
extern volatile uint8_t notification_enabled;

extern volatile uint8_t end_read_tx_char_handle;
extern volatile uint8_t end_read_rx_char_handle;
extern volatile fine;


/* USER CODE BEGIN PV */

volatile float angolo;
extern float misure_temperatura;
extern float misure_umidita;
extern uint8_t acquisizione_da_inviare;
uint8_t contatore_invii=0;
#define DIM 2048
#define SAMPLES                    DIM             /* 256 real party and 256 imaginary parts */
#define FFT_SIZE                SAMPLES / 2        /* FFT size is always the same size as we have samples, so 256 in our case */
extern IKS01A3_MOTION_SENSOR_Axes_t misure_accelerometro[DIM];

extern int conteggio_campioni;
extern float32_t fft_in_buf_cplx [SAMPLES];
extern  float32_t fft_in_buf_real [SAMPLES];
extern float32_t fft_out_buf_real[FFT_SIZE];
extern float32_t fft_out_buf_comp[FFT_SIZE];
double psd_out_buf_x[FFT_SIZE];
double psd_out_buf_y[FFT_SIZE];
double psd_out_buf_z[FFT_SIZE];
double sum_psd_out_buf_x;
double sum_psd_out_buf_y;
double sum_psd_out_buf_z;
extern arm_rfft_fast_instance_f32 fft_handler;
extern arm_cfft_radix4_instance_f32 fft_handler_cplx;
extern float32_t maxValue;                /* Max FFT value is stored here */
extern uint32_t maxIndex;                /* Index in Output array where max value is */
extern TIM_HandleTypeDef htim3;
Stato_cuscinetto cuscinetto;


/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
static void User_Process(void);
static void User_Init(void);

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

#if PRINT_CSV_FORMAT
extern volatile uint32_t ms_counter;
/**
 * @brief  This function is a utility to print the log time
 *         in the format HH:MM:SS:MSS (DK GUI time format)
 * @param  None
 * @retval None
 */
void print_csv_time(void){
	uint32_t ms = HAL_GetTick();
	PRINT_CSV("%02ld:%02ld:%02ld.%03ld", (long)(ms/(60*60*1000)%24), (long)(ms/(60*1000)%60), (long)((ms/1000)%60), (long)(ms%1000));
}
#endif

void MX_BlueNRG_MS_Init(void)
{
	/* USER CODE BEGIN SV */

	/* USER CODE END SV */

	/* USER CODE BEGIN BlueNRG_MS_Init_PreTreatment */

	/* USER CODE END BlueNRG_MS_Init_PreTreatment */

	/* Initialize the peripherals and the BLE Stack */
	uint8_t CLIENT_BDADDR[] = {0xbb, 0x00, 0x00, 0xE1, 0x80, 0x02};
	uint8_t SERVER_BDADDR[] = {0xaa, 0x00, 0x00, 0xE1, 0x80, 0x02};
	uint8_t bdaddr[BDADDR_SIZE];
	uint16_t service_handle, dev_name_char_handle, appearance_char_handle;

	uint8_t  hwVersion;
	uint16_t fwVersion;
	int ret;

	User_Init();

	/* Get the User Button initial state */
	user_button_init_state = BSP_PB_GetState(BUTTON_KEY);

	hci_init(user_notify, NULL);

	/* get the BlueNRG HW and FW versions */
	getBlueNRGVersion(&hwVersion, &fwVersion);

	/*
	 * Reset BlueNRG again otherwise we won't
	 * be able to change its MAC address.
	 * aci_hal_write_config_data() must be the first
	 * command after reset otherwise it will fail.
	 */
	hci_reset();

	HAL_Delay(100);

	printf("HWver %d, FWver %d\n", hwVersion, fwVersion);

	if (hwVersion > 0x30) { /* X-NUCLEO-IDB05A1 expansion board is used */
		bnrg_expansion_board = IDB05A1;
	}

	if (BLE_Role == CLIENT) {
		BLUENRG_memcpy(bdaddr, CLIENT_BDADDR, sizeof(CLIENT_BDADDR));
	} else {
		BLUENRG_memcpy(bdaddr, SERVER_BDADDR, sizeof(SERVER_BDADDR));
	}

	ret = aci_hal_write_config_data(CONFIG_DATA_PUBADDR_OFFSET,
			CONFIG_DATA_PUBADDR_LEN,
			bdaddr);
	if (ret) {
		printf("Setting BD_ADDR failed 0x%02x.\n", ret);
	}

	ret = aci_gatt_init();
	if (ret) {
		printf("GATT_Init failed.\n");
	}

	if (BLE_Role == SERVER) {
		if (bnrg_expansion_board == IDB05A1) {
			ret = aci_gap_init_IDB05A1(GAP_PERIPHERAL_ROLE_IDB05A1, 0, 0x07, &service_handle, &dev_name_char_handle, &appearance_char_handle);
		}
		else {
			ret = aci_gap_init_IDB04A1(GAP_PERIPHERAL_ROLE_IDB04A1, &service_handle, &dev_name_char_handle, &appearance_char_handle);
		}
	}
	else {
		if (bnrg_expansion_board == IDB05A1) {
			ret = aci_gap_init_IDB05A1(GAP_CENTRAL_ROLE_IDB05A1, 0, 0x07, &service_handle, &dev_name_char_handle, &appearance_char_handle);
		}
		else {
			ret = aci_gap_init_IDB04A1(GAP_CENTRAL_ROLE_IDB04A1, &service_handle, &dev_name_char_handle, &appearance_char_handle);
		}
	}

	if (ret != BLE_STATUS_SUCCESS) {
		printf("GAP_Init failed.\n");
	}

	ret = aci_gap_set_auth_requirement(MITM_PROTECTION_REQUIRED,
			OOB_AUTH_DATA_ABSENT,
			NULL,
			7,
			16,
			USE_FIXED_PIN_FOR_PAIRING,
			123456,
			BONDING);
	if (ret == BLE_STATUS_SUCCESS) {
		printf("BLE Stack Initialized.\n");
	}

	if (BLE_Role == SERVER) {
		printf("SERVER: BLE Stack Initialized\n");
		ret = Add_Sample_Service();

		if (ret == BLE_STATUS_SUCCESS)
			printf("Service added successfully.\n");
		else
			printf("Error while adding service.\n");

	} else {
		printf("CLIENT: BLE Stack Initialized\n");
	}

	/* Set output power level */
	ret = aci_hal_set_tx_power_level(1,4);

	/* USER CODE BEGIN BlueNRG_MS_Init_PostTreatment */

	/* USER CODE END BlueNRG_MS_Init_PostTreatment */
}

/*
 * BlueNRG-MS background task
 */
void MX_BlueNRG_MS_Process(void)
{
	/* USER CODE BEGIN BlueNRG_MS_Process_PreTreatment */

	/* USER CODE END BlueNRG_MS_Process_PreTreatment */

	User_Process();
	hci_user_evt_proc();

	/* USER CODE BEGIN BlueNRG_MS_Process_PostTreatment */

	/* USER CODE END BlueNRG_MS_Process_PostTreatment */
}

/**
 * @brief  Initialize User process.
 *
 * @param  None
 * @retval None
 */
static void User_Init(void)
{
	BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_EXTI);
	BSP_LED_Init(LED2);

	BSP_COM_Init(COM1);
}

/**
 * @brief  Configure the device as Client or Server and manage the communication
 *         between a client and a server.
 *
 * @param  None
 * @retval None
 */
static void User_Process(void)
{
	if (set_connectable)
	{
		/* Establish connection with remote device */
		Make_Connection();
		HAL_TIM_Base_Start_IT(&htim3);

		set_connectable = FALSE;
		user_button_init_state = BSP_PB_GetState(BUTTON_KEY);
	}

	if (BLE_Role == CLIENT)
	{
		/* Start TX handle Characteristic dynamic discovery if not yet done */
		if (connected && !end_read_tx_char_handle){
			startReadTXCharHandle();
		}
		/* Start RX handle Characteristic dynamic discovery if not yet done */
		else if (connected && !end_read_rx_char_handle){
			startReadRXCharHandle();
		}

		if (connected && end_read_tx_char_handle && end_read_rx_char_handle && !notification_enabled)
		{
			BSP_LED_Off(LED2); //end of the connection and chars discovery phase
			enableNotification();
		}
	}

	/* Check if the User Button has been pushed */
	if (user_button_pressed || acquisizione_da_inviare)
	{
		/* Debouncing */
		//		HAL_Delay(50);

		/* Wait until the User Button is released */
		//		while (BSP_PB_GetState(BUTTON_KEY) == !user_button_init_state);

		/* Debouncing */
		//		HAL_Delay(50);

		//		if (connected && notification_enabled)
		//		{
		//			/* Send a toggle command to the remote device */
		//			uint8_t data[20] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J'};
		//			sendData(data, sizeof(data));
		//
		//			//BSP_LED_Toggle(LED2);  /* Toggle the LED2 locally. */
		//			/* If uncommented be sure the BSP_LED_Init(LED2)
		//			 * is called in main().
		//			 * E.g. it can be enabled for debugging. */
		//		}
		if (connected && notification_enabled)
		{

			if(conteggio_campioni==0){
				printf("dimensione massima \r\n");
				/******************************************************************************************/
				for (int i = 0; i < SAMPLES; i += 2) {
					fft_in_buf_real[i]=(float32_t)((float32_t)misure_accelerometro[i/2].x);
					//parte immaginaria
					fft_in_buf_real[(i + 1)] = 0;
				}
				arm_cfft_f32(&fft_handler, fft_in_buf_real, 0, 1);
				arm_cmplx_mag_f32(fft_in_buf_real, fft_out_buf_real, FFT_SIZE);
				arm_max_f32(fft_out_buf_real, FFT_SIZE, &maxValue, &maxIndex);
				for (int i = 0; i < FFT_SIZE; i ++) {
					psd_out_buf_x[i]= (double)((float)2000.0/2048.0)* pow(abs(fft_out_buf_real[i]),2);
				}
				sum_psd_out_buf_x=0;
				for (int i = 0; i < FFT_SIZE; i ++) {

					sum_psd_out_buf_x= sum_psd_out_buf_x + psd_out_buf_x[i];
				}
				sum_psd_out_buf_x=sum_psd_out_buf_x/FFT_SIZE;
				/******************************************************************************************/
				/******************************************************************************************/
				for (int i = 0; i < SAMPLES; i += 2) {
					fft_in_buf_real[i]=(float32_t)((float32_t)misure_accelerometro[i/2].y);
					//parte immaginaria
					fft_in_buf_real[(i + 1)] = 0;
				}
				arm_cfft_f32(&fft_handler, fft_in_buf_real, 0, 1);
				arm_cmplx_mag_f32(fft_in_buf_real, fft_out_buf_real, FFT_SIZE);
				arm_max_f32(fft_out_buf_real, FFT_SIZE, &maxValue, &maxIndex);
				for (int i = 0; i < FFT_SIZE; i ++) {
					psd_out_buf_y[i]= (double)((float)2000.0/2048.0)* pow(abs(fft_out_buf_real[i]),2);
				}
				sum_psd_out_buf_y=0;
				for (int i = 0; i < FFT_SIZE; i ++) {

					sum_psd_out_buf_y= sum_psd_out_buf_y + psd_out_buf_y[i];
				}
				sum_psd_out_buf_y=sum_psd_out_buf_y/FFT_SIZE;
				/******************************************************************************************/
				/******************************************************************************************/
				for (int i = 0; i < SAMPLES; i += 2) {
					fft_in_buf_real[i]=(float32_t)((float32_t)misure_accelerometro[i/2].z);
					//parte immaginaria
					fft_in_buf_real[(i + 1)] = 0;
				}
				arm_cfft_f32(&fft_handler, fft_in_buf_real, 0, 1);
				arm_cmplx_mag_f32(fft_in_buf_real, fft_out_buf_real, FFT_SIZE);
				arm_max_f32(fft_out_buf_real, FFT_SIZE, &maxValue, &maxIndex);
				for (int i = 0; i < FFT_SIZE; i ++) {
					psd_out_buf_z[i]= (double)((float)2000.0/2048.0)* pow(abs(fft_out_buf_real[i]),2);
				}
				sum_psd_out_buf_z=0;
				for (int i = 0; i < FFT_SIZE; i ++) {

					sum_psd_out_buf_z= sum_psd_out_buf_z + psd_out_buf_z[i];
				}
				sum_psd_out_buf_z=sum_psd_out_buf_z/FFT_SIZE;
				/******************************************************************************************/

				if(sum_psd_out_buf_y<10000.0)
					cuscinetto=Bearing_Broken;
				else cuscinetto=Bearing_Healthy;

				/******************************************************************************************/
				IKS01A3_ENV_SENSOR_GetValue(IKS01A3_STTS751_0, ENV_TEMPERATURE, &misure_temperatura);
				IKS01A3_ENV_SENSOR_GetValue(IKS01A3_HTS221_0, ENV_HUMIDITY, &misure_umidita);
				acquisizione_da_inviare=0;
				HAL_TIM_Base_Start_IT(&htim3);
				conteggio_campioni=0;
				fine=0;
			}

			uint8_t data[20];
			sprintf((char *)data, "%d,%.2f,%.2f,%.2f#",cuscinetto, misure_temperatura, misure_umidita, angolo);
			sendData(data, sizeof(data));
			printf("\nAngolo: %f\r\n", angolo);
			//				sprintf((char *)data, ",%f\r\n", misure_temperatura);
			//				sendData(data, sizeof(data));
			contatore_invii++;

		}

		/* Reset the User Button flag */
		user_button_pressed = 0;

		/*RESET SISTEMA A 30 INVII, CIRCA 30 SECONDI */
		if(contatore_invii>30) HAL_NVIC_SystemReset();
	}



	/* USER CODE BEGIN DIGIMAT CODE */

	//#ifndef SERVER_ROLE
	//	if (connected && notification_enabled)
	//	{
	//		uint8_t data[50] = {0};
	//		sprintf((char *)data, "%ld,%ld,%ld,%f",misure_accelerometro.x, misure_accelerometro.y, misure_accelerometro.z, misure_temperatura);
	//		sendData(data, sizeof(data));
	//	}
	//#endif
	/* USER CODE END DIGIMAT CODE */
}

/**
 * @brief  BSP Push Button callback
 * @param  Button Specifies the pin connected EXTI line
 * @retval None.
 */
void BSP_PB_Callback(Button_TypeDef Button)
{
	/* Set the User Button flag */
	user_button_pressed = 1;
}
