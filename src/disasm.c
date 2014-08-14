#include "stdio.h"
#include "disasm.h"
#include "vproc.h"
#include "opcodes.h"

void regs_dump(vproc_t* current){
	printf("PC:\t%X\n", pc);
	printf("SP:\t%X\n", sp);
	printf("FP:\t%X\n", fp);
}

void disasm(vproc_t* current, var address){
	int i;
	int offset;
	for(i = 0, offset = 0; offset < 4; offset++){
		if((address + i) >= current->code_size)
			break;

		if((code[address + i] > (NUM_OPS - 1)) || (code[address + i] < 0))
			printf("%X:\tUNDEFINED OPCODE\n", address + i);
		else{
			printf("%X:\t%s", address + i, op_str_val[code[address + i]]);
			i++;
			int j;
			for(j = 0; j < op_len_val[code[address + i + j]]; j++, i++)
				printf(" %X", code[address + i + j]);

			puts("");
		}
	}
}

void data_dump(vproc_t* current){
	int* ptr = (int*) data;
	
	int i;
	for(i = 0; i < (current->data_size / sizeof(int)); i++)
		printf("%X: %X\n", i * 4, ptr[i]);
		
}

void stack_dump(vproc_t* current){
	int i;
	for(i = 0; i < sp; i++)
		printf("%d ", stack[i]);
	
	puts("");
}
