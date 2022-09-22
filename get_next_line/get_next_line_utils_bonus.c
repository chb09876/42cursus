/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:15:17 by hacho             #+#    #+#             */
/*   Updated: 2022/09/22 19:35:54 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	const char *const	tmp = src;

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

char	*ft_strdup(const char *s1)
{
	const size_t	len = ft_strlen(s1);
	const char		*new_str = malloc((len + 1) * sizeof(char));

	if (new_str == NULL)
		return (NULL);
	ft_strlcpy((char *)new_str, s1, (len + 1) * sizeof(char));
	return ((char *)new_str);
}

size_t	ft_strlen(const char *s)
{
	const char *const	tmp = s;

	while (*s)
		++s;
	return (s - tmp);
}
