#include "fsm.h"

/* ------- Constants --------*/
enum SUBSTATES { S_IDLE, MOVING_P1_X, MOVING_P1_Y, MOVING_P2_X, MOVING_P2_Y, END };
uint8_t state = STATE_INPUT;
uint8_t old_state = STATE_INIT;
uint8_t substate = S_IDLE;
uint8_t next_state = MOVING_P1_X;

/* ------- Functions --------*/
void reset_vars(void);

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

    HAL_Delay(1000); // Wait 1 second (for dramatic effect)
    if (board_move(data)){
        old_state = state;
        state = STATE_OUTPUT;
    }
    else{
        old_state = state;
        state = STATE_INPUT;
        // Clear data
        memset(data, 0, sizeof(data));
    }
}

void state_output(void) {
    if(old_state != state) {
        lcd_change_text("Moving...");
        usart_print("\n\rMoving...\n\r");
    }

    switch (substate) {
    case S_IDLE:
        if(!motorBUSY){
            substate = next_state;
        }
        break;
    case MOVING_P1_X:
        board_move_to_x(starting_point);
        next_state = MOVING_P1_Y;
        substate = S_IDLE;
        break;
    case MOVING_P1_Y:
        board_move_to_y(starting_point);
        next_state = MOVING_P2_X;
        substate = S_IDLE;
        break;
    case MOVING_P2_X:
        last_point = starting_point;
        board_move_to_x(ending_point);
        next_state = MOVING_P2_Y;
        substate = S_IDLE;
        break;
    case MOVING_P2_Y:
        board_move_to_y(ending_point);
        next_state = END;
        substate = S_IDLE;
        break;
    case END:
        last_point = ending_point;
        reset_vars();
        return;
    default:
        break;
    }

    old_state = state;
}

void reset_vars(void){
    state = STATE_INPUT;
    old_state = STATE_INIT;
    substate = S_IDLE;
    next_state = MOVING_P1_X;
    memset(UART1_rxBuffer,0,2);
    memset(data,0,50);
}