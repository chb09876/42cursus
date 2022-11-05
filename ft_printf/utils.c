/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:06:20 by hacho             #+#    #+#             */
/*   Updated: 2022/11/05 00:12:54 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "utils.h"

ssize_t	ft_putchar_repeat(char c, int repeat, int fd)
{
	int count;

	count = 0;
	while (repeat > count)
	{
		if (write(fd, &c, sizeof c) == -1)
			return (-1);
		++count;
	}
	return (repeat);
}

size_t	get_number_length(int n)
{
	int len;
	long long int long_num;

	if (n == 0)
		return (1);
	len = 0;
	long_num = n;
	if (n < 0)
	{
		long_num = -n;
	}
	while (long_num)
	{
		long_num /= 10;
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
		ft_putnbr_fd(unsigned_n / 10, fd);
		ft_putchar_fd(unsigned_n % 10 + '0', fd);
	}
}
