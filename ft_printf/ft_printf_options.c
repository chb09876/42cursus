/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_options.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 21:56:22 by hacho             #+#    #+#             */
/*   Updated: 2022/10/23 17:12:36 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft.h"

int			ft_numlen(int num);
static void	init_options(t_conversion_options *opt);
static char	*set_flags(char *format, t_flags *flags);
static char	*set_min_field_width(char *format, t_conversion_options *opt);
static char	*set_precision(char *format, t_conversion_options *opt);

void	set_conversion_options(char **format, t_conversion_options *opt)
{
	init_options(opt);
	*format = set_flags(*format + 1, &opt->flags);
	*format = set_min_field_width(*format, opt);
	*format = set_precision(*format, opt);
	opt->type = **format;
	++(*format);
}

static void	init_options(t_conversion_options *opt)
{
	opt->flags.adjust_left = false;
	opt->flags.alt_form = false;
	opt->flags.show_sign = false;
	opt->flags.sign_padding =false;
	opt->flags.zero_padding = false;
	opt->min_field_width = 0;
	opt->precision = -1;
	opt->type = 0;
}

static char	*set_flags(char *format, t_flags *flags)
{
	while (*format == '-' || *format == ' ' || *format == '+' || *format == '#' || *format == '0')
	{
		if (*format == '#')
			flags->alt_form = true;
		else if (*format == '0')
			flags->zero_padding = true;
		else if (*format == '-')
			flags->adjust_left = true;
		else if (*format == ' ')
			flags->sign_padding = true;
		else if (*format == '+')
			flags->show_sign = true;
		++(format);
	}
	return (format);
}

static char	*set_min_field_width(char *format, t_conversion_options *opt)
{
	if (*format >= '0' && *format <= '9')
	{
		opt->min_field_width = ft_atoi(format);
		while (*format >= '0' && *format <= '9')
			++format;
	}
	return (format);
}

static char	*set_precision(char *format, t_conversion_options *opt)
{
	if (*format == '.')
	{
		++format;
		if (*format >= '0' && *format <= '9')
		{
			opt->precision = ft_atoi(format);
			while (*format >= '0' && *format <= '9')
				++format;
		}
	}
	return (format);
}

int	ft_numlen(int num)
{
	int len = 0;

	if (num == 0)
		return (1);
	while (num)
	{
		num /= 10;
		++len;
	}
	return (len);
}
