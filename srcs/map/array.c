/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:16:45 by rbroque           #+#    #+#             */
/*   Updated: 2022/12/16 14:42:02 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_strs(char **array)
{
	size_t	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		++i;
	}
	free(array);
}

void	free_pos_array(t_pos **pos_array)
{
	size_t	i;

	i = 0;
	while (pos_array[i] != NULL)
	{
		free(pos_array[i]);
		++i;
	}
	free(pos_array);
}

size_t	get_pos_array_size(t_pos **pos_array)
{
	size_t	size;

	size = 0;
	if (pos_array != NULL)
	{
		while (pos_array[size] != NULL)
			++size;
	}
	return (size);
}

t_pos	**dup_array(t_pos **src, const size_t array_size)
{
	t_pos	**new;
	size_t	i;

	new = (t_pos **)malloc((array_size + 1) * sizeof(t_pos *));
	if (new != NULL)
	{
		i = 0;
		while (i < array_size)
		{
			new[i] = init_pos(src[i]->x, src[i]->y, src[i]->z);
			++i;
		}
		new[array_size] = NULL;
	}
	return (new);
}
