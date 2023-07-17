# Trabajo Practico Final

## Introduccion

El ajedrez es un juego milenario que ha fascinado a jugadores de todas las edades y culturas. Su complejidad estratégica y la necesidad de tomar decisiones basadas en la evaluación de múltiples variables han llevado a los seres humanos a desafiar sus habilidades mentales a través de este apasionante juego.

A partir del avenimiento de la digitalizacion, y con el fin de compartir este grandioso juego con otras personas, se han diseñado muchas aplicaciones que nos permiten jugar remotamente a través de software con cualquier persona del mundo. En este caso nuestro enfoque es como llevar esa experiencia digital al mundo físico, creando un robot que cumpla esta función de mover las piezas como si la persona con la que jugamos se encontrara con nosotros.

En este informe, se detallarán los pasos seguidos para diseñar y construir dicho, así como los desafíos encontrados durante el proceso y las soluciones implementadas.

## Objetivo - Scope

El objetivo de este trabajo es lograr la implementacion de un sistema de juego completamente automatizado en el que a traves de nuestra computadora, podamos jugar al ajedrez con otra persona sin que ninguno de los dos necesite tocar ninguna pieza.

## Hardware

### ***STM32***
- STM32F103C8T6
El microprocesador utilizado durante toda la cursada, ideal para aplicaciones de control de este estilo.

### ***Motores, steppers, finales de carrera***
- x3 Pololu DRV8825
- x3 Leadshine Stepping Motor, bipolar, 1.8◦/stepp, 1,5A
- x3 Finales de carrera

Para el movimiento de nuestro robot se decidio el uso de motores paso a paso, debido a su presicion, velocidad y confiabilidad. Los mismos se controlan mediante un driver que le proporciona la corriente para excitar las bobinas y posee 3 conexiones con la placa: STEP, DIR. La primera recibe los pulsos para activar las bobinas (donde cada pulso equivaldra a 1 step), el segundo sera para diferenciar el sentido de giro.
Como se tienen ejes lineales y el motor tiene un movimiento radial, habra que convertir las vueltas del motor en movimiento lineal. Para ello se utilizo la siguiente formula de conversion: 

El motor tiene 360 grados, y cada paso del motor (step) equivale a 1.8◦. Es decir que para una vuelta completa de motor se tienen que ejecutar 200 stepps. Ademas el movimiento se logra con un tornillo acme de 4 hilos, con un avance de 8mm por vuelta. Entonces queda:

1 vuelta de tornillo    -> 8mm de avance

1 vuelta de tornillo -> 200 pasos

-> 200 pasos/8mm = 25 pasos/mm

Teniendo en cuenta esto, se creo una funcion que recibe como parametro la direccion y cantidad de mm y esta le envia al motor hacia donde cuanto debera moverse.

Lo ultimo que se hizo, es mediante los finales de carrera es setear las coordenadas 0,0,0 de la maquina, para tener nocion del espacio.
Los finales de carrera al ser pushbutton fisicos, al presionar el boton, se puenden obtener falsos positivos, por ruido o por el transitorio de 0 a 1. Por eso se debio crear una rutina de lectura de entradas con debounce. Donde se espera que la lectura de igual 4 veces consecutivas para contarlo como un cambio en el estado del boton.


### ***Electroiman + Alimentacion externa apropiada***

- Electroiman
  
- Modulo Rele con transistor y diodo

- Fuente step-down XL4015, tension regulabre 1.35V-48V, Corriente regulable 0A-5A

Para levantar las piezas se decidio utilizar un electroiman.

Se analizaron distintas opciones pero se termino optando por hacer uno a traves de un bobinado simple y la utilizacion de un pequeño modulo para limitar la corriente y aislar el sistema de potencia respecto del circuito de control.

El mismo consiste en una bobina de cobre esmaltado alrededor de un tornillo ( tambien asilado). Al darle corriente a la bobina, debido al efecto del flujo de campo magnetico a travez de una espira, mediante Fahraday-Lenz, se magnetizas el tornillo para poder levantar la pieza.

Debido al alto consumo del Electroiman (12V - 2A). Se creo un circuito externo para poder enviar la señal de 3.3V 20mA desde el micro al Electroiman, alimentado externamente con un a fuente step-down de 12V, con la corriente limitada por HW a 2A, a travez de un rele en cascada con un transistor, para no sobrecargar la pata del micro.

#todo imagen

### ***LCD + I2C***
- LCD1602A
- PCF8574
Conectaremos el display a traves del modulo I2C con el fin de utilizar menos GPIO. En este display se monstrara informacion sobre las etapas del proceso con el fin de debugguear en caso de fallas en el sistema.

