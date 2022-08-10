/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 21:29:54 by hacho             #+#    #+#             */
/*   Updated: 2022/08/10 21:42:26 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	trimmed_start;
	size_t	trimmed_end;

	trimmed_start = 0;
	while (is_set(*(s1 + trimmed_start), set))
		++trimmed_start;
	trimmed_end = ft_strlen(s1) - 1;
	while (is_set(*(s1 + trimmed_end), set))
		--trimmed_end;
}

int	is_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (*(set + i))
	{
		if (c == *(set + i))
			return (1);
	}
	return (0);
}
