/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:38:40 by hacho             #+#    #+#             */
/*   Updated: 2023/03/04 18:52:39 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "fdf.h"
#include "draw.h"
#include "libft.h"
#include "matrix.h"
#include "init.h"
#include <memory.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

static int	ft_error(char *str, int exitnum);
static void	exit_hook(mlx_key_data_t keydata, void *param);
static void	terminate_fdf(t_fdf_context *fdf);

int	main(int argc, char *argv[])
{
	t_fdf_context	fdf;

	if (argc != 2)
		return (ft_error("Invalid arguments.", 1));
	fdf = init_fdf(argv[1]);
	if (fdf.world == NULL || fdf.mlx == NULL || fdf.paper == NULL)
		return (ft_error("init fdf is failed.", 1));
	init_screen(&fdf);
	if (mlx_image_to_window(fdf.mlx, fdf.paper, 0, 0) == -1)
		return (ft_error("fail...", 1));
	drawfdf(&fdf);
	mlx_key_hook(fdf.mlx, exit_hook, &fdf);
	mlx_loop(fdf.mlx);
	terminate_fdf(&fdf);
	return (0);
}

static void	terminate_fdf(t_fdf_context *fdf)
{
	int	y;

	mlx_delete_image(fdf->mlx, fdf->paper);
	mlx_terminate(fdf->mlx);
	y = -1;
	while (++y < fdf->world->height)
		free(fdf->world->map[y]);
	free(fdf->world->map);
	free(fdf->world);
}

static int	ft_error(char *str, int exitnum)
{
	ft_putstr_fd(str, STDERR_FILENO);
	return (exitnum);
}

static void	exit_hook(mlx_key_data_t keydata, void *param)
{
	t_fdf_context	*fdf;

	fdf = param;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(fdf->mlx);
}
