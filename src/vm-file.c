#include "vm-file.h"
#include "vproc.h"

vproc_t* load_vfile(vfile_t* file, var uid){
	validate_vfile(file);

	var offset = ((var) ((void*) file)) + (var) sizeof(vfile_t);
	return new_proc((int*) offset, file->code_size, file->data_size, file->stack_size, file->code_start, uid);
}

var validate_vfile(vfile_t* file){
	if(file->magic != VFILE_MAGIC)
		return VFILE_INVALID;

	return 0;
}
