/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:33:09 by hacho             #+#    #+#             */
/*   Updated: 2022/11/06 22:28:11 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_BONUS_H
# define UTILS_BONUS_H

# include "sys/types.h"

ssize_t	ft_putchar_repeat(char c, int repeat, int fd);
size_t	get_unsigned_length(unsigned long long int n, int radix);
void	print_number(long long int n, int fd);
void	print_number_hex(unsigned int n, const char *table, int fd);
void	print_number_pointer(
			unsigned long long int n, const char *table, int fd);

#endif
