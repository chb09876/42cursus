/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 21:48:13 by hacho             #+#    #+#             */
/*   Updated: 2023/03/03 00:12:47 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "color.h"

unsigned int	gradient(unsigned int start,
	unsigned int dest, int period, int level)
{
	int	grad_r;
	int	grad_g;
	int	grad_b;

	if (get_r(dest) > get_r(start))
		grad_r = get_r(start) + (get_r(dest) - get_r(start)) / period * level;
	else
		grad_r = get_r(start) - (get_r(start) - get_r(dest)) / period * level;
	if (get_g(dest) > get_g(start))
		grad_g = get_g(start) + (get_g(dest) - get_g(start)) / period * level;
	else
		grad_g = get_g(start) - (get_g(start) - get_g(dest)) / period * level;
	if (get_b(dest) > get_b(start))
		grad_b = get_b(start) + (get_b(dest) - get_b(start)) / period * level;
	else
		grad_b = get_b(start) - (get_b(start) - get_b(dest)) / period * level;
	return (get_rgba(grad_r, grad_g, grad_b, 0xff));
}

unsigned int	get_r(unsigned int color)
{
	return ((color >> 24) & 0xff);
}

unsigned int	get_g(unsigned int color)
{
	return ((color >> 16) & 0xff);
}

unsigned int	get_b(unsigned int color)
{
	return ((color >> 8) & 0xff);
}

unsigned int	get_rgba(unsigned int r,
	unsigned int g, unsigned int b, unsigned int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}
