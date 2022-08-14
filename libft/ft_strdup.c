/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 18:33:38 by hacho             #+#    #+#             */
/*   Updated: 2022/08/13 19:38:07 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	const size_t	len = ft_strlen(s1);
	const char		*new_str = malloc(len * sizeof(char) + 1);

	if (new_str == NULL)
		return (NULL);
	ft_strlcpy((char *)new_str, s1, (len + 1) * sizeof(char));
	return ((void *)new_str);
}
