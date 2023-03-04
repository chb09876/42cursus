/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:06:46 by hacho             #+#    #+#             */
/*   Updated: 2023/03/04 18:38:19 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

unsigned int	get_r(unsigned int color);
unsigned int	get_g(unsigned int color);
unsigned int	get_b(unsigned int color);
unsigned int	get_rgba(unsigned int r, unsigned int g,
					unsigned int b, unsigned int a);
unsigned int	gradient(unsigned int start, unsigned int dest,
					int period, int level);

#endif