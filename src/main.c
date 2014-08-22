#include "stdio.h"
#include "opcodes.h"
#include "vproc.h"
#include "disasm.h"

var run[] = {
	CONSTI, 1,
	CONSTI, 1,
	ADDI,
	DBG,
	HALT
};

int main(){
	vproc_t* current = new_proc(run, 7, 0, 4, 0, 0);
	int status = 0;
	while(!status){
		status = tick(current);
	}
	
	return 0;
}
