/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:17:47 by hacho             #+#    #+#             */
/*   Updated: 2022/11/17 19:16:49 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "conversion.h"

ssize_t	print_string(const char *s)
{
	ssize_t	write_bytes;
	size_t	strlen;

	if (s == NULL)
		s = "(null)";
	strlen = ft_strlen(s);
	write_bytes = write(STDOUT_FILENO, s, strlen);
	if (write_bytes == -1 || (size_t)write_bytes < strlen)
		return (-1);
	return (strlen);
}
