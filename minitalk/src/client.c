/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:00:59 by hacho             #+#    #+#             */
/*   Updated: 2023/03/18 19:45:59 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

int	ft_error(char *message, int exitcode)
{
	ft_putstr_fd(message, STDOUT_FILENO);
	return (exitcode);
}

void	send_char(int pid, char c)
{
	unsigned char	bit_mask;

	bit_mask = 0b10000000;
	// printf("char: %c\n", c);
	while (bit_mask)
	{
		// printf("bit: %d masked: %d\n",bit_mask, c & bit_mask);
		if (c & bit_mask)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		bit_mask = bit_mask >> 1;
		usleep(2000);
	}
}

int main(int argc, char *argv[])
{
	int	i;
	int	server_pid;

	if (argc != 3)
		ft_error("Invalid argument.", 1);
	server_pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i])
	{
		send_char(server_pid, argv[2][i]);
		++i;
	}
	return (0);
}