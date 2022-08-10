/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 18:22:29 by hacho             #+#    #+#             */
/*   Updated: 2022/08/10 18:26:15 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*allocated;

	if (count == 0 || size == 0)
		return (NULL);
	allocated = malloc(count * size);
	ft_memset(allocated, 0, count * size);
	return (allocated);
}