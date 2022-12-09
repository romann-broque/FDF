/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 21:52:12 by rbroque           #+#    #+#             */
/*   Updated: 2022/12/09 15:40:55 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	hook(t_win *window)
{
	mlx_key_hook(window->win_ptr, close_window1, window);
	mlx_hook(window->win_ptr, DestroyNotify, StructureNotifyMask, close_window2, window);
//	mlx_hook(window->win_ptr, MotionNotify, PointerMotionMask, detect_mouse_pos, window);
	mlx_hook(window->win_ptr, ButtonPress, ButtonPressMask, zoom, window);
}

void	loop(t_win *window)
{
	hook(window);
	mlx_loop(window->mlx_ptr);
}
