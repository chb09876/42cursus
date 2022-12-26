/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_sort.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 04:04:09 by hacho             #+#    #+#             */
/*   Updated: 2022/12/27 04:04:11 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAP_SORT_H
# define HEAP_SORT_H

typedef struct s_heap
{
	int	*arr;
	int	size;
}	t_heap;

int	*heap_sort(int *arr, int size);

#endif