/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vertex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:10:09 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/18 12:02:58 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_altitude(const char *format)
{
	return (ft_atoi(format));
}

static bool	is_prefix_valid(const char *format)
{
	return (ft_strncmp(format, COLOR_PREFIX, ft_strlen(COLOR_PREFIX)) == 0);
}

static int	get_color(const int alt, const char *format)
{
	int	color;

	format += abs_index(format, SEPARATOR);
	if (is_prefix_valid(format) == true)
		color = ft_atoi_base(format + 2, HEX_BASE);
	else
		color = WHITE - alt * 20;
	return (color);
}

void	set_vertex(t_vertex *vertex,
				const float x, const float y, const float z, const int color)
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
	const int	color = get_color(new_z, format);

	set_vertex(vertex, new_x, new_y, new_z, color);
}
