/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 21:48:43 by rbroque           #+#    #+#             */
/*   Updated: 2022/12/22 18:14:44 by rbroque          ###   ########.fr       */
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

int	zoom(int key, int x, int y, t_win *window)
{
	t_transform *const	transform = window->transform;

	(void)x;
	(void)y;
	if (key == SCROLL1_KEY && transform->zoom < MAX_ZOOM_OFFSET) // should_zoom
		++transform->zoom;
	else if (key == SCROLL2_KEY && window->transform->zoom > MIN_ZOOM_OFFSET) // should_unzoom
		--transform->zoom;
	return (0);
}

int	rotate(int key, t_win *window)
{
	printf("y_rot --> %d\n", window->transform->y_rot % (2 * window->transform->zoom));
	if (key == R_KEY)
		++window->transform->y_rot;
	else
		--window->transform->y_rot;
	return (0);
}

int	contrast(int key, t_win *window)
{
	if (key == C_KEY)
		window->data->contrast += CONTRAST_SHIFT;
	else
		window->data->contrast += CONTRAST_SHIFT;
	return (0);
}

int	altitude(int key, t_win *window)
{
	if (key == Z_KEY)
		++window->transform->altitude;
	else if (window->transform->altitude > 1)
		--window->transform->altitude;
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


// t_key do_action(t_action_string action_id) {
// 	static const t_action_key action_keys[] = {
// 		{ .action_id = CLOSE, .key = ESCAPE_KEY }
// 	};
// 	return action_keys[action_id].key
	
// }



// bool should_close(...)
// {
// 	return get_action_key(CLOSE) && windows.state == UP;
// }