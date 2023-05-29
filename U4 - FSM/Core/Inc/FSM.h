#pragma once
#ifndef SRC_FSM_H_
#define SRC_FSM_H_

#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#define MENU_OPTIONS 	"*** MENU ***"\
						"1. Mostrar último valor medido"\
						"2. Mostrar valores medidos en tiempo real"\
						"3. Ajustes"
#define IMPRIMIR true
#define GO_BACK "Presione q para volver."

extern const char* uartTransmit;

enum STATES {
	MENU, //esperando instrucciones
	UNICAMED, //muestra la ultima medicion
	STREAM, //muestra las mediciones cada 0.5 seg
	CONFIG // configuracion de layout
};

/* Funciones */
// Inicializacion
void inicializarFSM(void);
//Estados

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
