/*
 * STEPPER_MOTOR.c
 *
 *  Created on: Jun 11, 2023
 *      Author: Joaquin
 *
 *  El movimineto de los motores se activa en la rutina de TIM Callback
 */
#include "STEPPER_MOTOR.h"

bool motorBUSY = false;

bool Motor1 = STOP;
bool Motor2 = STOP;
bool Motor3 = STOP;

uint32_t stepsM1=0;
uint32_t stepsM2=0;
uint32_t stepsM3=0;

uint32_t distFromCeroX=0;
uint32_t distFromCeroY=0;
uint32_t distFromCeroZ=0;

bool rutinaOrigin=false;

//void motorInit(){
//
//}

//void moverMotor_cm(uint8_t motor, uint32_t cantCm){
//
//}

void moverMotor_mm(uint16_t nroMotor, bool dir, uint32_t mms){
	uint32_t steps = mms*STxMM;
	moverMotor_step(nroMotor, dir, steps);
}

//void moverMotor_tiempo(uint8_t motor, uint32_t cantT){
//
//}

//Multiplico steps x dos, ya que steps cuenta medio pulso
void moverMotor_step(uint16_t nroMotor, bool dir, uint32_t steps)
{
	if(nroMotor<1 && nroMotor>3){
		return;
	}
	if(nroMotor == 1){
		Motor1 = START;
		HAL_GPIO_WritePin(dirMOTOR1_Port, dirMOTOR1_Pin, (uint32_t)dir);
		stepsM1 = steps*2;

	}
	else if(nroMotor == 2){
		Motor2 = START;
		HAL_GPIO_WritePin(dirMOTOR2_Port, dirMOTOR2_Pin, (uint32_t)dir); // creo q va esta y n la de abajo
		//HAL_GPIO_WritePin(MOTOR2_Port, MOTOR2_Pin, dir);
		stepsM2 = steps*2;
	}
	else if(nroMotor == 3){
		Motor3 = START;
		HAL_GPIO_WritePin(dirMOTOR3_Port, dirMOTOR3_Pin, (uint32_t)dir);
		//HAL_GPIO_WritePin(MOTOR3_Port, MOTOR3_Pin, dir);
		stepsM3 = steps*2;
	}

}


/*******Funciones mayor abstraccion***************************/
void moverXmm(int dist){ // si es negativo mueve izq, positivo derecha
	if (dist == 0)
		return;
	motorBUSY = true;
	// si es negativo mueve izq, positivo derecha
	//while 1 mientras esta en movimiento
	bool dir = false;
	if (dist<0){
		dir = IZQUIERDA;
		dist = dist*-1;
	}
	else{
		dir = DERECHA;
	}
	moverMotor_mm(EJEX, dir, dist);
}
void moverYmm(int dist){
	if (dist == 0)
		return;
	motorBUSY = true;
	// si es negativo mueve izq, positivo derecha
	//while 1 mientras esta en movimiento
	bool dir = false;
	if (dist<0){
		dir = IZQUIERDA;
		dist = dist*-1;
	}
	else{
		dir = DERECHA;
	}
	moverMotor_mm(EJEY, dir, dist);
}
void bajarZ(){
	motorBUSY = true;
	moverMotor_mm(EJEZ, ABAJO, 20);
}
void subirZ(){
	motorBUSY = true;
	moverMotor_mm(EJEZ, ARRIBA, 20);
}
void volverOrigen(void){

	motorBUSY=true;
	rutinaOrigin=true;
	//Rutinas para llegar a 0,0,0
	moverMotor_mm(EJEX, IZQUIERDA, MAXDIST_X);
	// mover eje X hasta pulsar el endstop o 15 seg de movimiento
	//	+ bloquear el resto del programa
	// mover eje y hasta pulsar el endstop o 15 seg de movimiento
	//	+ bloquear el resto del programa
	// mover eje z hasta pulsar el endstop o 15 seg de movimiento
	//	+ bloquear el resto del programa
}

void stepperWatchDog(){

	static bool zeroX= false;
	static bool zeroY= false;
	static bool zeroZ= false;

	//variable global de cant de mov, si se mueve mas de xxx desde el 0. Bloquear movimiento
//	if((distFromCeroX + stepsM1)>MAXDIST_X){
//		Motor1=STOP;
//		//print error
//	}
//	if((distFromCeroY + stepsM2)>MAXDIST_Y){
//		Motor2=STOP;
//		//print error
//	}
//	if((distFromCeroZ + stepsM3)>MAXDIST_Z){
//		Motor3=STOP;
//		//print error
//	}

	zeroX= LeerEntrada(END_X);
	zeroY= LeerEntrada(END_Y);
	zeroZ= LeerEntrada(END_Z);

	if(rutinaOrigin){
		if(zeroX){
			Motor1=STOP;
			moverMotor_mm(EJEY, ADELANTE, MAXDIST_Y);
			motorBUSY=true;
		}
		if(zeroY){
			Motor2=STOP;
			moverMotor_mm(EJEZ, ARRIBA, MAXDIST_Z);
			motorBUSY=true;
		}
		if(zeroZ){
			Motor3=STOP;
			motorBUSY=false;
			distFromCeroX=0;
			distFromCeroY=0;
			distFromCeroZ=0;
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, 0);
			//mensaje de finalizacion de rutinaOrigen
		}

	}

	if(!rutinaOrigin){
		if(zeroX)
			Motor1=STOP;
		if(zeroY)
			Motor1=STOP;
		if(zeroZ)
			Motor1=STOP;
	}

	//iniciar un contador: si los motores estan prendidos masde 20 seg apagar todo
}



