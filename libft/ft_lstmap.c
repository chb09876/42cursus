/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 20:52:41 by hacho             #+#    #+#             */
/*   Updated: 2022/08/11 21:30:10 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	**new_lst;
	t_list	*new;

	if (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (new == NULL)
			return (NULL);
		new_lst = &new;
		lst = lst->next;
	}
	while (lst)
	{
		new->next = ft_lstnew(f(lst->content));
		if (new->next == NULL)
		{
			ft_lstclear(new_lst, del);
			break ;
		}
		new = new->next;
		lst = lst->next;
	}
	return (*new_lst);
}
