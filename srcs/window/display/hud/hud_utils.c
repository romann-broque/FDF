/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 00:21:46 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/27 15:11:15 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	display_controls(t_win *window, char *text, const int width, const int height, const int x_offset, const int y_offset)
{
	display_rectangle(window, width, 30, x_offset, y_offset);
	print_center_text(window, text, width, x_offset, y_offset, WHITE);
	display_rectangle(window, width, height - 30, x_offset, y_offset + 30);
	print_info(window, x_offset + 15, 35 + y_offset);
}

void	display_interface(t_win *window, char *text, const int width, const int height, const int x_offset, const int y_offset, const int color)
{
	display_rectangle(window, width, height, x_offset, y_offset);
	print_center_text(window, text, width, x_offset, y_offset, color);
}
