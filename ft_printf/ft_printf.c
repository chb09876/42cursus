/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 22:36:43 by hacho             #+#    #+#             */
/*   Updated: 2022/11/05 01:00:43 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "options.h"
#include "conversion.h"
#include "ft_printf.h"

static ssize_t	print_converted_string(va_list *ap, t_conversion_context *context);
static ssize_t	print_ordinary_characters(const char *format);

int	ft_printf(const char *format, ...)
{
	va_list					ap;
	t_conversion_context	context;
	ssize_t					write_bytes_sum;
	ssize_t					write_bytes;

	va_start(ap, format);
	write_bytes_sum = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format += set_conversion_context(format, &context);
			write_bytes = print_converted_string(&ap, &context);
		}
		else
		{
			write_bytes = print_ordinary_characters(format);
			if (write_bytes == -1)
				return (-1);
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

static ssize_t	print_converted_string(va_list *ap, t_conversion_context *context)
{
	if (context->type == 'c')
		return (print_character(va_arg(*ap, int), context));
	if (context->type == 's')
		return (print_string(va_arg(*ap, char *), context));
	// if (**format == 'p')
	// 	return (print_pointer_in_hex(va_arg(*ap, void *), &opt));
	// if (opt->type == 'd')
	// 	return (print_decimal(va_arg(*ap, int), &opt));
	// if (**format == 'i')
	// 	return (print_integer(va_arg(*ap, int), &opt));
	// if (**format == 'u')
	// 	return (print_unsigned_decimal(va_arg(*ap, unsigned int), &opt));
	// if (**format == 'x')
	// 	return (print_num_in_hex_lower(va_arg(*ap, int), &opt));
	// if (**format == 'X')
	// 	return (print_num_in_hex_upper(va_arg(*ap, int), &opt));
	// if (**format == '%')
	// 	return (print_percent(&opt));
	return (-1);
}