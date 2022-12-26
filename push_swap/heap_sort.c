/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 04:04:05 by hacho             #+#    #+#             */
/*   Updated: 2022/12/27 04:24:47 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heap_sort.h"
#include <stdlib.h>

static void		swap(int *a, int *b);
static void		insert(t_heap *heap, int elem);
static int		pop(t_heap *heap);
static t_heap	*make_heap(int reserved);

int	*heap_sort(int *arr, int size)
{
	t_heap	*heap;
	int		*sorted;
	int		i;

	heap = make_heap(size);
	sorted = malloc(sizeof * sorted * size);
	if (sorted == NULL)
		return (NULL);
	i = 0;
	while (i < size)
		insert(heap, arr[i++]);
	i = 0;
	while (i < size)
		sorted[i++] = pop(heap);
	free(heap->arr);
	free(heap);
	return (sorted);
}

static t_heap	*make_heap(int reserved)
{
	t_heap	*new_heap;

	new_heap = malloc(sizeof * new_heap);
	if (new_heap == NULL)
		return (NULL);
	new_heap->arr = malloc(sizeof * new_heap->arr * reserved);
	if (new_heap->arr == NULL)
		return (NULL);
	new_heap->size = 0;
	return (new_heap);
}

static void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	insert(t_heap *heap, int elem)
{
	int	curr_idx;

	curr_idx = heap->size;
	heap->arr[curr_idx] = elem;
	while (curr_idx != 0 && heap->arr[(curr_idx - 1) / 2] > elem)
	{
		swap(heap->arr + curr_idx, heap->arr + (curr_idx - 1) / 2);
		curr_idx = (curr_idx - 1) / 2;
	}
	++(heap->size);
}

static int	pop(t_heap *heap)
{
	const int	peeked = heap->arr[0];
	int			curr_idx;
	int			next_idx;

	curr_idx = 0;
	next_idx = 0;
	heap->arr[curr_idx] = heap->arr[--(heap->size)];
	while ((curr_idx + 1) * 2 - 1 < heap->size)
	{
		if (heap->arr[(curr_idx + 1) * 2 - 1] < heap->arr[next_idx])
			next_idx = (curr_idx + 1) * 2 - 1;
		if ((curr_idx + 1) * 2 < heap->size && \
			heap->arr[(curr_idx + 1) * 2] < heap->arr[next_idx])
			next_idx = (curr_idx + 1) * 2;
		if (next_idx == curr_idx)
			break ;
		swap(heap->arr + next_idx, heap->arr + curr_idx);
		curr_idx = next_idx;
	}
	return (peeked);
}
