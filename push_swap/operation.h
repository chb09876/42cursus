/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 04:23:51 by hacho             #+#    #+#             */
/*   Updated: 2022/12/27 15:50:45 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATION_H
#define OPERATION_H

#include "stack.h"

void op_swap(t_stack *stack, char *op);
void op_swap_same(t_stack *a, t_stack *b, char *op);
void op_push(t_stack *from, t_stack *to, char *op);
void op_rotate(t_stack *stack, char *op);
void op_rotate_same(t_stack *a, t_stack *b, char *op);
void op_rrotate(t_stack *stack, char *op);
void op_rrotate_same(t_stack *a, t_stack *b, char *op);

#endif