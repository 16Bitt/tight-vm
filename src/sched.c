#include "vproc.h"
#include "sched.h"
#include "vm-error.h"

vproc_t** vproc_list;

void init_sched(){
	vproc_list = (vproc_t**) malloc(sizeof(vproc_t*) * SCHED_SIZE);
	ASSERT(vproc_list, "Couldn't initialize scheduler list")
}

var tick_all(){
	int i;
	for(i = 0; i < SCHED_SIZE; i++)
		if(vproc_list[i])
			tick(vproc_list[i]);
}

var mk_vproc(vproc_t* proc){
	return 0;
}

var rm_vproc(vproc_t* proc){
	return 0;
}
