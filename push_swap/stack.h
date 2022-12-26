#ifndef STACK_H
#define STACK_H

#include "node.h"

typedef struct s_stack
{
	int size;
	t_node *top;
	t_node *bottom;
} t_stack;

t_stack *make_empty_stack();
t_stack *make_stack_with_list(int *arr, int size);
void push(t_stack *stack, t_node *node);
t_node *pop(t_stack *stack);
int print_stack(t_stack *stack);

#endif