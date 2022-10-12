/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_decimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:17:54 by hacho             #+#    #+#             */
/*   Updated: 2022/10/08 23:48:33 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../ft_printf.h"

// ssize_t	print_decimal(int d, t_conversion_options *opt)
// {
	

// 	if (opt->flags.adjust_left == false)
// 	{
// 		if (print_padding(' ', opt->min_field_width - sizeof c) == -1)
// 			return (-1);
// 		if (write(STDOUT_FILENO, &c, sizeof c) == -1)
// 			return (-1);
// 	}
// 	else if (opt->flags.adjust_left == true)
// 	{
// 		if (write(STDOUT_FILENO, &c, sizeof c) == -1)
// 			return (-1);
// 		if (print_padding(' ', opt->min_field_width - sizeof c) == -1)
// 			return (-1);
// 	}
// 	if (opt->min_field_width - sizeof c > 0)
// 		return (opt->min_field_width);
// 	return (sizeof c);
// }
