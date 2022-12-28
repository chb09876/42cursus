/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 04:03:48 by hacho             #+#    #+#             */
/*   Updated: 2022/12/27 20:56:17 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "radix_sort.h"
#include "operation.h"
#include "utils.h"
#include <stdio.h>

#define DEBUG 0

static int check_rotate(t_stack *stack, int level, int radix);
static int get_digit(int num, int level, int radix);

void radix_sort_binary(t_stack *a, t_stack *b)
{
	int level;
	int tmp;

	level = 0;
	while (!is_sorted(a) && level < (int)sizeof(int) * 8)
	{
		if (check_rotate(a, level, 2))
		{
			tmp = a->size;
			while (tmp > 0)
			{
				if (get_digit(a->top->data, level, 2) != 1)
					op_push(a, b, "pb\n");
				else if (a->size > 1)
					op_rotate(a, "ra\n");
				--tmp;
			}
			tmp = b->size + 1;
			while (--tmp > 0)
				op_push(b, a, "pa\n");
		}
		++level;
	}
}

static int check_rotate(t_stack *stack, int level, int radix)
{
	t_node *node;
	int flag;

	node = stack->bottom;
	if (stack->size == 0)
		return (0);
	node = stack->bottom;
	flag = get_digit(node->data, level, radix);
	node = node->next;
	while (node)
	{
		if (flag != get_digit(node->data, level, radix))
			return (1);
		node = node->next;
	}
	return (0);
}

static int get_digit(int num, int level, int radix)
{
	return (num / ft_pow(radix, level) % radix);
}
