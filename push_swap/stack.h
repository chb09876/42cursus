#ifndef STACK_H
#define STACK_H

typedef struct s_stack
{
	int *arr;
	int reserved;
	int size;
} t_stack;

t_stack *make_stack(int reserved);

#endif