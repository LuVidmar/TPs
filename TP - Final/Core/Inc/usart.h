#ifndef __USART_H__
#define __USART_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include <stdbool.h>

/* ------- Variables ------- */
extern char UART1_rxBuffer[2]; //buffer for recieving data from UART1
extern char data_python[50]; //last recieved data from UART1 in python mode
extern char data[50]; //last recieved data from UART1
extern UART_HandleTypeDef huart1; //UART1 handle

void MX_USART1_UART_Init(void);
void usart_print(char*); //print text to UART1
void usart_clear(void); //clear UART1 buffer and terminal
bool valid_char(char); //check if char is valid for UART1

#ifdef __cplusplus
}
#endif

#endif /* __USART_H__ */