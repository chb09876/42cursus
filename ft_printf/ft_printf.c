/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 22:36:43 by hacho             #+#    #+#             */
/*   Updated: 2022/10/01 17:31:56 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

int		validate_format(const char *format);
ssize_t	print_conversion_specification(const char **format, va_list *ap);
ssize_t	print_ordinary_characters(const char **format);

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		print_count;
	ssize_t	write_bytes;

	if (validate_format(format) == -1)
		return (-1);
	va_start(ap, format);
	print_count = 0;
	while (*format)
	{
		if (*format == '%')
			write_bytes = print_conversion_specification(&format, &ap);
		else
			write_bytes = print_ordinary_characters(&format);
		if (write_bytes == -1)
			return (-1);
		print_count += write_bytes;
	}
	va_end(ap);
	return (print_count);
}

ssize_t	print_ordinary_characters(const char **format)
{
	const char	*end;
	ssize_t		write_bytes;

	end = *format;
	while (*end && *end != '%')
		++end;
	write_bytes = write(STDOUT_FILENO, *format, end - *format);
	if (write_bytes == -1)
		return (-1);
	*format = end;
	return (write_bytes);
}

// 플래그들에 비트마스크???

ssize_t	print_conversion_specification(const char **format, va_list *ap)
{
	t_options	opt;

	init_options(&opt);
	set_options(format, &opt);
	if (**format == 'c')
		return (print_character(va_arg(*ap, char), &opt));
	if (**format == 's')
		return (print_string(va_arg(*ap, char *), &opt));
	if (**format == 'p')
		return (print_pointer_in_hex(va_arg(*ap, void *), &opt));
	if (**format == 'd')
		return (print_decimal(va_arg(*ap, int), &opt));
	if (**format == 'i')
		return (print_integer(va_arg(*ap, int), &opt));
	if (**format == 'u')
		return (print_unsigned_decimal(va_arg(*ap, unsigned int), &opt));
	if (**format == 'x')
		return (print_num_in_hex_lower(va_arg(*ap, int), &opt));
	if (**format == 'X')
		return (print_num_in_hex_upper(va_arg(*ap, int), &opt));
	if (**format == '%')
		return (print_percent(&opt));
	return (-1);
}


int main()
{
	ft_printf("hello");
	
}
