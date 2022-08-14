/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 18:12:17 by hacho             #+#    #+#             */
/*   Updated: 2022/08/13 21:22:03 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static void	print_num(unsigned int n, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	unsigned_n;

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

static void	print_num(unsigned int n, int fd)
{
	char	c;

	if (n)
	{
		c = n % 10 + '0';
		print_num(n / 10, fd);
		write(fd, &c, sizeof(char));
	}
}
