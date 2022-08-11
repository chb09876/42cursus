/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 18:12:17 by hacho             #+#    #+#             */
/*   Updated: 2022/08/11 18:18:44 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == 0)
	{
		c = '0';
		write(fd, &c, sizeof(char));
	}
	else
	{	
		while (n)
		{
			c = n % 10 + '0';
			write(fd, &c, sizeof(char));
			c /= 10;
		}
	}
}
