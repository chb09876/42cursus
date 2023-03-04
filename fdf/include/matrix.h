/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:32:49 by hacho             #+#    #+#             */
/*   Updated: 2023/03/04 18:37:41 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include "vector.h"

# define PI 3.1415926535897932384

typedef double	t_deg;
typedef double	t_rad;

t_rad		deg_to_rad(t_deg deg);
t_deg		rad_to_deg(t_rad rad);
t_vector2	rotate2(t_vector2 a, t_vector2 pivot, double rad);
t_vector2	transform2(t_vector2 a, t_vector2 t);
t_vector2	basis_to_iso(t_vector2 a);

#endif