#include "stdio.h"
#include "vproc.h"
#include "disasm.h"
#include "vm-error.h"

int error(char* message, vproc_t* current, int e_offs){
	puts(message);
	regs_dump(current);
	disasm(current, pc - e_offs);
	return VMERR;
}
