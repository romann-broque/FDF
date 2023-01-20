/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:01:02 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/20 16:42:47 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	hook(t_win *window)
{
	mlx_hook(window->win_ptr, DestroyNotify, StructureNotifyMask, close_window, window);
	mlx_hook(window->win_ptr, KeyPress, KeyPressMask, key_press, window);
	// mlx_hook(window->win_ptr, ButtonPress, ButtonPressMask, mouse_press, window);
}

void	loop(t_win *window)
{
	hook(window);
	mlx_loop(window->mlx_ptr);
}
