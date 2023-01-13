/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:00:22 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/13 18:55:29 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	destroy_parsing(char ****parsing, const size_t size)
{
	size_t	i;

	if (*parsing != NULL)
	{
		i = 0;
		while (i < size)
		{
			free_strs((*parsing)[i]);
			++i;
		}
		free(*parsing);
		*parsing = NULL;
	}
}

static char	***parse_file(char **content, const size_t size)
{
	size_t	i;
	char	***parsing;

	parsing = (char ***)ft_calloc(size + 1, sizeof(char **));
	if (parsing != NULL)
	{
		parsing[size] = NULL;
		i = 0;
		while (i < size)
		{
			printf("%s\n", content[i]);
			parsing[i] = ft_split_set(content[i], "\n ");
			if (parsing[i] == NULL)
			{
				destroy_parsing(&parsing, size + 1);
				break ;
			}
			++i;
		}
	}
	return (parsing);
}

void	free_parsing(char ****parsing)
{
	size_t	i;

	if (*parsing != NULL)
	{
		i = 0;
		while ((*parsing)[i] != NULL)
		{
			free_strs((*parsing)[i]);
			++i;
		}
	}
	free(*parsing);
	*parsing = NULL;
}

void	parse(char ****dest, const char *path_file)
{
	const size_t	file_size = get_file_size(path_file);
	char			**file_content;
	char			***parsing;

	parsing = NULL;
	file_content = get_file_content(path_file, file_size);
	if (is_valid_file(file_content) == true)
		parsing = parse_file(file_content, file_size);
	free_strs(file_content);
	*dest = parsing;
}
