/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:16:21 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/10 12:21:21 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf(const char *path_file)
{
	char	***parsing;
	t_win	window;
	int		ret_val;

	ret_val = EXIT_FAILURE;
	parse(&parsing, path_file);
	if (is_parsing_valid(parsing) == true)
	{
		init_window(&window, parsing);
		if (is_window_initialised(&window) == true)
		{
			display_window(&window);
			ret_val = EXIT_SUCCESS;
		}
		free_window(&window);
	}
	else
		print_error(INVALID_PARSING_ERROR);
	free_parsing(&parsing);
	return (ret_val);
}
