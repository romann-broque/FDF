/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 11:39:50 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/12 15:29:34 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(t_win *ptr)
{
	mlx_loop_end(ptr->mlx_ptr);
	return (EXIT_SUCCESS);
}

// ANGLE

static void	change_angle(t_win *ptr, double rotation)
{
	ptr->map.angle = (ptr->map.angle + rotation) * 1.02;
	printf("angle --> %lf\n", ptr->map.angle);
}

int	increase_angle(t_win *window)
{
	change_angle(window, 0.1);
	return (EXIT_SUCCESS);
}

int	decrease_angle(t_win *window)
{
	change_angle(window, -0.1);
	return (EXIT_SUCCESS);
}
