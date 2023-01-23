/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 11:52:06 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/23 10:18:54 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	browse_mapping(
								t_event_mapping *mapping,
								const int key,
								t_win *window
							)
{
	int		ret_val;
	size_t	i;

	ret_val = EXIT_SUCCESS;
	i = 0;
	while (mapping[i].event != NULL)
	{
		if (key == mapping[i].key)
			ret_val = mapping[i].event(window);
		++i;
	}
	refresh(window);
	return (ret_val);
}

int	key_press(const int key, t_win *window)
{
	static t_event_mapping	mapping[] = {
	{.key = ESCAPE_KEY, .event = close_window},
	{.key = K_ZOOM, .event = increase_zoom},
	{.key = K_UNZOOM, .event = decrease_zoom},
	{.key = K_XROT1, .event = increase_x_angle},
	{.key = K_XROT2, .event = decrease_x_angle},
	{.key = K_YROT1, .event = increase_y_angle},
	{.key = K_YROT2, .event = decrease_y_angle},
	{.key = K_ZROT1, .event = increase_z_angle},
	{.key = K_ZROT2, .event = decrease_z_angle},
	{.key = K_ALT1, .event = increase_altitude},
	{.key = K_ALT2, .event = decrease_altitude},
	{.key = K_ALT3, .event = increase_altitude_boost},
	{.key = K_ALT4, .event = decrease_altitude_boost},
	{.key = NO_KEY, .event = NULL},
	};

	return (browse_mapping(mapping, key, window));
}
