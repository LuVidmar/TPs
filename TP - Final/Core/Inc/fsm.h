#ifndef FSM_H_
#define FSM_H_

/* ------- Includes --------*/
#include "main.h"
#include <stdbool.h>

/* ------- Constants --------*/
#define PYTHON_INPUT false

/* ------- Variables --------*/
//States
typedef enum {
    STATE_INIT = 0,
    STATE_INPUT,
    STATE_PROCESS,
    STATE_OUTPUT,
} state_t;

extern uint8_t state;
extern state_t states;
extern bool waiting_for_input;

/* ------- Functions --------*/
// FSM init
void fsm_init(void);
// FSM handler
void fsm(void);
// State functions
void state_input(void);
void state_process(void);
void state_output(void);
void state_python(void);

#endif /* FSM_H_ */