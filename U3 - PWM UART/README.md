# Medidor de tensión extendido

Tiene como objetivo extender el funcionamiento del Medidor de Tensión para mostrar información a través de dos nuevas interfaces: PWM y UART. 

## Consignas

1. Configurar y programar una salida PWM del microcontrolador de modo que la entrada analógica por donde se mide la tensión varíe la intensidad de un LED externo a la placa. Utilice una escala lineal, de modo que para una entrada de tensión de cero volts (0V) el LED esté completamente apagado (ciclo de trabajo de la PWM: 0%), mientras que una entrada de 3,3 V se traduzca en un LED completamente encendido (ciclo de trabajo de la PWM: 100%). 
2. Enviar la información de tensión medida hacia una computadora a través de puerto serie en intervalos de 0,5 segundos. El formato debe ser:

> Tensión medida: x,xx V

Donde x,xx es el valor de tensión medido, que va de 0,00 V a 3,33 V.  

Configurar la comunicación serie con los siguientes parámetros: 9600 8N1, es decir, 9600 baudios, 8 bits de datos, sin bit de paridad, 1 bit de stop.

## Diagramas

### Pinout

### Circuito