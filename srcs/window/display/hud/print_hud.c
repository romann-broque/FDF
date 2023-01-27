/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hud.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:03:30 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/27 15:10:54 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_info(const t_win *window, const int x_offset, const int y_offset)
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

void    print_view(t_win *window, const int width, const int height, const int x_offset, const int y_offset, int color)
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
		display_interface(window, title[i], width, height, x_offset + (i * width), y_offset, color);
		++i;
	}
}
