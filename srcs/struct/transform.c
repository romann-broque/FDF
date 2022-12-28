/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:53:22 by rbroque           #+#    #+#             */
/*   Updated: 2022/12/28 15:56:09 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pos *get_center(t_pos ***pos_matrix)
{
	size_t	i;	
	size_t	j;	
	t_pos	*center;

	center = init_pos(0, 0, 0);
	if (center != NULL)
	{
		i = 0;
		while (pos_matrix[i] != NULL)
		{
			j = 0;
			while (pos_matrix[i][j] != NULL)
			{
				if (center->y < pos_matrix[i][j]->y)
					center->y = pos_matrix[i][j]->y;
				++j;
			}
			++i;
		}
		center->x = i / 2;
		center->y /= 2;
	}
	return (center);
}

t_transform *init_transform(t_pos ***pos_matrix)
{
	t_transform *transform;

	transform = (t_transform *)malloc(sizeof(t_transform));
	if (transform != NULL)
	{
		transform->zoom = ZOOM;
		transform->altitude = ALTITUDE;
		transform->x_offset = HEIGHT / 3;
		transform->y_offset = WIDTH / 3;
		transform->x_rot = 0;
		transform->y_rot = -6;
		transform->center = get_center(pos_matrix);
	}
	return (transform);
}

void	free_transform(t_transform *transform)
{
	free(transform->center);
	free(transform);
}