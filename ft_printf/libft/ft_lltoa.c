/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:40:20 by hacho             #+#    #+#             */
/*   Updated: 2022/11/15 21:44:21 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	get_len_unsigned_ll_int(unsigned long long int n);
static void		unsigned_ll_int_to_string(
					char *str,
					size_t len,
					unsigned long long int n);

char	*ft_lltoa(long long int n)
{
	int						neg;
	unsigned long long int	unsigned_n;
	char					*str;
	size_t					len;

	neg = 0;
	if (n < 0)
	{
		neg = 1;
		unsigned_n = -n;
	}
	else
		unsigned_n = n;
	len = get_len_unsigned_ll_int(unsigned_n) + neg;
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	if (neg)
		str[0] = '-';
	unsigned_ll_int_to_string(str, len, unsigned_n);
	return (str);
}

static size_t	get_len_unsigned_ll_int(unsigned long long int n)
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

static void	unsigned_ll_int_to_string(
						char *str,
						size_t len,
						unsigned long long int n)
{
	str[len] = '\0';
	if (n == 0)
		str[--len] = '0';
	else
	{
		while (n)
		{
			str[--len] = n % 10 + '0';
			n /= 10;
		}
	}
}
