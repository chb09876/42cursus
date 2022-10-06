/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ordinary.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 22:01:52 by hacho             #+#    #+#             */
/*   Updated: 2022/10/03 23:55:47 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
