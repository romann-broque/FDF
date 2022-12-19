/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:19:34 by rbroque           #+#    #+#             */
/*   Updated: 2022/12/19 15:19:49 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_rot(int *y_rot)
{
	const int	quarter = 20;
	int			rot;

	if (*y_rot == 4 * quarter)
		*y_rot = 0;
	rot = *y_rot;
	if (rot > quarter && rot < 2 * quarter)
		rot = (2 * quarter) - rot;
	else if (rot >= 2 * quarter && rot < 3 * quarter)
		rot = -rot % (2 * quarter);
	else if (rot >= 3 * quarter)
		rot = (-4 * quarter) + rot;
	return (rot);
}
