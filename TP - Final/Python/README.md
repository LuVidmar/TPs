# Protocolo

1. STM32 envia comando 'STM-Ready.' indicando que esta listo para recibir instrucciones.
2. PC inicializa el tablero y pide al jugador que ingrese un movimiento.
3. PC Valida el movimiento.
4. PC envia el movimiento al STM32 y espera confirmacion de que el movimiento fue realizado.
5. STM32 avisa que el movimiento fue realizado.
6. Volver al paso 2.

>> Si falla la transmision de datos (es incorrecto el comando), STM32 envia 'STM-Error.' y se vuelve al paso 1.