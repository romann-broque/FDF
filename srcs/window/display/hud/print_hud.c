/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hud.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:03:30 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/27 23:35:40 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	print_controls_info(
	const t_win *window, char info[][100], t_imginfo *img)
{
	size_t	i;

	i = 0;
	while (i < 9)
	{
		img->y_offset += 20;
		print_string(window, info[i], img, LIGHT_BLUE);
		++i;
	}
}

void	print_info(const t_win *window, const t_imginfo *img)
{
	static char	info[][100] = {
		"MOVE       Arrows",
		"ZOOM       + -",
		"ROTATE     (Q E) (A D) (W S)",
		"AMPLITUDE  (O P) (U I)",
		"VIEW       1 / 2 / 3",
		"CENTER     C",
		"RESET      R",
		"HUD        H",
		"EXIT       ESC",
	};
	t_imginfo	tmp_img;

	cpy_imginfo(&tmp_img, img);
	tmp_img.x_offset += 15;
	print_controls_info(window, info, &tmp_img);
}

void	print_view(t_win *window, const t_imginfo *img, int color)
{
	static char	title[][20] = {
		"[1] ISOMETRIC ",
		"[2] TOP-DOWN  ",
		"[3] ELEVATION ",
		"   - FREE -   ",
	};
	const int	tmp_color = color;
	t_imginfo	tmp_img;
	size_t		i;

	cpy_imginfo(&tmp_img, img);
	i = 0;
	while (i < VIEW_COUNT)
	{
		if (window->map.view == i)
			color = GREEN;
		else
			color = tmp_color;
		display_interface(window, title[i], &tmp_img, color);
		tmp_img.x_offset += img->width;
		++i;
	}
}
