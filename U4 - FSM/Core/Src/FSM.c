#include "FSM.h"

/* Variables */
uint32_t state; // Estado actual
char* message; // Mensaje a mostrar en UART
char* recieved; // Input de UART
bool imprimir_en_lcd; // Flag para imprimir en LCD
bool imprimir_en_uart;
static bool runned_once = false;

void inicializarFSM(void){
	state = MENU; // Estado inicial

	message = (char*)malloc(100 * sizeof(char)); // Reservo memoria para el mensaje
	message = MENU_OPTIONS; // Mensaje inicial (menu)
	
	recieved = (char*)malloc(10 * sizeof(char)); // Reservo memoria para recibir
	
	imprimir_en_lcd = !IMPRIMIR; // Inicialmente no imprimimos en lcd
	imprimir_en_uart = IMPRIMIR; 
}

/**********************************/
/*******ESTADOS DE LA MdE**********/
/**********************************/
void state_menu(){
	
	// Imprimo el menu
	imprimir_en_uart = IMPRIMIR;
	// Validaciones
	if (strlen(recieved) != 1){
		return;
	}
	// Si se recibe un estado valido, cambio de estado
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

	if(!runned_once){
		runned_once = true;
		// Imprimo la ultima medicion
		strcpy(message,strcat(uartTransmit,GO_BACK));
		imprimir_en_uart = IMPRIMIR;
	}

	// Revisar si se quiere volver
	if(strcmp(recieved,"q")){
		state = MENU;
		runned_once = false;
		imprimir_en_uart = !IMPRIMIR;
	}

}

void state_stream(){

	imprimir_en_uart = IMPRIMIR;
	strcpy(message,uartTransmit);

	// Revisar si se quiere volver
	if(strcmp(recieved,"q")){
		imprimir_en_uart = !IMPRIMIR;
		state = MENU;
	}

	return;
}

void state_config(){
	return;
}
/**********************************/
/*******FIN ESTADOS DE LA MdE**********/
/**********************************/


