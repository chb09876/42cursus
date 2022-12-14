/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:17:20 by hacho             #+#    #+#             */
/*   Updated: 2022/11/06 22:32:12 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_bonus.h"

ssize_t	print_percent(t_conversion_context *context)
{
	return (print_character('%', context));
}
