/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 21:10:04 by rbroque           #+#    #+#             */
/*   Updated: 2022/12/10 16:50:07 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_win	*init_window(const int height, const int width, char *title, t_pos ***orig_matrix)
{
	t_win	*new;

	new = (t_win *)malloc(sizeof(t_win));	
	if (new != NULL)
	{
		new->mlx_ptr = mlx_init();
		new->win_ptr = mlx_new_window(new->mlx_ptr, height, width, title);
		new->data = init_data(new->mlx_ptr);
		new->zoom = ZOOM;
		new->orig_matrix = orig_matrix;
		new->refr_matrix = orig_matrix;
	}
	return (new);
}

void	destroy_window(t_win *window)
{
	mlx_destroy_window(window->mlx_ptr, window->win_ptr);
	mlx_destroy_image(window->mlx_ptr, window->data->img);
	mlx_destroy_display(window->mlx_ptr);
	free(window->mlx_ptr);
	free(window->data);
	free_pos_matrix(window->orig_matrix);
	free(window);
}
