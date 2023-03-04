/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 20:50:57 by hacho             #+#    #+#             */
/*   Updated: 2023/03/04 18:50:02 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "libft.h"

t_fdf_context	init_fdf(char *filename)
{
	t_fdf_context	fdf;

	fdf.world = parse_map(filename);
	if (fdf.world == NULL)
		return (fdf);
	fdf.mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "hello FDF!", false);
	if (fdf.mlx == NULL)
		return (fdf);
	fdf.paper = mlx_new_image(fdf.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (fdf.paper == NULL)
		return (fdf);
	ft_memset(fdf.paper->pixels, 0,
		fdf.paper->width * fdf.paper->height * sizeof(int32_t));
	return (fdf);
}

void	init_screen(t_fdf_context *fdf)
{
	fdf->scale = DEFAULT_SCALE;
	fdf->screen_offset.x = OFFSET_X;
	fdf->screen_offset.y = OFFSET_Y;
}
