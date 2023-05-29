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
#include "adc.h"
#include "dma.h"
#include "tim.h"
#include "gpio.h"

void SystemClock_Config(void);

/* Variables Globales */
uint16_t lectura = 0; //Variable para guardar el valor del ADC
uint16_t parteEntera = 0; //Variable para guardar la parte entera del valor del ADC
uint16_t parteDec = 0; //Variable para guardar la parte decimal del valor del ADC
char formatted[16] = {0}; //Variable para guardar el string formateado para imprimir en el LCD

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  HAL_Init();


  SystemClock_Config();

  MX_GPIO_Init();
  MX_DMA_Init();
  MX_TIM2_Init();
  MX_ADC1_Init();

  /* Inicializacion de LCD */
  LCD_Init();
  LCD_Clear();

  /* Calibracion ADC */
  HAL_ADCEx_Calibration_Start(&hadc1);

  while (1)
  {
	  // Dos decimales - No podemos hacer operaciones con decimales
	  // Separamos el numero en parte entera y parte decimal
	  parteEntera = ((AD_RES * REFVOLT) / 10) / BITSONADC; //Hacemos las operaciones como ints (los decimales se pierden)
    /*
    Para la parte decimal hacemo un corrimiento
    del numero para que los decimales "sean enteros" y le
    restamos la parte entera para solo quedarnos con lo decimal
    */
	  parteDec = ((AD_RES * REFVOLT * 10) / BITSONADC) - (parteEntera * 100);
    /* Concatenamos y guardamos en un string la parte entera, la coma, la parte decimal y
    "V" para imprimirlo por pantalla */
	  sprintf(formatted,"%d.%d V",parteEntera,parteDec);
	  LCD_Clear(); // limpio la pantalla antes de escribir el nuevo valor y evitar que queden cosas impresas en la pantalla que no necesito
	  LCD_SetCursor(1, 1); //seteo el cursor en la primer fila y columna
	  LCD_WriteString("CONVERSION ADC:"); //Dejamos esto dentro del while debido q a que impiamos la pantalla continuamente
	  LCD_SetCursor(2, 1); //seteo el cursor en la 2da fila y 1er columna
	  LCD_WriteString(formatted); // escribo el string generado por el ADC
	  DWT_Delay_ms(400); // hago una espera para que no refresque tan rapido
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
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
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
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC;
  PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV6;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
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
