/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 21:03:49 by hacho             #+#    #+#             */
/*   Updated: 2022/10/03 23:58:02 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

static int	is_space(char c);
static int	check_sign(const char **str);
static void	before_check_overflow(
				int is_negative,
				int *is_overflow,
				int *cutlim,
				unsigned long *cutoff);
static int	check_overflow(
				long result,
				char c,
				int cutlim,
				unsigned long cutoff);

int	ft_atoi(const char *str)
{
	int				is_negative;
	int				is_overflow;
	int				cutlim;
	long			result;
	unsigned long	cutoff;

	result = 0;
	while (is_space(*str))
		++str;
	is_negative = check_sign(&str);
	before_check_overflow(is_negative, &is_overflow, &cutlim, &cutoff);
	while (*str >= '0' && *str <= '9')
	{
		is_overflow = check_overflow(result, *str, cutlim, cutoff);
		if (is_overflow)
			break ;
		result = result * 10 + (*str++ - '0');
	}
	if (is_overflow && is_negative)
		result = LONG_MIN;
	else if (is_overflow && is_negative == 0)
		result = LONG_MAX;
	else if (is_overflow == 0 && is_negative)
		result = -result;
	return ((int)result);
}

static int	is_space(char c)
{
	return (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ');
}

static int	check_sign(const char **str)
{
	const char	c = **str;

	if (c == '-' || c == '+')
	{
		++(*str);
		if (c == '-')
			return (-1);
	}
	return (0);
}

static void	before_check_overflow(
				int is_negative,
				int *is_overflow,
				int *cutlim,
				unsigned long *cutoff)
{
	if (is_negative == -1)
		*cutoff = (unsigned long)(-LONG_MIN);
	else
		*cutoff = LONG_MAX;
	*cutlim = *cutoff % 10;
	*cutoff /= 10;
	*is_overflow = 0;
}

static int	check_overflow(
				long result,
				char c,
				int cutlim,
				unsigned long cutoff)
{
	if ((unsigned long)result > cutoff || \
		((unsigned long)result == cutoff && (c - '0') > cutlim))
		return (1);
	return (0);
}
