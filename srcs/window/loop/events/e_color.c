/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_color.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:36:47 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/20 10:36:43 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	change_color(t_win *window)
{
	t_color *const	color = &window->map.color;

	if (color->red < UCHAR_MAX)
	{
		if (color->blue > 0)
		{
			--(color->blue);
			++(color->green);
		}
		else if (color->green > 0)
		{
			--(color->green);
			++(color->red);
		}
		color->sum = sum_color(*color);
	}
	else
		init_color(color);
	return (EXIT_SUCCESS);
}
