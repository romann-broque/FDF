/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:53:22 by rbroque           #+#    #+#             */
/*   Updated: 2022/12/28 19:02:08 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pos *get_dimensions(t_pos ***pos_matrix)
{
	size_t	i;	
	size_t	j;	
	t_pos	*dimensions;

	dimensions = init_pos(0, 0, 0);
	if (dimensions != NULL)
	{
		i = 0;
		while (pos_matrix[i] != NULL)
		{
			j = 0;
			while (pos_matrix[i][j] != NULL)
				++j;
			if (dimensions->x < (long)j)
				dimensions->x = j;
			++i;
		}
		dimensions->y = i - (i > 0);
	}
	return (dimensions);
}

t_pos	*get_center(t_transform *transform)
{
	const int	x = (transform->dimensions->x + (transform->dimensions->x % 2)) * transform->zoom + transform->x_offset;
	const int	y = transform->dimensions->y * (2 * transform->zoom);
	const int	z = 0;

	return (init_pos(x, y, z));
}

t_transform *init_transform(t_pos ***pos_matrix)
{
	t_transform *transform;

	transform = (t_transform *)malloc(sizeof(t_transform));
	if (transform != NULL)
	{
		transform->zoom = ZOOM;
		transform->altitude = ALTITUDE;
		transform->x_offset = HEIGHT / 2;
		transform->y_offset = WIDTH / 2;
		transform->x_rot = 0;
		transform->y_rot = -6;
		transform->dimensions = get_dimensions(pos_matrix);
		transform->center = get_center(transform);
	}
	return (transform);
}

void	free_transform(t_transform *transform)
{
	free(transform->dimensions);
	free(transform->center);
	free(transform);
}