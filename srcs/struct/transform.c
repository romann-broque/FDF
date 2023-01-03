/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:53:22 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/03 18:13:07 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_transform	*init_transform(t_pos ***pos_matrix)
{
	t_transform	*transform;

	transform = (t_transform *)malloc(sizeof(t_transform));
	if (transform != NULL)
	{
		transform->zoom = ZOOM;
		transform->altitude = ALTITUDE;
		transform->x_rot = 0;
		transform->y_rot = 0;
		transform->dimensions = get_dimensions(pos_matrix);
		transform->center = get_center(transform);
		transform->x_offset = HEIGHT / 2 - transform->center->x;
		transform->y_offset = WIDTH / 2 - transform->center->y;
	}
	return (transform);
}

void	free_transform(t_transform *transform)
{
	free(transform->dimensions);
	free(transform->center);
	free(transform);
}