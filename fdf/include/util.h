/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:37:50 by hacho             #+#    #+#             */
/*   Updated: 2023/03/04 18:37:48 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include "MLX42/MLX42.h"

int		hex_to_int(char hex);
void	safe_pixel(mlx_image_t *img, int x, int y, unsigned int color);

#endif