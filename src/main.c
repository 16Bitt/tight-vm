#include "stdio.h"
#include "opcodes.h"
#include "vproc.h"
#include "disasm.h"
#include "stdio.h"
#include "vm-file.h"
#include "vm-error.h"

int main(){
	FILE* file = fopen("./userland/tty", "rb");
	ASSERT(file, "Couldn't open tty server binary")
	FILE* file2 = fopen("./userland/test", "rb");
	ASSERT(file2, "Couldn't open test client binary")

	unsigned char buf[512];
	unsigned char buf2[512];
	fread(buf, 512, 1, file);
	fread(buf2, 512, 1, file2);
	fclose(file);
	fclose(file2);
	
	puts("");

	init_sched();
	init_vsocks();
	vproc_t* vp = load_vfile((void*) buf, 0);
	vproc_t* vp2 = load_vfile((void*) buf2, 0);
	mk_vproc(vp);
	mk_vproc(vp2);
	
	while(1)
		tick_all();
	
	return 0;
}
