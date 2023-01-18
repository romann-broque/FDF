/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_color.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:36:47 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/18 20:34:39 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	change_color(t_win *window)
{
	uint *const	color_offset = &window->map.color_offset;

	if (*color_offset)
		*color_offset >>= 1;
	else
		*color_offset = WHITE;
	return (EXIT_SUCCESS);
}
