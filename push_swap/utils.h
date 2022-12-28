/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 04:01:13 by hacho             #+#    #+#             */
/*   Updated: 2022/12/27 21:25:27 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
#define UTILS_H

#include "stack.h"

int ft_pow(int num, int level);
void ft_putstr_fd(char *s, int fd);
int is_sorted(t_stack *stack);

#endif
