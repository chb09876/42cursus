/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 17:25:41 by hacho             #+#    #+#             */
/*   Updated: 2022/10/01 23:15:37 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <sys/types.h>
#include "ft_printf.h"

void	init_options(t_options *opt)
{
	opt->f_adjust_left = false;
	opt->f_alt_form = false;
	opt->f_show_sign = false;
	opt->f_sign_space =false;
	opt->f_zero_padding = false;
	opt->min_field_width = 0;
	opt->precision = 0;
}

void	set_options(const char **format, t_options *opt)
{
	// flags!

	// min field width!

	// if period? percision!
}

ssize_t	print_character(char c, t_options *opt)
{
	ssize_t	write_bytes;
	ssize_t	padding_bytes;

	if (opt->f_adjust_left == false)
	{
		if (opt->min_field_width - sizeof c > 0)
		{
			// write padding
			while (opt->min_field_width - sizeof c != 0)
			{
				write_bytes = write(STDOUT_FILENO, " ", sizeof(char));
				if (write_bytes == -1)
					return (-1);
				--(opt->min_field_width);
			}
		}
		write_bytes = write(STDOUT_FILENO, &c, sizeof c);
	}
	return (write(STDOUT_FILENO, &c, sizeof c));
}