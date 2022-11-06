/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacho <hacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 21:25:23 by hacho             #+#    #+#             */
/*   Updated: 2022/11/06 22:27:59 by hacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTIONS_BONUS_H
# define OPTIONS_BONUS_H

# include <stdbool.h>

typedef struct s_conversion_context
{
	bool	alt_form;
	bool	zero_padding;
	bool	adjust_left;
	bool	sign_padding;
	bool	show_sign;
	int		min_field_width;
	int		precision;
	char	type;
}	t_conversion_context;

int	set_conversion_context(const char *format, t_conversion_context *context);

#endif
