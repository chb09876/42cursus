/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 21:29:54 by hacho             #+#    #+#             */
/*   Updated: 2022/08/15 18:56:33 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	is_set(char c, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	int		trim_start;
	int		trim_end;
	int		trimmed_str_len;
	char	*trimmed_str;

	trim_start = 0;
	while (*(s1 + trim_start) && is_set(*(s1 + trim_start), set))
		++trim_start;
	trim_end = ft_strlen(s1) - 1;
	while (trim_end >= 0 && is_set(*(s1 + trim_end), set))
		--trim_end;
	if (trim_end < trim_start)
		trimmed_str_len = 1;
	else
		trimmed_str_len = trim_end - trim_start + 2;
	trimmed_str = malloc(trimmed_str_len * sizeof(char));
	if (trimmed_str == NULL)
		return (NULL);
	ft_strlcpy(trimmed_str, s1 + trim_start, trimmed_str_len);
	return (trimmed_str);
}

int	is_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (*(set + i))
	{
		if (c == *(set + i))
			return (1);
		++i;
	}
	return (0);
}
