/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 03:37:26 by hacho             #+#    #+#             */
/*   Updated: 2022/08/14 18:12:59 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	if (!dst && !src)
		return (NULL);
	while (n)
	{
		--n;
		*((unsigned char *)dst + n) = *((unsigned char *)src + n);
	}
	return (dst);
}

#include <string.h>

int main()
{
	char a[] ="a";
	memcpy(NULL, NULL, 10);
	ft_memcpy(a, NULL, 0);
}