#include "stdio.h"
#include "opcodes.h"
#include "vproc.h"
#include "disasm.h"
#include "stdio.h"
#include "vm-file.h"
#include "vm-error.h"

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

var run3[] = {
	MKSOCK,
	DUP,
	NOP,
	NOP,
	CONSTI, 69,
	RTSOCK,
	HALT
};

var run4[] = {
	CONSTI, 0,
	DUP,
	LKSOCK,
	RDSOCK,
	PRINTI,
	HALT
};

int main(){
	FILE* file = fopen("./userland/tty", "rb");
	ASSERT(file, "Couldn't open vfile")
	
	unsigned char buf[512];
	fread(buf, 512, 1, file);
	
	puts("");

	init_sched();
	init_vsocks();
	vproc_t* vp = load_vfile((void*) buf, 0);
	disasm(vp, 0);
	mk_vproc(vp);
	
	while(1) tick_all();
	
	return 0;
}
