/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_hud.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:06:18 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/28 00:35:04 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	display_hud(t_win *window)
{
	t_imginfo	ctrl;
	t_imginfo	view;

	ctrl.width = CTRL_WIDTH;
	ctrl.height = CTRL_HEIGHT;
	ctrl.x_offset = WIDTH - CTRL_WIDTH - WIDTH / 40;
	ctrl.y_offset = HEIGHT / 4;
	view.width = VIEW_WIDTH;
	view.height = VIEW_HEIGHT;
	view.x_offset = (WIDTH - VIEW_COUNT * VIEW_WIDTH) / 2;
	view.y_offset = HEIGHT / 40;
	if (window->hud_status == ON)
	{
		display_controls(window, CTRL_TITLE, &ctrl);
		print_view(window, &view, RED);
	}
}
