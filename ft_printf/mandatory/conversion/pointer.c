/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:17:25 by hacho             #+#    #+#             */
/*   Updated: 2022/11/17 19:33:00 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "conversion.h"

static size_t	get_hexlen(unsigned long long int n);

ssize_t	print_pointer(unsigned long long int n)
{
	const size_t	hexlen = get_hexlen(n);
	char			*buffer;
	ssize_t			write_bytes;
	size_t			idx;

	buffer = malloc((hexlen + 2) * sizeof(char));
	if (buffer == NULL)
		return (-1);
	ft_memmove(buffer, "0x", 2);
	idx = 0;
	while (idx < hexlen)
	{
		buffer[hexlen + 1 - idx++] = "0123456789abcdef"[n % 16];
		n /= 16;
	}
	write_bytes = write(STDOUT_FILENO, buffer, hexlen + 2);
	free(buffer);
	if (write_bytes == -1 || (size_t)write_bytes < hexlen)
		return (-1);
	return (hexlen + 2);
}

static size_t	get_hexlen(unsigned long long int n)
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
