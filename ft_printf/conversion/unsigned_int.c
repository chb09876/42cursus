/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:17:54 by hacho             #+#    #+#             */
/*   Updated: 2022/11/06 22:18:35 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "utils.h"
#include "conversion.h"

static ssize_t	adjust_right_with_space_padding(
					long long int num, int length, char sign,
					t_conversion_context *context);
static ssize_t	adjust_right_with_zero_padding(
					long long int num, int length, char sign,
					t_conversion_context *context);
static ssize_t	adjust_left_with_space_padding(
					long long int num, int length, char sign,
					t_conversion_context *context);

ssize_t	print_unsigned_integer(unsigned int n, t_conversion_context *context)
{
	int		length;
	char	sign;

	sign = (context->sign_padding) * ' ' + \
		(!context->sign_padding && context->show_sign) * '+';
	length = !(context->precision == 0 && n == 0) * get_unsigned_length(n, 10);
	if (context->precision != -1 && context->precision < length)
		context->precision = length;
	if (context->adjust_left == false && context->zero_padding == false)
		return (adjust_right_with_space_padding(n, length, sign, context));
	else if (context->adjust_left == false && context->zero_padding == true)
		return (adjust_right_with_zero_padding(n, length, sign, context));
	else if (context->adjust_left == true)
		return (adjust_left_with_space_padding(n, length, sign, context));
	return (-1);
}

static ssize_t	adjust_right_with_space_padding(
	long long int num, int length, char sign, t_conversion_context *context)
{
	ft_putchar_repeat(' ', context->min_field_width - length - \
		(context->precision > length) * (context->precision - length) - \
		(sign != 0), STDOUT_FILENO);
	if (sign != 0)
		ft_putchar_fd(sign, STDOUT_FILENO);
	ft_putchar_repeat('0', context->precision - length, STDOUT_FILENO);
	if (length != 0)
		print_number(num, STDOUT_FILENO);
	if (context->min_field_width - length - (context->precision - length > 0) * \
		(context->precision - length) - (sign != 0) > 0)
		return (context->min_field_width);
	return (length + (sign != 0) + (context->precision > length) * \
		(context->precision - length));
}

static ssize_t	adjust_right_with_zero_padding(
	long long int num, int length, char sign, t_conversion_context *context)
{
	if (context->precision == -1)
		context->precision = context->min_field_width - (sign != 0);
	ft_putchar_repeat(' ', context->min_field_width - length - \
		(context->precision > length) * (context->precision - length) - \
		(sign != 0), STDOUT_FILENO);
	if (sign != 0)
		ft_putchar_fd(sign, STDOUT_FILENO);
	ft_putchar_repeat('0', context->precision - length, STDOUT_FILENO);
	if (length != 0)
		print_number(num, STDOUT_FILENO);
	if (context->min_field_width - length - (context->precision - length > 0) * \
		(context->precision - length) - (sign != 0) > 0)
		return (context->min_field_width);
	return (length + (sign != 0) + (context->precision > length) * \
		(context->precision - length));
}

static ssize_t	adjust_left_with_space_padding(
	long long int num, int length, char sign, t_conversion_context *context)
{
	if (sign != 0)
		ft_putchar_fd(sign, STDOUT_FILENO);
	ft_putchar_repeat('0', context->precision - length, STDOUT_FILENO);
	if (length != 0)
		print_number(num, STDOUT_FILENO);
	ft_putchar_repeat(' ', context->min_field_width - length - \
		(context->precision > length) * (context->precision - length) - \
		(sign != 0), STDOUT_FILENO);
	if (context->min_field_width - length - (context->precision - length > 0) * \
		(context->precision - length) - (sign != 0) > 0)
		return (context->min_field_width);
	return (length + (sign != 0) + (context->precision > length) * \
		(context->precision - length));
}
