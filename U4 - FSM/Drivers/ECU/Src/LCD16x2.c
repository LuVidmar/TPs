
#include "../../ECU/Inc/LCD16x2.h"

#include "../../ECU/Inc/DWT_Delay.h"
#include "../../ECU/Inc/LCD16x2_cfg.h"



/* Escribe 1 o 0 en los pines configurados en LCD16x2_CfgParam */
/* En el if, un 0 es falso, cualquier cosa distinta a 0 es verdadero
 * Analizo cada posicion del char, a ver si tiene un 1 o un cero, con un AND
 * 1 = 0001
 * 2 = 0010
 * 4 = 0100
 * 8 = 1000
 */
void LCD_DATA(unsigned char Data)
{
    if(Data & 1) HAL_GPIO_WritePin(LCD16x2_CfgParam.LCD_GPIO, LCD16x2_CfgParam.D4_PIN, 1);
    else HAL_GPIO_WritePin(LCD16x2_CfgParam.LCD_GPIO, LCD16x2_CfgParam.D4_PIN, 0);

    if(Data & 2) HAL_GPIO_WritePin(LCD16x2_CfgParam.LCD_GPIO, LCD16x2_CfgParam.D5_PIN, 1);
    else HAL_GPIO_WritePin(LCD16x2_CfgParam.LCD_GPIO, LCD16x2_CfgParam.D5_PIN, 0);

    if(Data & 4) HAL_GPIO_WritePin(LCD16x2_CfgParam.LCD_GPIO, LCD16x2_CfgParam.D6_PIN, 1);
    else HAL_GPIO_WritePin(LCD16x2_CfgParam.LCD_GPIO, LCD16x2_CfgParam.D6_PIN, 0);

    if(Data & 8) HAL_GPIO_WritePin(LCD16x2_CfgParam.LCD_GPIO, LCD16x2_CfgParam.D7_PIN, 1);
    else HAL_GPIO_WritePin(LCD16x2_CfgParam.LCD_GPIO, LCD16x2_CfgParam.D7_PIN, 0);
}


/*
 * Envio de comandos al LCD, con rs=0
 */
void LCD_CMD(unsigned char a_CMD)
{
    // Selecconar Registro de Comando (rs=1 para datos, rs=0 para comandos)
	HAL_GPIO_WritePin(LCD16x2_CfgParam.LCD_GPIO, LCD16x2_CfgParam.RS_PIN, 0);
    // Enviar comando a LCD
	LCD_DATA(a_CMD);
    // Enviar flanco a la señal ENable. No olvidar delays.
    HAL_GPIO_WritePin(LCD16x2_CfgParam.LCD_GPIO, LCD16x2_CfgParam.EN_PIN, 1);
    DWT_Delay_us(LCD16x2_CfgParam.LCD_EN_Delay);
    HAL_GPIO_WritePin(LCD16x2_CfgParam.LCD_GPIO, LCD16x2_CfgParam.EN_PIN, 0);
    DWT_Delay_us(LCD16x2_CfgParam.LCD_EN_Delay);
}

/*
 * Envio de Letras al LCD, con rs=1
 * Primero envio el nibble alto y despues el bajo
 */
void LCD_WriteChar(char Data)
{
   char Low4, High4; //Separo en nibble alto y bajo con un AND
   Low4  = Data & 0x0F;
   High4 = Data & 0xF0;

   HAL_GPIO_WritePin(LCD16x2_CfgParam.LCD_GPIO, LCD16x2_CfgParam.RS_PIN, 1); //seteo par enviar datos

   // Enviar nible alto
   LCD_DATA(High4>>4); // shifteo y envio el dato

   //Envio el flanco a la señal de ENable
   HAL_GPIO_WritePin(LCD16x2_CfgParam.LCD_GPIO, LCD16x2_CfgParam.EN_PIN, 1);
   DWT_Delay_us(LCD16x2_CfgParam.LCD_EN_Delay);
   HAL_GPIO_WritePin(LCD16x2_CfgParam.LCD_GPIO, LCD16x2_CfgParam.EN_PIN, 0);
   DWT_Delay_us(LCD16x2_CfgParam.LCD_EN_Delay);

   // Enviar nibble bajo
   LCD_DATA(Low4); //envio el dato

   //Envio el flanco a la señal de ENable
   HAL_GPIO_WritePin(LCD16x2_CfgParam.LCD_GPIO, LCD16x2_CfgParam.EN_PIN, 1);
   DWT_Delay_us(LCD16x2_CfgParam.LCD_EN_Delay);
   HAL_GPIO_WritePin(LCD16x2_CfgParam.LCD_GPIO, LCD16x2_CfgParam.EN_PIN, 0);
   DWT_Delay_us(LCD16x2_CfgParam.LCD_EN_Delay);
}


