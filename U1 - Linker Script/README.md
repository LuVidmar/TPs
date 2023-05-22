# Linker Script

El objetivo de esta prácticaes crear un linker script básico para el microcontrolador STM32F103C8T6.

## Consignas

El linker script obtenidose pasa por parámetroa arm-none-eabi-gcc(sin opciones -c, -S, -E, de modo que se llegue hasta la etapa de enlazado), o a arm-none-eabi-ld (linker)luego del flag -T.
1. Definados regiones de memoriamediante el comando MEMORY:
- una de ROM(o FLASH) que comience enla dirección0x08000000 y tenga tamaño 64kiB.
- una de RAMque comience en 0x20000000y tenga tamaño 20kiB.
2. Defina un símboloSTACK_SIZEcuyo valor sea 0x2000. Esto seráusado luego para definir el espacio de memoria RAM reservado para pila.
3. Defina como  entry  point  al  reset  handler  (ISR de  reset)  mediante  el  comando ENTRY. El símbolode reset handler deberáser exactamente el mismo que use en el códigostartup, por ejemplo ResetHandlero Reset_Handler.Defina secciones de salida.
4. .text:que contenga  primero  la  tabla  de  vectores  deinterrupción,  y  luego  las porciones  de códigoejecutable(por  defecto  .text)de  los  archivos  de  entrada.Coloque esta secciónen ROM (FLASH).
5. .bss: combinaciónde secciones .bss de archivodeentrada. Marque a esta seccióncon la directiva NOLOAD. Cree símbolospara el inicio y el final de la sección.bss, por  ejemplo_sbss  y  _ebss,  respectivamente.  Estos símbolosseránútilesen  el códigode startup para inicializar esta sección.Coloque esta secciónen RAM.
6. .data: combinaciónde secciones .datade archivodeentrada.Cree símbolospara el inicio y el final de la sección.data, por ejemplo_sdatay _edata,respectivamente. Estos símbolosseránútilesen el códigode startup para inicializar esta sección. Recuerde que  esta seccióntiene  una VMA  diferente  de  la LMA:  las  variables “viven”  en  RAM,  pero  sus  valores  iniciales estaránen  ROM.Recuerde  el comando AT.
7. Guarde  el  inicio  de  LMA  del  inciso  anterior  en  un símbolo(_data_loadaddrpor ejemplo)con  el  comando LOADADDR.Esto  es útilen  el códigode  startup  para inicializar la sección.data.
8. Reserve espacio en la pila. Para ello defina una secciónmarcada como NOLOAD que luego colocara en RAM. Use el símboloSTACK_SIZE para definir el tamaño a reservar. Marque  el  inicio  de  pila  con  un símbolo(_sstack  por  ejemplo).  Investigue  en  qué sentido crece la pila en ARM Cortex-M3, y en base a eso decida si dicho símbolodeberáser colocado al inicio de la definiciónde la sección, o al final.