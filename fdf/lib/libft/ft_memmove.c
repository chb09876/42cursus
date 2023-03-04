/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 03:52:17 by hacho             #+#    #+#             */
/*   Updated: 2022/08/15 18:54:33 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const size_t	length = len;

	if (dst < src)
	{
		while (len)
		{
			--len;
			*((unsigned char *)dst + length - len - 1) = \
			*((unsigned char *)src + length - len - 1);
		}
	}
	else if (dst > src)
	{
		while (len)
		{
			--len;
			*((unsigned char *)dst + len) = *((unsigned char *)src + len);
		}
	}
	return (dst);
}
