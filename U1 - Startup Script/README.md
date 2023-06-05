# Startup Script

El objetivo de esta práctica es crear código de startup básico para el microcontrolador STM32F103C8T6.

## Consigna

1. Cree un archivo con el nombre startup.c .
2. Necesitará de símbolos definidos en el linker script. Defina los que sean necesarios como variables externas enteras sin signo (*extern uint32_t*). ¿Por qué es necesario el modificador *extern*?
3. Declare lo prototipos de las funciones que utilizara en el resto del archivo. Por ejemplo, *int main(void)*, y manejadores de interrupciones (ISRs o handlers).
4. Escriba la tabla de vectores de excepciones/interrupciones. Declárela como un array de tipo *uint32_t*. Colóquela en la sección **.vectors** (o un nombre de su preferencia). Para ellos utilice la directiva `__attribute__((section(...)))`.
5. Escriba los manejadores de excepción/interrupción (ISRs o exception/interrupt handlers). Para evitar escribir un manejador para cada excepción o interrupción, puede escribir uno solo (ejemplo: *void Default_Handler()* ) y utilizarlo como alias de los manejadores que tendrán un determinado comportamiento por defecto (como un bucle infinito). Para ellos utilice las directivasde atributo weak y alias.
6. Escriba el manejador de reset (*Reset_Handler*). Dentro de este debe:
   - Inicializar las “variables inicializadas”, las cuales se ubican enla sección **.data** de la RAM. Para ellos utilicelos valores iniciales de estamisma seccióncargados en ROM. Recuerde que **.data** tiene una direcciónVMA diferente de la LMA.
   - Inicializar las variables “no inicializadas”a cero. Para ello, debe borrar el contenido de la sección **.bss**.
   - Llamar a la función *main()*.