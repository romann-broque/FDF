/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:13:06 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/08 16:12:36 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_data(void *mlx_ptr, t_data *dest)
{
	dest->img = mlx_new_image(mlx_ptr, WIDTH, HEIGHT);
	dest->addr = mlx_get_data_addr(dest->img, &dest->bits_per_pixel, &dest->line_length, &dest->endian);
}
