/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 19:22:02 by hacho             #+#    #+#             */
/*   Updated: 2022/09/19 22:16:14 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_read_status	read_status;
	char					*temp;

	// 1. read data since Buffer is full or meet EOF.
	gnl_read(fd, &read_status);
	if (read_status.state == READ_STATE_DONE)
		return (read_status.line);
	else if (read_status.read_len == -1)
		return (NULL);
	// 2. copy at container with Buffer.
	while (read_status.read_len >= 0)
	{
		if (status.line == NULL)
		{
			status.line = ft_strdup("");
			if (status.line == NULL)
				return (NULL);
		}
		temp = status.line;
		status.line = ft_bufjoin(status.line, status.buffer, status.read_len);
		if (status.line == NULL)
			return (NULL);
		free(temp);
		if (status.read_len == 0)
			return (status.line);
		status.read_len = read(fd, status.buffer, BUFFER_SIZE);
	}
	free(status.line);
	return (NULL);
}


