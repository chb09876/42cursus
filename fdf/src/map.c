/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:44:52 by hacho             #+#    #+#             */
/*   Updated: 2023/03/04 19:30:10 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "libft.h"
#include "fdf.h"
#include "util.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

static t_world		*get_size(char *filename, t_world *world);
static unsigned int	get_color(char *color, int alpha);
static t_world		*fill_map(int fd, t_world *world);
static void			fill_x(char	**splitted_line, t_world *world, int y);

t_world	*parse_map(char *filename)
{
	t_world		*world;
	const int	fd = open(filename, O_RDONLY);

	if (fd == -1)
		return (NULL);
	world = get_size(filename, malloc(sizeof * world));
	if (world->width == -1 || world == NULL || fd == -1)
		return (NULL);
	world->map = malloc(world->height * sizeof(t_vertex *));
	if (world->map == NULL)
		return (NULL);
	return (fill_map(fd, world));
}

static t_world	*fill_map(int fd, t_world *world)
{
	char	*line;
	char	**splitted_line;
	int		y;

	y = -1;
	line = get_next_line(fd);
	while (line)
	{
		world->map[++y] = malloc(world->width * sizeof(t_vertex));
		if (world->map[y] == NULL)
			return (NULL);
		splitted_line = ft_split(line, ' ');
		free(line);
		fill_x(splitted_line, world, y);
		line = get_next_line(fd);
	}
	return (world);
}

static void	fill_x(char	**splitted_line, t_world *world, int y)
{
	int		x;
	char	**num_and_color;

	x = 0;
	while (*(splitted_line + x))
	{
		num_and_color = ft_split(*(splitted_line + x), ',');
		world->map[y][x].pos = vector2(x, y);
		world->map[y][x].z = ft_atoi(num_and_color[0]);
		world->map[y][x].color = get_color(num_and_color[1], 0xFF);
		ft_split_free(num_and_color);
		++x;
	}
	ft_split_free(splitted_line);
}

static t_world	*get_size(char *filename, t_world *world)
{
	int		fd;
	char	*line;
	char	**splitted;

	fd = open(filename, O_RDONLY);
	if (fd == -1 || world == NULL)
		return (NULL);
	line = get_next_line(fd);
	splitted = ft_split(line, ' ');
	world->width = 0;
	while (*(splitted + world->width))
		++world->width;
	ft_split_free(splitted);
	world->height = 0;
	while (line)
	{
		++world->height;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (world);
}

static unsigned int	get_color(char *color, int alpha)
{
	int	r;
	int	g;
	int	b;

	if (color == NULL)
		return (DEFAULT_COLOR);
	r = hex_to_int(color[2]) << 4 | hex_to_int(color[3]);
	g = hex_to_int(color[4]) << 4 | hex_to_int(color[5]);
	b = hex_to_int(color[6]) << 4 | hex_to_int(color[7]);
	return (r << 24 | g << 16 | b << 8 | alpha);
}
