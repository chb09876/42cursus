/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 04:03:52 by hacho             #+#    #+#             */
/*   Updated: 2022/12/27 21:27:13 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heap_sort.h"
#include "push_swap.h"
#include "radix_sort.h"
#include "hard_sort.h"
#include "ft_atoi.h"
#include "utils.h"
#include <unistd.h>
#include <stdlib.h>

static int find_index(int *arr, int size, int elem);
static t_arrays parser(int argc, char *argv[]);
static int error(char *msg, int code);

int main(int argc, char *argv[])
{
	t_arrays input;
	t_stack *a;
	t_stack *b;

	input = parser(argc, argv);
	if (input.arr == NULL || input.ranked == NULL || input.sorted == NULL)
		return (error("Error\n", 1));
	a = make_stack_with_list(input.ranked, argc - 1);
	b = make_empty_stack();
	if (a == NULL || b == NULL)
		return (error("Error\n", 1));
	if (argc - 1 <= 5)
		hard_sort(a, b, argc - 1);
	else
		radix_sort_binary(a, b);
	free(input.arr);
	free(input.sorted);
	free(input.ranked);
	free_stack(a);
	free_stack(b);
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

static t_arrays parser(int argc, char *argv[])
{
	int i;
	t_arrays input;

	input.arr = malloc(sizeof *input.arr * (argc - 1));
	if (input.arr == NULL)
		return (input);
	i = 0;
	while (++i < argc)
		input.arr[i - 1] = ft_atoi(argv[i]);
	input.sorted = heap_sort(input.arr, argc - 1);
	input.ranked = malloc(sizeof *input.ranked * (argc - 1));
	if (input.ranked == NULL || input.sorted == NULL)
		return (input);
	i = -1;
	while (++i < argc - 1)
		input.ranked[i] = find_index(input.sorted, argc - 1, input.arr[i]);
	return (input);
}

static int error(char *msg, int code)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	return (code);
}
