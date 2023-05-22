#pragma once
#ifndef __MAIN_H
#define __MAIN_H

#include "stm32f1xx_hal.h"
#include "stm32f1xx_it.h"
#include "stdio.h"
#include "../../ECU/Inc/DWT_Delay.h"
#include "../../ECU/Inc/LCD16x2_cfg.h"

#define BITSONADC 4096 //ADC de 12 bits
#define REFVOLT 33     //Amplitud 0-3.3V

void Error_Handler(void);

#endif /* __MAIN_H */