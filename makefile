SOURCES = main.o
CFLAGS	= -w
OUTPUT	= main

all: $(SOURCES)
	cc $(CFLAGS) $(SOURCES) -o $(OUTPUT)

init:
	./utils/gendict opcodes.dict header/opcodes.h

uninit:
	-rm header/opcodes.h

clean:
	-rm *.o $(OUTPUT)

run: all
	./$(OUTPUT)
