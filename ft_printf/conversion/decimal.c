/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:17:54 by hacho             #+#    #+#             */
/*   Updated: 2022/11/04 23:38:06 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "utils.h"
#include "conversion.h"

ssize_t	print_decimal(int n, t_conversion_context *context)
{
	long long int	n_without_sign;
	int				length;
	char			sign;

	if (n < 0)
		n_without_sign = -n;
	else
		n_without_sign = n;
	sign = 0;
	length = get_number_length(n);
	if (n < 0)
		sign = '-';
	else if (context->sign_padding)
		sign = ' ';
	else if (context->show_sign)
		sign = '+';
	if (context->precision != -1 && context->precision < length)
		context->precision = length;
	if (context->adjust_left == false && context->zero_padding == false)
	{
		ft_putchar_repeat(' ', context->min_field_width - (sign != 0) - (context->precision != -1) * context->precision, STDOUT_FILENO);
		if (sign != 0)
			ft_putchar_fd(sign, STDOUT_FILENO);
		ft_putchar_repeat('0', context->precision - length, STDOUT_FILENO);
		print_number(n_without_sign, STDOUT_FILENO);
	}
	else if (context->adjust_left == false && context->zero_padding == true)
	{
		if (context->precision == -1)
			context->precision = context->min_field_width - (sign != 0);
		ft_putchar_repeat(' ', context->min_field_width - (sign != 0) - (context->precision != -1) * context->precision, STDOUT_FILENO);
		if (sign != 0)
			ft_putchar_fd(sign, STDOUT_FILENO);
		ft_putchar_repeat('0', context->precision - length, STDOUT_FILENO);
		print_number(n_without_sign, STDOUT_FILENO);
	}
	else if (context->adjust_left == true)
	{
		if (sign != 0)
			ft_putchar_fd(sign, STDOUT_FILENO);
		ft_putchar_repeat('0', context->precision - length, STDOUT_FILENO);
		print_number(n_without_sign, STDOUT_FILENO);
		ft_putchar_repeat(' ', context->min_field_width - (sign != 0) - (context->precision != -1) * context->precision, STDOUT_FILENO);
	}
	if (context->min_field_width - length > 0)
		return (context->min_field_width);
	return (length);
}


