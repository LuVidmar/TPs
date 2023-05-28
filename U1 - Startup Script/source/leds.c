#include "../Headers/leds.h"

int apagarLeds(int ledNumber){
    // apagamos LED mediante "Port output data register"
    GPIOC_ODR |= 1<<ledNumber;
    return 1;
}

int encenderLeds(int ledNumber){
    // encendemos LED mediante "Port output data register"
    GPIOC_ODR &= ~(1U<<ledNumber);
    return 1;
}

void softwareDelay(int ticks){
    if (ticks <= 0)
        return;
    for(int i = 0; i < ticks; i++);
}