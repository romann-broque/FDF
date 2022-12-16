/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 21:48:43 by rbroque           #+#    #+#             */
/*   Updated: 2022/12/16 14:55:23 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window1(int key, t_win *ptr)
{
	if (key == ESCAPE_KEY)
		mlx_loop_end(ptr->mlx_ptr);
	return (0);
}

int	close_window2(t_win *ptr)
{
	mlx_loop_end(ptr->mlx_ptr);
	return (0);
}

/*
int	detect_mouse_pos(int x, int y, t_win *window)
{
	t_pos	center;
	t_pos	pos;

	set_pos(&center, HEIGHT / 2, WIDTH / 2, 0);
	set_pos(&pos, x, y, 0);
	refresh(window);
	print_line(&center, &pos, window->data, BLUE);
	printf("x=%d; y=%d\n", x, y);
	return (0);
}
*/

int	zoom(int key, int x, int y, t_win *window)
{
	t_transform	*const transform = window->transform;

	(void)x;
	(void)y;
	if (key == 4 && transform->zoom < MAX_ZOOM_OFFSET)
		++transform->zoom;
	if (key == 5 && window->transform->zoom > -window->transform->y_rot + MIN_ZOOM_OFFSET)
		--transform->zoom;
	refresh(window);
	return (0);
}

int	button_press(int key, int x, int y, t_win *window)
{
	if (key == 4 || key == 5)
		zoom(key, x, y, window);
	return (0);
}
