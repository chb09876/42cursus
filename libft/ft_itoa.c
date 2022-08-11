/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 17:15:06 by hacho             #+#    #+#             */
/*   Updated: 2022/08/11 21:21:09 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	get_len_unsigned_int(unsigned int n);
static void		unsigned_int_to_string(char *str, unsigned int n, int neg);

char	*ft_itoa(int n)
{
	int				neg;
	unsigned int	tmp;
	char			*str;

	neg = 0;
	if (n < 0)
		neg = 1;
	tmp = -((unsigned int)n);
	str = malloc(sizeof(char) * (get_len_unsigned_int(tmp) + neg + 1));
	if (str == NULL)
		return (NULL);
	if (neg)
		str[0] = '-';
	unsigned_int_to_string(str, tmp, neg);
	return (str);
}

static size_t	get_len_unsigned_int(unsigned int n)
{
	size_t	i;

	if (n == 0)
		return (1);
	i = 0;
	while (n)
	{
		n /= 10;
		++i;
	}
	return (i);
}

static void	unsigned_int_to_string(char *str, unsigned int n, int neg)
{
	size_t	i;

	i = neg;
	if (n == 0)
		str[i++] = '0';
	else
	{
		while (n)
		{
			str[i++] = n % 10 + '0';
			n /= 10;
		}
	}
	str[i] = '\0';
}
