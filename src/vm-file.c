#include "vm-file.h"
#include "vproc.h"
#include "stdio.h"
#include "vm-error.h"

vproc_t* load_vfile(vfile_t* file, var uid){
	ASSERT(!validate_vfile(file), "Can't validate vfile_t*");

	void* offset = ((unsigned int) ((void*) file)) + (unsigned int) sizeof(vfile_t);
	/*printf("magic %X\n", file->magic);
	printf("cstart %X\n", file->code_start);
	printf("xstart %X\n", file->exit_start);
	printf("dsize %X\n", file->data_size);
	printf("csize %X\n", file->code_size);
	printf("ssize %X\n", file->stack_size);
	printf("perms %X\n", file->permissions);*/
	return new_proc((int*) offset, file->code_size, file->data_size, file->stack_size, file->code_start, uid);
}

var validate_vfile(vfile_t* file){
	if(file->magic != VFILE_MAGIC)
		return VFILE_INVALID;

	return 0;
}
