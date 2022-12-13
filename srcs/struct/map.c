/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:04:04 by rbroque           #+#    #+#             */
/*   Updated: 2022/12/12 23:04:46 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_x_offset(t_pos *pos)
{
	return (pos->x);
}

int		get_y_offset(t_pos *curr_pos, t_pos *last_pos)
{
	return (last_pos->y + (last_pos->z - curr_pos->z) / 6);
}

void	apply_persp(t_pos *curr_pos, t_pos *last_pos)
{
	curr_pos->x = get_x_offset(last_pos);
	curr_pos->y = get_y_offset(curr_pos, last_pos);
}

void	set_offset(t_pos **pos_array, int zoom)
{
	size_t	i;

	i = 0;
	while (pos_array[i] != NULL)
	{
		set_pos(pos_array[i], pos_array[i]->x + (zoom * i) + HEIGHT / 3,
				pos_array[i]->y * (zoom - 5) + WIDTH / 3,
				pos_array[i]->z);
		++i;
	}
}

t_pos	**get_pos_array(char **coord, int y, int zoom)
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
		set_offset(pos_array, zoom);
	}
	return (pos_array);
}

t_pos	***get_pos_matrix(int fd, int zoom, size_t size)
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
			pos_matrix[i] = get_pos_array(coord, y, zoom);
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
