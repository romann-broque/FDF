/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_vertex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:11:26 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/20 18:07:13 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static uint	get_red(float rad)
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

static uint	get_green(float rad)
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

static uint	get_blue(float rad)
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

void	color_vertex(t_vertex *vertex, const int minz, const int maxz)
{
	float	rad;

	if (minz == maxz)
	{
		vertex->color.red = UCHAR_MAX;
		vertex->color.green = UCHAR_MAX;
		vertex->color.blue = UCHAR_MAX;
		vertex->color.sum = WHITE;
	}
	else
	{
		rad = (float)(vertex->z - minz) / (float)(maxz - minz);
		vertex->color.red = get_red(rad);
		vertex->color.green = get_green(rad);
		vertex->color.blue = get_blue(rad);
		vertex->color.sum = sum_color(vertex->color);
	}
}
