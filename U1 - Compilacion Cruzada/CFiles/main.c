#include "../Headers/leds.h"
#include "../Headers/registros.h"

int main()
{
  // habilitamos clock a GPIOC mediante "APB2 peripheral clock enable register" 
  RCC_APB2ENR |= 1U << 4;

  // Ponemos a GPIOC 13 como salida push-pull (frec. max. de 50 MHz)
  // con MODE elejimos "Output mode, max speed 50 MHz." (pagina 171)
  GPIOC_CRH |=  (0x3 << 20);
  // con CNF seleccionamos  "General purpose output push-pull" (pagina 171)
  GPIOC_CRH &= ~(0x3 << 22);

  while(1){
    
    apagarLeds(13); //apago led controlable por bit 13 (pagina 173)

    // delay por software
    softwareDelay(500000);

    apagarLeds(13); //encender led controlable por bit 13 (pagina 173)

    // delay por software
    softwareDelay(500000);

  }

  return 0;
}
