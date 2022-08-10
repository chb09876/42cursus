/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:00:49 by hacho             #+#    #+#             */
/*   Updated: 2022/08/10 18:40:00 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	const char	*s_org = s;

	while (*s)
		++s;
	while (*s != (char)c && s != s_org)
		--s;
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}
