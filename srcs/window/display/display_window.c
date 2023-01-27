/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:55:08 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/27 14:38:21 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	display_window(t_win *window)
{
	transform_map(&window->map);
	display_map(window);
	display_hud(window);
	if (window->map.vertex != NULL)
		loop(window);
}
