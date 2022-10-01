/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 20:43:43 by hacho             #+#    #+#             */
/*   Updated: 2022/10/01 15:26:41 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list		args;
	const int 	args_count;
	int			write_count;

	args_count = count_specifier(format);
	if (args_count == -1)
		return (-1);
	va_start(args, format);
	write_count = 0;
	while (format)
	{
		if (*format != '%')
		{
			++write_count;
			ft_printf
		}
	}
}
