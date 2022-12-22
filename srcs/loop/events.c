/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 21:48:43 by rbroque           #+#    #+#             */
/*   Updated: 2022/12/22 20:00:10 by rbroque          ###   ########.fr       */
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

int	contrast(int key, t_win *window)
{
	if (key == C_KEY)
		window->data->contrast += CONTRAST_SHIFT;
	else
		window->data->contrast += CONTRAST_SHIFT;
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