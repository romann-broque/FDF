/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_vertex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:48:35 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/09 13:49:04 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vertex	*create_vertex(const int x, const int y, const int z, const int color)
{
	t_vertex	*new;

	new = (t_vertex *)malloc(sizeof(t_vertex));
	if (new != NULL)
	{
		new->x = x;
		new->y = y;
		new->z = z;
		new->color = color;
	}
	return (new);
}
