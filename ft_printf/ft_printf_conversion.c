/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 22:01:38 by hacho             #+#    #+#             */
/*   Updated: 2022/10/04 01:00:05 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <stdarg.h>
#include "ft_printf.h"

ssize_t	print_character(char c, t_options *opt);
void	init_options(t_options *opt);
char	*set_options(const char *format, t_options *opt);

ssize_t	print_conversion_specification(const char **format, va_list *ap)
{
	t_options	opt;

	init_options(&opt);
	*format = set_options(*format, &opt) + 1;

	if (*(*format - 1) == 'c'){
		return (print_character(va_arg(*ap, int), &opt));}
	// if (**format == 's')
	// 	return (print_string(va_arg(*ap, char *), &opt));
	// if (**format == 'p')
	// 	return (print_pointer_in_hex(va_arg(*ap, void *), &opt));
	// if (**format == 'd')
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
	++(*format);
	return (-1);
}