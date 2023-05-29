#include "FSM.h"

void inicializarFSM(void){
	state = MENU; // Estado inicial
	message = (char*)malloc(100 * sizeof(char)); // Reservo memoria para el mensaje
	message = MENU_OPTIONS; // Mensaje inicial (menu)
	imprimir_en_lcd = !IMPRIMIR; // Inicialmente no imprimimos en lcd
}

/**********************************/
/*******ESTADOS DE LA MdE**********/
/**********************************/
uint32_t state_menu(){
	return;
}
void state_unicamed(){
	return;
}
void state_stream(){
	return;
}
void state_config(){
	return;
}
/**********************************/
/*******FIN ESTADOS DE LA MdE**********/
/**********************************/


