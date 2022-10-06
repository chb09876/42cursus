/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 21:56:22 by hacho             #+#    #+#             */
/*   Updated: 2022/10/04 01:08:54 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

int	ft_atoi(const char *str);

void	init_options(t_options *opt)
{
	opt->f_adjust_left = false;
	opt->f_alt_form = false;
	opt->f_show_sign = false;
	opt->f_sign_space =false;
	opt->f_zero_padding = false;
	opt->min_field_width = 0;
	opt->precision = 0;
}

char	*set_options(char *format, t_options *opt)
{
	while (*format == '-' || *format == ' ' || *format == '+' || *format == '#' || *format == '0')
	{
		if (*format == '#')
			opt->f_alt_form = true;
		else if (*format == '0')
			opt->f_zero_padding = true;
		else if (*format == '-')
			opt->f_adjust_left = true;
		else if (*format == ' ')
			opt->f_sign_space = true;
		else if (*format == '+')
			opt->f_show_sign = true;
		++(format);
	}
	if (*format >= '0' && *format <= '9'){
		opt->min_field_width = ft_atoi(format++);}
		// 숫자 만큼 format 스킵해줘야 함... ㅠㅠ
	if (*format == '.')
		opt->precision = ft_atoi(++format);
	return (format);
}