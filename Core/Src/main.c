/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  *
  *
  *Se modifico el archivo w5500.h por problemas con las interrupciones del sistema utilizando FATFS
  *de: #define IR  a:  #define IR_5500
  *
  *
  *
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "app_fatfs.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "wizchip_conf.h"
#include "socket.h"
#include "ftpd.h"
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

COM_InitTypeDef BspCOMInit;
SPI_HandleTypeDef hspi2;
SPI_HandleTypeDef hspi3;

/* USER CODE BEGIN PV */
FATFS fs;
FATFS *pfs;
FIL fil;
FRESULT fres;
DWORD fre_clust;
uint32_t totalSpace, freeSpace;
char buffer[100];

/*----------------------------PV Puerto Serie ----------------------------------------*/
//sprintf descarta el volatile cuando se pasa por argumento en la funcion
//Volatile hace referencia a que es una variable que se usara dentro de interrupciones
//Static se usa para variables locales dentro del archivo
static char tx_buff[100];
static volatile uint8_t buff_length;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_SPI2_Init(void);
static void MX_SPI3_Init(void);
/* USER CODE BEGIN PFP */

//Ethernet Chip Select
void CS_SEL_FUN(void);
void CS_DES_FUN(void);

void configuracion_IP(void);
uint8_t SPI_Received(void);
void SPI_Transmit(uint8_t TX_Buff);
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
  MX_SPI2_Init();
  if (MX_FATFS_Init() != APP_OK) {
    Error_Handler();
  }
  MX_SPI3_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Initialize led */
  BSP_LED_Init(LED_GREEN);

  /* Initialize USER push-button, will be used to trigger an interrupt each time it's pressed.*/
  BSP_PB_Init(BUTTON_USER, BUTTON_MODE_EXTI);

  /* Initialize COM1 port (115200, 8 bits (7-bit data + 1 stop bit), no parity */
  BspCOMInit.BaudRate   = 115200;
  BspCOMInit.WordLength = COM_WORDLENGTH_8B;
  BspCOMInit.StopBits   = COM_STOPBITS_1;
  BspCOMInit.Parity     = COM_PARITY_NONE;
  BspCOMInit.HwFlowCtl  = COM_HWCONTROL_NONE;
  if (BSP_COM_Init(COM1, &BspCOMInit) != BSP_ERROR_NONE)
  {
    Error_Handler();
  }

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

	/* Wait for SD module reset */
	HAL_Delay(500);
	buff_length = sprintf(tx_buff, "Inicio de prueba\r\n");
	HAL_UART_Transmit(&hcom_uart[COM1],  (uint8_t *)tx_buff, buff_length, 100);

	/* Mount SD Card */
	if(f_mount(&fs, "", 0) != FR_OK)
		Error_Handler();

//	/* Open file to write */
//	if(f_open(&fil, "first.txt", FA_OPEN_ALWAYS | FA_READ | FA_WRITE) != FR_OK)
//		Error_Handler();
//
//	/* Check freeSpace space */
//	if(f_getfree("", &fre_clust, &pfs) != FR_OK)
//		Error_Handler();
//
//	totalSpace = (uint32_t)((pfs->n_fatent - 2) * pfs->csize * 0.5);
//	freeSpace = (uint32_t)(fre_clust * pfs->csize * 0.5);
//
//	/* free space is less than 1kb */
//	if(freeSpace < 1)
//		Error_Handler();
//
//	/* Writing text */
//	f_puts("STM32 SD Card I/O Example via SPI\r\n", &fil);
//	f_puts("Save the world!!!\r\n", &fil);
//
//	/* Close file */
//	if(f_close(&fil) != FR_OK)
//		Error_Handler();
//
//	/* Open file to read */
//	if(f_open(&fil, "first.txt", FA_READ) != FR_OK)
//		Error_Handler();
//
//	while(f_gets(buffer, sizeof(buffer), &fil))
//	{
//		/* SWV output */
//		printf("%s", buffer);
//		fflush(stdout);
//		buff_length = sprintf(tx_buff, "%s", buffer);
//		HAL_UART_Transmit(&hcom_uart[COM1],  (uint8_t *)tx_buff, buff_length, 100);
//	}
//
//	/* Close file */
//	if(f_close(&fil) != FR_OK)
//		Error_Handler();

	/* Unmount SDCARD */ //Para esta prueba se ocupa tener montada la unidad SD
//	if(f_mount(NULL, "", 1) != FR_OK)
//		Error_Handler();
	buff_length = sprintf(tx_buff, "FIN de prueba\r\n");
	HAL_UART_Transmit(&hcom_uart[COM1],  (uint8_t *)tx_buff, buff_length, 100);