### ***UART***
- CP2102
Componente necesario para interaccion con el usuario a traves de la terminal por serial e interaccion con aplicacion en Python para jugar al ajedrez.

## Montaje

### ***Pinout***
|              |        **Tipo de Pin**       | **I/O** | **Cantidad** |            **Pin**           |
|:------------:|:----------------------------:|:-------:|:------------:|:----------------------------:|
| LCD          | I2C                          |    O    |       2      | PB6, PB7                     |
| UART         | GPIO                         |   I/O   |       2      | PA9, PA10                    |
| 3x Stepper   | 3x GPIO - Dir 3x GPIO - Step |   O O   |      3 3     | PA7, PB13, PB5 PB0, PB1, PB4 |
| 3x End-stops | GPIO                         |    I    |       3      | PB10, PB11, PB12             |
| Electroiman  | GPIO                         |    O    |       1      | PB14                         |

### ***Circuito***
Para comenzar lo montamos todo sobre una breadboard:
#todo insertar fritzing, insertar imagenes de la realidad

Luego pasamos a soldar todos los componentes posibles en una perfboard:
#todo insertar fritzing, insertar imagenes de la realidad

## Software

### ***C***
Todos los modulos que corren en el microprocesador, orientados al contro, estan escritos en lenguaje C y se encuentran en este repositorio. El codigo fue mayormente desarrollado de manera propia, se utilizaron las siguientes librerias:
- #todo agregar librerias, explicar modulos, agregar diagrama de flujo

### ***Python***
Para conseguir una logica de juego continua, se decidio optar por el lenguaje Python que intefacea a traves de serial con el microprocesador.
#todo agregar librerias, explicar modulos, agregar diagrama de flujo


## Implementacion

Para comenzar con la implementacion primero se debe dividir el proceso en sus modulos funcionales. De esta manera, y utilizando principios de OOP, se puede luego implementar estos modulos funcionales como modulos logicos en C. Para ello se identifican los siguientes modulos:

- FSM (Finite State Machine) -> Responsable de orquestrar todos los procesos internos del programa, luego del set-up inicial, el programa iterara infinitamente sobre la FSM, que decidira que subprocesos ejecutar.
- Modulo LCD -> Modulo encargado del control del display LCD a traves de I2C.
- Modulo UART -> Las interacciones con el usuario y con la aplicacion de Python se realizara a traves de este modulo.
- Modulo Motores -> Como lo indica su nombre, controlara los motores, finales de carrera, electroiman, etc.

## Desafios

Como desafio principal, mas alla de hacer funcionar lo propuesto, nos propusimos a hacer un programa que sea 100% NO-BLOQUEANTE. Esto a la primera puede sonar muy bueno, logico y facil. A la hora de implementarlo surgen muchos problemas que en primera instancia estaban ocultos. Ya que en la solucion esta el problema. Como hacer que todo ande a la vez, que no sea bloqueante, pero que a su vez, no se pisen los distintos modulos. Ya que por ejemplo. Si un motor esta andando, no hay un delay(1000), esperando a que se termine de mover. 
Esto tambien dificulta el debbugeo ya que muchas cosas corren con interrupciones o durante varios ciclos de clock.

Pero con planeamiento previo y debugeo logramos resultdos muy positivos. 

Lo que nos permite haber hecho esto, es que la escalabilidad del proyecto es mucho mas facil, ya que se podria embeber en un RTOS o agregas otras funcionalidades que funciones en "paralelo", sin perjudirar el correcto funcionameieneto de lo que ya tenemos.

Otro desafio que tuvimos (un poco en sintonia con el anterior) fue poder diseccionar el proyecto y poder abarcarlo de a partes mas pequeñas sin perder de vista la funcionalidad macro. Al ser un proyecto ambisioso a la hora de querer abordar los pequeños modulos, se podia perder un poco la vision general. Con que me refiero a esto. A veces nos paso que en el afan de querer hacer andar una parte, por ejemplo el motor, al tenerlo andando por su cuenta, no siempre se acoplaba bien a la primera y habia que hacermodificaciones y darle una vuelta de rosca para que funcione todo en sintonia.

## Conclusion


## Proximos pasos
- Conexion de los pines ENABLE de los drives para poder apagar los motores en runtime
- Antes de comer una ficha, deberia mover la pieza a comer, fuera del tablero. Y luego mover la pieza seleccionada.
  
### ***Creacion de librerias propias***
#todo 
### ***Implementacion de interfaz grafica y juego a traves de internet***
#todo
