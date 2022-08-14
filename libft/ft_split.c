/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 22:35:40 by hacho             #+#    #+#             */
/*   Updated: 2022/08/13 20:25:47 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	count_token(const char *s, char delimiter);
static int		split_word(
					char **splited,
					char const *src,
					char delimiter,
					size_t count);

char	**ft_split(char const *s, char c)
{
	const size_t	token_number = count_token(s, c);
	char			**splited;

	splited = malloc(sizeof(char **) * (token_number + 1));
	if (splited == NULL)
		return (NULL);
	if (split_word(splited, (char *)s, c, token_number) == 0)
	{
		free(splited);
		return (NULL);
	}
	return (splited);
}

static size_t	count_token(const char *s, char delimiter)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == delimiter)
			++s;
		if (*s != '\0')
			++count;
		while (*s != delimiter && *s != '\0')
			++s;
	}
	return (count);
}

static int	split_word(
				char **splited,
				const char *src,
				char delimiter,
				size_t count)
{
	char	*tmp;
	size_t	i;

	i = 0;
	while (i < count)
	{
		while (*src == delimiter)
			++src;
		tmp = (char *)src;
		while (*src != delimiter && *src)
			++src;
		splited[i] = malloc(sizeof(char) * (src - tmp + 1));
		if (splited[i] == NULL)
		{
			while (i)
				free(splited[--i]);
			return (0);
		}
		ft_strlcpy(splited[i], tmp, src - tmp + 1);
		i++;
	}
	splited[i] = NULL;
	return (1);
}
