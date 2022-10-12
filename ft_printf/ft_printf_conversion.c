/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 22:01:38 by hacho             #+#    #+#             */
/*   Updated: 2022/10/07 22:37:57 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <stdarg.h>
#include "ft_printf.h"

ssize_t	print_character(unsigned char c, t_conversion_options *opt);
ssize_t	print_string(char *s, t_conversion_options *opt);
ssize_t	print_decimal(int d, t_conversion_options *opt);

ssize_t	print_conversion(va_list *ap, t_conversion_options *opt)
{
	if (opt->type == 'c')
		return (print_character(va_arg(*ap, int), opt));
	if (opt->type == 's')
		return (print_string(va_arg(*ap, char *), opt));
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