#include "stdio.h"
#include "disasm.h"
#include "vproc.h"

void regs_dump(vproc_t* current){
	printf("PC:\t%X\n", pc);
	printf("SP:\t%X\n", sp);
	printf("FP:\t%X\n", fp);
}

void disasm(vproc_t* current, var address){

}

void data_dump(vproc_t* current){
	int* ptr = (int*) data;
	
	int i;
	for(i = 0; i < (current->data_size / sizeof(int)); i++)
		printf("%X: %X\n", i, ptr[i]);
		
}

void stack_dump(vproc_t* current){
	int i;
	for(i = 0; i < sp; i++)
		printf("%d ", stack[i]);
	
	puts("");
}
