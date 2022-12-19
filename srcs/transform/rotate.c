/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:19:34 by rbroque           #+#    #+#             */
/*   Updated: 2022/12/20 00:04:49 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_neg_rot(t_transform *transform)
{
	const int	quarter = -2 * transform->zoom;
	int			rot;

	if (transform->y_rot == 4 * quarter)
		transform->y_rot = 0;
	rot = transform->y_rot;
	if (rot < quarter && rot > 2 * quarter)
		rot = (2 * quarter) - rot;
	else if (rot <= 2 * quarter && rot > 3 * quarter)
		rot = rot % (2 * quarter);
	else if (rot <= 3 * quarter)
		rot = (4 * quarter) - rot;
	return (rot + transform->zoom);
}

int	get_rot(t_transform *transform)
{
	if (transform->y_rot >= 0)
		transform->y_rot = 4 * -2 * transform->zoom + 1;
	return (get_neg_rot(transform));
}
