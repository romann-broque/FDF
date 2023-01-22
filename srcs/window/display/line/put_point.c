/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:44:39 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/22 19:37:05 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static float	get_interpol_factor(const t_vertex *v1, const t_vertex *v2, const size_t pts_nb)
{
	return ((float)(sqrt(pow(v1->x - v2->x, 2) + pow(v1->y - v2->y, 2))) / (float)pts_nb);
}

static int	get_point_red(const t_vertex *v1, const t_vertex *v2, const float interpol_factor)
{
	int	red;

	red = (v2->color.red * (1 - interpol_factor) + v1->color.red * interpol_factor);
	if (red < 0)
		red = 0;
	return (red);
}

static int	get_point_blue(const t_vertex *v1, const t_vertex *v2, const float interpol_factor)
{
	int	blue;

	blue = (v2->color.blue * (1 - interpol_factor) + v1->color.blue * interpol_factor);
	if (blue < 0)
		blue = 0;
	return (blue);
}

static int	get_point_green(const t_vertex *v1, const t_vertex *v2, const float interpol_factor)
{
	int	green;

	green = (v2->color.green * (1 - interpol_factor) + v1->color.green * interpol_factor);
	if (green < 0)
		green = 0;
	return (green);
}

static int	get_point_color(const t_vertex *v1, const t_vertex *v2, const float interpol_factor)
{
	const int	red = get_point_red(v1, v2, interpol_factor);
	const int	green = get_point_green(v1, v2, interpol_factor);
	const int	blue = get_point_blue(v1, v2, interpol_factor);

	return ((red << 16) + (green << 8) + blue);
}

void	put_point(t_data *data, const t_line *line)
{
	const float	interpol_factor = get_interpol_factor(&(line->v1), &(line->v2), line->nb_points);
	const int	color = get_point_color(&(line->v1), &(line->v2), interpol_factor);

	put_pixel(data, line->v1.x, line->v1.y, color);
}
