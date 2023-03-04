/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:50:58 by hacho             #+#    #+#             */
/*   Updated: 2023/03/04 18:11:58 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

int	hex_to_int(char hex)
{
	if (hex >= '0' && hex <= '9')
		return (hex - '0');
	return (hex - 'A');
}

void	safe_pixel(mlx_image_t *img, int x, int y, unsigned int color)
{
	if (x >= 0 && x < (int)img->width && y >= 0 && y < (int)img->height)
		mlx_put_pixel(img, x, y, color);
}
