#ifndef VPROC_H
#define VPROC_H

typedef struct {
		//Register status
		unsigned int	pc;
		unsigned int	sp;
		unsigned int	fp;
		
		//User priveledge
		unsigned int	uid;
		
		//Code and data segments
		unsigned int*	code;
		void*		data;
		unsigned int*	stack;

		unsigned int	code_size;
		unsigned int	data_size;
		unsigned int	stack_size;
} vproc_t;

typedef unsigned int var

//This will make cleaner code since we are always referring to the
//values of the current process
#define pc	current->pc
#define sp	current->sp
#define fp	current->fp
#define code	current->code
#define data	current->data
#define stack	current->stack

//Update process
int tick(vproc_t* process);

#endif
