#include "MLX42/MLX42.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#define WIDTH 1024
#define HEIGHT 512

mlx_image_t *g_img;

void hook(void *param)
{
	mlx_t *mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		g_img->instances[0].y -= 1;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		g_img->instances[0].y += 1;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		g_img->instances[0].x -= 1;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		g_img->instances[0].x += 1;
}

int32_t main(void)
{
	mlx_t *mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	g_img = mlx_new_image(mlx, 1, 1);
	memset(g_img->pixels, 255, g_img->width * g_img->height * sizeof(int));

	for (int i = 0; i < 100; ++i)
		mlx_image_to_window(mlx, g_img, i, 50);

	mlx_loop_hook(mlx, &hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}