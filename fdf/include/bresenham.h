/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:57:20 by hacho             #+#    #+#             */
/*   Updated: 2023/01/25 16:57:58 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRESENHAM_H
#define BRESENHAM_H

#include "vector.h"
#include "fdf.h"

int bresenham(t_vector2 a, t_vector2 b, t_fdf_context *fdf);

#endif