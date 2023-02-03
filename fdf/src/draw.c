/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:03:45 by hacho             #+#    #+#             */
/*   Updated: 2023/01/30 16:10:05 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "bresenham.h"
#include "vector.h"
#include "fdf.h"
#include "MLX42/MLX42.h"
#include "util.h"

int drawline(t_vector2 a, t_vector2 b, t_fdf_context *fdf)
{
	if (a.x < b.x)
		return (bresenham(a, b, fdf));
	return (bresenham(b, a, fdf));
}