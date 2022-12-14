/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:17:54 by hacho             #+#    #+#             */
/*   Updated: 2022/11/06 22:34:38 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion.h"

ssize_t	print_integer(int n, t_conversion_context *context)
{
	return (print_decimal(n, context));
}
