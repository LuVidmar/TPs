/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    usart.h
  * @brief   This file contains all the function prototypes for
  *          the usart.c file
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
#ifndef __USART_H__
#define __USART_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* ------- Variables ------- */
extern char UART1_rxBuffer[2]; //buffer for recieving data from UART1
extern char data[50]; //last recieved data from UART1
extern UART_HandleTypeDef huart1; //UART1 handle

void MX_USART1_UART_Init(void);
void usart_print(char*); //print text to UART1
void usart_clear(void); //clear UART1 buffer and terminal

#ifdef __cplusplus
}
#endif

#endif /* __USART_H__ */