/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:03:45 by hacho             #+#    #+#             */
/*   Updated: 2023/03/04 19:28:11 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "bresenham.h"
#include "vector.h"
#include "matrix.h"
#include "fdf.h"

static void	scaling(t_vertex *a, t_vertex *b, int scale);
static void	move_offset(t_vertex *a, t_vertex *b, t_vector2 offset);

void	drawline(t_vertex a, t_vertex b, t_fdf_context *fdf)
{
	scaling(&a, &b, fdf->scale);
	move_offset(&a, &b, fdf->screen_offset);
	a.pos.y -= a.z * fdf->scale * Z_CORRECTION;
	b.pos.y -= b.z * fdf->scale * Z_CORRECTION;
	if (a.pos.x < b.pos.x)
		return (bresenham(a, b, fdf));
	return (bresenham(b, a, fdf));
}

void	drawfdf(t_fdf_context *fdf)
{
	int			x;
	int			y;
	t_vertex	**map;

	map = fdf->world->map;
	y = -1;
	while (++y < fdf->world->height)
	{
		x = -1;
		while (++x < fdf->world->width - 1)
			drawline(map[y][x], map[y][x + 1], fdf);
	}
	x = -1;
	while (++x < fdf->world->width)
	{
		y = -1;
		while (++y < fdf->world->height - 1)
			drawline(map[y][x], map[y + 1][x], fdf);
	}
}

static void	scaling(t_vertex *a, t_vertex *b, int scale)
{
	a->pos = scalar_mul(a->pos, scale);
	b->pos = scalar_mul(b->pos, scale);
}

static void	move_offset(t_vertex *a, t_vertex *b, t_vector2 offset)
{
	a->pos = transform2(basis_to_iso(a->pos), offset);
	b->pos = transform2(basis_to_iso(b->pos), offset);
}