//##############################################################################################################33
	configuracion_IP();

	uint8_t gFTPBUF[_MAX_SS];
	uint8_t ret;
	uint8_t IPAddress[4] = {192,168,10,10};
	ftpd_init(IPAddress);

  while (1)
  {
	/* Infinite loop */
	if((ret = ftpd_run(gFTPBUF)) < 0)
	{
		Error_Handler();
	}
	HAL_Delay(15);
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

  /** Configure the main internal regulator output voltage
  */
  HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1_BOOST);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = RCC_PLLM_DIV4;
  RCC_OscInitStruct.PLL.PLLN = 85;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
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
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief SPI2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI2_Init(void)
{

  /* USER CODE BEGIN SPI2_Init 0 */

  /* USER CODE END SPI2_Init 0 */

  /* USER CODE BEGIN SPI2_Init 1 */

  /* USER CODE END SPI2_Init 1 */
  /* SPI2 parameter configuration*/
  hspi2.Instance = SPI2;
  hspi2.Init.Mode = SPI_MODE_MASTER;
  hspi2.Init.Direction = SPI_DIRECTION_2LINES;
  hspi2.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi2.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi2.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi2.Init.NSS = SPI_NSS_SOFT;
  hspi2.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_32;
  hspi2.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi2.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi2.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi2.Init.CRCPolynomial = 7;
  hspi2.Init.CRCLength = SPI_CRC_LENGTH_DATASIZE;
  hspi2.Init.NSSPMode = SPI_NSS_PULSE_ENABLE;
  if (HAL_SPI_Init(&hspi2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI2_Init 2 */

  /* USER CODE END SPI2_Init 2 */

}

/**
  * @brief SPI3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI3_Init(void)
{

  /* USER CODE BEGIN SPI3_Init 0 */

  /* USER CODE END SPI3_Init 0 */

  /* USER CODE BEGIN SPI3_Init 1 */

  /* USER CODE END SPI3_Init 1 */
  /* SPI3 parameter configuration*/
  hspi3.Instance = SPI3;
  hspi3.Init.Mode = SPI_MODE_MASTER;
  hspi3.Init.Direction = SPI_DIRECTION_2LINES;
  hspi3.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi3.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi3.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi3.Init.NSS = SPI_NSS_SOFT;
  hspi3.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_16;
  hspi3.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi3.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi3.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi3.Init.CRCPolynomial = 7;
  hspi3.Init.CRCLength = SPI_CRC_LENGTH_DATASIZE;
  hspi3.Init.NSSPMode = SPI_NSS_PULSE_ENABLE;
  if (HAL_SPI_Init(&hspi3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI3_Init 2 */

  /* USER CODE END SPI3_Init 2 */

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
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(CS_S_GPIO_Port, CS_S_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(ETH_CS_GPIO_Port, ETH_CS_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin : CS_S_Pin */
  GPIO_InitStruct.Pin = CS_S_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
  HAL_GPIO_Init(CS_S_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : ETH_CS_Pin */
  GPIO_InitStruct.Pin = ETH_CS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
  HAL_GPIO_Init(ETH_CS_GPIO_Port, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
void CS_SEL_FUN(void)
{
// CS y GPIO de SPI3
	HAL_GPIO_WritePin(ETH_CS_GPIO_Port, ETH_CS_Pin, GPIO_PIN_RESET);
}

void CS_DES_FUN(void)
{
	HAL_GPIO_WritePin(ETH_CS_GPIO_Port, ETH_CS_Pin, GPIO_PIN_SET);
}

// Tener cuidado con el SPI que se esta usando
uint8_t SPI_Received(void)
{
	uint8_t RX_Buff;
	HAL_SPI_Receive(&hspi3, &RX_Buff, 1, 100);
	return RX_Buff;
}

void SPI_Transmit(uint8_t TX_Buff)
{
	HAL_SPI_Transmit(&hspi3, &TX_Buff, 1, 100);
}

void configuracion_IP(void)
{
	//char Archivo[25];
	//Obtenemos direccion IP
	int Address = 10;

	//bufsize se refiere al tamaño del buffer tx, rx por cada socket el w5500 tiene hasta 8 sockets. Los 32Kbytes se dividen por los 8 sockets
	printf("\r\nStart Eth Settings\r\n");
	uint8_t bufSize[] = {2, 2, 2, 2, 2, 2, 2, 2};

	//Funciones para mandar a seleccionar el chip:
	reg_wizchip_cs_cbfunc(CS_SEL_FUN, CS_DES_FUN);

	//Funciones para mandar a escribir y leer datos del SPI
	reg_wizchip_spi_cbfunc(SPI_Received, SPI_Transmit);

	//Init Buffer tx rx
	wizchip_init(bufSize, bufSize);
	wiz_NetInfo netInfo = { .mac 	= {0x00, 0x08, 0xdc, 0xab, 0xcd, 0xef},	// Mac address
	        	            .ip 	= {192, 168, 10, Address},					// IP address
	          	            .sn 	= {255, 255, 255, 0},					// Subnet mask
	          	            .gw 	= {192, 168, 10, 1}};					// Gateway address

	wizchip_setnetinfo(&netInfo);											//Se configura el chip con los datos ingresados anteriormente

	buff_length = sprintf(tx_buff, "FIN Config W5500 \r\n");
	HAL_UART_Transmit(&hcom_uart[COM1],  (uint8_t *)tx_buff, buff_length, 100);

}


/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
	buff_length = sprintf(tx_buff, "Error Prueba SD: \r\n");
	HAL_UART_Transmit(&hcom_uart[COM1],  (uint8_t *)tx_buff, buff_length, 100);
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
