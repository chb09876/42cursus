/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 04:01:42 by hacho             #+#    #+#             */
/*   Updated: 2022/12/27 19:40:49 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
#define STACK_H

#include "node.h"

typedef struct s_stack
{
	int size;
	t_node *top;
	t_node *bottom;
} t_stack;

t_stack *make_empty_stack(void);
t_stack *make_stack_with_list(int *arr, int size);
void push(t_stack *stack, t_node *node);
t_node *pop(t_stack *stack);
void free_stack(t_stack *stack);

#endif