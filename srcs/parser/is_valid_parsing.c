/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:04:07 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/07 12:11:23 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static bool	is_format_valid(const char *str)
{
	size_t	i;

	if (*str == '-' || *str == '+')
		++str;
	i = 0;
	while (ft_isdigit(str[i]) != 0)
		++i;
	return (i > 0 && str[i] == '\0');
}

static bool	is_line_valid(char **line)
{
	size_t	i;

	i = 0;
	while (line[i] != NULL)
	{
		if (is_format_valid(line[i]) == false)
			return (false);
		++i;
	}
	return (i >= MIN_WIDTH);
}

bool	is_parsing_valid(char ***parsing)
{
	size_t	i;
	bool	is_val;

	is_val = false;
	if (parsing != NULL)
	{
		is_val = true;
		i = 0;
		while (parsing[i] != NULL)
		{
			if (is_line_valid(parsing[i]) == false)
				return (false);
			++i;
		}
		if (i < MIN_HEIGHT)
			is_val = false;
	}
	return (is_val);
}
