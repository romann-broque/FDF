/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:18:12 by rbroque           #+#    #+#             */
/*   Updated: 2022/12/14 15:43:50 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	get_matrix_size(const char *path)
{
	char	buffer[BUFFER_SIZE + 1];
	int		fd;
	ssize_t	nb_bytes;
	size_t	size;

	fd = open(path, O_RDONLY);
	size = 0;
	ft_bzero(buffer, BUFFER_SIZE + 1);
	nb_bytes = read(fd, buffer, BUFFER_SIZE);
	while (nb_bytes > 0)
	{
		size += strcountchr(buffer, '\n');
		ft_bzero(buffer, BUFFER_SIZE);
		nb_bytes = read(fd, buffer, BUFFER_SIZE);
	}
	close(fd);
	return (size);
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

size_t	get_pos_matrix_size(t_pos ***pos_array)
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

void	cpy_matrix(t_pos ***dest, t_pos ***src)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (src[i] != NULL)
	{
		j = 0;
		while (src[i][j] != NULL)
		{
			dest[i][j] = init_pos(src[i][j]->x, src[i][j]->y, src[i][j]->z); //
			++j;
		}
		++i;
	}
}

t_pos	***dup_matrix(t_pos ***src, const size_t matrix_size)
{
	size_t	x_nb;
	size_t	i;
	t_pos	***new;

	new = (t_pos ***)malloc((matrix_size + 1) * sizeof(t_pos **));
	if (new != NULL)
	{
		i = 0;
		while (i < matrix_size)
		{
			x_nb = get_pos_array_size(src[i]);
			new[i] = (t_pos **)malloc((x_nb + 1) * sizeof(t_pos *));
			//if (new[i] == NULL)  --> free_all
			new[i][x_nb] = NULL;
			++i;
		}
		new[matrix_size] = NULL;
		cpy_matrix(new, src);
	}
	return (new);
}
