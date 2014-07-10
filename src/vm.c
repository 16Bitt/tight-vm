#include "vproc.h"
#include "stdio.h"
#include "vm-error.h"

int tick(vproc_t* current){
	var op = code[pc];
	pc++;

	var a, b;
	switch(op){
		case NOP:
			break;
		case ADDI:
			a = stack[--sp];
			b = stack[--sp];
			stack[sp++] = a + b;
			break;
		case SUBI:
			a = stack[--sp];
			b = stack[--sp];
			stack[sp++] = b - a;
			break;
		case MULI:
			a = stack[--sp];
			b = stack[--sp];
			stack[sp++] = a * b;
			break;
		case DIVI:
			a = stack[--sp];
			b = stack[--sp];
			stack[sp++] = b / a;
			break;
		case PRINTI:
			printf("%u", stack[--sp]);
			break;

		default:
			return error("Unrecognized opcode", current);
			break;
	}
}
