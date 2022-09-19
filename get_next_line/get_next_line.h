/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:04:36 by hacho             #+#    #+#             */
/*   Updated: 2022/09/19 22:13:59 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#define BUFFER_SIZE 10

#include <stddef.h>

typedef enum e_read_state {
	READ_STATE_INIT = 0,
	READ_STATE_READING,
	READ_STATE_DONE,
	READ_STATE_ERROR
}	t_read_state;

typedef struct s_read_status {
	char			*line;
	char			buf[BUFFER_SIZE];
	t_read_state	state;
	ssize_t			read_len;
}	t_read_status;

char			*get_next_line(int fd);
t_read_state	gnl_read(int fd, t_read_status *read_status);

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

#endif