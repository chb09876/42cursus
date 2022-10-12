/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 22:36:43 by hacho             #+#    #+#             */
/*   Updated: 2022/10/08 23:49:30 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

int		validate_format(const char *format);
ssize_t	print_conversion(va_list *ap, t_conversion_options *opt);
ssize_t	print_ordinary_characters(const char **format);
int	set_conversion_options(const char **format, t_conversion_options *opt);

int	ft_printf(const char *format, ...)
{
	va_list					ap;
	t_conversion_options	options;
	ssize_t					print_bytes;
	ssize_t					write_bytes;

	va_start(ap, format);
	print_bytes = 0;
	while (*format)
	{
		if (*format == '%')
		{
			set_conversion_options(&format, &options);
			write_bytes = print_conversion(&ap, &options);
		}
		else
			write_bytes = print_ordinary_characters(&format);
		if (write_bytes == -1)
			return (-1);
		print_bytes += write_bytes;
	}
	va_end(ap);
	return (print_bytes);
}
