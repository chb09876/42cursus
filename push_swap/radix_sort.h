#ifndef RADIX_SORT_H
#define RADIX_SORT_H

#include "stack.h"

typedef struct s_pivot
{
	int big;
	int small;
} t_pivot;

int radix_sort_binary_three_chunk(t_stack *a, t_stack *b, int *sorted, int size);
int radix_sort_binary_two_chunk(t_stack *a, t_stack *b, int *sorted, int size);
int radix_sort_binary(t_stack *a, t_stack *b, int *sorted, int size);
int radix_sort_ternary(t_stack *a, t_stack *b, int *sorted, int size);

#endif