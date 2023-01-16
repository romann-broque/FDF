/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 11:52:06 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/16 17:51:16 by rbroque          ###   ########.fr       */
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
	{.key = R_KEY, .event = increase_zoom},
	{.key = F_KEY, .event = decrease_zoom},
	{.key = A_KEY, .event = increase_x_angle},
	{.key = S_KEY, .event = decrease_x_angle},
	{.key = Q_KEY, .event = increase_y_angle},
	{.key = W_KEY, .event = decrease_y_angle},
	{.key = Z_KEY, .event = increase_z_angle},
	{.key = X_KEY, .event = decrease_z_angle},
	{.key = P_KEY, .event = increase_altitude},
	{.key = O_KEY, .event = decrease_altitude},
	{.key = U_KEY, .event = increase_altitude_boost},
	{.key = I_KEY, .event = decrease_altitude_boost},
	{.key = NO_KEY, .event = NULL},
	};

	return (browse_mapping(mapping, key, window));
}
