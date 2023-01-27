/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_xangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:37:50 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/27 17:37:58 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	increase_x_angle(t_win *window)
{
	change_angle(window, E_XANGLE, ANGLE_SHIFT);
	return (EXIT_SUCCESS);
}

int	decrease_x_angle(t_win *window)
{
	change_angle(window, E_XANGLE, -ANGLE_SHIFT);
	return (EXIT_SUCCESS);
}
