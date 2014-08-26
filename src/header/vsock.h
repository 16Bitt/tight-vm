#ifndef VSOCK_H
#define VSOCK_H

//For 'var' datatype
#include "vproc.h"

typedef struct{
	//Required priveledge, smaller is higher priveledge
	var priveledge;
	//Pid of owner, 0 if public
	var pid;

	//If not zero, socket is locked
	var locked;

	//Location to write
	var input;
	//Location to read
	var ouput;
} vsock_t;

//Make a socket
vsock_t*	mk_vsock(var priveledge, var pid);
//Remove a socket
void		rm_vsock(vsock_t* socket);

#endif
