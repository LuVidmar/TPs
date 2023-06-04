#pragma once
#ifndef SRC_FSM_H_
#define SRC_FSM_H_

/* Std lib */
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

/* Libs */
#include "main.h"

/* Constants */
#define MENU_OPTIONS 	"*** MENU ***\n\r"\
						"1. Mostrar último valor medido\n\r"\
						"2. Mostrar valores medidos en tiempo real\n\r"\
						"3. Ajustes\n\r"
#define IMPRIMIR true
#define GO_BACK "Presione q para volver.\n\r"

/* FSM Variables */
extern uint32_t state; // Estado actual
extern char* message; // Mensaje a mostrar en UART
extern char* recieved; // Input de UART
extern bool imprimir_en_lcd; // Flag para imprimir en LCD
extern bool imprimir_en_uart;
extern int stream_ms;

enum STATES {
	MENU, //esperando instrucciones
	UNICAMED, //muestra la ultima medicion
	STREAM, //muestra las mediciones cada 0.5 seg
	CONFIG, // configuracion de layout
	START
};

/* Funciones */
// Inicializacion
void inicializarFSM(void);
/*
Se le pasa la instruccion recibida por UART y es validada.
*/
void state_menu(void);
/*
Va a imprimir una medicion y esperar una 'q' para salir.
*/
void state_unicamed(void);
/*
*/
void state_stream(void);
/*
*/
void state_config(void);

#endif /* SRC_FSM_H_ */