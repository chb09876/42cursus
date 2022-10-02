/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 22:37:11 by hacho             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/09/29 18:49:50 by hacho            ###   ########.fr       */
=======
/*   Updated: 2022/10/01 16:16:00 by hacho            ###   ########.fr       */
>>>>>>> 9df3d51a822705e245fbcde1ae67086b55fbc7a6
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

// '%' [flags] [min field width number] [optioanl precision period followed by number] [type specifier]

typedef struct s_options
{
	bool	f_alt_form;			// '#'
	bool	f_zero_padding;		// '0'
	bool	f_adjust_left;		// '-'
	bool	f_sign_padding;		// ' '
	bool	f_show_sign;		// '+'
	int		min_field_width;	// number following flags
	int		precision;			// '.' followed by number
}	t_options;

int	ft_printf(const char *format, ...);

#endif
