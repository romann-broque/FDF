/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:10:16 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/17 16:19:09 by rbroque          ###   ########.fr       */
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

static void	put_vertex(t_data *data, t_vertex *vertex)
{
	int	color;

	color = vertex->color;
	if (vertex->color == UNDEFINED_COLOR)
		color = fabs(vertex->z) * 100 + WHITE;
	put_pixel(data, vertex->x, vertex->y, color);
}

static void	plot_line(t_data *data, t_line *line)
{
	size_t	i;

	i = 0;
	while (i < UINT_MAX)
	{
		put_vertex(data, &line->v1);
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

static bool are_pixels_out(const double x1, const double y1, const double x2, const double y2)
{
	if (x1 >= 0 && x1 <= WIDTH && x2 >= 0 && x2 <= WIDTH)
		return ((y1 < 0 && y2 < 0) || (y1 > HEIGHT && y2 > HEIGHT));
	else if (y1 >= 0 && y1 <= HEIGHT && y2 >= 0 && y2 <= HEIGHT)
		return ((x1 < 0 && x2 < 0) || (x1 > WIDTH && x2 > WIDTH));
	return (((x1 < 0 && x2 < 0) || (x1 > WIDTH && x2 > WIDTH))
		&& ((y1 < 0 && y2 < 0) || (y1 > HEIGHT && y2 > HEIGHT)));
}

static bool	is_line_printable(t_line *line)
{
	return (are_pixels_out(line->v1.x, line->v1.y, line->v2.x, line->v2.y) == false);
}

//

void	cpy_vertex(t_vertex *vdest, const t_vertex *vsrc)
{
	set_vertex(vdest, vsrc->x, vsrc->y, vsrc->z, vsrc->color);
}

//

void	put_line(t_data *data, const t_vertex *v1, const t_vertex *v2)
{
	t_line	line;

	cpy_vertex(&line.v1, v1);
	cpy_vertex(&line.v2, v2);
	line.dx = fabs(v2->x - v1->x);
	line.sx = get_sign(v2->x - v1->x);
	line.dy = -fabs(v2->y - v1->y);
	line.sy = get_sign(v2->y - v1->y);
	line.error = line.dx + line.dy;
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
