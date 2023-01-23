/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_offset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:59:14 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/23 15:20:53 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	change_offset(int *offset, const int shift)
{
	*offset += shift;
}

int	up(t_win *window)
{
	change_offset(&(window->map.y_offset), OFFSET_SHIFT);
	return (EXIT_SUCCESS);
}

int	down(t_win *window)
{
	change_offset(&(window->map.y_offset), -OFFSET_SHIFT);
	return (EXIT_SUCCESS);
}

int	left(t_win *window)
{
	change_offset(&(window->map.x_offset), OFFSET_SHIFT);
	return (EXIT_SUCCESS);
}

int	right(t_win *window)
{
	change_offset(&(window->map.x_offset), -OFFSET_SHIFT);
	return (EXIT_SUCCESS);
}
