/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 20:52:41 by hacho             #+#    #+#             */
/*   Updated: 2022/08/14 17:59:54 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	null_guard(
				t_list **lst,
				t_list *dest,
				void *content,
				void (*del)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*new;
	void	*f_result;

	if (!lst || !f)
		return (NULL);
	f_result = f(lst->content);
	new = ft_lstnew(f_result);
	if (new == NULL)
	{
		del(f_result);
		return (NULL);
	}
	start = new;
	lst = lst->next;
	while (lst)
	{
		f_result = f(lst->content);
		new->next = ft_lstnew(f_result);
		if (null_guard(&start, new->next, f_result, del))
			break ;
		new = new->next;
		lst = lst->next;
	}
	return (start);
}

static int	null_guard(
				t_list **lst,
				t_list *dest,
				void *content,
				void (*del)(void *))
{
	if (dest == NULL)
	{
		del(content);
		ft_lstclear(lst, del);
		return (1);
	}
	return (0);
}
