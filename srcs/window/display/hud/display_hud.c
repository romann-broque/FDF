/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_hud.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:06:18 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/27 15:06:26 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	display_hud(t_win *window)
{
	if (window->hud_status == ON)
	{
		display_controls(window, "CONTROLS", CTRL_WIDTH, CTRL_HEIGHT, WIDTH - CTRL_WIDTH - WIDTH / 40, HEIGHT / 4);
		print_view(window, VIEW_WIDTH, VIEW_HEIGHT, (WIDTH - 3 * VIEW_WIDTH) / 2, HEIGHT / 40, RED);
	}
}