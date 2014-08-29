#include "stdio.h"
#include "opcodes.h"
#include "vproc.h"
#include "disasm.h"

var run1[] = {
	DBG,
	CONSTI, 65,
	PRINTI,
	CONSTI, 66,
	PRINTI,
	HALT
};

var run2[] = {
	DBG,
	CONSTI, 67,
	PRINTI,
	CONSTI, 68,
	PRINTI,
	CONSTI, 10,
	EMITB,
	HALT
};

int main(){
	vproc_t* p1 = new_proc(run1, 8, 0, 4, 0, 0);
	vproc_t* p2 = new_proc(run2, 11, 0, 4, 0, 0);

	int status1	= 0;
	int status2	= 0;
	while(1){
		if(!status1)
			status1 = tick(p1);
		if(!status2)
			status2 = tick(p2);
		
		if(status1 && status2)
			break;
	}
	
	return 0;
}
