/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 11:52:06 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/08 14:28:46 by rbroque          ###   ########.fr       */
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
	return (ret_val);
}

int	key_press(const int key, t_win *window)
{
	static t_event_mapping	mapping[] = {
	{.key = ESCAPE_KEY, .event = close_window},
	{.key = NO_KEY, .event = NULL},
	};

	return (browse_mapping(mapping, key, window));
}
