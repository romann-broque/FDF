/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 01:28:32 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/07 01:30:30 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "run_tests.h"

int	check_result(const size_t test_index, const int curr_res, const int exp_res)
{
	printf("Test%zu: ", test_index + 1);
	if (curr_res == exp_res)
	{
		printf(GREEN "OK\n" RESET);
		return (EXIT_SUCCESS);
	}
	printf(RED "KO\n" RESET);
	return (EXIT_FAILURE);
}

int	test_sequence(int (*tests[])(const size_t))
{
	int			ret_val;
	size_t		i;

	ret_val = EXIT_SUCCESS;
	i = 0;
	while (tests[i] != NULL)
	{
		if (tests[i](i) == EXIT_FAILURE)
			ret_val = EXIT_FAILURE;
		++i;
	}
	return (ret_val);

}
