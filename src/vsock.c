#include "vproc.h"
#include "vsock.h"
#include "vm-error.h"
#include "stdlib.h"

vsock_t** vsock_list;

void init_vsocks(){
	vsock_list = (vsock_t**) malloc(sizeof(vsock_t*) * VSOCK_SIZE);
	
	int i;
	for(i = 0; i < VSOCK_SIZE; i++)
		vsock_list[i] = (vsock_t*) 0;
}

var mk_vsock(var priveledge, var pid){
	vsock_t* socket = (vsock_t*) malloc(sizeof(vsock_t));
	ASSERT(socket, "No memory for socket creation")
	
	socket->priveledge	= priveledge;
	socket->pid		= pid;
	
	int i;
	for(i = 0; i < VSOCK_SIZE; i++)
		if(!vsock_list[i]){
			vsock_list[i] = socket;
			return i;
		}


	ASSERT(0, "VSocket memory is too full for socket creation");
}

var rm_vsock(var sock_id){
	ASSERT(vsock_list[sock_id], "Removed nonexistent socket")
	free(vsock_list[sock_id]);
	vsock_list[sock_id] = (vsock_t*) 0;

	return 0;
}
