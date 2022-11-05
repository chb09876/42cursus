/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:33:09 by hacho             #+#    #+#             */
/*   Updated: 2022/11/04 23:59:12 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
#define UTILS_H

#include "sys/types.h"

ssize_t	ft_putchar_repeat(char c, int repeat, int fd);
size_t	get_number_length(int n);
void	print_number(long long int n, int fd);

#endif