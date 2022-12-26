#ifndef OPERATION_H
#define OPERATION_H

#include "stack.h"

void op_swap(t_stack *stack, const char *op);
void op_swap_same(t_stack *a, t_stack *b, const char *op);
void op_push(t_stack *from, t_stack *to, const char *op);
void op_rotate(t_stack *stack, const char *op);
void op_rotate_same(t_stack *a, t_stack *b, const char *op);
void op_rrotate(t_stack *stack, const char *op);
void op_rrotate_same(t_stack *a, t_stack *b, const char *op);

#endif