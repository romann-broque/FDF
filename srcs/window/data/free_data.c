/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:56:59 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/09 15:54:16 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_data(const t_data *data, void *mlx_ptr)
{
	if (mlx_ptr != NULL && data->img != NULL)
		mlx_destroy_image(mlx_ptr, data->img);
}
