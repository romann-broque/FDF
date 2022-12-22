/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_transform.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:43:57 by rbroque           #+#    #+#             */
/*   Updated: 2022/12/22 15:03:31 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		get_x_shift(t_pos *pos)
{
	return (pos->x);
}

static int		get_y_shift(t_pos *curr_pos, t_pos *last_pos, t_transform *transform)
{
	return (last_pos->y + get_altitude(last_pos->z, curr_pos->z, transform) / get_rot(transform));
}

void	apply_persp(t_pos *curr_pos, t_pos *last_pos, t_transform *transform)
{
	curr_pos->x = get_x_shift(last_pos);
	curr_pos->y = get_y_shift(curr_pos, last_pos, transform);
}

void	apply_transform(t_pos *pos, size_t x, t_transform *transform)
{
	const int	y_rot = get_rot(transform);
	const int	new_x = pos->x + (transform->zoom * x);
	int	new_y = pos->y * (y_rot * get_sign(y_rot - transform->zoom));
	const int	new_z = pos->z;

	if (y_rot == transform->zoom)
		new_y *= -1;
	set_pos(pos, new_x + transform->x_offset,
	new_y + transform->y_offset,
	new_z);
}
