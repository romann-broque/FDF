/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:46:19 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/28 01:51:48 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static bool	are_pixels_out(const double x1, const double y1,
					const double x2, const double y2)
{
	if (x1 >= 0 && x1 <= WIDTH && x2 >= 0 && x2 <= WIDTH)
		return ((y1 < 0 && y2 < 0) || (y1 > HEIGHT && y2 > HEIGHT));
	else if (y1 >= 0 && y1 <= HEIGHT && y2 >= 0 && y2 <= HEIGHT)
		return ((x1 < 0 && x2 < 0) || (x1 > WIDTH && x2 > WIDTH));
	return (((x1 < 0 && x2 < 0) || (x1 > WIDTH && x2 > WIDTH))
		&& ((y1 < 0 && y2 < 0) || (y1 > HEIGHT && y2 > HEIGHT)));
}

bool	is_line_printable(t_line *line)
{
	return (are_pixels_out(
			line->v1.x, line->v1.y,
			line->v2.x, line->v2.y) == false);
}

bool	are_crd_same(const double c1, const double c2)
{
	return ((int)c1 == (int)c2);
}

bool	are_pos_same(const t_vertex *v1, const t_vertex *v2)
{
	return ((are_crd_same(v1->x, v2->x) == true) && (are_crd_same(v1->y, v2->y) == true));
}
