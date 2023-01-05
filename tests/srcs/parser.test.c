/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:31:39 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/05 15:10:26 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "run_tests.h"

int	parser_test(const char *path_file)
{
	char	***parsing;

	parsing = parse(path_file);
	free_parsing(parsing);
	return (EXIT_SUCCESS);
}
