/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 04:03:43 by hacho             #+#    #+#             */
/*   Updated: 2022/12/27 04:23:44 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"
#include "utils.h"
#include <unistd.h>

void	op_swap(t_stack *stack, const char *op)
{
	t_node	*tmp1;
	t_node	*tmp2;

	if (stack->size < 2)
		return ;
	tmp1 = pop(stack);
	tmp2 = pop(stack);
	push(stack, tmp1);
	push(stack, tmp2);
	if (op != NULL)
		ft_putstr_fd(op, STDOUT_FILENO);
}

void	op_swap_same(t_stack *a, t_stack *b, const char *op)
{
	op_swap(a, NULL);
	op_swap(b, NULL);
	if (op != NULL)
		ft_putstr_fd(op, STDOUT_FILENO);
}

void	op_push(t_stack *from, t_stack *to, const char *op)
{
	if (from->size > 0)
		push(to, pop(from));
	if (op != NULL)
		ft_putstr_fd(op, STDOUT_FILENO);
}
