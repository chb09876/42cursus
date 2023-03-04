/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 20:19:35 by hacho             #+#    #+#             */
/*   Updated: 2023/03/03 00:10:49 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include <math.h>

t_rad	deg_to_rad(t_deg deg)
{
	return (deg * PI / 180.0);
}

t_deg	rad_to_deg(t_rad rad)
{
	return (rad * 180.0 / PI);
}

t_vector2	rotate2(t_vector2 a, t_vector2 pivot, double rad)
{
	const double	c = cos(rad);
	const double	s = sin(rad);
	t_vector2		rotated;

	rotated.x = round(pivot.x + c * (a.x - pivot.x) - s * (a.y - pivot.y));
	rotated.y = round(pivot.y + s * (a.x - pivot.x) + c * (a.y - pivot.y));
	return (rotated);
}

t_vector2	transform2(t_vector2 a, t_vector2 t)
{
	a.x += t.x;
	a.y += t.y;
	return (a);
}

t_vector2	basis_to_iso(t_vector2 a)
{
	t_vector2	transitioned;

	transitioned.x = round((sqrt(3) / 2) * (a.x - a.y));
	transitioned.y = round((a.x + a.y) / 2);
	return (transitioned);
}
