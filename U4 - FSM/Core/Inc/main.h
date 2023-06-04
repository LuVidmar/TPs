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
#include "stm32f1xx_hal.h"
#include "../../ECU/Inc/DWT_Delay.h"
#include "../../ECU/Inc/LCD16x2_cfg.h"

/* Std libraries */
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

/* Modules */
#include "tim.h"
#include "usart.h"
#include "adc.h"
#include "gpio.h"
#include "FSM.h"

/* Exported constants --------------------------------------------------------*/
#define BITSONADC 4096 //ADC de 12 bits
#define REFVOLT 33     //Amplitud 0-3.3V
#define ARR_MAX 65535

/* Variables */
extern char uartTransmitStream[26];

/* Functions */
void calculos(void);
void refrescar_lcd(bool);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */