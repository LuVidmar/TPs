#include "usart.h"

char UART1_rxBuffer[2] = {0};
char data[50] = {0};
char data_python[50] = {0};
UART_HandleTypeDef huart1;

/* USART1 init function */
void MX_USART1_UART_Init(void)
{
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 9600;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }

}

void HAL_UART_MspInit(UART_HandleTypeDef* uartHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(uartHandle->Instance==USART1)
  {

    /* USART1 clock enable */
    __HAL_RCC_USART1_CLK_ENABLE();

    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**USART1 GPIO Configuration
    PA9     ------> USART1_TX
    PA10     ------> USART1_RX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_9;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_10;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    HAL_NVIC_SetPriority(USART1_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(USART1_IRQn);
  }
}

void HAL_UART_MspDeInit(UART_HandleTypeDef* uartHandle)
{

  if(uartHandle->Instance==USART1)
  {
    /* Peripheral clock disable */
    __HAL_RCC_USART1_CLK_DISABLE();

    /**USART1 GPIO Configuration
    PA9     ------> USART1_TX
    PA10     ------> USART1_RX
    */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_9|GPIO_PIN_10);

    /* USART1 interrupt Deinit */
    HAL_NVIC_DisableIRQ(USART1_IRQn);
  }
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  if (state == STATE_INPUT && !PYTHON_INPUT){ //Check if we are supposed to input

    if (!valid_char(UART1_rxBuffer[0])){ // invalid char, ignore it
      //Receive next data
      HAL_UART_Receive_IT(&huart1, (uint8_t*)UART1_rxBuffer, 1);
      return;
    }

    //Check if data is complete
    if (UART1_rxBuffer[0] == '\r'){
      //Change state to STATE_OUTPUT
      state = STATE_PROCESS;
      return; //Don't receive next data
    }
    else if (UART1_rxBuffer[0] == 127){ //Backspace
      //Remove last character from data array
      data[strlen(data)-1] = '\0';
      //Remove last character from LCD
      lcd_del_last_char();
      //Remove last character from serial monitor
      usart_print("\b \b");
      //Receive next data
      HAL_UART_Receive_IT(&huart1, (uint8_t*)UART1_rxBuffer, 1);
    }
    else{ //Valid character
      //Show the received data on the serial monitor
      usart_print(UART1_rxBuffer);
      //Also show it on the LCD
      lcd_send_data(UART1_rxBuffer[0]);
      //Copy received data to data array
      strcat(data, UART1_rxBuffer);
      //Receive next data
      HAL_UART_Receive_IT(&huart1, (uint8_t*)UART1_rxBuffer, 1);
    }

  }
  else if(state == STATE_INPUT && PYTHON_INPUT){ //Check if we are supposed to interact with python

    char c = UART1_rxBuffer[0];
  
    // Push data to data_python
    strcat(data_python, UART1_rxBuffer);
    if (c == '.'){ //Check if data is complete
      waiting_for_input = false; //We are not waiting for input anymore
      return; //Don't receive next data
    }
    //Receive next data
    HAL_UART_Receive_IT(&huart1, (uint8_t*)UART1_rxBuffer, 1);
    
  }

}

void usart_print(char* text){
  //Print text once
  uint8_t len = strlen(text);
  HAL_UART_Transmit(&huart1, (uint8_t*)text, len, 1000);
}

void usart_clear(void){
  //Clear the data array
  memset(data, 0, sizeof(data));
  for(int i=0; i<10; i++) {
    usart_print("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
  }
}

bool valid_char(char c){
  //Check if the character is valid
  if (c >= '1' && c <= '8'){
    return true;
  }
  else if (c >= 'A' && c <= 'H'){
    return true;
  }
  else if (c == '\r'){
    return true;
  }
  else if (c == 127) //Backspace
    return true;
  else{
    return false;
  }
}