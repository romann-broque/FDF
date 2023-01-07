/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:16:21 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/07 14:56:06 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf(const char *path_file)
{
	char		***parsing;
	t_window	*window;
	int			ret_val;

	parsing = parse(path_file);
	ret_val = is_parsing_valid(parsing);
	if (ret_val == true)
	{
		window = init_window();
	// 	display_window;
		free_window(window);
	}
	free_parsing(parsing);
	return (!ret_val);
}

