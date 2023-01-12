/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 11:39:50 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/12 14:21:22 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(t_win *ptr)
{
	mlx_loop_end(ptr->mlx_ptr);
	return (EXIT_SUCCESS);
}

int	angle(t_win *ptr)
{
	printf("angle --> %f\n", ptr->map.angle);
	ptr->map.angle += 0.1;
	return (EXIT_SUCCESS);
}
