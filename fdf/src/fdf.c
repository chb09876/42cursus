/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:38:40 by hacho             #+#    #+#             */
/*   Updated: 2023/01/30 22:29:05 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "fdf.h"
#include "draw.h"
#include "libft.h"
#include "matrix.h"
#include <memory.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

static t_fdf_context init_fdf(char *filename);
static int ft_error(char *str, int exitnum);
static void exit_hook(mlx_key_data_t keydata, void *param);
static void terminate_fdf(t_fdf_context *fdf);

void check_leak(void)
{
	system("leaks --list -- fdf");
}

int main(int argc, char *argv[])
{
	atexit(check_leak);
	t_fdf_context	fdf;

	if (argc != 2)
		return (ft_error("Invalid arguments.", 1));
	fdf = init_fdf(argv[1]);
	if (fdf.world == NULL || fdf.mlx == NULL || fdf.paper == NULL)
		return (ft_error("init fdf is failed.", 1));
	if (mlx_image_to_window(fdf.mlx, fdf.paper, 0, 0) == -1)
		return (ft_error("fail...", 1));

	print_map(fdf.world);

	t_vector2 a, b;

	a.x = 200;
	a.y = 200;

	b.x = a.x + 100;
	b.y = a.y;
	// drawline(a, b, &fdf);

	for (int i = 0; i < 36; ++i)
	{
		drawline(a, rotate2(b, a, deg_to_rad(i * 10)), &fdf);
		
	}
	mlx_key_hook(fdf.mlx, exit_hook, &fdf);
	mlx_loop(fdf.mlx);
	terminate_fdf(&fdf);
	return 0;
}

static void terminate_fdf(t_fdf_context *fdf)
{
	int y;

	mlx_delete_image(fdf->mlx, fdf->paper);
	mlx_terminate(fdf->mlx);
	y = -1;
	while (++y < fdf->world->height)
		free(fdf->world->map[y]);
	free(fdf->world->map);
	free(fdf->world);
}

static t_fdf_context init_fdf(char *filename)
{
	t_fdf_context	fdf;

	fdf.world = parse_map(filename);
	if (fdf.world == NULL)
		return (fdf);
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

static void exit_hook(mlx_key_data_t keydata, void *param)
{
	t_fdf_context *fdf;

	fdf = param;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(fdf->mlx);
}
