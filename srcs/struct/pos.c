/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 21:13:39 by rbroque           #+#    #+#             */
/*   Updated: 2022/12/20 23:57:53 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pos	set_pos(t_pos *pos, int x, int y, int z)
{
	pos->x = x;
	pos->y = y;
	pos->z = z;
	return (*pos);
}

t_pos	*init_pos(int x, int y, int z)
{
	t_pos	*new;

	new = (t_pos *)malloc(sizeof(t_pos)); // NO MALLOC
	if (new != NULL)
		set_pos(new, x, y, z);
	return (new);
}
