/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_character.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 22:00:17 by hacho             #+#    #+#             */
/*   Updated: 2022/10/04 01:06:49 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../ft_printf.h"

static ssize_t	print_padding(char pad, int size);

ssize_t	print_character(char c, t_options *opt)
{
	if (opt->f_adjust_left == false)
	{
		if (print_padding(' ', opt->min_field_width - sizeof c) == -1)
			return (-1);
		if (write(STDOUT_FILENO, &c, sizeof c) == -1)
			return (-1);
	}
	else if (opt->f_adjust_left == true)
	{
		if (write(STDOUT_FILENO, &c, sizeof c) == -1)
			return (-1);
		if (print_padding(' ', opt->min_field_width - sizeof c) == -1)
			return (-1);
	}
	if (opt->min_field_width - sizeof c > 0)
		return (opt->min_field_width);
	return (sizeof c);
}

static ssize_t	print_padding(char pad, int size)
{
	ssize_t	padding_bytes;

	padding_bytes = 0;
	while (padding_bytes < size)
	{
		if (write(STDOUT_FILENO, &pad, sizeof pad) == -1)
			return (-1);
		padding_bytes += sizeof pad;
	}
	return (padding_bytes);
}