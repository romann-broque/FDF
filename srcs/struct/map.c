/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:04:04 by rbroque           #+#    #+#             */
/*   Updated: 2022/12/09 14:17:12 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_x_offset(int x, int zoom, int i)
{
	(void)i;
	return (x + zoom);
}

int		get_y_offset(int y, int z, int last_z, int zoom, int i)
{
	(void)i;
	(void)zoom;
	if (last_z < z)
		return (y - 1);
	if (last_z > z)
		return (y + 1);
	return (y);
}

t_pos	*get_curr_pos(int *x, int *y, int *z, int last_z, int zoom, int i)
{
	*x = get_x_offset(*x, zoom, i);
	*y = get_y_offset(*y, *z, last_z, zoom, i);
	return (init_pos(*x + HEIGHT / 5,
					*y * (zoom) + WIDTH / 5,
					*z));
}

t_pos	**get_pos_array(char **coord, int y, int zoom)
{
	const size_t	size = get_array_size_char(coord);
	size_t			i;
	int				x;
	int				z;
	int				last_z;
	t_pos			**pos_array;

	pos_array = (t_pos **)malloc((size + 1) * sizeof(t_pos *));
	if (pos_array != NULL)
	{
		i = 0;
		x = 0;
		last_z = 0;
		while (coord[i] != NULL)
		{
			z = ft_atoi(coord[i]);
			pos_array[i] = get_curr_pos(&x, &y, &z, last_z, zoom, i);
			++i;
			last_z = z;
		}
		pos_array[i] = NULL;
	}
	return (pos_array);
}

t_pos	***get_pos(int fd, int zoom)
{
	t_pos	***pos_array;
	t_pos	**curr_pos_array;
	int		y;
	char	**coord;
	char	*curr_line;

	y = 0;
	pos_array = NULL;
	curr_pos_array = NULL;
	curr_line = get_next_line(fd);
	while (curr_line != NULL)
	{
		coord = ft_split_set(curr_line, " \n");
		curr_pos_array = get_pos_array(coord, y, zoom);
		pos_array = extend_array_pos(pos_array, curr_pos_array);
		free(curr_line);
		free_strs(coord);
		curr_line = get_next_line(fd);
		++y;
	}
	return (pos_array);
}
