/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:16:45 by rbroque           #+#    #+#             */
/*   Updated: 2022/12/07 23:45:21 by rbroque          ###   ########.fr       */
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

void	free_pos_matrix(t_pos ***pos_matrix)
{
	size_t	i;

	i = 0;
	while (pos_matrix[i] != NULL)
	{
		free_pos_array(pos_matrix[i]);
		++i;
	}
	free(pos_matrix);
}

size_t	get_array_size_pos(t_pos ***pos_array)
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

size_t	get_array_size_char(char **array)
{
	size_t	size;

	size = 0;
	while (array[size] != NULL)
		++size;
	return (size);
}

t_pos	***extend_array_pos(t_pos ***array, t_pos **element)
{
	const size_t	array_size = get_array_size_pos(array);
	t_pos			***new;

	new = (t_pos ***)malloc((array_size + 1 + 1) * sizeof(t_pos **));
	if (new != NULL)
	{
		if (array != NULL)
		{
			ft_memcpy(new, array, array_size * sizeof(t_pos *));
			free(array);
		}
		new[array_size] = element;
		new[array_size + 1] = NULL;
	}
	return (new);
}
