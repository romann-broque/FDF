/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:44:39 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/27 23:55:21 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_point(t_data *data, const t_line *line)
{
	const float	interpol_factor = get_interpol_factor(
			&(line->v1),
			&(line->v2), line->nb_points);
	const int	color = get_point_color(
			&(line->v1),
			&(line->v2),
			interpol_factor);

	put_pixel(data, line->v1.x, line->v1.y, color);
}
