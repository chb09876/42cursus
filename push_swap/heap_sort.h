#ifndef HEAP_SORT_H
#define HEAP_SORT_H

typedef struct s_heap
{
	int *arr;
	int size;
} t_heap;

int *heap_sort(int *arr, int size);

#endif