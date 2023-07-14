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
- Pololu A4988
- #todo insertar modelo de motores
#todo insertar explicacion

### ***Electroiman + XXXXX***
#todo modulo limitador de corriente y explicacion, optoacoplador, etc 
Para el electroiman, se analizaron distintas opciones pero se termino optando por hacer uno a traves de un bobinado simple y la utilizacion de un pequeno modulo para limitar la corriente y aislar el sistema de potencia respecto del circuito de control.

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

## Conclusion
#todo

## Proximos pasos

### ***Creacion de librerias propias***
#todo 
### ***Implementacion de interfaz grafica y juego a traves de internet***
#todo
