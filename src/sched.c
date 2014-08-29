#include "vproc.h"
#include "sched.h"
#include "vm-error.h"

vproc_t** vproc_list;

void init_sched(){
	vproc_list = (vproc_t**) malloc(sizeof(vproc_t*) * SCHED_SIZE);
	ASSERT(vproc_list, "Couldn't initialize scheduler list")
	
	int i;
	for(i = 0; i < SCHED_SIZE; i++)
		vproc_list[i] = (vproc_t*) 0;
}

var tick_all(){
	int i;
	for(i = 0; i < SCHED_SIZE; i++)
		if(vproc_list[i]){
			int status = tick(vproc_list[i]);
			if(status)
				rm_vproc(vproc_list[i]);
		}
}

var mk_vproc(vproc_t* proc){
	int i;
	for(i = 0; i < SCHED_SIZE; i++)
		if(!vproc_list[i]){
			vproc_list[i] = proc;
			return 0;
		}
	
	//Empty frame couldn't be found, error
	return 0xFFFFFFFF;
}

var rm_vproc(vproc_t* proc){
	int i;
	for(i = 0; i < SCHED_SIZE; i++)
		if(vproc_list[i] == proc){
			vproc_list[i] = (vproc_t*) 0;
			return 0;
		}
	
	return 0xFFFFFFFF;
}
