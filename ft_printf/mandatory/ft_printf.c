/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:36:20 by hacho             #+#    #+#             */
/*   Updated: 2022/11/17 19:40:57 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <sys/types.h>
#include "conversion.h"

static ssize_t	print_converted_argument(va_list *ap, char type);
static ssize_t	print_ordinary_characters(const char *format);

int	ft_printf(const char *format, ...)
{
	va_list					ap;
	ssize_t					write_bytes_sum;
	ssize_t					write_bytes;

	va_start(ap, format);
	write_bytes_sum = 0;
	while (*format)
	{
		if (*format == '%')
		{	
			write_bytes = print_converted_argument(&ap, *(format + 1));
			format += 2;
		}
		else
		{
			write_bytes = print_ordinary_characters(format);
			format += write_bytes;
		}
		if (write_bytes == -1)
			return (-1);
		write_bytes_sum += write_bytes;
	}
	va_end(ap);
	return (write_bytes_sum);
}

static ssize_t	print_ordinary_characters(const char *format)
{
	const char	*end;

	end = format;
	while (*end && *end != '%')
		++end;
	return (write(STDOUT_FILENO, (char *)format, end - format));
}

static ssize_t	print_converted_argument(va_list *ap, char type)
{
	if (type == 'c')
		return (print_character(va_arg(*ap, int)));
	if (type == 's')
		return (print_string(va_arg(*ap, char *)));
	if (type == 'p')
		return (print_pointer(va_arg(*ap, unsigned long long int)));
	if (type == 'd')
		return (print_decimal(va_arg(*ap, int)));
	if (type == 'i')
		return (print_integer(va_arg(*ap, int)));
	if (type == 'u')
		return (print_unsigned_integer(va_arg(*ap, unsigned long long int)));
	if (type == 'x')
		return (print_hex_lower(va_arg(*ap, unsigned int)));
	if (type == 'X')
		return (print_hex_upper(va_arg(*ap, unsigned int)));
	if (type == '%')
		return (print_percent());
	return (-1);
}
