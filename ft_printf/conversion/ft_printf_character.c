/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_character.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 22:00:17 by hacho             #+#    #+#             */
/*   Updated: 2022/10/12 17:04:10 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../ft_printf.h"

ssize_t	print_padding(char pad, int size);

ssize_t	print_character(unsigned char c, t_conversion_options *opt)
{
	if (opt->flags.adjust_left == false)
	{
		if (print_padding(' ', opt->min_field_width - sizeof c) == -1)
			return (-1);
		if (write(STDOUT_FILENO, &c, sizeof c) == -1)
			return (-1);
	}
	else if (opt->flags.adjust_left == true)
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
