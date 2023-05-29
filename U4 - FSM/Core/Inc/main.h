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
#pragma once
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"
#include "../../Drivers/ECU/Inc/DWT_Delay.h"
#include "../../Drivers/ECU/Inc/LCD16x2_cfg.h"
#include <string.h>
#include <stdio.h>

/* Defines ----------------------------------------------------------*/
#define BITSONADC 4096 //ADC de 12 bits
#define REFVOLT 33     //Amplitud 0-3.3V
#define ARR_MAX 65535 //ARR maximo

extern uint16_t AD_RES;

/* Interrupciones */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef*);

/* Handler */
void Error_Handler(void);

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
