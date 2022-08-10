/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 03:52:17 by hacho             #+#    #+#             */
/*   Updated: 2022/08/10 18:39:34 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const size_t	length = len;

	if (dst < src)
		while (len--)
			*((unsigned char *)dst + length - len - 1) = \
			*((unsigned char *)src + length - len - 1);
	else
		while (len--)
			*((unsigned char *)dst + len) = *((unsigned char *)src + len);
	return (dst);
}
