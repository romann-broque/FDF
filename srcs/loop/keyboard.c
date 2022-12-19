/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:34:19 by rbroque           #+#    #+#             */
/*   Updated: 2022/12/20 00:20:34 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_press(int key, t_win *window)
{
	if (key == ESCAPE_KEY)
		close_window1(key, window);
	else if (key == R_KEY || key == F_KEY)
		rotate(key, window);
	else if (key == C_KEY || key == V_KEY)
		contrast(key, window);
	return (0);
}
