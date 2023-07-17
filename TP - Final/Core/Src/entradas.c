#include "entradas.h"

uint32_t BufferEntradas = 0;

void DebounceEntradas (void)
{
	static uint8_t ContadorEntradas[MAX_ENTRADAS] = {0};
	uint8_t in = 0, x;
	uint8_t i;

	if ( !HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_10) )
		in |= 0x01; //END_X bit 0

	if ( !HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_11) )
		in |= 0x02; //END_Y bit 1

	if ( !HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_12) )
		in |= 0x04; //END_Z bit 2

	x = in ^ BufferEntradas; // Deteccion de flanco, XOR (son diferentes es 1)

	if ( !x ) // No hay flanco, todo en cero
	{
		for ( i=0 ; i < MAX_ENTRADAS ; i++ )
			ContadorEntradas[i] = 0;
	}
	else // Hay flanco, actualizar variables
	{
		for ( i=0 ; i<MAX_ENTRADAS ; i++ )
		{
			if ( x & (1<<i) ) // Si hay flanco en la entrada i
			{
				ContadorEntradas[i]++; // Incrementar contador
				if ( ContadorEntradas[i] >= Rebotes ){ // Si se supera el umbral, cambiar estado
					BufferEntradas = BufferEntradas ^ (1<<i);
					ContadorEntradas[i] = 0;
				}
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