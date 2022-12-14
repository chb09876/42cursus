#include "heap_sort.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		printf("Error! argument is not delivered.\n");
		return 1;
	}
	t_stack *a = make_stack(argc - 1);
	t_stack *b = make_stack(argc - 1);

	for (int i = 0; i < argc - 1; ++i)
		a->arr[i] = atoi(argv[argc - 1 - i]);
	a->size = argc - 1;

	for (int i = 0; i < argc - 1; ++i)
	{
		int a_top = a->arr[a->size - 1];
		a->size--;
		printf("pb\n");
		heap_insert(b, a_top);
	}

	for (int i = 0; i < argc - 1; ++i)
	{
		printf("rrb\n");
		printf("pa\n");
		heap_pop(b);
	}
}