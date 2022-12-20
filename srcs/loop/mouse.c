/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:33:33 by rbroque           #+#    #+#             */
/*   Updated: 2022/12/20 17:38:44 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_press(int key, int x, int y, t_win *window)
{
	(void)x;
	(void)y;
	if (key == SCROLL1_KEY || key == SCROLL2_KEY)
	{
		zoom(key, x, y, window);
		refresh(window);
	}
	return (0);
}
