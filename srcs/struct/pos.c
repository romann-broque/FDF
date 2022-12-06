/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 21:13:39 by rbroque           #+#    #+#             */
/*   Updated: 2022/12/06 21:13:54 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_pos(t_pos *pos, int x, int y)
{
	pos->x = x;
	pos->y = y;
}

t_pos	*init_pos(int x, int y)
{
	t_pos	*new;

	new = (t_pos *)malloc(sizeof(t_pos));
	if (new != NULL)
		set_pos(new, x, y);
	return (new);
}
