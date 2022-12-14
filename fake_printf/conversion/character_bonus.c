/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 22:00:17 by hacho             #+#    #+#             */
/*   Updated: 2022/11/06 22:30:23 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utils_bonus.h"
#include "conversion_bonus.h"

ssize_t	print_character(unsigned char c, t_conversion_context *context)
{
	if (context->adjust_left == false)
	{
		if (ft_putchar_repeat(' ', context->min_field_width - \
			(int)(sizeof c), STDOUT_FILENO) == -1)
			return (-1);
		if (write(STDOUT_FILENO, &c, sizeof c) == -1)
			return (-1);
	}
	else if (context->adjust_left == true)
	{
		if (write(STDOUT_FILENO, &c, sizeof c) == -1)
			return (-1);
		if (ft_putchar_repeat(' ', context->min_field_width - \
			(int)(sizeof c), STDOUT_FILENO) == -1)
			return (-1);
	}
	if (context->min_field_width - (int)(sizeof c) > 0)
		return (context->min_field_width);
	return (sizeof c);
}
