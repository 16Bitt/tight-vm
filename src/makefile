SOURCES = main.o
CFLAGS	= -w -Iheader/
OUTPUT	= main

all: init $(SOURCES)
	cc $(CFLAGS) $(SOURCES) -o $(OUTPUT)

init:
	./utils/gendict opcodes.dict header/opcodes.h

uninit:
	-rm header/opcodes.h

clean: uninit
	-rm *.o $(OUTPUT)

run: all
	./$(OUTPUT)
