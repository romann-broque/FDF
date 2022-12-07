/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:04:04 by rbroque           #+#    #+#             */
/*   Updated: 2022/12/07 16:19:23 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_strs(char **strs)
{
	if (strs != NULL)
	{
		while (*strs != NULL)
		{
			printf("[%s]", *strs);
			++strs;
		}
		printf("\n");
	}
}

void	get_map(int fd)
{
//	t_map	*map;
	char	**coord;
	char	*curr_line;

//	map = NULL;
	curr_line = get_next_line(fd);
	while (curr_line != NULL)
	{
		coord = ft_split(curr_line, ' ');
		print_strs(coord);
		free_array((void **)coord);
		curr_line = get_next_line(fd);
	}
}
