/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:45:04 by hacho             #+#    #+#             */
/*   Updated: 2023/01/30 21:39:23 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
#define MAP_H

# include "vector.h"
# include "MLX42/MLX42.h"

typedef struct s_vertex {
	t_vector3		pos;
	unsigned int	color;
}	t_vertex;

typedef struct s_world {
	t_vertex	**map;
	int			width;
	int			height;
}	t_world;

t_world	*parse_map(char *filename);
void print_map(t_world *world);

#endif