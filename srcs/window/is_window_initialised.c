/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_window_initialised.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:48:46 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/09 14:53:19 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

bool	is_window_initialised(t_win *window)
{
	return (window != NULL
		&& window->mlx_ptr != NULL
		&& window->win_ptr != NULL
		&& window->map.vertex != NULL);
}
