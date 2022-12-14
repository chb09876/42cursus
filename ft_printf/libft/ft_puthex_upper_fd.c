/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_upper_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:56:50 by hacho             #+#    #+#             */
/*   Updated: 2022/11/15 22:03:18 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthex_upper_fd(unsigned int n, int fd)
{
	if (n < 16)
		ft_putchar_fd("0123456789ABCDEF"[n], fd);
	else
	{
		ft_puthex_upper_fd(n / 16, fd);
		ft_putchar_fd("0123456789ABCDEF"[n % 16], fd);
	}
}
