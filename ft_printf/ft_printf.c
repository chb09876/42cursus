/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 22:36:43 by hacho             #+#    #+#             */
/*   Updated: 2022/10/06 13:19:59 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

int		validate_format(const char *format);
ssize_t	print_conversion_specification(const char **format, va_list *ap);
ssize_t	print_ordinary_characters(const char **format);
ssize_t	print_character(char c, &options);

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		print_count;
	ssize_t	write_bytes;

	va_start(ap, format);
	print_count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			write_bytes = print_conversion_specification(&format, &ap);
		}
		else
			write_bytes = print_ordinary_characters(&format);
		if (write_bytes == -1)
			return (-1);
		print_count += write_bytes;
	}
	va_end(ap);
	return (print_count);
}
