#pragma once
#ifndef SRC_FSM_H_
#define SRC_FSM_H_

#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef enum STATES {
	MENU, //esperando instrucciones
	UNICAMED, //muestra la ultima medicion
	STREAM, //muestra las mediciones cada 0.5 seg
	CONFIG // configuracion de layout
} states_t;

typedef struct FSM {

	uint32_t state; // Estado actual

} FSM_t;

// Devuelve una FSM con el estado inicial
FSM_t inicializarFSM(void);
// Cambia el estado de la FSM
void pasarDeEstado(FSM_t, uint32_t);
// Devuelve true si el estado es valido
static bool estadoValido(FSM_t, uint32_t);

void Emenu(FSM_t);
void Eunicamed(FSM_t);
void Estream(FSM_t);
void Econfig(FSM_t);

#endif /* SRC_FSM_H_ */
