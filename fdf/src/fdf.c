/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:38:40 by hacho             #+#    #+#             */
/*   Updated: 2023/01/24 22:58:04 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "fdf.h"
#include "draw.h"
#include "libft.h"
#include <memory.h>
#include <stdio.h>
#include <unistd.h>

static t_fdf_context init_fdf();
static int ft_error(char *str, int exitnum);
static void exit_hook(mlx_key_data_t keydata, void* param);

int main()
{
	t_fdf_context	fdf;

	fdf = init_fdf();
	if (fdf.mlx == NULL || fdf.paper == NULL)
		return (ft_error("init fdf is failed.", 1));
	if (mlx_image_to_window(fdf.mlx, fdf.paper, 0, 0) == -1)
		return (ft_error("fail...", 1));
	// for (int i = 0; i < WINDOW_WIDTH; ++i)
	// 	for (int j = 0; j < 200; ++j)
	// 		mlx_put_pixel(fdf.paper, i, j, 0xff0000ff);
	t_vector2 a = {0, 100};
	t_vector2 b = {100, 50};
	bresenham(a, b, &fdf);
	// bresenham(a, b, &fdf);
	// t_vector2 c = {0, 100};
	// t_vector2 d = {100, 50};
	// bresenham(c, d, &fdf);
	mlx_key_hook(fdf.mlx, exit_hook, &fdf);
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
	memset(fdf.paper->pixels, 0, fdf.paper->width * fdf.paper->height * sizeof(int32_t));
	return (fdf);
}

static int ft_error(char *str, int exitnum)
{
	ft_putstr_fd(str, STDERR_FILENO);
	return (exitnum);
}

static void exit_hook(mlx_key_data_t keydata, void* param)
{
	t_fdf_context *fdf;

	fdf = param;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(fdf->mlx);
}
