/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 19:22:02 by hacho             #+#    #+#             */
/*   Updated: 2022/09/21 17:47:10 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

static t_gnl_state gnl_read(int fd, char **line);

char *get_next_line(int fd)
{
	t_gnl_state gnl_state;
	char *gnl_line;

	gnl_state = GNL_STATE_INIT;
	gnl_line = NULL;
	while (gnl_state == GNL_STATE_INIT || gnl_state == GNL_STATE_READING)
		gnl_state = gnl_read(fd, &gnl_line);
	if (gnl_state == GNL_STATE_DONE || gnl_state == GNL_STATE_EOF)
		return (gnl_line);
	else if (gnl_state == GNL_STATE_ERROR)
	{
		free(gnl_line);
		return (NULL);
	}
}

static t_gnl_state gnl_read(int fd, char **line)
{
	static t_read_buffer buf;
	char *temp;

	if (buf.offset == buf.read_size)
	{
		buf.read_size = read(fd, buf.buffer, BUFFER_SIZE);
		buf.offset = 0;
		if (buf.read_size == -1)
			return (GNL_STATE_ERROR);
		else if (buf.read_size == 0)
			return (GNL_STATE_EOF);
	}
	if (gnl_concat(line, &buf) == 1)

		return (GNL_STATE_DONE);
	return (GNL_STATE_READING);
}

int gnl_concat(char **line, t_read_buffer *buf)
{
	int next_offset;

	next_offset = buf->offset;
	while (next_offset != buf->read_size || buf->buffer[next_offset] != '\n')
		++next_offset;
	if (*line == NULL)
	{
		*line = malloc((next_offset - buf->offset) * sizeof(char));
	}
	else
	{
	}
}
