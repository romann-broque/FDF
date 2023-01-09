/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:52:19 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/09 16:02:02 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_window(t_win *window)
{
	if (window != NULL)
	{
		free_data(&window->data, window->mlx_ptr);
		free_map(&window->map);
		if (window->mlx_ptr != NULL)
		{
			if (window->win_ptr != NULL)
				mlx_destroy_window(window->mlx_ptr, window->win_ptr);
			mlx_destroy_display(window->mlx_ptr);
		}
		free(window->mlx_ptr);
	}
}
