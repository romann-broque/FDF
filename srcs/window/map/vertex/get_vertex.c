/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vertex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:10:09 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/10 12:49:48 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_altitude(const char *format)
{
	return (ft_atoi(format));
}

static int	get_color(const char *format)
{
	(void)format;
	return (0);
}

static void	set_vertex(t_vertex *vertex,
				const int x, const int y, const int z, const int color)
{
	vertex->x = x;
	vertex->y = y;
	vertex->z = z;
	vertex->color = color;
}

void	get_vertex(t_vertex *vertex, const size_t x, const size_t y, const char *format)
{
	const int	new_x = (int)x;
	const int	new_y = (int)y;
	const int	new_z = get_altitude(format);
	const int	color = get_color(format);

	set_vertex(vertex, new_x, new_y, new_z, color);
}
