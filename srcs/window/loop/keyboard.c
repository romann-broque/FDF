/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 11:52:06 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/12 13:10:07 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

	// cpy_matrix(window->refr_matrix, window->orig_matrix);
	// set_offset(window->refr_matrix, window->transform);
	// window->transform->center = get_center(window->transform);
	// mlx_destroy_image(window->mlx_ptr, window->data->img);
	// window->data = init_data(window->mlx_ptr, window->data->contrast);
	// free(tmp); // assign instead of realloc
	// print_map(window->refr_matrix, window, WHITE);
	// mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, window->data->img, 0, 0);

static void	refresh(t_win *window)
{
	mlx_destroy_image(window->mlx_ptr, window->data.img);
	init_data(window->mlx_ptr, &window->data);
	transform_map(&window->map);
	display_window(window);
	mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, window->data.img, 0, 0);
}

static int	browse_mapping(
								t_event_mapping *mapping,
								const int key,
								t_win *window
							)
{
	int		ret_val;
	size_t	i;

	ret_val = EXIT_SUCCESS;
	i = 0;
	while (mapping[i].event != NULL)
	{
		if (key == mapping[i].key)
			ret_val = mapping[i].event(window);
		++i;
	}
	refresh(window);
	return (ret_val);
}

int	key_press(const int key, t_win *window)
{
	static t_event_mapping	mapping[] = {
	{.key = ESCAPE_KEY, .event = close_window},
	{.key = R_KEY, .event = angle},
	{.key = NO_KEY, .event = NULL},
	};

	return (browse_mapping(mapping, key, window));
}
