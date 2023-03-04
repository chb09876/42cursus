/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 21:35:20 by hacho             #+#    #+#             */
/*   Updated: 2023/03/04 18:37:59 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vector2
{
	int	x;
	int	y;
}	t_vector2;

t_vector2	vector2(int x, int y);
t_vector2	scalar_mul(t_vector2 v, int scala);

#endif