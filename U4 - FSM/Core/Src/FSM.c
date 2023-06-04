#include "FSM.h"

/* Variables */
uint32_t state; // Estado actual
char* message; // Mensaje a mostrar en UART
char* recieved; // Input de UART
bool imprimir_en_lcd; // Flag para imprimir en LCD
bool imprimir_en_uart;
static bool runned_once = false;
int stream_ms = 500;

void inicializarFSM(void){
	state = START; // Estado inicial

	message = (char*)malloc(200 * sizeof(char)); // Reservo memoria para el mensaje
	strcpy(message,MENU_OPTIONS); // Mensaje inicial (menu)

	
	recieved = (char*)malloc(10 * sizeof(char)); // Reservo memoria para recibir
	
	imprimir_en_lcd = !IMPRIMIR; // Inicialmente no imprimimos en lcd
	imprimir_en_uart = IMPRIMIR; 
}

/**********************************/
/*******ESTADOS DE LA MdE**********/
/**********************************/
void state_menu(){
	
	if (state == START){
		strcpy(message,MENU_OPTIONS);
		imprimir_en_uart = IMPRIMIR;
		state = MENU;
	}
	else if (state == MENU){
		imprimir_en_uart = !IMPRIMIR;
	}
	// Si se recibe un estado valido, cambio de estado
	if (recieved[0]=='1'){
		state = UNICAMED;
	}
	else if (recieved[0]=='2'){
		state = STREAM;
	}
	else if (recieved[0]=='3'){
		state = CONFIG;
	}
	return;
}

void state_unicamed(){

	if(!runned_once){
		runned_once = true;
		// Imprimo la ultima medicion
		memset(message,0,strlen(message));
		strcpy(message,strcat(uartTransmit,GO_BACK));
		imprimir_en_uart = IMPRIMIR;
		return;
	}
	imprimir_en_uart = !IMPRIMIR;
	// Revisar si se quiere volver
	if(recieved[0]=='q'){
		state = START;
		runned_once = false;
		imprimir_en_uart = !IMPRIMIR;
		return;
	}
}

void state_stream(){

	imprimir_en_uart = IMPRIMIR;

	memset(message,0,strlen(message));
	strcpy(message,strcat(uartTransmitStream,GO_BACK));
	DWT_Delay_ms(stream_ms);

	// Revisar si se quiere volver
	if(recieved[0]=='q'){
		imprimir_en_uart = !IMPRIMIR;
		state = START;
	}
	return;
}

void state_config(){

	// Revisar si se quiere volver
	if(recieved[0]=='q'){
		imprimir_en_uart = !IMPRIMIR;
		state = START;
	}
	return;
}
/**********************************/
/*******FIN ESTADOS DE LA MdE**********/
/**********************************/


