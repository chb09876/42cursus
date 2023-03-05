/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:10:54 by hacho             #+#    #+#             */
/*   Updated: 2023/03/04 20:32:40 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "MLX42/MLX42.h"
# include "map.h"
# define WINDOW_WIDTH 1800
# define WINDOW_HEIGHT 1000
# define DEFAULT_COLOR 0xffffffff
# define DEFAULT_SCALE 10
# define OFFSET_X 500
# define OFFSET_Y 300
# define Z_CORRECTION 0.3

typedef struct s_fdf_context
{
	mlx_t		*mlx;
	mlx_image_t	*paper;
	t_world		*world;
	t_vector2	screen_offset;
	int			scale;
}	t_fdf_context;

#endif