/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 18:22:29 by hacho             #+#    #+#             */
/*   Updated: 2022/08/14 19:30:14 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*allocated;

	allocated = malloc(count * size);
	if (allocated == NULL)
		return (NULL);
	ft_memset(allocated, 0, count * size);
	return (allocated);
}
