# Flags
CC := arm-none-eabi-gcc --specs=nosys.specs
COMPILEFLAGS := -g -Wall -nostdlib
ARCHFLAGS := -mcpu=cortex-m3 -mthumb # architecture
LINKERFILE := custom-script.ld
LINKFLAGS := -T $(LINKERFILE) -nostartfiles

# Commands
LINK := $(CC) $(LINKFLAGS)
COMPILE := $(CC) $(COMPILEFLAGS) $(ARCHFLAGS)

# Directories
sourcedir := source
builddir := build
preprocesseddir := preprocessed
headersdir := headers

# Files
cfiles = $(wildcard $(sourcedir)/*.c)
ofiles = $(wildcard $(builddir)/*.o)

# Functions
all: build link binary
build: $(patsubst %.c, %.o, $(cfiles))
pp: $(patsubst %.c, %.i, $(cfiles))

%.o: %.c
	@echo "Compiling $< into $@:"
	@mkdir -p $(builddir)
	$(COMPILE) -c $< -o $(subst $(sourcedir),$(builddir),$@)

%.i: %.c
	@echo "Preprocessing $< into $@:"
	@mkdir -p $(preprocesseddir)
	$(COMPILE) -E $< -o $(subst $(sourcedir),$(preprocesseddir),$@)

link: build
	@echo "Linking object files into build/application.elf:"
	$(LINK) $(ofiles) -o $(builddir)/application.elf

binary: link
	@echo "Generating binary file from build/application.elf:"
	arm-none-eabi-objcopy -O binary $(builddir)/application.elf $(builddir)/application.bin

clean:
	@echo "Removing build and preprocessed directories"
	@rm -r -f build
	@rm -r -f preprocessed
	@echo "Cleaned up"