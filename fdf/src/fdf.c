/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:38:40 by hacho             #+#    #+#             */
/*   Updated: 2023/01/24 21:00:32 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "fdf.h"
#include "draw.h"
#include <memory.h>
#include <stdio.h>
#include <unistd.h>

static t_fdf_context init_fdf();
static int ft_error(const char *str);

int main()
{
	t_fdf_context fdf;

	fdf = init_fdf();
	if (fdf.mlx == NULL || fdf.paper == NULL)
		ft_error("init fdf is failed.");
	mlx_image_t *img = mlx_new_image(fdf.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	memset(img->pixels, 0, img->width * img->height * sizeof(int));
	for (int i = 0; i < WINDOW_WIDTH; ++i)
		mlx_put_pixel(img, i, 10, 0x7cfff400);
	mlx_image_to_window(fdf.mlx, img, 0, 0);
	// t_vector2 a = {0, 100};
	// t_vector2 b = {100, 50};
	// bresenham(a, b, &fdf, img);
	// bresenham(a, b, &fdf, img);
	// t_vector2 c = {0, 100};
	// t_vector2 d = {100, 50};
	// bresenham(c, d, &fdf, img);
	mlx_loop(fdf.mlx);
	mlx_terminate(fdf.mlx);
	return 0;
}

static t_fdf_context init_fdf()
{
	t_fdf_context fdf;

	fdf.mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "hello FDF!", false);
	if (fdf.mlx == NULL)
		return (fdf);
	fdf.paper = mlx_new_image(fdf.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (fdf.paper == NULL)
		return (fdf);
	memset(fdf.paper->pixels, 0, fdf.paper->width * fdf.paper->height * sizeof(int));
	return (fdf);
}

static int ft_error(const char *str)
{
	ft_putstr_fd();
}
