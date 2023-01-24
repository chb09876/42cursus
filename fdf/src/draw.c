#include "vector.h"
#include "fdf.h"
#include "MLX42/MLX42.h"
#include "util.h"

// static int discriminant(t_vector2 midpoint, t_vector2 a, t_vector2 b);

int bresenham(t_vector2 a, t_vector2 b, t_fdf_context *fdf, mlx_image_t *pixel)
{
	// assume that 1 > slope > 0
	t_vector2 delta;
	int discriminant;

	delta.x = b.x - a.x;
	delta.y = b.y - a.y;

	mlx_image_to_window(fdf->mlx, pixel, a.x, a.y);
	if (delta.y >= 0 && delta.x >= delta.y)
	{
		discriminant = 2 * delta.y - delta.x;
		while (a.x < b.x)
		{
			if (discriminant < 0)
			{
				mlx_image_to_window(fdf->mlx, pixel, ++a.x, a.y);
				discriminant += 2 * delta.y;
			}
			else
			{
				mlx_image_to_window(fdf->mlx, pixel, ++a.x, ++a.y);
				discriminant += 2 * (delta.y - delta.x);
			}
		}
	}
	else if (delta.y >= 0 && delta.x < delta.y)
	{
		// reverse bresenham
	}
	else if (delta.y < 0 && delta.x >= -delta.y)
	{
		discriminant = 2 * -delta.y + delta.x;
		while (a.x < b.x)
		{
			if (discriminant < 0)
			{
				mlx_image_to_window(fdf->mlx, pixel, ++a.x, a.y);
				discriminant += 2 * -delta.y;
			}
			else
			{
				mlx_image_to_window(fdf->mlx, pixel, ++a.x, --a.y);
				discriminant += 2 * (-delta.y + delta.x);
			}
		}
	}
	else if (delta.y < 0 && delta.x < -delta.y)
	{
	}
	return 1;
}

// static int discriminant(t_vector2 midpoint, t_vector2 a, t_vector2 b)
// {
// 	// assuem that delta.x and delta.y are positive
// 	t_vector2 delta;

// 	delta.x = a.x - b.x;
// 	delta.y = a.y - b.y;
// 	return (-2 * delta.x * (midpoint.y - a.y) + 2 * delta.y * (midpoint.x - a.x));
// }