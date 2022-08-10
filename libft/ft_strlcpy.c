/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 04:43:27 by hacho             #+#    #+#             */
/*   Updated: 2022/08/10 22:32:57 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	const char *const	tmp = src;

	while (--dstsize && *src)
		*((unsigned char *)dst++) = *((unsigned char *)src++);
	*dst = '\0';
	while (*src)
		++src;
	return (src - tmp);
}
