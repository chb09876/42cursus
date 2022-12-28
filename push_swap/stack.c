/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 04:04:27 by hacho             #+#    #+#             */
/*   Updated: 2022/12/27 19:43:02 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "node.h"
#include <stdlib.h>

void push(t_stack *stack, t_node *node)
{
	if (stack->size == 0)
		stack->bottom = node;
	else
		stack->top->next = node;
	stack->top = node;
	++stack->size;
}

t_node *pop(t_stack *stack)
{
	t_node *top_node;
	t_node *tmp;

	if (stack->size == 0)
		return (NULL);
	top_node = stack->top;
	if (top_node == stack->bottom)
	{
		stack->top = NULL;
		stack->bottom = NULL;
		--stack->size;
		return (top_node);
	}
	tmp = stack->bottom;
	while (tmp->next != stack->top)
		tmp = tmp->next;
	tmp->next = NULL;
	stack->top = tmp;
	--stack->size;
	return (top_node);
}

t_stack *make_empty_stack(void)
{
	t_stack *new_stack;

	new_stack = malloc(sizeof *new_stack);
	if (new_stack == NULL)
		return (NULL);
	new_stack->bottom = NULL;
	new_stack->top = NULL;
	new_stack->size = 0;
	return (new_stack);
}

t_stack *make_stack_with_list(int *arr, int size)
{
	t_stack *new_stack;
	t_node *node;
	int i;

	new_stack = make_empty_stack();
	if (new_stack == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		node = make_node(arr[size - 1 - i], NULL);
		if (node == NULL)
		{
			while (new_stack->size > 0)
				free(pop(new_stack));
			free(new_stack);
			return (NULL);
		}
		push(new_stack, node);
		++i;
	}
	return (new_stack);
}

void free_stack(t_stack *stack)
{
	while (stack->size > 0)
		free(pop(stack));
	free(stack);
}
