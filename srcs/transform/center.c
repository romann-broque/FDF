/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:12:41 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/03 18:12:57 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pos	*get_center(t_transform *transform)
{
	const int	x = (transform->dimensions->x / 2 + (transform->dimensions->x % 2)) * transform->zoom;
	const int	y = (transform->dimensions->y / 2 + (transform->dimensions->y % 2)) * transform->zoom;
	const int	z = 0;

	return (init_pos(x, y, z));
}