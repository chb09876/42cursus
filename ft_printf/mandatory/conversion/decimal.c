/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:17:54 by hacho             #+#    #+#             */
/*   Updated: 2022/11/17 19:38:26 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "conversion.h"

ssize_t	print_decimal(int n)
{
	char const	*num_to_str = ft_itoa(n);
	size_t		numlen;
	ssize_t		write_bytes;

	if (num_to_str == NULL)
		return (-1);
	numlen = ft_strlen(num_to_str);
	write_bytes = write(STDOUT_FILENO, num_to_str, numlen);
	free((void *)num_to_str);
	if (write_bytes == -1 || (size_t)write_bytes < numlen)
		return (-1);
	return (numlen);
}
