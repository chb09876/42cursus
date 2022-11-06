/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_upper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:17:28 by hacho             #+#    #+#             */
/*   Updated: 2022/11/06 22:17:35 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "utils.h"
#include "conversion.h"

static ssize_t	adjust_right_with_space_padding(
					unsigned int num, int length,
					t_conversion_context *context);
static ssize_t	adjust_right_with_zero_padding(
					unsigned int num, int length,
					t_conversion_context *context);
static ssize_t	adjust_left_with_space_padding(
					unsigned int num, int length,
					t_conversion_context *context);

ssize_t	print_hex_upper(unsigned int n, t_conversion_context *context)
{
	int	length;

	length = get_unsigned_length(n, 16);
	if (context->precision == 0 && n == 0)
		length = 0;
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
	unsigned int num, int length, t_conversion_context *context)
{
	ft_putchar_repeat(' ', context->min_field_width - length - \
		(context->alt_form == true && num != 0) * 2 - \
		(context->precision > length) * (context->precision - length),
		STDOUT_FILENO);
	if (context->alt_form == true && num != 0)
		write(STDOUT_FILENO, HEX_PREFIX_UPPER, 2);
	ft_putchar_repeat('0', context->precision - length, STDOUT_FILENO);
	if (length != 0)
		print_number_hex(num, HEX_TABLE_UPPER, STDOUT_FILENO);
	if (context->min_field_width - length - \
		(context->alt_form == true && num != 0) * 2 - \
		(context->precision > length) * (context->precision - length) > 0)
		return (context->min_field_width);
	return (length + (context->alt_form == true && num != 0) * 2 + \
		(context->precision - length > 0) * (context->precision - length));
}

static ssize_t	adjust_right_with_zero_padding(
	unsigned int num, int length, t_conversion_context *context)
{
	if (context->precision == -1)
		context->precision = context->min_field_width - \
		(context->alt_form == true && num != 0) * 2;
	ft_putchar_repeat(' ', context->min_field_width - length - \
		(context->alt_form == true && num != 0) * 2 - \
		(context->precision > length) * (context->precision - length), \
		STDOUT_FILENO);
	if (context->alt_form == true && num != 0)
		write(STDOUT_FILENO, HEX_PREFIX_UPPER, 2);
	ft_putchar_repeat('0', context->precision - length, STDOUT_FILENO);
	if (length != 0)
		print_number_hex(num, HEX_TABLE_UPPER, STDOUT_FILENO);
	if (context->min_field_width - length - \
		(context->alt_form == true && num != 0) * 2 - \
		(context->precision > length) * (context->precision - length) > 0)
		return (context->min_field_width);
	return (length + (context->alt_form == true && num != 0) * 2 + \
		(context->precision - length > 0) * (context->precision - length));
}

static ssize_t	adjust_left_with_space_padding(
	unsigned int num, int length, t_conversion_context *context)
{
	if (context->alt_form == true && num != 0)
		write(STDOUT_FILENO, HEX_PREFIX_UPPER, 2);
	ft_putchar_repeat('0', context->precision - length, STDOUT_FILENO);
	if (length != 0)
		print_number_hex(num, HEX_TABLE_UPPER, STDOUT_FILENO);
	ft_putchar_repeat(' ', context->min_field_width - length - \
		(context->alt_form == true && num != 0) * 2 - \
		(context->precision > length) * (context->precision - length),
		STDOUT_FILENO);
	if (context->min_field_width - length - \
		(context->alt_form == true && num != 0) * 2 - \
		(context->precision > length) * (context->precision - length) > 0)
		return (context->min_field_width);
	return (length + (context->alt_form == true && num != 0) * 2 + \
		(context->precision - length > 0) * (context->precision - length));
}
