/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 21:49:29 by hacho             #+#    #+#             */
/*   Updated: 2023/01/24 22:29:21 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
#define DRAW_H

#include "vector.h"
#include "fdf.h"

int bresenham(t_vector2 a, t_vector2 b, t_fdf_context *fdf);

#endif