#include "FSM.h"

/* Variables */
uint32_t state; // Estado actual
char* message; // Mensaje a mostrar en UART
char* recieved; // Input de UART
bool imprimir_en_lcd; // Flag para imprimir en LCD

void inicializarFSM(void){
	state = MENU; // Estado inicial

	message = (char*)malloc(100 * sizeof(char)); // Reservo memoria para el mensaje
	message = MENU_OPTIONS; // Mensaje inicial (menu)
	
	recieved = (char*)malloc(10 * sizeof(char)); // Reservo memoria para recibir
	
	imprimir_en_lcd = !IMPRIMIR; // Inicialmente no imprimimos en lcd
}

/**********************************/
/*******ESTADOS DE LA MdE**********/
/**********************************/
void state_menu(){
	
	// Validaciones
	if (strlen(recieved) != 1){
		return;
	}
	else if (strcmp(recieved,"1")){
		state = UNICAMED;
	}
	else if (strcmp(recieved,"2")){
		state = STREAM;
	}
	else if (strcmp(recieved,"3")){
		state = CONFIG;
	}
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


