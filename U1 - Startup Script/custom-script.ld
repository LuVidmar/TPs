/*
Punto 1:
Definir dos regiones de memoria compartida
*/

MEMORY
{
    ROM (rx): ORIGIN = 0x08000000, LENGTH = 64K
    RAM (rwx): ORIGIN = 0x20000000, LENGTH = 20K
}

/*
Punto 2:
Definir simbolo STACK_SIZE
*/

STACK_SIZE = 0x2000; # defino el tamaño de la pila

/*
Punto 3:
Definir entry point de ISR de reset
*/

ENTRY(Reset_Handler);

/*
Punto 4:
Definir secciones de salida:
.text: tabla de vectores de interrupciones y codigo
*/

SECTIONS
{
    .text :
    {
        *(.isr_vector)
        *(.text)
        *(.text*) # cargo el codigo
        . = ALIGN(4);
    } > ROM
}

/*
Punto 5:
Definir combinacion de secciones .bss de archivo de entrada
*/

SECTIONS
{
    .bss (NOLOAD) : # no se carga en memoria
    {
        . = ORIGIN(RAM);
        _sbss = .; # defino comienzo de .bss
        *(.bss*) # carga los .bss
        *(COMMON) # carga datos no inicializados
        . = ALIGN(4);
        _ebss = .; # defino final de .bss
    } > RAM
}

/*
Punto 6:
Definir combinacion de secciones .data de archivo de entrada
*/

SECTIONS
{
    .data :
    {
        _sdata = .; # defino comienzo de .data
        *(.data*) # carga los .data
        . = ALIGN(4);
        _edata = .; # defino final de .data
    } > RAM AT > ROM
}

/*
Punto 7:
Guardar inicio de LMA de .data en un simbolo
*/

_data_loadaddr = LOADADDR(.data);

/*
Punto 8:
Definir seccion .stack
*/

SECTIONS
{
    .stack (NOLOAD) : # no se carga en memoria
    {
        . = ORIGIN(RAM) + LENGTH(RAM) - STACK_SIZE; # defino el comienzo de la pila
        . = ALIGN(4);
        _sstack = .; # defino comienzo de la pila
    }
}