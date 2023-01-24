/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 21:49:29 by hacho             #+#    #+#             */
/*   Updated: 2023/01/23 21:50:11 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
#define DRAW_H

#include "vector.h"
#include "fdf.h"

int bresenham(t_vector2 a, t_vector2 b, t_fdf_context *fdf, mlx_image_t *pixel);

#endif