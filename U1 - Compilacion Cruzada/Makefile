CC = arm-none-eabi-gcc
COMPILEFLAGS = -g -Wall -nostdlib
ARCHFLAGS = -mcpu=cortex-m3 -mthumb

objects = $(wildcard ./src/*.o)
cfiles = $(wildcard ./CFiles/*.c)
hfiles = $(wildcard ./Headers/*.h)

generateobjs: $(cfiles) $(hfiles)
	$(CC) $(COMPILEFLAGS) $(ARCHFLAGS) -c $(cfiles)

pp: $(cfiles)
	$(CC) $(cfiles) -E -o $(subst .c,.i,$(cfiles))

clean:
	rm *.o
	echo "Cleaned up"