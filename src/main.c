#include "stdio.h"
#include "opcodes.h"
#include "vproc.h"
#include "disasm.h"

var run1[] = {
	DBG,
	CONSTI, 65,
	PRINTI,
	BR, 1,
	PRINTI,
	HALT
};

var run2[] = {
	DBG,
	CONSTI, 67,
	PRINTI,
	BR, 1,
	PRINTI,
	CONSTI, 10,
	EMITB,
	HALT
};

int main(){
	vproc_t* p1 = new_proc(run1, 8, 0, 4, 0, 0);
	vproc_t* p2 = new_proc(run2, 11, 0, 4, 0, 0);

	init_sched();
	mk_vproc(p1);
	mk_vproc(p2);

	while(1) tick_all();
	
	return 0;
}
