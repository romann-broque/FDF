/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:01:26 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/27 15:52:42 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

uint	get_red(float rad)
{
	uint	red;

	if (rad < 0.5)
		red = 0;
	else if (rad < 0.75)
		red = (uint)(4 * (rad - 0.5) * UCHAR_MAX);
	else
		red = UCHAR_MAX;
	return (red);
}

uint	get_green(float rad)
{
	uint	green;

	if (rad < 0.25)
		green = (uint)(4 * rad * UCHAR_MAX);
	else if (rad < 0.75)
		green = UCHAR_MAX;
	else
		green = (uint)((1 - 4 * (rad - 0.75)) * UCHAR_MAX);
	return (green);
}

uint	get_blue(float rad)
{
	uint	blue;

	if (rad < 0.25)
		blue = UCHAR_MAX;
	else if (rad < 0.5)
		blue = (uint)((1 - 4 * (rad - 0.25)) * UCHAR_MAX);
	else
		blue = 0;
	return (blue);
}

uint	sum_color(t_color color)
{
	color.red <<= 16;
	color.green <<= 8;
	return (color.red + color.green + color.blue);
}

void	get_color_comp(t_color *color)
{
	color->red = (color->sum & RED_MASK) >> 16;
	color->green = (color->sum & GREEN_MASK) >> 8;
	color->blue = (color->sum & BLUE_MASK);
}
