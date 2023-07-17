#ifndef ECU_INC_STEPPER_MOTOR_H_
#define ECU_INC_STEPPER_MOTOR_H_

#include <stdio.h>
#include "stdbool.h"
#include "stm32f1xx_hal.h"
#include "entradas.h"

#define VUELTA_COMP 400
#define STxMM 25
#define START true
#define STOP false

#define DERECHA false
#define IZQUIERDA true

#define ATRAS false
#define ADELANTE true

#define ARRIBA false
#define ABAJO true

#define EJEX 1
#define EJEY 2
#define EJEZ 3

#define MOTOR1_Port GPIOB
#define MOTOR2_Port GPIOB
#define MOTOR3_Port GPIOB
#define MOTOR1_Pin GPIO_PIN_0
#define MOTOR2_Pin GPIO_PIN_1
#define MOTOR3_Pin GPIO_PIN_4

#define dirMOTOR1_Port GPIOA
#define dirMOTOR2_Port GPIOB
#define dirMOTOR3_Port GPIOB
#define dirMOTOR1_Pin GPIO_PIN_7
#define dirMOTOR2_Pin GPIO_PIN_13
#define dirMOTOR3_Pin GPIO_PIN_5

#define MAXDIST_X 4000//DEFINIR DISTANCIA MAXIMA
#define MAXDIST_Y 4000//DEFINIR DISTANCIA MAXIMA
#define MAXDIST_Z 1000//DEFINIR DISTANCIA MAXIMA

extern bool motorBUSY;
extern bool Motor1;
extern bool Motor2;
extern bool Motor3;
extern uint32_t stepsM1;
extern uint32_t stepsM2;
extern uint32_t stepsM3;
extern uint32_t distFromCeroX;
extern uint32_t distFromCeroY;
extern uint32_t distFromCeroZ;

extern bool rutinaOrigin;

/******Funciones de movimiento de steppers***********/

void motorInit();

void moverMotor_cm(uint8_t*, uint32_t);
void moverMotor_mm(uint16_t, bool, uint32_t);
void moverMotor_tiempo(uint8_t*, uint32_t);
void moverMotor_step(uint16_t, bool, uint32_t);
void velocidadMotor(uint8_t*, uint16_t);

/*******Funciones mayor abstraccion*******/
void moverXmm(int); // si es negativo mueve izq, positivo derecha
void moverYmm(int);
void bajarZ();
void subirZ();
void volverOrigen(void);
void stepperWatchDog(void);

//void rutinaTIM3(void);

#endif /* ECU_INC_STEPPER_MOTOR_H_ */