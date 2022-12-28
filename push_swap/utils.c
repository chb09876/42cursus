/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 04:01:20 by hacho             #+#    #+#             */
/*   Updated: 2022/12/27 21:25:52 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "stack.h"
#include <unistd.h>

static int ft_strlen(const char *s);

int ft_pow(int num, int level)
{
	int result;

	if (level == 0)
		return (1);
	result = 1;
	while (level > 0)
	{
		result *= num;
		--level;
	}
	return (result);
}

void ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s) * sizeof(char));
}

int is_sorted(t_stack *stack)
{
	t_node *node;
	int tmp;

	tmp = stack->bottom->data;
	node = stack->bottom;
	while (node)
	{
		if (tmp < node->data)
			return (0);
		tmp = node->data;
		node = node->next;
	}
	return (1);
}

static int ft_strlen(const char *s)
{
	const char *const tmp = s;

	while (*s)
		++s;
	return (s - tmp);
}
