/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:45:55 by hacho             #+#    #+#             */
/*   Updated: 2022/11/05 01:00:15 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_H
#define CONVERSION_H

# include "options.h"

# define NULL_STR "(null)"

ssize_t	print_character(unsigned char c, t_conversion_context *context);
ssize_t	print_string(const char *s, t_conversion_context *context);
ssize_t	print_decimal(int n, t_conversion_context *context);

#endif