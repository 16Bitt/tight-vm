#include "stdio.h"
#include "vproc.h"
#include "disasm.h"
#include "vm-error.h"
#include "stdlib.h"

int error(char* message, vproc_t* current, int e_offs){
	puts(message);
	regs_dump(current);
	disasm(current, pc - e_offs);
	return VMERR;
}

void e_fatal(char* message, char* file, int line){
	printf("[%s:%d]Fatal!\t%s\n", file, line, message);
	exit -1;	
}
