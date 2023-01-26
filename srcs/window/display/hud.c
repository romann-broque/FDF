/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 00:21:46 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/25 14:26:23 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	print_string(const t_win *window, char *str, const int x_offset, const int y_offset, const int color)
{
	mlx_string_put(window->mlx_ptr, window->win_ptr, x_offset, y_offset, color, str);
	mlx_string_put(window->mlx_ptr, window->win_ptr, x_offset, y_offset + 1, color, str);
	mlx_string_put(window->mlx_ptr, window->win_ptr, x_offset + 1, y_offset, color, str);
	mlx_string_put(window->mlx_ptr, window->win_ptr, x_offset + 1, y_offset + 1, color, str);
}

static void	display_info(const t_win *window, const int x_offset, const int y_offset)
{
	static char	info[][100] = {
		"MOVE       Arrows",
		"ZOOM       + -",
		"ROTATE     (Q E) (A D) (W S)",
		"AMPLITUDE  (O P) (U I)",
		"CENTER     C",
		"RESET      R",
		"HUD        H",
		"EXIT       ESC",
	};
	size_t		i;

	i = 0;
	while (i < 8)
	{
		print_string(window, info[i], x_offset, y_offset + (i + 1) * 20, LIGHT_BLUE);
		++i;
	}
}

static void	display_rectangle(t_win *window, const int width, const int height, const int x_offset, const int y_offset)
{
	t_vertex	v1;
	t_vertex	v2;
	t_vertex	v3;
	t_vertex	v4;

	set_vertex(&v1, x_offset, y_offset, 0, WHITE);
	set_vertex(&v2, x_offset + width, y_offset, 0, WHITE);
	set_vertex(&v3, x_offset + width, y_offset + height, 0, WHITE);
	set_vertex(&v4, x_offset, y_offset + height, 0, WHITE);
	put_line(&window->data, &v1, &v2);
	put_line(&window->data, &v2, &v3);
	put_line(&window->data, &v3, &v4);
	put_line(&window->data, &v4, &v1);
}

static void	display_interface(t_win *window, const int width, const int height, const int x_offset, const int y_offset)
{
	display_rectangle(window, width, height, x_offset, y_offset);
	print_string(window, "CONTROLS", x_offset + width / 2 - 5 * 4, y_offset + 20, WHITE);
}

void	display_hud(t_win *window)
{
	if (window->hud_status == ON)
	{
		display_info(window, WIDTH - WIDTH / 8, HEIGHT / 10);
		display_interface(window, 200, 200, WIDTH - WIDTH / 8 - 20, HEIGHT / 13);
	}
}
