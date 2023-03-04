/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:57:20 by hacho             #+#    #+#             */
/*   Updated: 2023/03/04 18:35:59 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRESENHAM_H
# define BRESENHAM_H

# include "vector.h"
# include "fdf.h"

void	bresenham(t_vertex a, t_vertex b, t_fdf_context *fdf);

#endif