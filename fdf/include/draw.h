/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 21:49:29 by hacho             #+#    #+#             */
/*   Updated: 2023/03/04 18:36:16 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "vector.h"
# include "fdf.h"

void	drawline(t_vertex a, t_vertex b, t_fdf_context *fdf);
void	drawfdf(t_fdf_context *fdf);

#endif