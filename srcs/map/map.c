/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:04:04 by rbroque           #+#    #+#             */
/*   Updated: 2022/12/20 14:44:53 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_offset(t_pos ***pos_matrix, t_transform *transform)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (pos_matrix[y] != NULL)
	{
		x = 0;
		while (pos_matrix[y][x] != NULL)
		{
			apply_transform(pos_matrix[y][x], x, transform);
			++x;
		}
		++y;
	}
}

t_pos	**get_pos_array(char **coord, int y)
{
	const size_t	size = get_array_size_char(coord);
	size_t			i;
	int				x;
	t_pos			**pos_array;

	pos_array = (t_pos **)malloc((size + 1) * sizeof(t_pos *));
	if (pos_array != NULL)
	{
		i = 0;
		x = 0;
		while (coord[i] != NULL)
		{
			pos_array[i] = init_pos(x, y, ft_atoi(coord[i]));
			if (i > 0)
				apply_persp(pos_array[i], pos_array[i - 1]); // else => free
			++i;
		}
		pos_array[size] = NULL;
	}
	return (pos_array);
}

t_pos	***get_pos_matrix(int fd, size_t size)
{
	t_pos	***pos_matrix;
	int		y;
	size_t	i;
	char	**coord;
	char	*curr_line;

	y = 0;
	pos_matrix = (t_pos ***)malloc((size + 1) * sizeof(t_pos **));
	if (pos_matrix != NULL)
	{
		curr_line = get_next_line(fd);
		i = 0;
		while (curr_line != NULL)
		{
			coord = ft_split_set(curr_line, " \n");
			pos_matrix[i] = get_pos_array(coord, y);
			free(curr_line);
			free_strs(coord);
			curr_line = get_next_line(fd);
			++i;
			++y;
		}
		pos_matrix[size] = NULL;
	}
	return (pos_matrix);
}
