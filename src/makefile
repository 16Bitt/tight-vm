SOURCES = main.o vm-error.o vm.o disasm.o opcodes.o vm-file.o vsock.o
CFLAGS	= -w -Iheader/ -m32 -ggdb
OUTPUT	= main

all: init $(SOURCES)
	cc $(CFLAGS) $(SOURCES) -o $(OUTPUT)

init:
	./utils/gendict opcodes.dict header/opcodes.h opcodes.c

uninit:
	-rm header/opcodes.h

clean: uninit
	-rm *.o $(OUTPUT)

gdb:
	sudo gdb ./$(OUTPUT)

run: all
	./$(OUTPUT)
