/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 21:56:22 by hacho             #+#    #+#             */
/*   Updated: 2022/11/06 22:36:35 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "options_bonus.h"
#include "libft.h"

static void	init_context(t_conversion_context *context);
static int	set_flags(const char *format, t_conversion_context *context);
static int	set_min_field_width(
				const char *format, t_conversion_context *context);
static int	set_precision(const char *format, t_conversion_context *context);

int	set_conversion_context(const char *format, t_conversion_context *context)
{
	int	offset;

	offset = 0;
	init_context(context);
	offset += set_flags(format + offset, context);
	offset += set_min_field_width(format + offset, context);
	offset += set_precision(format + offset, context);
	context->type = *(format + offset++);
	return (offset);
}

static void	init_context(t_conversion_context *context)
{
	context->adjust_left = false;
	context->alt_form = false;
	context->show_sign = false;
	context->sign_padding = false;
	context->zero_padding = false;
	context->min_field_width = 0;
	context->precision = -1;
	context->type = 0;
}

static int	set_flags(const char *format, t_conversion_context *context)
{
	int	offset;

	offset = 0;
	while (*(format + offset) == '-' || *(format + offset) == ' ' || \
		*(format + offset) == '+' || *(format + offset) == '#' || \
		*(format + offset) == '0')
	{
		if (*(format + offset) == '#')
			context->alt_form = true;
		else if (*(format + offset) == '0')
			context->zero_padding = true;
		else if (*(format + offset) == '-')
			context->adjust_left = true;
		else if (*(format + offset) == ' ')
			context->sign_padding = true;
		else if (*(format + offset) == '+')
			context->show_sign = true;
		++offset;
	}
	return (offset);
}

static int	set_min_field_width(
			const char *format, t_conversion_context *context)
{
	int	offset;

	offset = 0;
	if (*(format + offset) >= '0' && *(format + offset) <= '9')
	{
		context->min_field_width = ft_atoi((format + offset));
		while (*(format + offset) >= '0' && *(format + offset) <= '9')
			++offset;
	}
	return (offset);
}

static int	set_precision(const char *format, t_conversion_context *context)
{
	int	offset;

	offset = 0;
	if (*(format + offset) == '.')
	{
		++offset;
		context->precision = ft_atoi(format + offset);
		while (*(format + offset) >= '0' && *(format + offset) <= '9')
			++offset;
	}
	return (offset);
}
