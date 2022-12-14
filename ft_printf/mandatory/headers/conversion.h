/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:45:55 by hacho             #+#    #+#             */
/*   Updated: 2022/11/17 19:39:42 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_H
# define CONVERSION_H

# include <sys/types.h>

ssize_t	print_character(unsigned char c);
ssize_t	print_string(const char *s);
ssize_t	print_decimal(int n);
ssize_t	print_integer(int n);
ssize_t	print_unsigned_integer(unsigned int n);
ssize_t	print_percent(void);
ssize_t	print_hex_lower(unsigned int n);
ssize_t	print_hex_upper(unsigned int n);
ssize_t	print_pointer(unsigned long long int n);

#endif
