#ifndef ECU_INC_ENTRADAS_H_
#define ECU_INC_ENTRADAS_H_

#include "stdbool.h"
#include "stdlib.h"
#include <stdio.h>
#include "stm32f1xx_hal.h"

#define MAX_ENTRADAS 3
#define Rebotes      4

#define END_X 0
#define END_Y 1
#define END_Z 2

void entradasIntit(void);
void DebounceEntradas (void);
uint8_t LeerEntrada ( uint8_t nEntrada );

#endif /* ECU_INC_ENTRADAS_H_ */