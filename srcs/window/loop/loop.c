/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:01:02 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/16 17:57:45 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	detect_mouse_pos(int x, int y, t_win *window)
{
	window->map.cursor_x = x;
	window->map.cursor_y = y;
	printf("x --> %d\n", x);
	printf("y --> %d\n", y);
	printf("ptr --> %p\n", window);
	return (EXIT_SUCCESS);
}

static void	hook(t_win *window)
{
	mlx_hook(window->win_ptr, DestroyNotify, StructureNotifyMask, close_window, window);
	mlx_hook(window->win_ptr, MotionNotify, PointerMotionMask, detect_mouse_pos, window);
	mlx_hook(window->win_ptr, KeyPress, KeyPressMask, key_press, window);
	// mlx_hook(window->win_ptr, ButtonPress, ButtonPressMask, mouse_press, window);
}

void	loop(t_win *window)
{
	hook(window);
	mlx_loop(window->mlx_ptr);
}
