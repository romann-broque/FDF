/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:32:34 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/05 00:39:56 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	get_file_size(const char *path_file)
{
	const int	fd = open(path_file, O_RDONLY);
	size_t		size;
	char		*curr_line;

	curr_line = get_next_line(fd);
	size = 0;
	while (curr_line != NULL)
	{
		++size;
		free(curr_line);
		curr_line = get_next_line(fd);
	}
	return (size);
}

char	**get_file_content(const char *path_file, const size_t size)
{
	const int	fd = open(path_file, O_RDONLY);
	size_t		i;
	char		**lines;

	lines = (char **)ft_calloc(size + 1, sizeof(char *));
	if (lines != NULL)
	{
		i = 0;
		while (i < size)
		{
			lines[i] = get_next_line(fd);
			++i;
		}
		lines[size] = NULL;
	}
	return (lines);
}

bool	is_valid_file(char **content)
{
	return (content != NULL);
}
