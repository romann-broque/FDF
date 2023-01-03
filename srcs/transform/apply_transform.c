/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_transform.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:43:57 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/03 17:47:23 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		get_x_shift(t_pos *curr_pos, t_pos *last_pos)
{
	(void)last_pos;
	return (curr_pos->x);
}

static long		get_y_shift(t_pos *curr_pos, t_pos *last_pos, t_transform *transform)
{
	const int	y_rot = get_rot(transform);
	long		shift;
	
	shift = get_altitude(last_pos->z, curr_pos->z, transform);
	if (y_rot != 0)
		shift /= y_rot;
	if ((transform->y_rot / transform->zoom) % 2 == 0)
		return (last_pos->y - shift);
	return (last_pos->y + shift);
}

void	apply_persp(t_pos *curr_pos, t_pos *last_pos, t_transform *transform)
{
	curr_pos->x = get_x_shift(curr_pos, last_pos);
	curr_pos->y = get_y_shift(curr_pos, last_pos, transform);
}

static void	get_trans_pos(t_pos *dest, t_pos *src, t_transform *transform, size_t x)
{
	const int	y_rot = get_rot(transform);

	if (transform->center != NULL)
	{
		dest->x = src->x + transform->zoom * x + transform->x_offset;
		dest->y = src->y * y_rot + transform->y_offset;
		dest->z = src->z;
	}
}

void	apply_transform(t_pos *pos, size_t x, t_transform *transform)
{
	t_pos	new;

	get_trans_pos(&new, pos, transform, x);
	cpy_pos(pos, &new);
}