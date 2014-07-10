#ifndef VPROC_H
#define VPROC_H

typedef struct {
		//Register status
		unsigned int	pc_;
		int		sp_;
		unsigned int	fp_;
		
		//User priveledge
		unsigned int	uid;
		
		//Code and data segments
		unsigned int*	code_;
		void*		data_;
		unsigned int*	stack_;

		unsigned int	code_size;
		unsigned int	data_size;
		unsigned int	stack_size;
} vproc_t;

typedef unsigned int var;

//This will make cleaner code since we are always referring to the
//values of the current process
#define pc	current->pc_
#define sp	current->sp_
#define fp	current->fp_
#define code	current->code_
#define data	current->data_
#define stack	current->stack_

//Update process
int tick(vproc_t* process);
vproc_t* new_proc(int*, int, int, int, int, int);
void cleanup_proc(vproc_t* current);

#define VM_OK	(1)

#endif
