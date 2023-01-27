/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_yangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:38:15 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/27 17:38:21 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	increase_y_angle(t_win *window)
{
	change_angle(window, E_YANGLE, ANGLE_SHIFT);
	return (EXIT_SUCCESS);
}

int	decrease_y_angle(t_win *window)
{
	change_angle(window, E_YANGLE, -ANGLE_SHIFT);
	return (EXIT_SUCCESS);
}
