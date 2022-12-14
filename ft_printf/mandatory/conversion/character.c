/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 22:00:17 by hacho             #+#    #+#             */
/*   Updated: 2022/11/17 19:07:47 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "conversion.h"

ssize_t	print_character(unsigned char c)
{
	ssize_t	write_bytes;

	write_bytes = write(STDOUT_FILENO, &c, sizeof c);
	if (write_bytes == -1 || write_bytes < (ssize_t)(sizeof c))
		return (-1);
	return (write_bytes);
}
