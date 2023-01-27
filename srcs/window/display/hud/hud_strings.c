/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_strings.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:02:16 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/27 17:20:03 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_string(const t_win *window, char *str, const t_imginfo *img, const int color)
{
	mlx_string_put(window->mlx_ptr, window->win_ptr, img->x_offset, img->y_offset, color, str);
	mlx_string_put(window->mlx_ptr, window->win_ptr, img->x_offset, img->y_offset + 1, color, str);
	mlx_string_put(window->mlx_ptr, window->win_ptr, img->x_offset + 1, img->y_offset, color, str);
	mlx_string_put(window->mlx_ptr, window->win_ptr, img->x_offset + 1, img->y_offset + 1, color, str);
}

void	print_center_text(t_win *window, char *text, const t_imginfo *img, const int color)
{
	const size_t	half_len = ft_strlen(text) / 2;
	t_imginfo		tmp_img;

	cpy_imginfo(&tmp_img, img);
	tmp_img.x_offset = img->x_offset + img->width / 2 - (half_len + (half_len % 2 == 0)) * 4;
	tmp_img.y_offset = img->y_offset + 15;
	print_string(window, text, &tmp_img, color);
}
