#include "operation.h"
#include "node.h"
#include <unistd.h>

void op_swap(t_stack *stack, const char *op)
{
	t_node *tmp1;
	t_node *tmp2;

	if (stack->size < 2)
		return;
	tmp1 = pop(stack);
	tmp2 = pop(stack);
	push(stack, tmp1);
	push(stack, tmp2);
	if (op != NULL)
		write(1, op, 3);
}

void op_swap_same(t_stack *a, t_stack *b, const char *op)
{
	op_swap(a, NULL);
	op_swap(b, NULL);
	if (op != NULL)
		write(1, op, 3);
}

void op_push(t_stack *from, t_stack *to, const char *op)
{
	if (from->size > 0)
		push(to, pop(from));
	if (op != NULL)
		write(1, op, 3);
}

void op_rotate(t_stack *stack, const char *op)
{
	t_node *node;

	if (stack->size > 1)
	{
		node = pop(stack);
		node->next = stack->bottom;
		stack->bottom = node;
		stack->top->next = NULL;
		++stack->size;
	}
	if (op != NULL)
		write(1, op, 3);
}

void op_rotate_same(t_stack *a, t_stack *b, const char *op)
{
	op_rotate(a, NULL);
	op_rotate(b, NULL);
	if (op != NULL)
		write(1, op, 3);
}

void op_rrotate(t_stack *stack, const char *op)
{
	if (stack->size > 1)
	{
		stack->top->next = stack->bottom;
		stack->top = stack->bottom;
		stack->bottom = stack->bottom->next;
		stack->top->next = NULL;
	}
	if (op != NULL)
		write(1, op, 4);
}

void op_rrotate_same(t_stack *a, t_stack *b, const char *op)
{
	op_rrotate(a, NULL);
	op_rrotate(b, NULL);
	if (op != NULL)
		write(1, op, 4);
}