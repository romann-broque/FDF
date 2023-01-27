/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_strings.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:02:16 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/27 15:12:40 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_string(const t_win *window, char *str, const int x_offset, const int y_offset, const int color)
{
	mlx_string_put(window->mlx_ptr, window->win_ptr, x_offset, y_offset, color, str);
	mlx_string_put(window->mlx_ptr, window->win_ptr, x_offset, y_offset + 1, color, str);
	mlx_string_put(window->mlx_ptr, window->win_ptr, x_offset + 1, y_offset, color, str);
	mlx_string_put(window->mlx_ptr, window->win_ptr, x_offset + 1, y_offset + 1, color, str);
}

void    print_center_text(t_win *window, char *text, const int width, const int x_offset, const int y_offset, const int color)
{
	const size_t	half_len = ft_strlen(text) / 2;

	print_string(window, text, x_offset + width / 2 - (half_len + !(half_len % 2)) * 4, y_offset + 15, color);
}
