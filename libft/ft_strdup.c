/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 18:33:38 by hacho             #+#    #+#             */
/*   Updated: 2022/08/10 21:15:22 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_strdup(const char *s1)
{
	const size_t	len = ft_strlen(s1);
	const char		*new_str = malloc(len * sizeof(char) + 1);

	if (new_str == NULL)
		return (NULL);
	ft_strlcpy(new_str, s1, (len + 1) * sizeof(char));
	return (new_str);
}
