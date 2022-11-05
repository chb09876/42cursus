/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:17:47 by hacho             #+#    #+#             */
/*   Updated: 2022/11/02 16:59:27 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "utils.h"
#include "conversion.h"

ssize_t	print_string(const char *s, t_conversion_context *context)
{
	int	len;

	if (s == NULL)
		s = NULL_STR;
	len = ft_strlen(s);
	if (context->precision != -1 && len > context->precision)
		len = context->precision;
	if (context->adjust_left == false)
	{
		if (ft_putchar_repeat(' ', context->min_field_width - len, STDOUT_FILENO) == -1)
			return (-1);
		if (write(STDOUT_FILENO, s, len) == -1)
			return (-1);
	}
	else if (context->adjust_left == true)
	{
		if (write(STDOUT_FILENO, s, len) == -1)
			return (-1);
		if (ft_putchar_repeat(' ', context->min_field_width - len, STDOUT_FILENO) == -1)
			return (-1);
	}
	if (context->min_field_width - len > 0)
		return (context->min_field_width);
	return (len);
}
