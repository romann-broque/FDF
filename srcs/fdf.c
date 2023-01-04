/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:16:21 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/05 00:40:10 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	fdf(const char *path_file)
{
	char	***parsing;
	int		ret_val;

	parsing = parse(path_file);
	// if (is_parsing_valid)
	// {
	//     init_window(parsing);
	//     display_window;
	// }
	ret_val = is_parsing_valid(parsing);
	free_parsing(parsing);
	return (!ret_val);
}

int	main(int ac, char **av)
{
	int	ret_val;

	ret_val = EXIT_FAILURE;
	if (ac == EXPECT_COUNT_ARG)
		ret_val = fdf(av[1]);
	return (ret_val);
}
