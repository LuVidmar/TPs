#include "fsm.h"

uint8_t fsm_state = FSM_STATE_STARTING; //Estado inicial
uint8_t fsm_state_anterior = FSM_STATE_STARTING; //Estado inicial
bool imprimir_lcd = false; //Flag para imprimir en lcd
bool imprimir_uart = false; //Flag para imprimir en uart

void fsm(){

    switch (fsm_state) {
        case FSM_STATE_STARTING:
            fsm_state = FSM_STATE_MENU;
            fsm_state_anterior = FSM_STATE_STARTING;
        case FSM_STATE_MENU:
            fsm_menu();
            fsm_state_anterior = FSM_STATE_MENU;
            break;
        case FSM_STATE_UNICA_MED:
            fsm_unica_med();
            fsm_state_anterior = FSM_STATE_UNICA_MED;
            break;
        case FSM_STATE_DATA_STREAM:
            fsm_data_stream();
            fsm_state_anterior = FSM_STATE_DATA_STREAM;
            break;
        case FSM_STATE_CONFIG:
            fsm_config();
            fsm_state_anterior = FSM_STATE_CONFIG;
            break;
        default:
            break;
    }
}

void fsm_menu(void){
    imprimir_uart = true; //Queremos imprimir en el uart el menu
    imprimir_lcd = false; //No queremos imprimir en el

    /* Imprimo el menu una vez */
    if (fsm_state_anterior != fsm_state){
        strcpy(uartTransmit, MENU_OPTIONS); //Imprimo el menu
        imprimir_mensaje();
    }

    /* Procesamiento cambio de estado */
    if(recieved[0] == '1'){
        fsm_state = FSM_STATE_UNICA_MED;
    }
    else if(recieved[0] == '2'){
        fsm_state = FSM_STATE_DATA_STREAM;
    }
    else if(recieved[0] == '3'){
        fsm_state = FSM_STATE_CONFIG;
    }
    else{
        fsm_state = FSM_STATE_MENU; // sigo en mismo estado
    }
}

void fsm_unica_med(void){

    /* Imprimo una vez */
    if (fsm_state_anterior != fsm_state){
        strcpy(uartTransmit, medicion); //Imprimo la medicion
        imprimir_mensaje();
        strcpy(uartTransmit, "Presione q para volver al menu\n\r"); //Imprimo la medicion
        imprimir_mensaje();
    }

    if (recieved[0] == 'q'){ //Si presiono q vuelvo al menu
        fsm_state = FSM_STATE_MENU;
    }
}

void fsm_data_stream(void){

    /* Imprimo una vez */
    if (fsm_state_anterior != fsm_state){
        strcpy(uartTransmit, "Presione q para volver al menu\n\r"); //Imprimo la medicion
        imprimir_mensaje();
    }
    strcpy(uartTransmit, medicion); //Imprimo la medicion
    imprimir_mensaje();

    if (recieved[0] == 'q'){ //Si presiono q vuelvo al menu
        fsm_state = FSM_STATE_MENU;
    }
}

void fsm_config(void){

    // Pase lo que pase el proximo estado es el menu
    fsm_state = FSM_STATE_MENU;

    strcpy(uartTransmit, "Ingrese configuracion: [x,yyyy]\n\r"); //Imprimo la medicion
    imprimir_mensaje();

    /* Recibo la configuracion */
    char config[10] = {0}; // aunque solo deberia usar 6
    recieved[0] = '\0'; // borro el buffer
    while (strlen(config) < 6){ // mientras no reciba la configuracion
        HAL_UART_Receive_IT(&huart1, (uint8_t*)recieved, 1); //recibo 1 byte por interrupcion
        if (recieved[0] != '\0'){ // si recibo algo
            strcat(config, recieved); // concateno
            strcpy(uartTransmit, recieved); //Imprimo lo recibido
            imprimir_mensaje();
            recieved[0] = '\0'; // borro el buffer
        }
    }

    /* Validar configuracion [x,yyyy] */
    bool valid = true;

    /* Corroboro que sean numeros */
    for(uint8_t i = 0; i < 6; i++){ // chequeamos cada digito
        int n = char_to_number(config[i]);
        if (n == -1 && i != 1){ // si no es un numero (todos excepto 1 que es ',')
            valid = false;
            break;
        }
        else if (i == 1 && config[i] != ','){ // si no es una coma
            valid = false;
            break;
        }
    }

    /* Calculo de valores */
    int x = char_to_number(config[0]);
    int y = 1000 * char_to_number(config[2]) + 100 * char_to_number(config[3]) + 10 * char_to_number(config[4]) + 1 * char_to_number(config[5]);

    /* Informamos al usuario si es valido el input */
    if (valid){
        strcpy(uartTransmit, "\n\rConfiguracion valida.\n\r");
        imprimir_mensaje();
    }
    else{
        strcpy(uartTransmit, "\n\rConfiguracion invalida.\n\r");
        imprimir_mensaje();
        return;
    }

    /* Pasamos los valores a los registros pertinentes */
    // X
    if (x == 1){
        multiplicador_mV = 1;
    }
    else if (x == 2){
        multiplicador_mV = 1000;
    }
    // Y
    if (y > 500){
        timeout = y;
    }
    else{
        strcpy(uartTransmit, "\n\rEl valor de Y debe ser mayor a 500.\n\r");
        imprimir_mensaje();
    }

    return;
}

int char_to_number(char c){
    switch (c){
        case '0':
            return 0;
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
        default:
            return -1;
    }
}