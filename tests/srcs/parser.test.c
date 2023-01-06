/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:31:39 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/06 21:53:33 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "run_tests.h"

void	display_parsing(char ***parsing)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (parsing[i] != NULL)
	{
		j = 0;
		while (parsing[i][j] != NULL)
		{
			printf("pars1 --> %s\n", parsing[i][j]);
			printf("pars2 --> %s\n", parsing[i][j]);
			printf("\n");
			++j;
		}
		++i;
	}
}

int	parser_test(const char *path_file)
{
	char	***parsing;
	int		ret_val;

	parsing = parse(path_file);
	ret_val = is_parsing_valid(parsing);
	free_parsing(parsing);
	printf("ret_val --> %d\n", ret_val);
	return (!ret_val);
}
