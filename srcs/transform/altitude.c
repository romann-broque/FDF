/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   altitude.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:54:30 by rbroque           #+#    #+#             */
/*   Updated: 2022/12/22 19:58:25 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_altitude(int alt1, int alt2, t_transform *transform)
{
	(void)transform;
	return (alt1 - alt2);
}

int	altitude(int key, t_win *window)
{
	if (key == Z_KEY)
		++window->transform->altitude;
	else if (window->transform->altitude > 1)
		--window->transform->altitude;
	return (0);
}
