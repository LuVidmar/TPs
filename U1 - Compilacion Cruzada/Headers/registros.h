#ifndef         REGISTROS_H
#define         REGISTROS_H

#define         RCC_APB2ENR     (*((int*)0x40021018))
#define         GPIOC_BASE      (0x40011000U)
#define         GPIOC_CRH       (*((int*)(GPIOC_BASE + 0x4)))
#define         GPIOC_ODR       (*((int*)(GPIOC_BASE + 0xC)))

#endif