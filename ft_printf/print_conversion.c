/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:48:47 by hacho             #+#    #+#             */
/*   Updated: 2022/10/02 17:24:38 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include "ft_printf.h"

// 레프트 정렬인 경우
// 패딩 모두 오른쪽으로
// 

ssize_t	print_character(char c, t_options *options)
{
	ssize_t	write_bytes;

	if (options->f_adjust_left == true)
	{
		
	}
	write_bytes = write(STDOUT_FILENO, &c, sizeof c);
}