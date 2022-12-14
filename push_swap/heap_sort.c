#include "heap_sort.h"
#include "stack.h"
#include <stdio.h>

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void heap_insert(t_stack *stack, int elem)
{
	int curr_idx = stack->size;

	stack->arr[curr_idx] = elem;
	while (curr_idx != 0 && stack->arr[(curr_idx - 1) / 2] < elem)
	{
		swap(stack->arr + curr_idx, stack->arr + (curr_idx - 1) / 2);
		for (int i = 0; i < stack->size - curr_idx; ++i)
			printf("pa\n");
		for (int i = 0; i < (curr_idx - 1) / 2; ++i)
		{
			printf("rrb\n");
			printf("pa\n");
		}
		if ((curr_idx - 1) / 2 == curr_idx - 1)
			printf("sb\n");
		else
			printf("rrb\nsb\nrb\n");
		for (int i = 0; i < (curr_idx - 1) / 2; ++i)
		{
			printf("pb\n");
			printf("rb\n");
		}
		for (int i = 0; i < stack->size - curr_idx; ++i)
			printf("pb\n");
		// }
		curr_idx = (curr_idx - 1) / 2;
	}
	++(stack->size);
}

int heap_pop(t_stack *stack)
{
	int peeked = stack->arr[0];
	int curr_idx = 0;
	int next_idx = 0;

	stack->arr[curr_idx] = stack->arr[--(stack->size)];
	printf("rb\n");
	while ((curr_idx + 1) * 2 - 1 < stack->size)
	{
		if (stack->arr[(curr_idx + 1) * 2 - 1] > stack->arr[next_idx])
			next_idx = (curr_idx + 1) * 2 - 1;
		if ((curr_idx + 1) * 2 < stack->size && stack->arr[(curr_idx + 1) * 2] > stack->arr[next_idx])
			next_idx = (curr_idx + 1) * 2;
		if (next_idx == curr_idx)
			break;
		swap(stack->arr + next_idx, stack->arr + curr_idx);
		// *count += (stack->size - 1 - (curr_idx - 1) / 2) * 2 + (curr_idx)*4 + 3;
		for (int i = 0; i < stack->size - 1 - next_idx; ++i)
			printf("pa\n");
		for (int i = 0; i < curr_idx; ++i)
		{
			printf("rrb\n");
			printf("pa\n");
		}
		if (curr_idx == next_idx - 1)
			printf("sb\n");
		else
			printf("rrb\nsb\nrb\n");
		for (int i = 0; i < curr_idx; ++i)
		{
			printf("pb\n");
			printf("rb\n");
		}
		for (int i = 0; i < stack->size - 1 - next_idx; ++i)
			printf("pb\n");
		curr_idx = next_idx;
	}
	return (peeked);
}

#define SIZE 8
