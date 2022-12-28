/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 20:40:04 by hacho             #+#    #+#             */
/*   Updated: 2022/12/27 21:35:52 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hard_sort.h"
#include "utils.h"
#include "operation.h"

static void three_sort(t_stack *a, t_stack *b);

void hard_sort(t_stack *a, t_stack *b, int size)
{
	(void)b;
	if (size == 2 && !is_sorted(a))
		return (op_swap(a, "sa\n"));
	if (size == 3)
		return (three_sort(a, b));
	if (size)
}

static void three_sort(t_stack *a, t_stack *b)
{
	if (a->top->data == 2)
	{
		op_rotate(a, "ra\n");
		if (!is_sorted(a))
			op_swap(a, "sa\n");
	}
	else if (a->top->data == 0 && !is_sorted(a))
	{
		op_rotate(a, "ra\n");
		op_swap(a, "sa\n");
		op_rrotate(a, "rra\n");
	}
	else if (a->top->data == 1)
	{
		if (a->bottom->data == 2)
			op_swap(a, "sa\n");
		else
			op_rrotate(a, "rra\n");
	}
}