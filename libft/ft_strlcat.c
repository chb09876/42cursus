/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 16:18:51 by hacho             #+#    #+#             */
/*   Updated: 2022/08/10 18:39:42 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	const size_t	srclen = ft_strlen(src);
	size_t			dstlen;

	dstlen = 0;
	while (*(dst + dstlen) && dstlen != dstsize)
		++dstlen;
	if (dstlen != dstsize)
	{
		if (srclen < dstsize - dstlen)
			ft_memcpy(dst + dstlen, src, srclen + 1);
		else
		{
			ft_memcpy(dst + dstlen, src, dstsize - dstlen - 1);
			dst[dstsize - 1] = '\0';
		}
	}
	return (dstlen + srclen);
}
