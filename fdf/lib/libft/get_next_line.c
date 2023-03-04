/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 19:22:02 by hacho             #+#    #+#             */
/*   Updated: 2023/03/04 18:26:23 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

char					*ft_strdup(const char *s1);
void					*ft_memmove(void *dst, const void *src, size_t len);
t_buffer_node			*new_buffer_node(
							int fd, t_buffer_node *next, t_buffer_node *prev);
static t_gnl_state		gnl_read(int fd, t_read_buffer *buf, t_gnl_status *gnl);
static t_gnl_state		gnl_join(t_gnl_status *gnl, t_read_buffer *buf);
static t_buffer_node	*select_buffer(int fd, t_buffer_list *list);
static void				delete_buffer(
							t_buffer_node *buf_node, t_buffer_list *list);

char	*get_next_line(int fd)
{
	static t_buffer_list	buf_list;
	t_buffer_node			*buf_node;
	t_gnl_status			gnl;

	gnl.state = GNL_STATE_INIT;
	gnl.line = NULL;
	gnl.length = 0;
	buf_node = select_buffer(fd, &buf_list);
	if (buf_node == NULL)
		return (NULL);
	while (gnl.state == GNL_STATE_INIT || gnl.state == GNL_STATE_READING)
		gnl.state = gnl_read(fd, &(buf_node->buf), &gnl);
	if (gnl.state == GNL_STATE_DONE || gnl.state == GNL_STATE_EOF)
	{
		if (gnl.state == GNL_STATE_EOF)
			delete_buffer(buf_node, &buf_list);
		return (gnl.line);
	}
	if (gnl.state == GNL_STATE_ERROR)
	{
		free(gnl.line);
		delete_buffer(buf_node, &buf_list);
		return (NULL);
	}
	return (NULL);
}

static t_gnl_state	gnl_read(int fd, t_read_buffer *buf, t_gnl_status *gnl)
{
	if (buf->offset == buf->read_size)
	{
		buf->read_size = read(fd, buf->buffer, BUFFER_SIZE);
		buf->offset = 0;
		if (buf->read_size == -1)
		{
			buf->read_size = 0;
			return (GNL_STATE_ERROR);
		}
		if (buf->read_size == 0)
			return (GNL_STATE_EOF);
	}
	if (gnl->line == NULL)
		gnl->line = ft_strdup("");
	if (gnl->line == NULL)
		return (GNL_STATE_ERROR);
	return (gnl_join(gnl, buf));
}

static t_gnl_state	gnl_join(t_gnl_status *gnl, t_read_buffer *buf)
{
	int		next_offset;
	char	*temp;

	next_offset = buf->offset + 1;
	while (next_offset != buf->read_size && \
		buf->buffer[next_offset - 1] != '\n')
		++next_offset;
	temp = gnl->line;
	gnl->line = \
		malloc((gnl->length + next_offset - buf->offset + 1) * sizeof(char));
	if (gnl->line == NULL)
	{
		free(temp);
		return (GNL_STATE_ERROR);
	}
	ft_memmove(gnl->line, temp, gnl->length);
	ft_memmove(gnl->line + gnl->length,
		buf->buffer + buf->offset, next_offset - buf->offset);
	gnl->line[gnl->length + next_offset - buf->offset] = '\0';
	gnl->length += next_offset - buf->offset;
	buf->offset = next_offset;
	free(temp);
	if (buf->buffer[buf->offset - 1] == '\n')
		return (GNL_STATE_DONE);
	return (GNL_STATE_READING);
}

static t_buffer_node	*select_buffer(int fd, t_buffer_list *list)
{
	t_buffer_node	*node;

	if (list->head == NULL)
	{
		list->head = new_buffer_node(fd, NULL, NULL);
		if (list->head == NULL)
			return (NULL);
		return (list->head);
	}
	node = list->head;
	while (node->next && node->fd != fd)
		node = node->next;
	if (node->fd == fd)
		return (node);
	node->next = new_buffer_node(fd, NULL, node);
	if (node->next == NULL)
		return (NULL);
	return (node->next);
}

static void	delete_buffer(t_buffer_node *buf_node, t_buffer_list *list)
{
	if (buf_node == list->head)
		list->head = buf_node->next;
	if (buf_node->prev != NULL)
		buf_node->prev->next = buf_node->next;
	if (buf_node->next != NULL)
		buf_node->next->prev = buf_node->prev;
	free(buf_node);
}
