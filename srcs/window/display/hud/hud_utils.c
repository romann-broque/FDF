/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 00:21:46 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/27 17:29:49 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	cpy_imginfo(t_imginfo *dest, const t_imginfo *src)
{
	dest->width = src->width;
	dest->height = src->height;
	dest->x_offset = src->x_offset;
	dest->y_offset = src->y_offset;
}

static void	display_rectangle(t_win *window, const t_imginfo *img)
{
	t_vertex	v1;
	t_vertex	v2;
	t_vertex	v3;
	t_vertex	v4;

	set_vertex(&v1, img->x_offset, img->y_offset, 0);
	set_vertex(&v2, img->x_offset + img->width, img->y_offset, 0);
	set_vertex(&v3, img->x_offset + img->width, img->y_offset + img->height, 0);
	set_vertex(&v4, img->x_offset, img->y_offset + img->height, 0);
	put_line(&window->data, &v1, &v2);
	put_line(&window->data, &v2, &v3);
	put_line(&window->data, &v3, &v4);
	put_line(&window->data, &v4, &v1);
}

void	display_controls(t_win *window, char *text, const t_imginfo *img)
{
	t_imginfo	rectangle;

	cpy_imginfo(&rectangle, img);
	rectangle.height = 30;
	display_rectangle(window, &rectangle);
	print_center_text(window, text, img, WHITE);
	rectangle.height = img->height - 30;
	rectangle.y_offset += 30;
	display_rectangle(window, &rectangle);
	print_info(window, &rectangle);
}

void	display_interface(
	t_win *window, char *text, const t_imginfo *img, const int color)
{
	display_rectangle(window, img);
	print_center_text(window, text, img, color);
}
