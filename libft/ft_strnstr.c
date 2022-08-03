/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 20:39:26 by hacho             #+#    #+#             */
/*   Updated: 2022/08/03 21:02:22 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const size_t	needle_len = ft_strlen(needle);

	while (*haystack && len)
	{
		if (ft_strncmp(haystack, needle, needle_len) ==  0)
			return (haystack);
		--len;
		++haystack;
	}
	return (0);
}
