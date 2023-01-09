/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:16:21 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/09 14:08:49 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf(const char *path_file)
{
	char	***parsing;
	t_win	window;
	int		ret_val;

	parse(&parsing, path_file);
	ret_val = is_parsing_valid(parsing);
	if (ret_val == true)
	{
		init_window(&window, parsing);
		//if (is_window_initialized(window) == true)
		if (window.mlx_ptr != NULL)
		{
			display_window(&window);
			free_window(&window);
		}
	}
	free_parsing(&parsing);
	return (!ret_val);
}
