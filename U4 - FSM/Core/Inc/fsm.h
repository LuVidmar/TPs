#pragma once
#ifndef __FSM_H__
#define __FSM_H__

/* Modules */
#include "main.h"
#include "usart.h"

/* Std libs */
#include "stdbool.h"

/* Variables */
extern uint8_t fsm_state; //Estado inicial
extern bool imprimir_lcd; //Flag para imprimir en lcd
extern bool imprimir_uart; //Flag para imprimir en uart

/* States */
typedef enum
{
    FSM_STATE_MENU,
    FSM_STATE_UNICA_MED,
    FSM_STATE_DATA_STREAM,
    FSM_STATE_CONFIG,
    FSM_STATE_STARTING
} FSM_STATE;

/* Funciones */
int char_to_number(char);

/* Constantes */
#define MENU_OPTIONS 	"\n\r*** MENU ***\n\r"\
						"1. Mostrar último valor medido\n\r"\
						"2. Mostrar valores medidos en tiempo real\n\r"\
						"3. Ajustes\n\r"

#endif // !__FSM_H__