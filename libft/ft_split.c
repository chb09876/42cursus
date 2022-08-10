/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 22:35:40 by hacho             #+#    #+#             */
/*   Updated: 2022/08/10 22:52:42 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	count_token(const char *s, char delimiter);

char	**ft_split(char const *s, char c)
{
	const size_t	token_number = count_token(s, c);

	
}

static int	count_token(const char *s, char delimiter)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == delimiter)
			++s;
		if (*s != '\0')
			++count;
		while (*s != delimiter && *s != '\0')
			++s;
	}
	return (count);
}
