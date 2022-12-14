/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:06:20 by hacho             #+#    #+#             */
/*   Updated: 2022/11/06 22:52:48 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "utils.h"

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

ssize_t	print_number(long long int n, int fd)
{
	unsigned long long int	unsigned_n;
	char					c;
	ssize_t					len;

	len = 0;
	if (n < 0)
	{
		if (write(fd, "-", 1) == -1)
			return (-1);
		unsigned_n = -n;
	}
	else
		unsigned_n = n;
	if (unsigned_n < 10)
	{
		c = unsigned_n + '0';
		if (write(fd, &c, 1) == -1)
			return (-1);
	}
	else
	{
		print_number(unsigned_n / 10, fd);
		c = unsigned_n % 10 + '0';
		if (write(fd, &c, 1) == -1)
			return (-1);
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

// size_t	get_number_length_pointer(unsigned long long int n)
// {
// 	int	len;

// 	if (n == 0)
// 		return (1);
// 	len = 0;
// 	while (n)
// 	{
// 		n /= 16;
// 		++len;
// 	}
// 	return (len);
// }
