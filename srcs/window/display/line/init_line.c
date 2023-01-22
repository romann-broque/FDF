/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:54:53 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/22 17:55:26 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	cpy_vertex(t_vertex *vdest, const t_vertex *vsrc)
{
	set_vertex(vdest, vsrc->x, vsrc->y, vsrc->z, 0);
	vdest->color.red = vsrc->color.red;
	vdest->color.green = vsrc->color.green;
	vdest->color.blue = vsrc->color.blue;
	vdest->color.sum = vsrc->color.sum;
}

static const t_vertex	*get_max_alt(const t_vertex *v1, const t_vertex *v2)
{
	if (v1->z > v2->z)
		return (v1);
	return (v2);
}

static const t_vertex	*get_min_alt(const t_vertex *v1, const t_vertex *v2)
{
	if (v1->z > v2->z)
		return (v2);
	return (v1);
}

void	init_line(t_line *line, const t_vertex *v1, const t_vertex *v2)
{
	const t_vertex	*v_max = get_max_alt(v1, v2);
	const t_vertex	*v_min = get_min_alt(v1, v2);

	cpy_vertex(&(line->v1), v_max);
	cpy_vertex(&(line->v2), v_min);
	line->dx = fabs(v_min->x - v_max->x);
	line->sx = get_sign(v_min->x - v_max->x);
	line->dy = -fabs(v_min->y - v_max->y);
	line->sy = get_sign(v_min->y - v_max->y);
	line->error = line->dx + line->dy;
	line->nb_points = sqrt(line->dx * line->dx + line->dy * line->dy);
}
