/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:44:08 by hacho             #+#    #+#             */
/*   Updated: 2022/10/23 17:10:09 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf_print.h"

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

ssize_t	print_padding(char pad, int size)
{
	ssize_t	padding_bytes;

	padding_bytes = 0;
	while (padding_bytes < size)
	{
		if (write(STDOUT_FILENO, &pad, sizeof pad) == -1)
			return (-1);
		padding_bytes += sizeof pad;
	}
	return (padding_bytes);
}
