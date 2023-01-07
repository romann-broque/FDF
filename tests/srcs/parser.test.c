/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:31:39 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/07 01:30:30 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "run_tests.h"

static int	is_parsing_valid__test1(const size_t test_index)
{
	const char	*path_file = PARSER_PATH1;
	const int	exp_result = KO;
	char		***parsing;
	int			ret_val;

	parsing = parse(path_file);
	ret_val = is_parsing_valid(parsing);
	free_parsing(parsing);
	return (check_result(test_index, ret_val, exp_result));
}

static int	is_parsing_valid__test2(const size_t test_index)
{
	const char	*path_file = PARSER_PATH2;
	const int	exp_result = OK;
	char		***parsing;
	int			ret_val;

	parsing = parse(path_file);
	ret_val = is_parsing_valid(parsing);
	free_parsing(parsing);
	return (check_result(test_index, ret_val, exp_result));
}

int	parser_test(void)
{
	static int	(*tests[])(const size_t) = {
		is_parsing_valid__test1,
		is_parsing_valid__test2,
		NULL};

	return (test_sequence(tests));
}
