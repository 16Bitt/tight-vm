SOURCES		= main.o vm-error.o vm.o disasm.o opcodes.o vm-file.o vsock.o sched.o
USERMODE	= tty test
CFLAGS		= -w -Iheader/ -m32 -ggdb
OUTPUT		= main

all: init $(SOURCES) usermode
	cc $(CFLAGS) $(SOURCES) -o $(OUTPUT)

init:
	./utils/gendict opcodes.dict header/opcodes.h opcodes.c

uninit:
	-rm header/opcodes.h

usermode:
	bin/mkmult $(USERMODE)

clean: uninit
	-rm *.o $(OUTPUT) userland/*

gdb:
	sudo gdb ./$(OUTPUT)

run: all
	./$(OUTPUT)
