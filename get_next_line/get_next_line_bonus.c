/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 19:22:02 by hacho             #+#    #+#             */
/*   Updated: 2022/09/22 20:36:21 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

static t_gnl_state	gnl_read(int fd, t_read_buffer *buf, t_gnl_status *gnl);
static t_gnl_state	gnl_join(t_gnl_status *gnl, t_read_buffer *buf);

char	*get_next_line(int fd)
{
	static t_read_buffer	buf;
	t_gnl_status			gnl;

	gnl.state = GNL_STATE_INIT;
	gnl.line = NULL;
	gnl.length = 0;
	while (gnl.state == GNL_STATE_INIT || gnl.state == GNL_STATE_READING)
		gnl.state = gnl_read(fd, &buf, &gnl);
	if (gnl.state == GNL_STATE_DONE || gnl.state == GNL_STATE_EOF)
		return (gnl.line);
	if (gnl.state == GNL_STATE_ERROR)
	{
		free(gnl.line);
		buf.read_size = 0;
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
			return (GNL_STATE_ERROR);
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
	while (next_offset != buf->read_size
		&& buf->buffer[next_offset - 1] != '\n')
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
