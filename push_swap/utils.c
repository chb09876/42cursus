/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 04:01:20 by hacho             #+#    #+#             */
/*   Updated: 2022/12/27 04:01:31 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <unistd.h>

static int	ft_strlen(const char *s);

int	ft_pow(int num, int level)
{
	int	result;

	if (level == 0)
		return (1);
	result = 1;
	while (level > 0)
	{
		result *= num;
		--level;
	}
	return (result);
}

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s) * sizeof(char));
}

static int	ft_strlen(const char *s)
{
	const char *const	tmp = s;

	while (*s)
		++s;
	return (s - tmp);
}
