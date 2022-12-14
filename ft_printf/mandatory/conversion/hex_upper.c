/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_upper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:17:28 by hacho             #+#    #+#             */
/*   Updated: 2022/11/17 19:39:23 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "conversion.h"

static size_t	get_hexlen(unsigned int n);

ssize_t	print_hex_upper(unsigned int n)
{
	const size_t	hexlen = get_hexlen(n);
	char			*buffer;
	ssize_t			write_bytes;
	size_t			idx;

	buffer = malloc(hexlen * sizeof(char));
	if (buffer == NULL)
		return (-1);
	idx = 0;
	while (idx < hexlen)
	{
		buffer[hexlen - 1 - idx++] = "0123456789ABCDEF"[n % 16];
		n /= 16;
	}
	write_bytes = write(STDOUT_FILENO, buffer, hexlen);
	free(buffer);
	if (write_bytes == -1 || (size_t)write_bytes < hexlen)
		return (-1);
	return (hexlen);
}

static size_t	get_hexlen(unsigned int n)
{
	size_t	hexlen;

	if (n == 0)
		return (1);
	hexlen = 0;
	while (n)
	{
		n /= 16;
		++hexlen;
	}
	return (hexlen);
}
