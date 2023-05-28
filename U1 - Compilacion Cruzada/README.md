# Compilacion Cruzada

## Consignas

1. Cree una nueva carpeta. Refactorice el proyecto anterior en 4 archivos.
- Ponga las definiciones de registros en registros.h.
- Escriba  dos  funciones  EncenderLED()  y  ApagarLED()  en  led.c,  y  los prototipos de estas en led.h.
2. Modifique el Makefile para crearotro target: led.o
3. Cree el target "all" que compile main y led.
4. Ejecute e comando make all.
5. Desensamble la sección.text de led.o. ¿En qué dirección comienzan el código?Compare con main.o.¿Qué nota respecto a las direcciones de  memoria de las secciones .textde ambos archivos objeto?
6. Investigue qué es una secciónreubicable (rellocatable).