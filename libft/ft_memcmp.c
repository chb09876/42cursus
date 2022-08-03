/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:50:56 by hacho             #+#    #+#             */
/*   Updated: 2022/08/03 20:38:13 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_memcmp(void *dst, const void *src, size_t n)
{
	while (n && *((unsigned char *)dst) == *((unsigned char *)src))
	{
		--n;
		++src;
		++dst;
	}
	if (n == 0)
		return (0);
	return (*((unsigned char *)dst) - *((unsigned char *)src));
}
