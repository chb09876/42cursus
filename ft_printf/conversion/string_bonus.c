/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:17:47 by hacho             #+#    #+#             */
/*   Updated: 2022/11/06 22:32:58 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "utils_bonus.h"
#include "conversion_bonus.h"

static ssize_t	adjust_left(
					const char *s, int len, t_conversion_context *context);
static ssize_t	adjust_right(
					const char *s, int len, t_conversion_context *context);

ssize_t	print_string(const char *s, t_conversion_context *context)
{
	int	len;

	if (s == NULL)
		s = NULL_STR;
	len = ft_strlen(s);
	if (context->precision != -1 && len > context->precision)
		len = context->precision;
	if (context->adjust_left == false)
		return (adjust_left(s, len, context));
	else if (context->adjust_left == true)
		return (adjust_right(s, len, context));
	return (-1);
}

static ssize_t	adjust_left(
	const char *s, int len, t_conversion_context *context)
{
	if (ft_putchar_repeat(' ', context->min_field_width - len, \
		STDOUT_FILENO) == -1)
		return (-1);
	if (write(STDOUT_FILENO, s, len) == -1)
		return (-1);
	if (context->min_field_width - len > 0)
		return (context->min_field_width);
	return (len);
}

static ssize_t	adjust_right(
	const char *s, int len, t_conversion_context *context)
{
	if (write(STDOUT_FILENO, s, len) == -1)
		return (-1);
	if (ft_putchar_repeat(' ', context->min_field_width - len, \
		STDOUT_FILENO) == -1)
		return (-1);
	if (context->min_field_width - len > 0)
		return (context->min_field_width);
	return (len);
}
