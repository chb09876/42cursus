#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include "stack.h"

void swap(int *a, int *b);
void heap_insert(t_stack *stack, int elem);
int heap_pop(t_stack *stack);

#endif