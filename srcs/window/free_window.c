/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:52:19 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/08 16:14:24 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_window(t_win *window)
{
	if (window != NULL)
	{
		free_data(&window->data, window->mlx_ptr);
		mlx_destroy_window(window->mlx_ptr, window->win_ptr);
		mlx_destroy_display(window->mlx_ptr);
		free(window->mlx_ptr);
	}
}
