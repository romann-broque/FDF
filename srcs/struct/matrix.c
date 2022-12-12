/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:18:12 by rbroque           #+#    #+#             */
/*   Updated: 2022/12/12 18:19:08 by rbroque          ###   ########.fr       */
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

