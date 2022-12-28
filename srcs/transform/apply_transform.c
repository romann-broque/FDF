/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_transform.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:43:57 by rbroque           #+#    #+#             */
/*   Updated: 2022/12/22 20:05:22 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		get_x_shift(t_pos *curr_pos, t_pos *last_pos)
{
	(void)last_pos;
	return (curr_pos->x);
}

static int		get_y_shift(t_pos *curr_pos, t_pos *last_pos, t_transform *transform)
{
	const int	y_rot = get_rot(transform);
	const int	shift = get_altitude(last_pos->z, curr_pos->z, transform) / y_rot;

	if (transform->y_rot / transform->zoom % 2 == 0)
		return (last_pos->y - shift);
	return (last_pos->y + shift);
}

void	apply_persp(t_pos *curr_pos, t_pos *last_pos, t_transform *transform)
{
	curr_pos->x = get_x_shift(curr_pos, last_pos);
	curr_pos->y = get_y_shift(curr_pos, last_pos, transform);
}

void	apply_transform(t_pos *pos, size_t x, t_transform *transform)
{
	const int	y_rot = get_rot(transform);
	const int	new_x = pos->x + (transform->zoom * x);
	const int	new_y = pos->y * y_rot;
	const int	new_z = pos->z;

	set_pos(pos, new_x + transform->x_offset,
	new_y + transform->y_offset,
	new_z);
}
