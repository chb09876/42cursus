/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putllnbr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:36:01 by hacho             #+#    #+#             */
/*   Updated: 2022/11/15 23:05:54 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static void	print_num(unsigned long long int n, int fd);

void	ft_putllnbr_fd(long long int n, int fd)
{
	unsigned long long int	unsigned_n;

	if (n != 0)
	{
		if (n < 0)
		{
			write(fd, "-", sizeof(char));
			unsigned_n = -n;
		}
		else
			unsigned_n = n;
		print_num(unsigned_n, fd);
	}
	else
		write(fd, "0", sizeof(char));
}

static void	print_num(unsigned long long int n, int fd)
{
	char	c;

	if (n)
	{
		c = n % 10 + '0';
		print_num(n / 10, fd);
		write(fd, &c, sizeof(char));
	}
}
