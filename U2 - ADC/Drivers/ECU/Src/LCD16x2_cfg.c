
#include "../../ECU/Inc/LCD16x2.h"

const LCD16x2_CfgType LCD16x2_CfgParam =
{
	GPIOA,      //Puerto
	GPIO_PIN_3, //D4
	GPIO_PIN_4, //D5
	GPIO_PIN_5, //D6
	GPIO_PIN_6, //D7
	GPIO_PIN_1, //EN
	GPIO_PIN_2, //RS
	50          //La mayoria de los delays estan entre 40 y 50
};
