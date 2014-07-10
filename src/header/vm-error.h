#ifndef VM_ERROR_H
#define VM_ERROR_H
#include "vproc.h"

#define VMERR	(-1)

int error(char* message, vproc_t* process, int e_offs);

#endif
