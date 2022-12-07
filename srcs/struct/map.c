/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:04:04 by rbroque           #+#    #+#             */
/*   Updated: 2022/12/07 23:47:35 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
			pos_array[i] = init_pos(x + HEIGHT / 4, y * zoom + WIDTH / 4, ft_atoi(coord[i]));
			x += zoom;
			++i;
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
