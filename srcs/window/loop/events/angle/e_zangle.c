/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_zangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:38:35 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/27 17:38:41 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	increase_z_angle(t_win *window)
{
	change_angle(window, E_ZANGLE, ANGLE_SHIFT);
	return (EXIT_SUCCESS);
}

int	decrease_z_angle(t_win *window)
{
	change_angle(window, E_ZANGLE, -ANGLE_SHIFT);
	return (EXIT_SUCCESS);
}
