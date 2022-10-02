/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 22:37:11 by hacho             #+#    #+#             */
/*   Updated: 2022/10/01 16:16:00 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdbool.h>

typedef struct s_args
{
	va_list	ap;
	int		count;
}	t_args;

typedef struct s_options
{
	bool	f_alt_form;
	bool	f_zero_padding;
	bool	f_adjust_left;
	bool	f_sign_space;
	bool	f_show_sign;
	int		min_field_width;
	int		precision;
}	t_options;

int	ft_printf(const char *format, ...);

#endif
