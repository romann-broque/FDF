/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 00:21:46 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/26 15:29:49 by rbroque          ###   ########.fr       */
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
		"VIEW       1 / 2",
		"CENTER     C",
		"RESET      R",
		"HUD        H",
		"EXIT       ESC",
	};
	size_t		i;

	i = 0;
	while (i < 9)
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

static void print_center_text(t_win *window, char *text, const int width, const int x_offset, const int y_offset, const int color)
{
	const size_t	half_len = ft_strlen(text) / 2;

	print_string(window, text, x_offset + width / 2 - half_len * 4, y_offset + 15, color);
}

static void	display_controls(t_win *window, char *text, const int width, const int height, const int x_offset, const int y_offset)
{
	display_rectangle(window, width, 30, x_offset, y_offset);
	print_center_text(window, text, width, x_offset, y_offset, WHITE);
	display_rectangle(window, width, height - 30, x_offset, y_offset + 30);
	display_info(window, x_offset + 20, 35 + y_offset);
}

static void	display_interface(t_win *window, char *text, const int width, const int height, const int x_offset, const int y_offset, const int color)
{
	display_rectangle(window, width, height, x_offset, y_offset);
	print_center_text(window, text, width, x_offset, y_offset, color);
}

static void	print_view(t_win *window, const int width, const int height, const int x_offset, const int y_offset, int color)
{
	static char	title[][20] = {
		"[1] ISO     ",
		"[2] TOP-DOWN",
		"  - FREE -  ",
	};
	const int	tmp_color = color;
	size_t		i;

	i = 0;
	while (i < 3)
	{
		if (window->map.view == i)
			color = GREEN;
		else
			color = tmp_color;
		display_interface(window, title[i], width, height, x_offset, y_offset + (i * height) + height / 3, color);
		++i;
	}
}

void	display_hud(t_win *window)
{
	if (window->hud_status == ON)
	{
		display_controls(window, "CONTROLS", 200, 230, WIDTH - WIDTH / 8 - 20, HEIGHT / 13);
		print_view(window, 200, 25, WIDTH - WIDTH / 8 - 20, 250 + HEIGHT / 13, RED);
	}
}
