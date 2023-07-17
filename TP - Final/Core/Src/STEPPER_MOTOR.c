#include "STEPPER_MOTOR.h"
/*
El movimineto de los motores se activa en la rutina de TIM Callback
*/

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


void moverMotor_mm(uint16_t nroMotor, bool dir, uint32_t mms){
	uint32_t steps = mms*STxMM;
	moverMotor_step(nroMotor, dir, steps);
}

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


/*******Funciones mayor abstraccion********/
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
	moverMotor_mm(EJEZ, ABAJO, ALTURA);
}
void subirZ(){
	motorBUSY = true;
	moverMotor_mm(EJEZ, ARRIBA, ALTURA);
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

	static bool zeroX= false, zeroXdone = false;
	static bool zeroY= false, zeroYdone = false;
	static bool zeroZ= false, zeroZdone = false;

	zeroX= LeerEntrada(END_X);
	zeroY= LeerEntrada(END_Y);
	zeroZ= LeerEntrada(END_Z);

	if(rutinaOrigin){
		if(zeroX && !zeroXdone){
			Motor1=STOP;
			moverMotor_mm(EJEY, ADELANTE, MAXDIST_Y);
			motorBUSY=true;
			zeroXdone=true;
		}
		if(zeroY && !zeroYdone){
			Motor2=STOP;
			moverMotor_mm(EJEZ, ARRIBA, MAXDIST_Z);
			motorBUSY=true;
			zeroYdone=true;
		}
		if(zeroZ && !zeroZdone){
			Motor3=STOP;
			motorBUSY=true;
			distFromCeroX=0;
			distFromCeroY=0;
			distFromCeroZ=0;
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, 0);
			zeroZdone=true;
		}
		if (zeroXdone && zeroYdone && zeroZdone){
			rutinaOrigin=false;
			zeroXdone=false;
			zeroYdone=false;
			zeroZdone=false;
			motorBUSY=false;
			lcd_change_text("Origin Done");
  			usart_print("\n\rMoved to origin succesfully.\n\r");
		}

	}

	/*
	if(!rutinaOrigin){
		if(zeroX)
			Motor1=STOP;
		if(zeroY)
			Motor2=STOP;
		if(zeroZ)
			Motor3=STOP;
	}
	*/

	//iniciar un contador: si los motores estan prendidos masde 20 seg apagar todo
}