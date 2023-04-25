#define         RCC_APB2ENR     (*((int*)0x40021018))
#define         GPIOC_BASE      (0x40011000U)
#define         GPIOC_CRH       (*((int*)(GPIOC_BASE + 0x4)))
#define         GPIOC_ODR       (*((int*)(GPIOC_BASE + 0xC)))

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
    // apagamos LED mediante "Port output data register" (pagina 173)
    GPIOC_ODR |= 1<<13;

    // delay por software
    for(int i = 0; i < 500000; i++);

    // encendemos LED mediante "Port output data register" (pagina 173)
    GPIOC_ODR &= ~(1U<<13);

    // delay por software
    for(int i = 0; i < 500000; i++);

  }

  return 0;
}
