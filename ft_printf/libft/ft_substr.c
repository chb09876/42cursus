/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:47:59 by hacho             #+#    #+#             */
/*   Updated: 2022/08/13 20:07:49 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	const size_t	s_len = ft_strlen(s);
	size_t			len_from_start;
	char			*new_str;

	if (s_len <= start)
		return (ft_strdup(""));
	len_from_start = ft_strlen(s + start);
	if (len_from_start < len)
		len = len_from_start;
	new_str = malloc((len + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	ft_strlcpy(new_str, s + start, len + 1);
	return (new_str);
}
