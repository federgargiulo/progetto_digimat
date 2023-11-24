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
extern UART_HandleTypeDef huart1;
#include <stdio.h>
/* USER CODE END Includes */

/* Private defines -----------------------------------------------------------*/
/**
 * Define the role here only if it is not already defined in the project options
 * For the CLIENT_ROLE comment the line below
 * For the SERVER_ROLE uncomment the line below
 */
#define SERVER_ROLE

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

/* USER CODE BEGIN PV */
char c;
uint8_t response[16];
char* msg1 = {"AT"};
char* msg_rst = {"ATZ"};
//char* msg_at_appeui = {"AT+APPEUI"};
//char* msg_at_verbose = {"AT+VERB=1"};
char* msg_ate = {"ATE=1"};


//char* msg2 = {"AT+APPEUI=0000000000000001"};
//char* msg3 = {"AT+AK=00000000000000000000000000000001"};
char* msg2 = {"AT+APPEUI=1234567890ABCDEF"};
char* msg3 = {"AT+AK=1234567890ABCDEF1234567890ABCDEF"};
char* msg9 = {"AT+JRX1DT=5000"};
char* msg10 = {"AT+JRX2DT=10000"};
char* msg4 = {"AT+JOIN=1"};
char* msg5 = {"AT+SEND=15,23062023,0"};
char* msg_ascii = {"AT+SEND=15,303132,0"};
char* msg6 = {"AT+BAND=0"};
char msg7[64];
char msg8[120];
short int i;
uint8_t risposta_uart[50];
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
void modem_at_cmd(char* buffer, int n){

	for(uint8_t i=0; i<n; i++) {
		HAL_UART_Transmit(&huart1, (uint8_t*) buffer+i, 1, 100);
		//printf("tx: %c\n",buffer[i]);
		HAL_UART_Receive(&huart1, &c, 1, 100);
		//printf("rx: %c\n",c);
	}

	//	memset(response,0,sizeof(response));
	char tredici='\r';
	HAL_UART_Transmit(&huart1, (uint8_t*) &tredici, 1, 100);
	//	printf("tx: %c\n",tredici);
	HAL_UART_Receive(&huart1, &c, 1, 100);
	//	printf("rx: %c\n",c);
	int i=0;
	memset(risposta_uart,0,sizeof(risposta_uart));
	do {
		//		if (lora.readable()) {
		HAL_UART_Receive(&huart1,(uint8_t *) &c, 1, 100);
		//printf("rx: %c",c);
		risposta_uart[i]=c;
		i++;

		//	} while(c!='#' && c!='\r'&& c!=' ' && c!='\n');
	} while(c!=' ');
	printf("%s",risposta_uart);
}

void wait4join(){
	memset(risposta_uart,0,sizeof(risposta_uart));
	do {
		//		if(HAL_UART_Receive(&huart1, (uint8_t *) &response, 1, 100)){
		//			//        if (lora.readable()) {
		//
		//			printf("response: %s\n",response);
		//		}
		HAL_UART_Receive(&huart1,(uint8_t *) &c, 1, 100);
		//		printf("rx: %c",c);
		risposta_uart[i]=c;
		i++;
	}while(c!='d');
}

void lora_join(){
	printf("Test seriale no pc\r\n");
	modem_at_cmd(msg1,(int)strlen(msg1));
	printf("Inviato AT\r\n");
	HAL_Delay(1000);
	//	printf("Verbose\r\n");
	//  	modem_at_cmd(msg_at_verbose,(int)strlen(msg_at_verbose));
	//	printf("Verbose attivato\r\n");



	HAL_Delay(1000);
	modem_at_cmd(msg6,(int)strlen(msg6));
	printf("Inviato band\r\n");


	HAL_Delay(1000);
	modem_at_cmd(msg2,(int)strlen(msg2));
	printf("Inviato EUI\r\n");
	HAL_Delay(1000);

	//	HAL_Delay(1000);
	//	modem_at_cmd(msg_at_appeui,(int)strlen(msg_at_appeui));
	//	printf("Inviato band\r\n");


	modem_at_cmd(msg3,(int)strlen(msg3));
	printf("Inviato AK\r\n");
	HAL_Delay(1000);
	modem_at_cmd("AT+DC=0",7);
	printf("Disabled DUTY Cycle\r\n");
	//	HAL_Delay(1000);
	//	modem_at_cmd("AT+ADR=1",8);
	//  	printf("Enabled ADR\r\n");
	//	    modem_at_cmd(msg9,(int)strlen(msg9));
	//		  	    printf("Inviato JOIN Delay RX1\r\n");
	//		  	    modem_at_cmd(msg10,(int)strlen(msg10));
	//		  	    printf("Inviato JOIN Delay RX2\r\n");
	modem_at_cmd(msg4,(int)strlen(msg4));

	printf("Inviato JOIN\r\n");
	HAL_Delay(1000);
	wait4join();
	HAL_Delay(1000);
	printf("Inzialization done\r\n");
//	modem_at_cmd(msg_ascii,(int)strlen(msg_ascii));
//	printf("Inviato msg_ascii\r\n");
	//	HAL_Delay(1000);
}

void lora_send(char * msg_ascii){
	modem_at_cmd(msg_ascii,(int)strlen(msg_ascii));
	printf("Inviato send msg_not_ascii\r\n");
}
static void User_Process(void)
{
	if (set_connectable)
	{
		/* Establish connection with remote device */
		Make_Connection();
		lora_join();
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
	if (user_button_pressed)
	{
		/* Debouncing */
		HAL_Delay(50);

		/* Wait until the User Button is released */
		while (BSP_PB_GetState(BUTTON_KEY) == !user_button_init_state);

		/* Debouncing */
		HAL_Delay(50);

		if (connected && notification_enabled)
		{
			/* Send a toggle command to the remote device */
			//  uint8_t data[20] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J'};
			//sendData(data, sizeof(data));

//			lora_join();

//			printf("Initialization..\r\n");
			//BSP_LED_Toggle(LED2);  /* Toggle the LED2 locally. */
			/* If uncommented be sure the BSP_LED_Init(LED2)
			 * is called in main().
			 * E.g. it can be enabled for debugging. */
		}

		/* Reset the User Button flag */
		user_button_pressed = 0;
	}
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
