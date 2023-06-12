#include "fsm.h"

/* ------- Constants --------*/
uint8_t state = STATE_INPUT;
uint8_t old_state = STATE_INIT;

/* ------- Functions --------*/

// FSM handler
void fsm(void) {
    switch (state) {
        case STATE_INPUT:
            state_input();
            break;
        case STATE_PROCESS:
            state_process();
            break;
        case STATE_OUTPUT:
            state_output();
            break;
        default:
            break;
    }
}

void fsm_init(void){
    state = STATE_INPUT;
    old_state = STATE_INIT;
    usart_clear();
    usart_print("FSM initialized\n\r");
}

void state_input(void) {
    // Detect new state
    if(old_state != state) {
        lcd_change_text("INPUT:");
        usart_print("\n\rPlease input command\n\r");
        //Write input in second line in lcd
        lcd_write_in_second_line();
        // Trigger input mechanism
        HAL_UART_Receive_IT(&huart1, (uint8_t*)&UART1_rxBuffer, 1); // Start recieving data from UART1
    }

    old_state = state;
}

void state_process(void) {
    // Detect new state
    if(old_state != state) {
        lcd_change_text("Processing");
        usart_print("\n\rProcessing input\n\r");
    }

    HAL_Delay(1000); // Wait 1 second
    if (board_move(data)){
        old_state = state;
        state = STATE_OUTPUT;
    }
    else{
        old_state = state;
        state = STATE_INPUT;
    }
}

void state_output(void) {
    if(old_state != state) {
        lcd_change_text("Output:");
        usart_print("Output\n\r");
    }

    old_state = state;
}