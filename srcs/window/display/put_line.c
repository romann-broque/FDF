/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:10:16 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/20 10:39:03 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int get_sign(const double nb)
{
	if (nb < 0)
		return (-1);
	return (1);
}

static bool are_same_crd(const double c1, const double c2)
{
	return ((int)c1 == (int)c2);
}

static void put_vertex(t_data *data, t_vertex *vertex, double color_shift, uint color_offset)
{
	ulong color;

	color = vertex->color;
	// if (vertex->z > 0)
	//  	color += fabs(color_shift + GREEN);
	// else
	//  	color += fabs(color_shift + BLUE);
//	if (color <= WHITE - color_offset)
		color += color_offset;
	// else
	// 	color += color_offset;
	//color *= 10;
	//printf("color --> %lu\n", color);
	(void)color_shift;
	put_pixel(data, vertex->x, vertex->y, color);
}

static void plot_line(t_data *data, t_line *line)
{
	size_t i;

	i = 0;
	while (i < 1000)
	{
		put_vertex(data, &line->v1, line->color_shift * i, line->color_offset);
		if (are_same_crd(line->v1.x, line->v2.x) && are_same_crd(line->v1.y, line->v2.y))
			break;
		line->e2 = 2 * line->error;
		if (line->e2 >= line->dy)
		{
			if (are_same_crd(line->v1.x, line->v2.x))
				break;
			line->error += line->dy;
			line->v1.x += line->sx;
		}
		if (line->e2 <= line->dx)
		{
			if (are_same_crd(line->v1.y, line->v2.y))
				break;
			line->error += line->dx;
			line->v1.y += line->sy;
		}
		++i;
	}
}

static bool are_pixels_out(const double x1, const double y1, const double x2, const double y2)
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

//

void cpy_vertex(t_vertex *vdest, const t_vertex *vsrc)
{
	set_vertex(vdest, vsrc->x, vsrc->y, vsrc->z, vsrc->color);
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

double get_color_shift(const double dcolor, const double distance)
{
	if (distance == 0)
		return (0);
	return (dcolor / distance);
}
//

void put_line(t_data *data, const t_vertex *v1, const t_vertex *v2, const uint color_offset)
{
	t_line line;
	const t_vertex *v_max = get_max_alt(v1, v2);
	const t_vertex *v_min = get_min_alt(v1, v2);

	cpy_vertex(&line.v1, v_max);
	cpy_vertex(&line.v2, v_min);
	line.dx = fabs(v_min->x - v_max->x);
	line.sx = get_sign(v_min->x - v_max->x);
	line.dy = -fabs(v_min->y - v_max->y);
	line.sy = get_sign(v_min->y - v_max->y);
	line.error = line.dx + line.dy;
	line.color_shift = get_color_shift(v_max->color - v_min->color, sqrt(line.dx * line.dx + line.dy * line.dy));
	line.color_offset = color_offset;
	if (is_line_printable(&line) == true)
		plot_line(data, &line);
}

/*

// TESTS

static void	display_oct(t_data *data, int x, int y)
{
	t_vertex	v_center;
	t_vertex	v_target;

	set_vertex(&v_center, WIDTH / 2, HEIGHT / 2, 0, WHITE);
	set_vertex(&v_target, x, y, 0, WHITE);
	put_line(data, v_center, v_target);
}

void	display_line_test(t_win *window)
{
	size_t	i;

	i = 0;
	while (i <= 50)
	{
		display_oct(&window->data, WIDTH / 2 + i, HEIGHT / 2 + 50);
		display_oct(&window->data, WIDTH / 2 + i, HEIGHT / 2 - 50);
		display_oct(&window->data, WIDTH / 2 - i, HEIGHT / 2 + 50);
		display_oct(&window->data, WIDTH / 2 - i, HEIGHT / 2 - 50);
		display_oct(&window->data, WIDTH / 2 - 50, HEIGHT / 2 - i);
		display_oct(&window->data, WIDTH / 2 - 50, HEIGHT / 2 + i);
		display_oct(&window->data, WIDTH / 2 + 50, HEIGHT / 2 - i);
		display_oct(&window->data, WIDTH / 2 + 50, HEIGHT / 2 + i);
		++i;
	}
	put_pixel(&window->data, WIDTH / 2, HEIGHT / 2, RED);
	mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, window->data.img, 0, 0);
}
*/
