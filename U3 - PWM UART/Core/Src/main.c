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

/* Variables to use */
uint16_t PWM_ADC = 0;
uint16_t parteEntera = 0;
uint16_t parteDec = 0;
char formatted[8] = {0};

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);


/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_ADC1_Init();
  MX_TIM2_Init();
  //MX_TIM3_Init();
  //MX_USART1_UART_Init();

  /* ADC init */
  HAL_ADCEx_Calibration_Start(&hadc1);
  /* Timer init */
  HAL_TIM_Base_Start_IT(&htim2);
  //HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
  /* LCD init */
  LCD_Init();
  LCD_Clear();

  /* LCD primera linea */
  LCD_Clear(); // limpio la pantalla antes de escribir el nuevo valor y evitar que queden cosas impresas en la pantalla que no necesito
  LCD_SetCursor(1, 1); //seteo el cursor en la primer fila y columna
  LCD_WriteString("CONVERSION ADC:"); //Dejamos esto dentro del while debido q a que impiamos la pantalla continuamente

  while (1)
  {
    // Dos decimales - No podemos hacer operaciones con decimales
    // Separamos el numero en parte entera y parte decimal
    parteEntera = ((AD_RES * REFVOLT) / 10) / BITSONADC; //Hacemos las operanciones como ints (los decimales se pierden)
    /*
    Para la parte decimal hacemo un corrimiento
    del numero para que los decimales "sean enteros" y le
    restamos la parte entera para solo quedarnos con lo decimal
    */
    parteDec = ((AD_RES * REFVOLT * 10) / BITSONADC) - (parteEntera * 100);
    /*
    Concatenamos y guardamos en un string la parte entera, la coma, la parte decimal
    y "V" para imprimirlo por pantalla
    */
    sprintf(formatted,"%d.%d V",parteEntera,parteDec);
    sprintf(uartTransmit,"Tension Medida: %s\n\r",formatted); // para el uart

    LCD_SetCursor(2, 1); //seteo el cursor en la 2da fila y 1er columna
    LCD_WriteString(formatted); // escribo el string generado por el ADC
    DWT_Delay_ms(200); // hago una espera para que no refresque tan rapido

    /*PWM*/
    /*PWM_ADC = AD_RES * ARR_MAX / BITSONADC; //regla de 3
    TIM3->CCR1 = ARR_MAX - PWM_ADC; //negado (led prende con cero)*/
  }

}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

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
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC;
  PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV2;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

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