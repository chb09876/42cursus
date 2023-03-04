/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:15:17 by hacho             #+#    #+#             */
/*   Updated: 2023/03/04 18:23:00 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char			*ft_strdup(const char *s1);
void			*ft_memmove(void *dst, const void *src, size_t len);
t_buffer_node	*new_buffer_node(
					int fd, t_buffer_node *next, t_buffer_node *prev);

t_buffer_node	*new_buffer_node(
	int fd, t_buffer_node *next, t_buffer_node *prev)
{
	t_buffer_node	*new_node;

	new_node = malloc(sizeof * new_node);
	if (new_node == NULL)
		return (NULL);
	new_node->buf.offset = 0;
	new_node->buf.read_size = 0;
	new_node->fd = fd;
	new_node->next = next;
	new_node->prev = prev;
	return (new_node);
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
	size_t	i;
	char	*new_str;

	i = 0;
	while (*(s1 + i))
		++i;
	new_str = malloc((i + 1) * sizeof * new_str);
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new_str[i] = s1[i];
		++i;
	}
	new_str[i] = '\0';
	return (new_str);
}
