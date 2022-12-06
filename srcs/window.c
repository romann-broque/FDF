/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 21:48:43 by rbroque           #+#    #+#             */
/*   Updated: 2022/12/06 19:36:02 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_data	*init_data(void *mlx_ptr)
{
	t_data	*img;

	img = (t_data *)malloc(sizeof(t_data));
	if (img != NULL)
	{
		img->img = mlx_new_image(mlx_ptr, HEIGHT, WIDTH);
		img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	}
	return (img);
}

t_win	*init_window(const int height, const int width, char *title)
{
	t_win	*new;

	new = (t_win *)malloc(sizeof(t_win));	
	if (new != NULL)
	{
		new->mlx_ptr = mlx_init();
		new->win_ptr = mlx_new_window(new->mlx_ptr, height, width, title);
		new->data = init_data(new->mlx_ptr);
	}
	return (new);
}

void	destroy_window(t_win *window)
{
	mlx_destroy_window(window->mlx_ptr, window->win_ptr);
	mlx_destroy_display(window->mlx_ptr);
	free(window->mlx_ptr);
	free(window->data);
	free(window);
}

// events

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

	set_pos(&center, HEIGHT / 2, WIDTH / 2);
	set_pos(&pos, x, y);
	//mlx_clear_window(window->mlx_ptr, window->win_ptr);
	print_line(&center, &pos, window->data, BLUE);
	mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, window->data->img, 0, 0);
	printf("x: %d\n", x);
	printf("y: %d\n", y);
	return (0);
}

