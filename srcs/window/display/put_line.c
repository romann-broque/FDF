/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:10:16 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/22 17:31:46 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_sign(const double nb)
{
	if (nb < 0)
		return (-1);
	return (1);
}

static bool	are_same_crd(const double c1, const double c2)
{
	return ((int)c1 == (int)c2);
}

static void	put_point(t_data *data, const t_line *line)
{
	int		color;
	float	rad = (float)(sqrt((line->v1.x - line->v2.x) * (line->v1.x - line->v2.x)
				+ (line->v1.y - line->v2.y) * (line->v1.y - line->v2.y))) / (float)(line->nb_points);
	int		red = line->v2.color.red * (1 - rad) + line->v1.color.red * rad;
	int		green = (line->v2.color.green * (1 - rad) + line->v1.color.green * rad);
	int		blue = (line->v2.color.blue * (1 - rad) + line->v1.color.blue * rad);

	color = (red << 16) + (green << 8) + blue;
	put_pixel(data, line->v1.x, line->v1.y, color);
}

static void	plot_line(t_data *data, t_line *line)
{
	size_t	i;

	i = 0;
	while (i < 1000)
	{
		put_point(data, line);
		if (are_same_crd(line->v1.x, line->v2.x) && are_same_crd(line->v1.y, line->v2.y))
			break ;
		line->e2 = 2 * line->error;
		if (line->e2 >= line->dy)
		{
			if (are_same_crd(line->v1.x, line->v2.x))
				break ;
			line->error += line->dy;
			line->v1.x += line->sx;
		}
		if (line->e2 <= line->dx)
		{
			if (are_same_crd(line->v1.y, line->v2.y))
				break ;
			line->error += line->dx;
			line->v1.y += line->sy;
		}
		++i;
	}
}

static bool	are_pixels_out(const double x1, const double y1, const double x2, const double y2)
{
	if (x1 >= 0 && x1 <= WIDTH && x2 >= 0 && x2 <= WIDTH)
		return ((y1 < 0 && y2 < 0) || (y1 > HEIGHT && y2 > HEIGHT));
	else if (y1 >= 0 && y1 <= HEIGHT && y2 >= 0 && y2 <= HEIGHT)
		return ((x1 < 0 && x2 < 0) || (x1 > WIDTH && x2 > WIDTH));
	return (((x1 < 0 && x2 < 0) || (x1 > WIDTH && x2 > WIDTH)) && ((y1 < 0 && y2 < 0) || (y1 > HEIGHT && y2 > HEIGHT)));
}

static bool is_line_printable(t_line *line)
{
	return (are_pixels_out(line->v1.x, line->v1.y, line->v2.x, line->v2.y) == false);
}

void cpy_vertex(t_vertex *vdest, const t_vertex *vsrc)
{
	set_vertex(vdest, vsrc->x, vsrc->y, vsrc->z, 0);
	vdest->color.red = vsrc->color.red;
	vdest->color.green = vsrc->color.green;
	vdest->color.blue = vsrc->color.blue;
	vdest->color.sum = vsrc->color.sum;
}

const t_vertex *get_max_alt(const t_vertex *v1, const t_vertex *v2)
{
	if (v1->z > v2->z)
		return (v1);
	return (v2);
}

const t_vertex *get_min_alt(const t_vertex *v1, const t_vertex *v2)
{
	if (v1->z > v2->z)
		return (v2);
	return (v1);
}

void put_line(t_data *data, const t_vertex *v1, const t_vertex *v2)
{
	t_line			line;
	const t_vertex	*v_max = get_max_alt(v1, v2);
	const t_vertex	*v_min = get_min_alt(v1, v2);

	cpy_vertex(&line.v1, v_max);
	cpy_vertex(&line.v2, v_min);
	line.dx = fabs(v_min->x - v_max->x);
	line.sx = get_sign(v_min->x - v_max->x);
	line.dy = -fabs(v_min->y - v_max->y);
	line.sy = get_sign(v_min->y - v_max->y);
	line.error = line.dx + line.dy;
	line.nb_points = sqrt(line.dx * line.dx + line.dy * line.dy);
	if (is_line_printable(&line) == true)
		plot_line(data, &line);
}