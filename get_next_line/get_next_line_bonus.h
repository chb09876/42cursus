/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:04:36 by hacho             #+#    #+#             */
/*   Updated: 2022/09/22 20:27:23 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

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

char	*get_next_line(int fd);

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
void	*ft_memmove(void *dst, const void *src, size_t n);

#endif