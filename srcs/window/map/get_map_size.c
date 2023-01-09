/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:12:20 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/09 14:12:53 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	get_size_strs(char **parsed_line)
{
	size_t	size;

	size = 0;
	while (parsed_line[size] != NULL)
		++size;
	return (size);
}

size_t	get_x_size(char ***parsing)
{
	size_t	i;
	size_t	curr_size;
	size_t	size;

	size = 0;
	i = 0;
	while (parsing[i] != NULL)
	{
		curr_size = get_size_strs(parsing[i]);
		if (size < curr_size)
			size = curr_size;
		++i;
	}
	return (size);
}

size_t	get_y_size(char ***parsing)
{
	size_t	size;

	size = 0;
	while (parsing[size] != NULL)
		++size;
	return (size);
}
