/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 21:19:03 by hacho             #+#    #+#             */
/*   Updated: 2022/08/10 21:26:53 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	const char	*new_str = \
		malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));

	if (new_str == NULL)
		return (NULL);
	ft_strlcpy(new_str, s1, ft_strlen(s1) + 1);
	ft_strlcpy(new_str + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (new_str);
}