/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 04:03:56 by hacho             #+#    #+#             */
/*   Updated: 2022/12/27 04:24:08 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"
#include <stdlib.h>

t_node	*make_node(int data, t_node *next)
{
	t_node	*new_node;

	new_node = malloc(sizeof * new_node);
	if (new_node == NULL)
		return (NULL);
	new_node->data = data;
	new_node->next = next;
	return (new_node);
}
