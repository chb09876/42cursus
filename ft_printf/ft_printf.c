/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 22:36:43 by hacho             #+#    #+#             */
/*   Updated: 2022/10/01 15:30:21 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

int		validate_format(const char *format);
ssize_t	print_conversion_specifiers(const char **format, va_list *ap);
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

ssize_t	print_conversion_specification(const char **format)
{
	*format += 2;
	if (*(format - 1) == 'c')
		return (print_character());
	if (*(format - 1) == 's')
		return (print_string());
	if (*(format - 1) == 'p')
		return (print_pointer_in_hex());
	if (*(format - 1) == 'd')
		return (print_decimal());
	if (*(format - 1) == 'i')
		return (print_integer());
	if (*(format - 1) == 'u')
		return (print_unsigned_decimal());
	if (*(format - 1) == 'x')
		return (print_num_in_hex_lower());
	if (*(format - 1) == 'X')
		return (print_num_in_hex_upper());
	if (*(format - 1) == '%')
		return (print_percent());
	return (-1);
}

ssize_t	

int main()
{
	ft_printf("hello");
	
}
