/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_vertex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:11:26 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/23 12:00:30 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	set_defined_color(t_color *color, const char *format)
{
	const int	sum = ft_atoi_base(format + ft_strlen(COLOR_PREFIX), HEX_BASE);

	color->sum = sum;
	get_color_comp(color);
}

void	get_color(t_vertex *vertex, const char *format, const int minz, const int maxz)
{
	format += abs_index(format, SEPARATOR) + 1;
	if (is_color_prefix_valid(format) == true)
		set_defined_color(&vertex->color, format);
	else
		color_vertex(vertex, minz, maxz);
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
