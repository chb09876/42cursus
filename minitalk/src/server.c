/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 23:36:33 by hacho             #+#    #+#             */
/*   Updated: 2023/03/18 18:21:27 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include <signal.h>
#include <stdio.h>

void handler(int signo)
{
	static char	c = 0;
	static int	count = 0;

	if (signo == SIGUSR1)
		c = c << 1;
	else if (signo == SIGUSR2)
		c = (c << 1) + 0b1;
	++count;
	if (count == sizeof(char) * 8)
	{
		ft_putchar_fd(c, STDOUT_FILENO);
		count = 0;
		c = 0;
	}
}

int main(void)
{
	int	pid;

	pid = getpid();
	ft_putnbr_fd(pid, STDOUT_FILENO);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (pause());
}