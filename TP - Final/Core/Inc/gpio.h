#ifndef __GPIO_H__
#define __GPIO_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

#define ONBOARD_LED_Pin GPIO_PIN_13

/* ------- Functions ------- */
void MX_GPIO_Init(void);
void electromagnet_on(void);
void electromagnet_off(void);
void electromagnet_toggle(void);

#ifdef __cplusplus
}
#endif
#endif /*__ GPIO_H__ */