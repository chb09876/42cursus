/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:17:25 by hacho             #+#    #+#             */
/*   Updated: 2022/11/06 22:32:31 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utils_bonus.h"
#include "conversion_bonus.h"

static ssize_t	adjust_right_with_space_padding(
					unsigned long long int num, int length,
					t_conversion_context *context);
static ssize_t	adjust_right_with_zero_padding(
					unsigned long long int num, int length,
					t_conversion_context *context);
static ssize_t	adjust_left_with_space_padding(
					unsigned long long int num, int length,
					t_conversion_context *context);

ssize_t	print_pointer(unsigned long long int n, t_conversion_context *context)
{
	int				length;

	length = get_unsigned_length(n, 16);
	if (context->precision != -1 && context->precision < length)
		context->precision = length;
	if (context->adjust_left == false && context->zero_padding == false)
		return (adjust_right_with_space_padding(n, length, context));
	else if (context->adjust_left == false && context->zero_padding == true)
		return (adjust_right_with_zero_padding(n, length, context));
	else if (context->adjust_left == true)
		return (adjust_left_with_space_padding(n, length, context));
	return (-1);
}

static ssize_t	adjust_right_with_space_padding(
	unsigned long long int num, int length, t_conversion_context *context)
{
	ft_putchar_repeat(' ', context->min_field_width - 2 - \
		(context->precision != -1) * context->precision - \
		(context->precision == -1) * length, STDOUT_FILENO);
	write(STDOUT_FILENO, HEX_PREFIX_LOWER, 2);
	ft_putchar_repeat('0', context->precision - length, STDOUT_FILENO);
	print_number_pointer(num, HEX_TABLE_LOWER, STDOUT_FILENO);
	if (context->min_field_width - length - 2 > 0)
		return (context->min_field_width);
	return (length + 2 + (context->precision - length > 0) * \
		(context->precision - length));
}

static ssize_t	adjust_right_with_zero_padding(
	unsigned long long int num, int length, t_conversion_context *context)
{
	if (context->precision == -1)
		context->precision = context->min_field_width - 2;
	ft_putchar_repeat(' ', context->min_field_width - 2 - \
		(context->precision != -1) * context->precision, STDOUT_FILENO);
	write(STDOUT_FILENO, HEX_PREFIX_LOWER, 2);
	ft_putchar_repeat('0', context->precision - length, STDOUT_FILENO);
	print_number_pointer(num, HEX_TABLE_LOWER, STDOUT_FILENO);
	if (context->min_field_width - length - 2 > 0)
		return (context->min_field_width);
	return (length + 2 + (context->precision - length > 0) * \
		(context->precision - length));
}

static ssize_t	adjust_left_with_space_padding(
	unsigned long long int num, int length, t_conversion_context *context)
{
	write(STDOUT_FILENO, HEX_PREFIX_LOWER, 2);
	ft_putchar_repeat('0', context->precision - length, STDOUT_FILENO);
	print_number_pointer(num, HEX_TABLE_LOWER, STDOUT_FILENO);
	ft_putchar_repeat(' ', context->min_field_width - 2 - \
		(context->precision != -1) * context->precision - \
		(context->precision == -1) * length, STDOUT_FILENO);
	if (context->min_field_width - length - 2 > 0)
		return (context->min_field_width);
	return (length + 2 + (context->precision - length > 0) * \
		(context->precision - length));
}
