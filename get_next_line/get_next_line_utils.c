/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:15:17 by hacho             #+#    #+#             */
/*   Updated: 2022/09/20 18:31:33 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

char *ft_strjoin(char const *s1, char const *s2, int read_len)
{
	const size_t s1_len = ft_strlen(s1);
	char *new_str;

	new_str = malloc((s1_len + read_len + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	ft_strlcpy(new_str, s1, s1_len + 1);
	ft_strlcpy(new_str + s1_len, s2, read_len + 1);
	return (new_str);
}

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	const char *const tmp = src;

	if (dstsize)
	{
		while (--dstsize && *src)
			*((unsigned char *)dst++) = *((unsigned char *)src++);
		*dst = '\0';
	}
	while (*src)
		++src;
	return (src - tmp);
}
