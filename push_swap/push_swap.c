#include "stack.h"
#include "heap_sort.h"
#include "push_swap.h"
#include "radix_sort.h"
#include <stdio.h>
#include <stdlib.h>

static int find_index(int *arr, int size, int elem);
static int *parser(int argc, char *argv[]);

int main(int argc, char *argv[])
{
	t_stack *a;
	t_stack *b;
	int *arr = parser(argc, argv);
	int *sorted = heap_sort(arr, argc - 1);
	int *ranked = malloc(sizeof *ranked * (argc - 1));

	// printf("sorted: ");
	// for (int i = 0; i < argc - 1; ++i)
	// {
	// 	printf("%d ", sorted[i]);
	// }
	// printf("\n");

	// printf("ranked: ");
	for (int i = 0; i < argc - 1; ++i)
	{
		ranked[i] = find_index(sorted, argc - 1, arr[i]);
		// printf("%d ", ranked[i]);
	}
	// printf("\n");
	a = make_stack_with_list(ranked, argc - 1);
	b = make_empty_stack();
	// print_stack(a);
	radix_sort_binary(a, b, sorted, argc - 1);
	// print_stack(a);
	return (0);
}

static int find_index(int *arr, int size, int elem)
{
	int i;

	i = -1;
	while (++i < size)
	{
		if (arr[i] == elem)
			return (i);
	}
	return (-1);
}

static int *parser(int argc, char *argv[])
{
	int *arr;
	int i;

	arr = malloc(sizeof *arr * (argc - 1));
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (++i < argc)
		arr[i - 1] = atoi(argv[i]);
	return (arr);
}
