# Linker Script

El objetivo de esta prácticaes crear un linker script básico para el microcontrolador STM32F103C8T6.

## Consignas

El linker script obtenidose pasa por parámetro a `arm-none-eabi-gcc` (sin opciones -c, -S, -E, de modo que se llegue hasta la etapa de enlazado), o a `arm-none-eabi-ld` (linker) luego del flag -T.
1. Definados regiones de memoria mediante el comando MEMORY:
- una de **ROM** (o FLASH) que comience en la dirección 0x08000000 y tenga tamaño 64kiB.
- una de **RAM** que comience en 0x20000000 y tenga tamaño 20kiB.
2. Defina un símbolo **STACK_SIZE** cuyo valor sea 0x2000. Esto será usado luego para definir el espacio de memoria RAM reservado para pila.
3. Defina como entry point al reset handler (ISR de reset) mediante el comando *ENTRY*. El símbolo de reset handler deberá ser exactamente el mismo que use en el código startup, por ejemplo **ResetHandler** o **Reset_Handler**. Defina secciones de salida.
4. **.text**: que contenga primero la tabla de vectores deinterrupción, y luego las porciones de código ejecutable (por defecto **.text**) de los archivos de entrada. Coloque esta secciónen ROM (FLASH).
5. **.bss**: combinación de secciones .bss de archivo de entrada. Marque a esta sección con la directiva *NOLOAD*. Cree símbo los para el inicio y el final de la sección **.bss**, por ejemplo **_sbss** y **_ebss**, respectivamente. Estos símbolos serán útiles en el código de startup para inicializar esta sección. Coloque esta sección en RAM.
6. **.data**: combinación de secciones **.data** de archivo de entrada. Cree símbolos para el inicio y el final de la sección **.data**, por ejemplo **_sdata** y **_edata**, respectivamente. Estos símbolos serán útiles en el código de startup para inicializar esta sección. Recuerde que esta sección tiene una VMA diferente de la LMA: las variables “viven” en RAM, pero sus valores iniciales estarán en ROM.Recuerde el comando *AT*.
7. Guarde el inicio de LMA del inciso anterior en un símbolo (**_data_loadaddr** por ejemplo) con el comando *LOADADDR*. Esto es útilen el código de startup para inicializar la sección **.data**.
8. Reserve espacio en la pila. Para ello defina una sección marcada como *NOLOAD* que luego colocara en RAM. Use el símbolo **STACK_SIZE** para definir el tamaño a reservar. Marque el inicio de pila con un símbolo (**_sstack** por ejemplo). Investigue en qué sentido crece la pila en ARM Cortex-M3, y en base a eso decida si dicho símbolo deberá ser colocado al inicio de la definición de la sección, o al final.