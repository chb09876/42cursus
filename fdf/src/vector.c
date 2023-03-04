/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:09:47 by hacho             #+#    #+#             */
/*   Updated: 2023/03/04 14:27:55 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector2	vector2(int x, int y)
{
	t_vector2	v;

	v.x = x;
	v.y = y;
	return (v);
}

t_vector2	scalar_mul(t_vector2 v, int scalar)
{
	v.x *= scalar;
	v.y *= scalar;
	return (v);
}
