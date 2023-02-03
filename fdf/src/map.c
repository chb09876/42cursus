/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:44:52 by hacho             #+#    #+#             */
/*   Updated: 2023/01/30 21:41:41 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static t_world		*get_size(char *filename, t_world *world);
static unsigned int	get_color(char *color, int alpha);
static int hex_to_int(char hex);

void print_map(t_world *world)
{
	t_vertex **map = world->map;
	int x = 0, y = 0;

	y = -1;
	while (++y < world->height)
	{
		x = -1;
		while (++x < world->width)
			printf("[%d %d %d] ", map[y][x].pos.x, map[y][x].pos.y, map[y][x].pos.z);
		printf("\n");
	}
}

t_world	*parse_map(char *filename)
{
	t_world		*world;
	int x = 0, y = 0;
	const int	fd = open(filename, O_RDONLY);
	char *line;
	char	**splitted_line;

	// get width and height
	world = get_size(filename, malloc(sizeof * world));
	if (world->width == -1 || world == NULL || fd == -1)
		return (NULL);
	world->map = malloc(world->height * sizeof(t_vertex *));
	if (world->map == NULL)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		world->map[y] = malloc(world->width * sizeof(t_vertex));
		splitted_line = ft_split(line, ' ');
		free(line);
		x = 0;
		while (*(splitted_line + x))
		{
			char **num_and_color = ft_split(*(splitted_line + x), ',');
			world->map[y][x].pos.x = x;
			world->map[y][x].pos.y = y;
			world->map[y][x].pos.z = ft_atoi(num_and_color[0]);
			if (num_and_color[1] == NULL)
				world->map[y][x].color = 0xffffffff;
			else
				world->map[y][x].color = get_color(num_and_color[1], 0xFF);
			++x;
			ft_split_free(num_and_color);
		}
		ft_split_free(splitted_line);
		line = get_next_line(fd);
		++y;
	}
	return (world);
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

static unsigned int get_color(char *color, int alpha)
{
	const int r = hex_to_int(color[2]) << 4 | hex_to_int(color[3]);
	const int g = hex_to_int(color[4]) << 4 | hex_to_int(color[5]);
	const int b = hex_to_int(color[6]) << 4 | hex_to_int(color[7]);

	return (r << 24 | g << 16 | b << 8 | alpha);
}

static int hex_to_int(char hex)
{
	if (hex >= '0' && hex <= '9')
		return (hex - '0');
	return (hex - 'A');
}