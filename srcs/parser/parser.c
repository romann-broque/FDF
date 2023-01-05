/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:00:22 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/05 02:24:04 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	***parse_file(char **content, const size_t size)
{
	size_t	i;
	char	***parsing;

	parsing = (char ***)ft_calloc(size + 1, sizeof(char **));
	if (parsing != NULL)
	{
		i = 0;
		while (i < size)
		{
			parsing[i] = ft_split_set(content[i], "\n "); // protect against NULL
			++i;
		}
		parsing[size] = NULL;
	}
	return (parsing);
}

char	***parse(const char *path_file)
{
	const size_t	file_size = get_file_size(path_file);
	char			**file_content;
	char			***parsing;

	parsing = NULL;
	file_content = get_file_content(path_file, file_size);
	if (is_valid_file(file_content) == true)
		parsing = parse_file(file_content, file_size);
	free_strs(file_content);
	return (parsing);
}

static bool	is_format_valid(const char *str)
{
	while (ft_isdigit(*str) != 0)
		++str;
	return (*str == '\0');
}

bool	is_parsing_valid(char ***parsing)
{
	size_t	i;
	size_t	j;
	bool	is_val;

	is_val = false;
	if (parsing != NULL)
	{
		is_val = true;
		i = 0;
		while (parsing[i] != NULL)
		{
			j = 0;
			while (parsing[i][j] != NULL)
			{
				if (is_format_valid(parsing[i][j]) == false)
					return (false);
				++j;
			}
			++i;
		}
	}
	return (is_val);
}

void	free_parsing(char ***parsing)
{
	size_t	i;

	if (parsing != NULL)
	{
		i = 0;
		while (parsing[i] != NULL)
		{
			free_strs(parsing[i]);
			++i;
		}
	}
	free(parsing);
}
