#pragma once
#ifndef SRC_FSM_H_
#define SRC_FSM_H_

#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#define MENU_OPTIONS 	"*** MENU ***"\
						"1. Mostrar último valor medido"\
						"2. Mostrar valores medidos en tiempo real"\
						"3. Ajustes"
#define IMPRIMIR true

enum STATES {
	MENU, //esperando instrucciones
	UNICAMED, //muestra la ultima medicion
	STREAM, //muestra las mediciones cada 0.5 seg
	CONFIG // configuracion de layout
};

/* Variables */
uint32_t state; // Estado actual
char* message; // Mensaje a mostrar en UART
bool imprimir_en_lcd; // Flag para imprimir en LCD

/* Funciones */
// Inicializacion
void inicializarFSM(void);
//Estados

/*
Se le pasa la instruccion recibida por UART y es validada.
*/
void state_menu(void);
/*
*/
void state_unicamed(void);
/*
*/
void state_stream(void);
/*
*/
void state_config(void);

#endif /* SRC_FSM_H_ */
