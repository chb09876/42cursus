/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:45:55 by hacho             #+#    #+#             */
/*   Updated: 2022/11/06 22:30:03 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_H
# define CONVERSION_H

# include <sys/types.h>
# include "options.h"

# define NULL_STR "(null)"
# define HEX_TABLE_LOWER "0123456789abcdef"
# define HEX_TABLE_UPPER "0123456789ABCDEF"
# define HEX_PREFIX_LOWER "0x"
# define HEX_PREFIX_UPPER "0X"

ssize_t	print_character(unsigned char c, t_conversion_context *context);
ssize_t	print_string(const char *s, t_conversion_context *context);
ssize_t	print_decimal(int n, t_conversion_context *context);
ssize_t	print_integer(int n, t_conversion_context *context);
ssize_t	print_unsigned_integer(unsigned int n, t_conversion_context *context);
ssize_t	print_percent(t_conversion_context *context);
ssize_t	print_hex_lower(unsigned int n, t_conversion_context *context);
ssize_t	print_hex_upper(unsigned int n, t_conversion_context *context);
ssize_t	print_pointer(unsigned long long int n, t_conversion_context *context);

#endif
