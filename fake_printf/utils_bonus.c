/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:06:20 by hacho             #+#    #+#             */
/*   Updated: 2022/11/06 22:37:11 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "utils_bonus.h"

ssize_t	ft_putchar_repeat(char c, int repeat, int fd)
{
	int	count;

	count = 0;
	while (repeat > count)
	{
		if (write(fd, &c, sizeof c) == -1)
			return (-1);
		++count;
	}
	return (count);
}

size_t	get_unsigned_length(unsigned long long int n, int radix)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n)
	{
		n /= radix;
		++len;
	}
	return (len);
}

void	print_number(long long int n, int fd)
{
	unsigned long long int	unsigned_n;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		unsigned_n = -n;
	}
	else
		unsigned_n = n;
	if (unsigned_n < 10)
		ft_putchar_fd(unsigned_n + '0', fd);
	else
	{
		print_number(unsigned_n / 10, fd);
		ft_putchar_fd(unsigned_n % 10 + '0', fd);
	}
}

void	print_number_hex(unsigned int n, const char *table, int fd)
{
	if (n < 16)
		ft_putchar_fd(table[n], fd);
	else
	{
		print_number_hex(n / 16, table, fd);
		ft_putchar_fd(table[n % 16], fd);
	}
}

void	print_number_pointer(
	unsigned long long int n, const char *table, int fd)
{
	if (n < 16)
		ft_putchar_fd(table[n], fd);
	else
	{
		print_number_pointer(n / 16, table, fd);
		ft_putchar_fd(table[n % 16], fd);
	}
}
