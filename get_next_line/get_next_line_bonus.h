/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:04:36 by hacho             #+#    #+#             */
/*   Updated: 2022/09/25 15:53:41 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <sys/types.h>

typedef enum e_gnl_state
{
	GNL_STATE_INIT = 0,
	GNL_STATE_READING,
	GNL_STATE_DONE,
	GNL_STATE_EOF,
	GNL_STATE_ERROR
}	t_gnl_state;

typedef struct s_read_buffer
{
	char	buffer[BUFFER_SIZE];
	int		offset;
	ssize_t	read_size;
}	t_read_buffer;

typedef struct s_gnl_status
{
	char		*line;
	t_gnl_state	state;
	int			length;
}	t_gnl_status;

typedef struct s_buffer_node
{
	int						fd;
	t_read_buffer			buf;
	struct s_buffer_node	*next;
	struct s_buffer_node	*prev;
}	t_buffer_node;

typedef struct s_buffer_list
{
	t_buffer_node	*head;
}	t_buffer_list;

char	*get_next_line(int fd);

#endif