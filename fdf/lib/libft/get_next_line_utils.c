/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:15:17 by hacho             #+#    #+#             */
/*   Updated: 2023/03/05 12:23:31 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

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