void LCD_Clear()
{
    LCD_CMD(0); //LCD ON, cursor ON
    LCD_CMD(1); //Clear display screen
    DWT_Delay_ms(2);
}

/* Setea posicion de cursor */
void LCD_SetCursor(unsigned char fila, unsigned char columna)
{
    unsigned char Temp,Low4,High4;
    if(fila == 1)
    {
		Temp  = 0x80 + columna - 1; //0x80 is used to move the cursor
		High4 = Temp >> 4;
		Low4  = Temp & 0x0F;
		LCD_CMD(High4);
		LCD_CMD(Low4);
    }
    if(fila == 2)
    {
    	Temp  = 0xC0 + columna - 1;
	    High4 = Temp >> 4;
	    Low4  = Temp & 0x0F;
	    LCD_CMD(High4);
	    LCD_CMD(Low4);
    }
    DWT_Delay_ms(2);
}
void LCD_Init()
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	
	// Inicializa la funcion de delay DWT 
	DWT_Delay_Init();
	
    // habilitacion de clock en GPIOs
	if(LCD16x2_CfgParam.LCD_GPIO == GPIOA)
	    __HAL_RCC_GPIOA_CLK_ENABLE();
	else if(LCD16x2_CfgParam.LCD_GPIO == GPIOB)
	    __HAL_RCC_GPIOB_CLK_ENABLE();
	else if(LCD16x2_CfgParam.LCD_GPIO == GPIOC)
		__HAL_RCC_GPIOC_CLK_ENABLE();
	else if(LCD16x2_CfgParam.LCD_GPIO == GPIOD)
		__HAL_RCC_GPIOD_CLK_ENABLE();
	
	
	HAL_GPIO_WritePin(LCD16x2_CfgParam.LCD_GPIO, LCD16x2_CfgParam.D4_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD16x2_CfgParam.LCD_GPIO, LCD16x2_CfgParam.D5_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD16x2_CfgParam.LCD_GPIO, LCD16x2_CfgParam.D6_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD16x2_CfgParam.LCD_GPIO, LCD16x2_CfgParam.D7_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD16x2_CfgParam.LCD_GPIO, LCD16x2_CfgParam.RS_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD16x2_CfgParam.LCD_GPIO, LCD16x2_CfgParam.EN_PIN, GPIO_PIN_RESET);
	
	GPIO_InitStruct.Pin = LCD16x2_CfgParam.D4_PIN | LCD16x2_CfgParam.D5_PIN |
			LCD16x2_CfgParam.D6_PIN |LCD16x2_CfgParam.D7_PIN | LCD16x2_CfgParam.RS_PIN |
			LCD16x2_CfgParam.EN_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(LCD16x2_CfgParam.LCD_GPIO, &GPIO_InitStruct);

	// Inicializar display de acuerdo a la especificiación provista en DataSheet
    HAL_GPIO_WritePin(LCD16x2_CfgParam.LCD_GPIO, LCD16x2_CfgParam.RS_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LCD16x2_CfgParam.LCD_GPIO, LCD16x2_CfgParam.EN_PIN, GPIO_PIN_RESET);
    LCD_DATA(0x00);
    DWT_Delay_ms(150);

    LCD_CMD(0x03);
    DWT_Delay_ms(5);
    LCD_CMD(0x03);
    DWT_Delay_us(150);
    LCD_CMD(0x03);
    DWT_Delay_ms(10);
    LCD_CMD(0x02);
    LCD_CMD(0x02);
    LCD_CMD(0x08);
    LCD_CMD(0x00);
    LCD_CMD(0x0C);
    LCD_CMD(0x00);
    LCD_CMD(0x06);
    LCD_CMD(0x00);
    LCD_CMD(0x01);

    
}

void LCD_WriteString(char *str)
{
    int i;
    for(i=0;str[i]!='\0';i++)
       LCD_WriteChar(str[i]);
}
void LCD_ShiftLeft()
{
    LCD_CMD(0x01);
    LCD_CMD(0x08);
    DWT_Delay_us(35);
}
void LCD_ShiftRight()
{
    LCD_CMD(0x01);
    LCD_CMD(0x0C);
    DWT_Delay_us(35);
}
