/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:17:47 by hacho             #+#    #+#             */
/*   Updated: 2022/10/23 16:13:15 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../ft_printf.h"
#include "libft.h"

ssize_t	print_padding(char pad, int size);

ssize_t	print_string(const char *s, t_conversion_options *opt)
{
	int	len;

	if (s == NULL)
		s = FT_PRINTF_NULL_STR;
	len = ft_strlen(s);
	if (opt->precision != -1 && len > opt->precision)
		len = opt->precision;
	if (opt->flags.adjust_left == false)
	{
		if (print_padding(' ', opt->min_field_width - len) == -1)
			return (-1);
		if (write(STDOUT_FILENO, s, len) == -1)
			return (-1);
	}
	else if (opt->flags.adjust_left == true)
	{
		if (write(STDOUT_FILENO, s, len) == -1)
			return (-1);
		if (print_padding(' ', opt->min_field_width - len) == -1)
			return (-1);
	}
	if (opt->min_field_width - len > 0)
		return (opt->min_field_width);
	return (len);
}
