/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 22:36:43 by hacho             #+#    #+#             */
/*   Updated: 2022/11/06 22:36:05 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "options_bonus.h"
#include "conversion_bonus.h"
#include "ft_printf_bonus.h"

static ssize_t	print_converted_string(
					va_list *ap, t_conversion_context *context);
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
			format += set_conversion_context(format + 1, &context) + 1;
			write_bytes = print_converted_string(&ap, &context);
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

static ssize_t	print_converted_string(
	va_list *ap, t_conversion_context *context)
{
	if (context->type == 'c')
		return (print_character(va_arg(*ap, int), context));
	if (context->type == 's')
		return (print_string(va_arg(*ap, char *), context));
	if (context->type == 'p')
		return (print_pointer(va_arg(*ap, unsigned long long int), context));
	if (context->type == 'd')
		return (print_decimal(va_arg(*ap, int), context));
	if (context->type == 'i')
		return (print_integer(va_arg(*ap, int), context));
	if (context->type == 'u')
		return (print_unsigned_integer(
				va_arg(*ap, unsigned long long int), context));
	if (context->type == 'x')
		return (print_hex_lower(va_arg(*ap, unsigned int), context));
	if (context->type == 'X')
		return (print_hex_upper(va_arg(*ap, unsigned int), context));
	if (context->type == '%')
		return (print_percent(context));
	return (-1);
}
