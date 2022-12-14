/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_lower_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:56:50 by hacho             #+#    #+#             */
/*   Updated: 2022/11/15 22:03:49 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthex_lower_fd(unsigned int n, int fd)
{
	if (n < 16)
		ft_putchar_fd("0123456789abcdef"[n], fd);
	else
	{
		ft_puthex_lower_fd(n / 16, fd);
		ft_putchar_fd("0123456789abcdef"[n % 16], fd);
	}
}
