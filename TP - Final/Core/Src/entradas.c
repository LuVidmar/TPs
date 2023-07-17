#include "entradas.h"

uint32_t BufferEntradas = 0;

void DebounceEntradas (void)
{
	static uint8_t ContadorEntradas[MAX_ENTRADAS] = {0};
	uint8_t in = 0, x;
	uint8_t i;

	if ( !HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_10) )
		in = 1; //END_X

	if ( !HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_11) )
		in |= 0x02; //END_Y

	if ( !HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_12) )
		in |= 0x04; //END_Z

	x = in ^ BufferEntradas;

	if ( !x )
	{
		for ( i=0 ; i < MAX_ENTRADAS ; i++ )
			ContadorEntradas[i] = 0;
	}
	else
	{
		for ( i=0 ; i<MAX_ENTRADAS ; i++ )
		{
			if ( x & (1<<i) )
			{
				ContadorEntradas[i]++;
				if ( ContadorEntradas[i] >= Rebotes )
						BufferEntradas = BufferEntradas ^ (1<<i);
			}
			else
				ContadorEntradas[i] = 0;
		}
	}
}



uint8_t LeerEntrada ( uint8_t nEntrada )
{
	return ( BufferEntradas >> nEntrada ) & 1;
}