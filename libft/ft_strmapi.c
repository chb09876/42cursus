/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 17:49:22 by hacho             #+#    #+#             */
/*   Updated: 2022/08/11 18:01:28 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	s_len;
	char	*mapped;

	s_len = ft_strlen(s);
	mapped = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (mapped == NULL)
		return (NULL);
	while (s_len)
	{
		--s_len;
		mapped[s_len] = f(s_len, s[s_len]);
	}
	return (mapped);
}
