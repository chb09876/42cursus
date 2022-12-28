/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 04:03:40 by hacho             #+#    #+#             */
/*   Updated: 2022/12/27 15:50:54 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"
#include "utils.h"
#include <unistd.h>

void op_rotate(t_stack *stack, char *op)
{
	t_node *node;

	if (stack->size > 1)
	{
		node = pop(stack);
		node->next = stack->bottom;
		stack->bottom = node;
		stack->top->next = NULL;
		++stack->size;
	}
	if (op != NULL)
		ft_putstr_fd(op, STDOUT_FILENO);
}

void op_rotate_same(t_stack *a, t_stack *b, char *op)
{
	op_rotate(a, NULL);
	op_rotate(b, NULL);
	if (op != NULL)
		ft_putstr_fd(op, STDOUT_FILENO);
}

void op_rrotate(t_stack *stack, char *op)
{
	if (stack->size > 1)
	{
		stack->top->next = stack->bottom;
		stack->top = stack->bottom;
		stack->bottom = stack->bottom->next;
		stack->top->next = NULL;
	}
	if (op != NULL)
		ft_putstr_fd(op, STDOUT_FILENO);
}

void op_rrotate_same(t_stack *a, t_stack *b, char *op)
{
	op_rrotate(a, NULL);
	op_rrotate(b, NULL);
	if (op != NULL)
		ft_putstr_fd(op, STDOUT_FILENO);
}
