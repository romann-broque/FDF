/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dimensions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:11:57 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/03 18:12:23 by rbroque          ###   ########.fr       */
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