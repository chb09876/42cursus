/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:45:04 by hacho             #+#    #+#             */
/*   Updated: 2023/03/04 18:37:25 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "vector.h"

typedef struct s_vertex
{
	t_vector2		pos;
	int				z;
	unsigned int	color;
}	t_vertex;

typedef struct s_world
{
	t_vertex	**map;
	int			width;
	int			height;
}	t_world;

t_world	*parse_map(char *filename);

#endif