#ifndef FSM_H_
#define FSM_H_

/* ------- Includes --------*/
#include "main.h"

/* ------- Constants --------*/

/* ------- Variables --------*/
//States
typedef enum {
    STATE_INIT = 0,
    STATE_INPUT,
    STATE_PROCESS,
    STATE_OUTPUT
} state_t;

extern uint8_t state;
extern state_t states;

/* ------- Functions --------*/
// FSM init
void fsm_init(void);
// FSM handler
void fsm(void);
// State functions
void state_input(void);
void state_process(void);
void state_output(void);

#endif /* FSM_H_ */