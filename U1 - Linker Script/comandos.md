## Generacion de binario y programacion con STM32_Programmer_CLI


### Compilacion:
`arm-none-eabi-gcc -o main.o -c -g -nostdlib -mcpu=cortex-m3 -mthumb main.c`

### Linkeo:
`arm-none-eabi-gcc -o application.elf -Wl, -T linker_script.ld -nostartfiles main.o`

### Generacion de binario:
`arm-none-eabi-objcopy -O binary application.elf application.bin`

### Flasheo de micro:
`STM32_Programmer_CLI -c port=SWD -w application.bin  0x08000000`

### Run de aplicacion:
`STM32_Programmer_CLI -c port=SWD -s`

## Debugging con GDB

### Inicia server con:
`C:\ST\STM32CubeIDE_1.12.0\STM32CubeIDE\plugins\com.st.stm32cube.ide.mcu.externaltools.stlink-gdb-server.win32_2.0.500.202301161003\tools\bin\ST-LINK_gdbserver.exe -p 61234 -l 1 -d -s -cp`

`C:\ST\STM32CubeIDE_1.12.0\STM32CubeIDE\plugins\com.st.stm32cube.ide.mcu.externaltools.cubeprogrammer.win32_2.0.600.202301161003\tools\bin -m 0 -k`

### En otra terminal se inicia cliente con:
`arm-none-eabi-gdb application.elf`

### Dentro de gdb nos conectamos con el servidor mediante:
`target remote localhost:61234`
(o el puerto que corresponda)

### Se da continuacion al programa con:
`continue`

Se hace un halt con **Ctrl+C**