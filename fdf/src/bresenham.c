/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:56:32 by hacho             #+#    #+#             */
/*   Updated: 2023/03/04 18:40:36 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bresenham.h"
#include "color.h"
#include "util.h"

static void	bresenham2(t_vertex a, t_vertex b, t_fdf_context *fdf, int disc);
static void	bresenham3(t_vertex a, t_vertex b, t_fdf_context *fdf, int disc);
static void	bresenham4(t_vertex a, t_vertex b, t_fdf_context *fdf, int disc);
static void	bresenham5(t_vertex a, t_vertex b, t_fdf_context *fdf, int disc);

void	bresenham(t_vertex a, t_vertex b, t_fdf_context *fdf)
{
	t_vector2	delta;
	int			color_level;

	delta.x = b.pos.x - a.pos.x;
	delta.y = b.pos.y - a.pos.y;
	color_level = 0;
	if (delta.y >= 0 && delta.x >= delta.y)
		bresenham2(a, b, fdf, 2 * delta.y - delta.x);
	else if (delta.y >= 0 && delta.x < delta.y)
		bresenham3(a, b, fdf, 2 * delta.x - delta.y);
	else if (delta.y < 0 && delta.x >= -delta.y)
		bresenham4(a, b, fdf, 2 * -delta.y - delta.x);
	else if (delta.y < 0 && delta.x < -delta.y)
		bresenham5(a, b, fdf, 2 * delta.x + delta.y);
}

static void	bresenham2(t_vertex a, t_vertex b, t_fdf_context *fdf, int disc)
{
	t_vector2		delta;
	int				color_level;
	unsigned int	color;

	delta.x = b.pos.x - a.pos.x;
	delta.y = b.pos.y - a.pos.y;
	color_level = 0;
	color = gradient(a.color, b.color, delta.x, color_level);
	safe_pixel(fdf->paper, a.pos.x, a.pos.y, color);
	while (a.pos.x < b.pos.x && a.pos.x < (int)fdf->paper->width)
	{
		color = gradient(a.color, b.color, delta.x, color_level);
		if (disc < 0)
		{
			safe_pixel(fdf->paper, ++a.pos.x, a.pos.y, color);
			disc += 2 * delta.y;
		}
		else
		{
			safe_pixel(fdf->paper, ++a.pos.x, ++a.pos.y, color);
			disc += 2 * (delta.y - delta.x);
		}
	}
}

static void	bresenham3(t_vertex a, t_vertex b, t_fdf_context *fdf, int disc)
{
	t_vector2		delta;
	int				color_level;
	unsigned int	color;

	delta.x = b.pos.x - a.pos.x;
	delta.y = b.pos.y - a.pos.y;
	color_level = 0;
	color = gradient(a.color, b.color, delta.x, color_level);
	safe_pixel(fdf->paper, a.pos.x, a.pos.y, color);
	while (a.pos.y < b.pos.y && a.pos.y < (int)fdf->paper->height)
	{
		color = gradient(a.color, b.color, delta.y, ++color_level);
		if (disc < 0)
		{
			safe_pixel(fdf->paper, a.pos.x, ++a.pos.y, color);
			disc += 2 * delta.x;
		}
		else
		{
			safe_pixel(fdf->paper, ++a.pos.x, ++a.pos.y, color);
			disc += 2 * (delta.x - delta.y);
		}
	}
}

static void	bresenham4(t_vertex a, t_vertex b, t_fdf_context *fdf, int disc)
{
	t_vector2		delta;
	int				color_level;
	unsigned int	color;

	delta.x = b.pos.x - a.pos.x;
	delta.y = b.pos.y - a.pos.y;
	color_level = 0;
	color = gradient(a.color, b.color, delta.x, color_level);
	safe_pixel(fdf->paper, a.pos.x, a.pos.y, color);
	while (a.pos.x < b.pos.x && a.pos.x < (int)fdf->paper->width)
	{
		color = gradient(a.color, b.color, delta.x, ++color_level);
		if (disc < 0)
		{
			safe_pixel(fdf->paper, ++a.pos.x, a.pos.y, color);
			disc += 2 * -delta.y;
		}
		else
		{
			safe_pixel(fdf->paper, ++a.pos.x, --a.pos.y, color);
			disc += 2 * (-delta.y - delta.x);
		}
	}
}

static void	bresenham5(t_vertex a, t_vertex b, t_fdf_context *fdf, int disc)
{
	t_vector2		delta;
	int				color_level;
	unsigned int	color;

	delta.x = b.pos.x - a.pos.x;
	delta.y = b.pos.y - a.pos.y;
	color_level = 0;
	color = gradient(a.color, b.color, delta.x, color_level);
	safe_pixel(fdf->paper, a.pos.x, a.pos.y, color);
	while (a.pos.y > b.pos.y && a.pos.y > 0)
	{
		color = gradient(a.color, b.color, -delta.y, ++color_level);
		if (disc < 0)
		{
			safe_pixel(fdf->paper, a.pos.x, --a.pos.y, color);
			disc += 2 * delta.x;
		}
		else
		{
			safe_pixel(fdf->paper, ++a.pos.x, --a.pos.y, color);
			disc += 2 * (delta.x + delta.y);
		}
	}
}
