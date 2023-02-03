/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:32:49 by hacho             #+#    #+#             */
/*   Updated: 2023/01/26 14:34:48 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
#define MATRIX_H

#include "vector.h"

#define PI 3.1415926535897932384

double deg_to_rad(double deg);
double rad_to_deg(double rad);
t_vector2 rotate2(t_vector2 a, t_vector2 pivot, double rad);

#endif