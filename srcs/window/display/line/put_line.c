/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:10:16 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/26 11:18:31 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	plot_line(t_data *data, t_line *line)
{
	size_t	i;

	i = 0;
	while (i <= line->nb_points)
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

void	put_line(t_data *data, const t_vertex *v1, const t_vertex *v2)
{
	t_line	line;

	init_line(&line, v1, v2);
	if (is_line_printable(&line) == true)
		plot_line(data, &line);
}
