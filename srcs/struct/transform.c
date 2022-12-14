/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:53:22 by rbroque           #+#    #+#             */
/*   Updated: 2022/12/13 14:53:46 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_transform	*init_transform(void)
{
	t_transform	*transform;

	transform = (t_transform *)malloc(sizeof(t_transform));
	if (transform != NULL)
	{
		transform->zoom = ZOOM;
		transform->x_offset = HEIGHT / 3;
		transform->y_offset = WIDTH / 3;
		transform->x_rot = 0;
		transform->y_rot = -6;
	}
	return (transform);
}
