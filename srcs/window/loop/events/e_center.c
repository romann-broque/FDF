/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_center.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:25:24 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/27 16:00:36 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	center_offset(t_win *window)
{
	window->map.x_offset = X_OFFSET;
	window->map.y_offset = Y_OFFSET;
	return (EXIT_SUCCESS);
}
