/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 20:19:35 by hacho             #+#    #+#             */
/*   Updated: 2023/01/28 17:22:07 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include <math.h>

double deg_to_rad(double deg)
{
	return (deg * PI / 180.0);
}

double rad_to_deg(double rad)
{
	return (rad * 180.0 / PI);
}

t_vector2 rotate2(t_vector2 a, t_vector2 pivot, double rad)
{
	const double c = cos(rad);
	const double s = sin(rad);
	t_vector2 rotated;

	rotated.x = round(pivot.x + c * (a.x - pivot.x) - s * (a.y - pivot.y));
	rotated.y = round(pivot.y + s * (a.x - pivot.x) + c * (a.y - pivot.y));
	return (rotated);
}

t_vector3 rotate3(t_vector3 a)
{
	t_vector3 rotated = a;
	return (rotated);
}
