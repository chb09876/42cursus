/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:56:32 by hacho             #+#    #+#             */
/*   Updated: 2023/01/30 16:10:02 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bresenham.h"

int bresenham(t_vector2 a, t_vector2 b, t_fdf_context *fdf)
{
	// assume that 1 > slope > 0
	t_vector2 delta;
	int discriminant;

	delta.x = b.x - a.x;
	delta.y = b.y - a.y;
	mlx_put_pixel(fdf->paper, a.x, a.y, 0xFF9FE5ff);
	if (delta.y >= 0 && delta.x >= delta.y)
	{
		discriminant = 2 * delta.y - delta.x;
		while (a.x < b.x)
		{
			if (discriminant < 0)
			{
				mlx_put_pixel(fdf->paper, ++a.x, a.y, 0xFF9FE5ff);
				discriminant += 2 * delta.y;
			}
			else
			{
				mlx_put_pixel(fdf->paper, ++a.x, ++a.y, 0xFF9FE5ff);
				discriminant += 2 * (delta.y - delta.x);
			}
		}
	}
	else if (delta.y >= 0 && delta.x < delta.y)
	{ // slope > 1
		discriminant = 2 * delta.x - delta.y;
		while (a.y < b.y)
		{
			if (discriminant < 0)
			{
				mlx_put_pixel(fdf->paper, a.x, ++a.y, 0xFF9FE5ff);
				discriminant += 2 * delta.x;
			}
			else
			{
				mlx_put_pixel(fdf->paper, ++a.x, ++a.y, 0xFF9FE5ff);
				discriminant += 2 * (delta.x - delta.y);
			}
		}
	}
	else if (delta.y < 0 && delta.x >= -delta.y)
	{
		discriminant = 2 * -delta.y - delta.x;
		while (a.x < b.x)
		{
			if (discriminant < 0)
			{
				mlx_put_pixel(fdf->paper, ++a.x, a.y, 0xFF9FE5ff);
				discriminant += 2 * -delta.y;
			}
			else
			{
				mlx_put_pixel(fdf->paper, ++a.x, --a.y, 0xFF9FE5ff);
				discriminant += 2 * (-delta.y - delta.x);
			}
		}
	}
	else if (delta.y < 0 && delta.x < -delta.y)
	{
		discriminant = 2 * delta.x + delta.y;
		while (a.y > b.y)
		{
			if (discriminant < 0)
			{
				mlx_put_pixel(fdf->paper, a.x, --a.y, 0xFF9FE5ff);
				discriminant += 2 * delta.x;
			}
			else
			{
				mlx_put_pixel(fdf->paper, ++a.x, --a.y, 0xFF9FE5ff);
				discriminant += 2 * (delta.x + delta.y);
			}
		}
	}
	return 1;
}