/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 21:48:43 by rbroque           #+#    #+#             */
/*   Updated: 2022/12/09 15:40:13 by rbroque          ###   ########.fr       */
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

int	detect_mouse_pos(int x, int y, t_win *window)
{
	t_pos	center;
	t_pos	pos;

	set_pos(&center, HEIGHT / 2, WIDTH / 2, 0);
	set_pos(&pos, x, y, 0);
//	mlx_clear_window(window->mlx_ptr, window->win_ptr);
//	mlx_destroy_image(window->mlx_ptr, window->data->img);
//	window->data=init_data(window->mlx_ptr);

	print_line(&center, &pos, window->data, BLUE);
	mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, window->data->img, 0, 0);
	printf("x=%d; y=%d\n", x, y);
	return (0);
}

int	zoom(int x, int y, int key, t_win *window)
{
	printf("x --> %d\n", x);
	printf("y --> %d\n", y);
	printf("key --> %d\n", key);
	printf("window --> %p\n", window);
	return (0);
}
