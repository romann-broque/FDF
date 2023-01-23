/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:04:07 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/23 12:08:00 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static bool	is_line_valid(char **line, size_t ref_size)
{
	size_t	i;

	i = 0;
	while (line[i] != NULL)
	{
		if (is_format_valid(line[i]) == false)
			return (false);
		++i;
	}
	return (i >= MIN_HEIGHT && i <= INT_MAX
		&& ref_size <= INT_MAX && get_size_strs(line) == ref_size);
}

bool	is_parsing_valid(char ***parsing)
{
	size_t	i;
	size_t	ref_size;

	i = 0;
	if (parsing != NULL && parsing[0] != NULL)
	{
		ref_size = get_size_strs(parsing[0]);
		while (parsing[i] != NULL)
		{
			if (is_line_valid(parsing[i], ref_size) == false)
				return (false);
			++i;
		}
	}
	return (i >= MIN_WIDTH);
}
