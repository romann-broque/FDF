/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:13:06 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/08 15:18:45 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_data	*init_data(void *mlx_ptr)
{
	t_data	*img;

	img = (t_data *)malloc(sizeof(t_data));
	if (img != NULL)
	{
		img->img = mlx_new_image(mlx_ptr, WIDTH, HEIGHT);
		img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	}
	return (img);
}
