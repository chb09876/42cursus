/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:10:54 by hacho             #+#    #+#             */
/*   Updated: 2023/01/30 16:10:09 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#include "MLX42/MLX42.h"
#include "map.h"

#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 512

typedef struct s_fdf_context
{
	mlx_t		*mlx;
	mlx_image_t	*paper;
	t_world		*world;
}	t_fdf_context;

#endif