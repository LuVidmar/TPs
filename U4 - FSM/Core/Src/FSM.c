#include "FSM.h"

FSM_t inicializarFSM(void){
	FSM_t FSM;
	FSM.state = MENU;
	return FSM;
}

void pasarDeEstado(FSM_t FSM, uint32_t estado){
	if(!estadoValido(FSM, estado)){ // El estado no es valido
		return;
	}

	FSM.state = estado;
}

static bool estadoValido(FSM_t FSM, uint32_t estado){
	if (estado > 0 && estado < MENU){
		return true; // para que sea valido debe estar entre 0 y default
	}
	return false;
}


/**********************************/
/*******ESTADOS DE LA MdE**********/
/**********************************/
void Emenu(FSM_t fsm){
	return;
}
void Eunicamed(FSM_t fsm){
	return;
}
void Estream(FSM_t fsm){
	return;
}
void Econfig(FSM_t fsm){
	return;
}
/**********************************/
/*******FIN ESTADOS DE LA MdE**********/
/**********************************/


