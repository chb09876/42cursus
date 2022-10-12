/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:20:12 by hacho             #+#    #+#             */
/*   Updated: 2022/10/08 23:41:41 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define FT_PRINTF_NULL_STR "(null)"

# include <stdarg.h>
# include <stdbool.h>

typedef struct s_args
{
	va_list	ap;
	int		count;
}	t_args;

// '%' [flags] [min field width number] [optioanl precision period followed by number] [type specifier]

typedef struct s_flags
{
	bool	alt_form;			// '#'
	bool	zero_padding;		// '0'
	bool	adjust_left;		// '-'
	bool	sign_padding;		// ' '
	bool	show_sign;		// '+'
}	t_flags;

typedef struct s_conversion_options
{
	t_flags	flags;
	int		min_field_width;	// number following flags
	int		precision;			// '.' followed by number
	char	type;
}	t_conversion_options;

int	ft_printf(const char *format, ...);

#endif
