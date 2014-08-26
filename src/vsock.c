#include "vproc.h"
#include "vsock.h"
#include "vm-error.h"
#include "stdlib.h"

vsock_t* mk_vsock(var priveledge, var pid){
	vsock_t* socket = (vsock_t*) malloc(sizeof(vsock_t));
	ASSERT(socket, "No memory for socket creation")
}

void rm_vsock(vsock_t* priveledge){

}
